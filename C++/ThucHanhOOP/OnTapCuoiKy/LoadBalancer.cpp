#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Location {
    protected:
        int x;
        int y;
    public:
        void Nhap() {
            cin >> x >> y;
        }
        int getX() {
            return x;
        }
        int getY() {
            return y;
        }
        float getDistance(Location l) {
            return sqrt(pow(x-l.getX(), 2) + pow(y-l.getY(), 2));
        }
};
enum Status {
    FREE,
    BUSY,
};
class Server {
    private:
        int ID;
        float RAM;
        float CPU;
        Location location;
        Status status = FREE;

    public:
        virtual void Nhap() {
            cin >> ID;
            cin >> RAM;
            cin >> CPU;
            location.Nhap();
        }
        int getID() {
            return ID;
        }
        float getRAM() {
            return RAM;
        }
        float getCPU() {
            return CPU;
        }
        Status getStatus() {
            return status;
        }
        void setStatus(Status status) {
            this->status = status;
        }
        float getDistance(Location l) {
            return location.getDistance(l);
        }
        Location getLocation() {
            return location;
        }
};

class Request {
    private:
        int ID;
        float weight;
        Location location;
    public:
        void Nhap() {
            cin >> ID;
            cin >> weight;
            location.Nhap();
        }
        int getID() {
            return ID;
        }
        float getWeight() {
            return weight;
        }
        float getDistance(Location l) {
            return location.getDistance(l);
        }
        Location getLocation() {
            return location;
        }

};

class LoadBalancer {
    protected:
        int ID;
        int loai;
        Location location;
        vector<Server*> servers;
        vector<Request*> requests;
        vector<LoadBalancer*> subLoadBalancers;
    public:
        void addRequest(Request* r) {
            requests.push_back(r);
        }
        float getDistance(Location l) {
            return location.getDistance(l);
        }
        Location getLocation() {
            return location;
        }

        virtual void Nhap() {
            cin >> ID;
            cin >> loai;
            location.Nhap();

            int number_of_servers, number_of_sub_lb;
            cin >> number_of_servers >> number_of_sub_lb;
            for (int i = 0; i < number_of_servers; i++) {
                Server* s = new Server();
                s->Nhap();
                servers.push_back(s);
            }
            for (int i = 0; i < number_of_sub_lb; i++) {
                LoadBalancer* lb = new LoadBalancer();
                lb->Nhap();
                subLoadBalancers.push_back(lb);
            }
        }
        virtual void XuLy(set<pair<int, int>>& log) {
            switch (loai) {
                case 1:
                    RoundRonin(log);
                    break;
                case 2:
                    Weighted(log);
                    break;
                case 3:
                    Fastest(log);
                    break;
                default:
                    break;
            }
        }
        void RoundRonin(set<pair<int, int>>& log) {
            for (auto it = requests.begin(); it != requests.end(); it++) {
                for (int i = 0; i < servers.size(); i++) {
                    if (servers[i]->getStatus() == BUSY) {
                        continue;
                    }
                    servers[i]->setStatus(BUSY);
                    log.insert(make_pair((*it)->getID(), servers[i]->getID()));
                    it = requests.erase(it);
                    it--;
                    break;
                }
            }
        }
        void Weighted(set<pair<int, int>>& log) {
            for (auto it = requests.begin(); it != requests.end(); it++) {
                Server* minServer = NULL;
                for (int j = 0; j < servers.size(); j++) {
                    if (servers[j]->getStatus() == BUSY) {
                        continue;
                    }
                    if (minServer == NULL) {
                        minServer = servers[j];
                    }
                    else {
                        float capacity = abs((*it)->getWeight() - servers[j]->getCPU() * servers[j]->getRAM());
                        float minCapacity = abs((*it)->getWeight() - minServer->getCPU() * minServer->getRAM());
                        if (capacity < minCapacity) {
                            minServer = servers[j];
                        }
                    }
                }
                minServer->setStatus(BUSY);
                log.insert(make_pair((*it)->getID(), minServer->getID()));
                it = requests.erase(it);
                it--;
            }
        }
        void Fastest(set<pair<int, int>>& log) {
            for (auto it = requests.begin(); it != requests.end(); it++) {
                Server* minServer = NULL;
                for (int j = 0; j < servers.size(); j++) {
                    if (servers[j]->getStatus() == BUSY) {
                        continue;
                    }
                    if (minServer == NULL) {
                        minServer = servers[j];
                    }
                    else {
                        float time = getDistance(servers[j]->getLocation()) + servers[j]->getDistance((*it)->getLocation());
                        float minTime = getDistance(minServer->getLocation()) + minServer->getDistance((*it)->getLocation());
                        if (time < minTime) {
                            minServer = servers[j];
                        }
                    }
                }
                minServer->setStatus(BUSY);
                log.insert(make_pair((*it)->getID(), minServer->getID()));
                it = requests.erase(it);
                it--;
            }
        }
        ~LoadBalancer() {
            for (int i = 0; i < servers.size(); i++) {
                delete servers[i];
            }
            for (int i = 0; i < requests.size(); i++) {
                delete requests[i];
            }
            for (int i = 0; i < subLoadBalancers.size(); i++) {
                delete subLoadBalancers[i];
            }
        }
};

class MultiLoadBalancer : public LoadBalancer {
    public:
        void Nhap() override {
            LoadBalancer::Nhap();
            int number_of_requests;
            cin >> number_of_requests;
            for (int i = 0; i < number_of_requests; i++) {
                Request* r = new Request();
                r->Nhap();
                requests.push_back(r);
            }
        }
        void XuLy(set<pair<int, int>>& log) override {
            LoadBalancer::XuLy(log);
            int requestPerSubLB = requests.size() / subLoadBalancers.size();
            int requestRemain = requests.size() - (subLoadBalancers.size() - 1) * requestPerSubLB;
            for (int i = 0; i < subLoadBalancers.size() - 1; i++) {
                for (int j = 0; j < requestPerSubLB; j++) {
                    subLoadBalancers[i]->addRequest(requests.front());
                    subLoadBalancers[i]->XuLy(log);
                    requests.erase(requests.begin());
                }
            }
            for (int i = 0; i < requestRemain; i++) {
                subLoadBalancers[subLoadBalancers.size() - 1]->addRequest(requests.front());
                subLoadBalancers[subLoadBalancers.size() - 1]->XuLy(log);
                requests.erase(requests.begin());
            }
        }
};

class Logging {
    private:
        set<pair<int, int>> log;
        MultiLoadBalancer mlb;
    public:
        void Nhap() {
            mlb.Nhap();
        }
        void XuLy() {
            mlb.XuLy(log);
        }
        void Xuat() {
            for (auto it = log.begin(); it != log.end(); it++) {
                cout << it->first << " " << it->second << endl;
            }
        }

};

int main() {
    Logging l;
    l.Nhap();
    l.XuLy();
    l.Xuat();
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Location {
    private:
        int x, y;
    public:
        Location() {}
        Location(int x, int y) {
            this->x = x;
            this->y = y;
        }
        float get_distance(Location l) {
            return sqrt(pow(x-l.x, 2) + pow(y-l.y, 2));
        }
};

class Server {
    private:
        int ID;
        float RAM;
        float CPU;
        Location location;
        bool status = false; // false: free, true: busy
    public:
        void input() {
            cin >> ID >> RAM >> CPU;
            int x, y;
            cin >> x >> y;
            location = Location(x, y);
        }
        bool can_handle_request() {
            return !status;
        }
        void handle_request() {
            status = true;
        }
        Location get_location() {
            return location;
        }
        float get_distance(Location l) {
            return location.get_distance(l);
        }
        float get_RAM() {
            return RAM;
        }
        float get_CPU() {
            return CPU;
        }
        int get_ID() {
            return ID;
        }
};

class Request {
    private:
        int ID;
        int weight;
        Location location;
    public:
        void input() {
            cin >> ID >> weight;
            int x, y;
            cin >> x >> y;
            location = Location(x, y);
        }
        int get_weight() {
            return weight;
        }
        Location get_location() {
            return location;
        }
        int get_ID() {
            return ID;
        }
};


class LoadBalancer {
    protected:
        int ID;
        int type;
        Location location;
        vector<Server> servers;
        vector<LoadBalancer*> subloadbalancers;
        int number_of_requests = 0;
    public:
        LoadBalancer() {}
        LoadBalancer(int ID, int type, int x, int y) {
            this->ID = ID;
            this->type = type;
            location = Location(x, y);
        }

        void push_back_sublb(LoadBalancer* sublb) {
            subloadbalancers.push_back(sublb);
        }
        int input() {
            int server_size, sublb_size;
            cin >> server_size >> sublb_size;
            for (int i = 0; i < server_size; i++) {
                Server server;
                server.input();
                servers.push_back(server);
            }
            return sublb_size; 
        }
        virtual void dispatch(int, Request, set<pair<int,int>>&) = 0;
        bool can_handle_request(int request_size) {
            return number_of_requests < request_size;
        }
        void handle_request() {
            number_of_requests++;
        }
        void subbalance(int request_size, Request request, set<pair<int,int>>& log) {
            int request_per_sublb = request_size / subloadbalancers.size();
            for (auto& sublb : subloadbalancers) {
                if (sublb->can_handle_request(request_per_sublb)) {
                    sublb->handle_request();
                    sublb->dispatch(request_size, request, log);
                    return;
                }
            }
            auto last_sublb = subloadbalancers.back();
            last_sublb->handle_request();
            last_sublb->dispatch(request_size, request, log);
        }
        float get_distance(Location l) {
            return location.get_distance(l);
        }
};

class RoundRobin : public LoadBalancer {
    public:
        using LoadBalancer::LoadBalancer;

        void dispatch(int request_size, Request request, set<pair<int,int>>& log) override {
            bool is_dispatched = false;
            for (auto& s : servers) {
                if (s.can_handle_request()) {
                    s.handle_request();
                    log.insert({request.get_ID(), s.get_ID()});
                    is_dispatched = true;
                    break;
                }
            }
            if (is_dispatched) 
                return;
            if (subloadbalancers.size() != 0) {
                subbalance(request_size, request, log);
            }
        }
};

class WeightedRoundRobin : public LoadBalancer {
    public:
        using LoadBalancer::LoadBalancer;

        void dispatch(int request_size, Request request, set<pair<int,int>>& log) override {
            Server* best_server = nullptr;
            float best_cost = INFINITY;
            for (auto& s : servers) {
                if (s.can_handle_request()) {
                    float cost = abs(request.get_weight() - s.get_RAM() * s.get_CPU());
                    if (cost < best_cost) {
                        best_cost = cost;
                        best_server = &s;
                    }
                }
            }
            if (best_server != nullptr) {
                best_server->handle_request();
                log.insert({request.get_ID(), best_server->get_ID()});
                return;
            }
            if (subloadbalancers.size() != 0) {
                subbalance(request_size, request, log);
            }
        }

};

class FastestResponseTime : public LoadBalancer {
    public:
        using LoadBalancer::LoadBalancer;

        void dispatch(int request_size, Request request, set<pair<int,int>>& log) override {
            Server* best_server = nullptr;
            float best_cost = INFINITY;
            for (auto& s : servers) {
                if (s.can_handle_request()) {
                    float cost = get_distance(s.get_location()) + s.get_distance(request.get_location());
                    if (cost < best_cost) {
                        best_cost = cost;
                        best_server = &s;
                    }
                }
            }
            if (best_server != nullptr) {
                best_server->handle_request();
                log.insert({request.get_ID(), best_server->get_ID()});
                return;
            }
            if (subloadbalancers.size() != 0) {
                subbalance(request_size, request, log);
            }
        }

};

class System {
    private:
        LoadBalancer* master;
        vector<Request> requests;
        set<pair<int,int>> log;
    public:
        LoadBalancer* create(int ID, int type, int x, int y) {
            switch (type) {
                case 1:
                    return new RoundRobin(ID, type, x, y);
                case 2:
                    return new WeightedRoundRobin(ID, type, x, y);
                case 3:
                    return new FastestResponseTime(ID, type, x, y);
                default:
                    return nullptr;
            }
        }
        LoadBalancer* input_balancer(LoadBalancer* lb) {
            int sublb_size = lb->input();
            for (int i = 0; i < sublb_size; i++) {
                int ID, type, x, y;
                cin >> ID >> type >> x >> y;
                LoadBalancer* sublb = create(ID, type, x, y);
                lb->push_back_sublb(sublb);
                input_balancer(sublb);
            }
            return lb;
        }

        void input() {
            int ID, type, x, y;
            cin >> ID >> type >> x >> y;
            master = create(ID, type, x, y);
            input_balancer(master);
            int request_size;
            cin >> request_size;
            for (int i = 0; i < request_size; i++) {
                Request request;
                request.input();
                requests.push_back(request);
            }
        }
        void process() {
            for (auto it = requests.begin(); it != requests.end(); it++) {
                master->dispatch(requests.size(), *it, log);
                it = requests.erase(it);
                it--;
            }
        }
        void output() {
            for (auto i : log) {
                cout << i.first << " " << i.second << endl;
            }
        }
};

int main() {
    System system;
    system.input();
    system.process();
    system.output();
    return 0;
}
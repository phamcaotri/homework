#include <bits/stdc++.h>

using namespace std;


struct Graph {
    unordered_map<string, unordered_map<string, int>> dsKe;
    vector<string> dinh;
    int v, n;
    void Nhap() {
        cin >> v >> n;
        for (int i = 0; i < v; i++) {
            string c;
            cin >> c;
            dinh.push_back(c);
        }
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                int x;
                cin >> x;
                if (x != 0)
                    dsKe[dinh[i]][dinh[j]] = x;
                
            }
        }

    }
    void duyetGraph() {
        for (int i = 0; i < n; i++) {
            string begin, end;
            cin >> begin >> end;
            Dijsktra(begin, end);
        }
    }
    void DFS(string begin, string end) {
        unordered_map<string, string> trace;
        stack<string> open;
        unordered_map<string, bool> close;
        bool found = false;
        int dinhDaDuyet = 0;
        open.push(begin);
        while (!open.empty()) {
            string node = open.top();
            open.pop();
            if (close[node])
                continue;
            close[node] = true;
            dinhDaDuyet++;
            if (node == end) {
                found = true;
                break;
            }
            for (auto dinhKe : dinh) {
                if (!close[dinhKe] and dsKe[node][dinhKe] != 0) {
                    trace[dinhKe] = node;
                    open.push(dinhKe);
                }
            }
            
        }

        if (found) {
            int length = 0;
            string node = end;
            vector<string> path;
            while (node != begin) {
                path.push_back(node);
                length += dsKe[trace[node]][node];
                node = trace[node];
            } 
            path.push_back(begin);
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] << " ";
            }
            cout << endl;
            cout << dinhDaDuyet << " " << length << endl;
        } else {
            cout << "-unreachable-" << endl;
            cout << dinhDaDuyet << " " << 0 << endl;
        }
    }

    void BFS(string begin, string end) {
        unordered_map<string, string> trace;
        queue<string> open;
        unordered_map<string, bool> close;
        bool found = false;
        int dinhDaDuyet = 0;
        open.push(begin);
        while (!open.empty()) {
            string node = open.front();
            open.pop();
            if (close[node])
                continue;
            close[node] = true;
            dinhDaDuyet++;
            if (node == end) {
                found = true;
                break;
            }
            for (auto dinhKe : dinh) {
                if (!close[dinhKe] and dsKe[node][dinhKe] != 0) {
                    trace[dinhKe] = node;
                    open.push(dinhKe);
                }
            }
            
        }

        if (found) {
            int length = 0;
            string node = end;
            vector<string> path;
            while (node != begin) {
                path.push_back(node);
                length += dsKe[trace[node]][node];
                node = trace[node];
            } 
            path.push_back(begin);
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] << " ";
            }
            cout << endl;
            cout << dinhDaDuyet << " " << length << endl;
        } else {
            cout << "-unreachable-" << endl;
            cout << dinhDaDuyet << " " << 0 << endl;
        }
    }

    void Dijsktra(string begin, string end) {
        unordered_map<string, string> trace;
        unordered_map<string, int> distance;
        unordered_map<string, bool> close;
        bool found = false;
        int dinhDaDuyet = 0;
        for (auto dinhKe : dinh) {
            distance[dinhKe] = INT_MAX;
        }
        distance[begin] = 0;
        while (true) {
            string node = "";
            int minDistance = INT_MAX;
            for (auto dinhKe : dinh) {
                if (!close[dinhKe] and distance[dinhKe] < minDistance) {
                    node = dinhKe;
                    minDistance = distance[dinhKe];
                }
            }
            if (node == "") {
                break;
            }
            close[node] = true;
            dinhDaDuyet++;
            if (node == end) {
                found = true;
                break;
            }
            for (auto dinhKe : dinh) {
                if (!close[dinhKe] and dsKe[node][dinhKe] != 0) {
                    if (distance[dinhKe] > distance[node] + dsKe[node][dinhKe]) {
                        distance[dinhKe] = distance[node] + dsKe[node][dinhKe];
                        trace[dinhKe] = node;
                    }
                }
            }
        }

        if (found) {
            int length = 0;
            string node = end;
            vector<string> path;
            while (node != begin) {
                path.push_back(node);
                length += dsKe[trace[node]][node];
                node = trace[node];
            } 
            path.push_back(begin);
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] << " ";
            }
            cout << endl;
            cout << dinhDaDuyet << " " << length << endl;
        } else {
            cout << "-unreachable-" << endl;
            cout << dinhDaDuyet << " " << 0 << endl;
        }
    }

};

int main() {
    Graph g;
    g.Nhap();
    g.duyetGraph();
    return 0;
}
#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

struct Graph {
    vector<vector<int>> m;
    vector<string> name;
    unordered_map<string, int> id;
    int v;
    int n;

    void input() {
        cin >> v >> n;
        m.resize(v, vector<int>(v, 0));
        for (int i = 0; i < v; i++) {
            string s;
            cin >> s;
            name.push_back(s);
            id[s] = i;
        }
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                int x;
                cin >> x;
                if (x) {
                    m[i][j] = x;
                }
            }
        }
    }
    void Find() {
        for (int i = 0; i < n; i++) {
            string begin, end;
            cin >> begin >> end;
            DFS(id[begin], id[end]);
            BFS(id[begin], id[end]);
            BFS_NO_REPEAT(id[begin], id[end]);
            Dijkstra(id[begin], id[end]);
        }
    }
    void DFS(int begin, int end) {
        unordered_map<int, int> trace;
        unordered_map<int, bool> close;
        stack<int> open;
        bool found = false;
        open.push(begin);
        while (!open.empty()) {
            int u = open.top();
            open.pop();
            if (close[u]) {
                continue;
            }
            close[u] = true;
            if (u == end) {
                found = true;
                break;
            }
            for (int i = 0; i < v; i++) {
                if ((close.find(i) == close.end()) and m[u][i]) {
                    trace[i] = u;
                    open.push(i);
                }
            }
        }
        if (found) {
            vector<int> path;
            int u = end;
            int length = 0;
            while (u != begin) {
                path.push_back(u);
                length += m[trace[u]][u];
                u = trace[u];
            }
            path.push_back(begin);
            for (int i = path.size() -1; i >= 0; i--) {
                cout << name[path[i]] << ' ';
            }
            cout << endl;
            cout << close.size() << ' ' << length << endl; 
        } else {
            cout << "-unreachable-\n" << close.size() << ' ' << 0 << endl;
        }
    }

    void BFS(int begin, int end) {
        unordered_map<int, int> trace;
        unordered_map<int, bool> close;
        queue<int> open;
        bool found = false;
        open.push(begin);
        while(!open.empty()) {
            int u = open.front();
            open.pop();
            if (close[u]) {
                continue;
            }
            close[u] = true;
            if (u == end) {
                found = true;
                break;
            }
            for (int i = 0; i < v; i++) {
                if (close.find(i) == close.end() and m[u][i]) {
                    trace[i] = u;
                    open.push(i);
                }
            }
        }
        if (found) {
            vector<int> path;
            int u = end;
            int length = 0;
            while (u != begin) {
                path.push_back(u);
                length += m[trace[u]][u];
                u = trace[u];
            }
            path.push_back(begin);
            for (int i = path.size() -1; i >= 0; i--) {
                cout << name[path[i]] << ' ';
            }
            cout << endl;
            cout << close.size() << ' ' << length << endl;

        } else {
            cout << "-unreachable-\n" << close.size() << ' ' << 0 << endl;
        }
    }
    void BFS_NO_REPEAT(int begin, int end) {
        unordered_map<int, int> trace;
        unordered_map<int, bool> close;
        list<int> open;
        bool found = false;
        open.push_back(begin);
        while (!open.empty()) {
            int u = open.front();
            open.pop_front();
            if (close[u]) {
                continue;
            }
            close[u] = true;
            if (u == end) {
                found = true;
                break;
            }
            for (int i = 0; i < v; i++) {
                if (close.find(i) == close.end() and m[u][i] and find(open.begin(), open.end(), i) == open.end()) {
                    trace[i] = u;
                    open.push_back(i);
                }
            }
        }
        if (found) {
            vector<int> path;
            int u = end;
            int length = 0;
            while (u != begin) {
                path.push_back(u);
                length += m[trace[u]][u];
                u = trace[u];
            }
            path.push_back(begin);
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << name[path[i]] << ' ';
            }
            cout << endl;
            cout << close.size() << ' ' << length << endl;
        } else {
            cout << "-unreachable-\n" << close.size() << ' ' << 0 << endl;
        }
    }

    void Dijkstra(int begin, int end) {
        // unordered_map<int, int> trace;
        // unordered_map<int, bool> close;
        // unordered_map<int, int> distance;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> open;
        // bool found = false;
        // open.push(make_pair(0, begin));
        // while (!open.empty()) {
        //     int u = open.top().second;
        //     open.pop();
        //     if (close[u]) {
        //         continue;
        //     }
        //     close[u] = true;
        //     if (u == end) {
        //         found = true;
        //         break;
        //     }
        //     for (int i = 0; i < v; i++) {
        //         if (close.find(i) == close.end() and m[u][i]) {
        //             trace[i] = u;
        //             open.push(make_pair(distance[u] + m[u][i], i));
        //         }
        //     }
        // }
        // if (found) {
        //     vector<int> path;
        //     int u = end;
        //     int length = 0;
        //     while (u != begin) {
        //         path.push_back(u);
        //         length += m[trace[u]][u];
        //         u = trace[u];
        //     }
        //     path.push_back(begin);
        //     for (int i = path.size() - 1; i >= 0; i--) {
        //         cout << name[path[i]] << ' ';
        //     }
        //     cout << endl;
        //     cout << close.size() << ' ' << length << endl;
        // } else {
        //     cout << "-unreachable-\n" << close.size() << ' ' << 0 << endl;
        // }
        unordered_map<int, int> trace;
        unordered_map<int, bool> close;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> open;
        vector<int> distance(v, INT_MAX);
        bool found = false;
        distance[begin] = 0;
        open.push({0, begin});
        while (!open.empty()) {
            auto [d, u] = open.top();
            open.pop();
            if (close[u]) {
                continue;
            }
            close[u] = true;
            if (u == end) {
                found = true;
                break;
            }
            for (int i = 0; i < v; i++) {
                if (close.find(i) == close.end() and m[u][i]) {
                    if (distance[i] > distance[u] + m[u][i]) {
                        distance[i] = distance[u] + m[u][i];
                        trace[i] = u;
                        open.push({distance[i], i});
                    }
                }
            }
        }
        if (found) {
            vector<int> path;
            int u = end;
            int length = 0;
            while (u != begin) {
                path.push_back(u);
                length += m[trace[u]][u];
                u = trace[u];
            }
            path.push_back(begin);
            for (int i = path.size() -1; i >= 0 ; i --) {
                cout << name[path[i]] << ' ';
            }
            cout << endl;
            cout << close.size() << ' ' << length << endl;
        } else {
            cout << "-unreachable-\n" << close.size() << ' ' << 0 << endl;
        }

    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Graph g;
    g.input();
    g.Find();
    return 0;
}
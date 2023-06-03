#include <bits/stdc++.h>

using namespace std;


struct Graph {
    vector<vector<int>> g;

    map<string, int> m; // index string -> int
    vector<string> index; // index int -> string
    int n;
    void Nhap() {
        int v;
        cin >> v >> n;
        g = vector<vector<int>>(v, vector<int>(v, 0));
        for (int i = 0; i < v; i++) {
            string c;
            cin >> c;
            m[c] = i;
            index.push_back(c);
        }
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++) {
                cin >> g[i][j];
            }
    }
    void Xuat() {
        for (int i = 0; i < g.size(); i++) {
            cout << index[i] << " ";
            for (int j = 0; j < g[i].size(); j++) {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }
    void DFS(string begin, string end) {
        vector<pair<string, string>> p = {};
        stack<pair<string, string>> open = {};
        unordered_map<string, bool> close = {};
        bool find = false;

        int num_e = 0;
        // khoi tao
        open.push({begin, begin});
        while (!open.empty()) {
            p.push_back(open.top());
            open.pop();
            string x = p.back().first;
            close[x];
            for (int i = 0; i < g.size(); i++) {
                if (g[m[x]][i] > 0) {
                    if (close[x] == 0) {
                        open.push({index[i], p.back().first});
                    }
                }
            }
            if (x == end) {
                find = true;
                break;
            }
            if (close[x] == 1)
                continue;
            close[x] = 1;  
        }

        if (find) {
            stack<string> path = {};
            auto this_p = p.back();
            do {
                path.push(this_p.first);
                num_e += g[m[this_p.second]][m[this_p.first]];
                if (this_p.first == begin) break;
                this_p = p[m[this_p.second]];
            } while (true);
            while (!path.empty()) {
                cout << path.top() << ' ';
                path.pop();
                
            }
            cout << endl;
            cout << close.size() << ' ' << num_e << endl;
        } else {
            cout << "-unreachable-" << endl;
            cout << close.size() << ' ' << num_e << endl;
        }

    }
    void duyetGraph() {
        for (int i = 0; i < n; i++) {
            string x, y;
            cin >> x >> y;
            DFS(x, y);
        }
    }

};



int main() {
    Graph g;
    g.Nhap();
    g.duyetGraph();
    return 0;
}
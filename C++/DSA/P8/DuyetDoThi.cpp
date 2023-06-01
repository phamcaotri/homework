#include <bits/stdc++.h>

using namespace std;

struct Graph {
    vector<vector<int>> g;

    map<string, int> m; // index string -> int
    vector<string> index; // index int -> string

    stack<string> s;
    unordered_map<string, bool> visited;

    void Nhap() {
        int v, n;
        cin >> v >> n;
        g = vector<vector<int>>(v, vector<int>(v, 0));
        for (int i = 0; i < v; i++) {
            string c;
            cin >> c;
            m[c] = i;
            index.push_back(c);
        }
        for (int i = 0; i < v, i++)
            for (int j = 0; j < v; j++) {
                cin >> g[i][j];
            }
    }

};

int main() {
    Graph g;
    g.Nhap();
    return 0;
}
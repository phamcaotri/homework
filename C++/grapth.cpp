#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfs(map<int, set<int>>& graph, int start, const set<int>& k) {
        vector<int> ans;
        if (k.count(start)) {
            ans.push_back(start);
            return ans;
        }
        queue<pair<int, vector<int>>> q;
        q.push({ start, {start} });
        while (!q.empty()) {
            auto [v, path] = q.front();
            q.pop();
            for (auto& next : graph[v]) {
                if (k.count(next) == 0 && find(path.begin(), path.end(), next) == path.end()) {
                    vector<int> newPath = path;
                    newPath.push_back(next);
                    q.push({ next, newPath });
                }
                else if (k.count(next) != 0) {
                    vector<int> newPath = path;
                    newPath.push_back(next);
                    ans = newPath;
                    return ans;
                }
            }
        }
        return ans;
    }

    map<int, set<int>> tograph(const vector<vector<int>>& m) {
        map<int, set<int>> graph;
        for (auto& i : m) {
            graph[i[0]].insert(i[1]);
            graph[i[1]].insert(i[0]);
        }
        return graph;
    }

    vector<int> findexits(int n, const vector<vector<int>>& m, const set<int>& k) {
        map<int, set<int>> graph = tograph(m);
        vector<int> ans;
        for (int start = 1; start <= graph.size(); start++) {
            auto path = bfs(graph, start, k);
            ans.push_back(path.size() - 1);
        }
        return ans;
    }
};

/*
Dữ liệu vào:
10 2
10 8
9
6 7
7 5
5 8
8 1
1 10
10 3
3 4
4 9
9 2

*/

int main() {
    // int n = 10;
    // vector<vector<int>> m = { {6, 7}, {7,5},{5,8},{8,1},{1,10},{10,3},{3,4},{4,9},{9,2} };
    // set<int> k = { 10,8 };
    int n, temp_k;
    cin >> n >> temp_k;
    set<int> k;
    for (int i = 0; i < temp_k; i++) {
        int temp;
        cin >> temp;
        k.insert(temp);
    }
    vector<vector<int>> m;
    int temp_m;
    cin >> temp_m;
    for (int i = 0; i < temp_m; i++) {
        vector<int> temp;
        for (int j = 0; j < 2; j++) {
            int temp2;
            cin >> temp2;
            temp.push_back(temp2);
        }
        m.push_back(temp);
    }

    Solution s;
    vector<int> ans = s.findexits(n, m, k);
    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
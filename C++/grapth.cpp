#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> bfs(map<int, set<int>> &graph, int start, vector<int> &k){
        set<int> setK;
        for (auto &i: k){
            setK.insert(i);
        }
        vector<int> ans;
        if (setK.find(start) != setK.end()){
            ans.push_back(start);
            return ans;
        }
        queue<pair<int, vector<int>>> q;
        q.push(make_pair(start, vector<int>{start}));
        while (!q.empty()){
            auto p = q.front();
            q.pop();
            int v = p.first;
            vector<int> path = p.second;
            for (auto &next: graph[v]){
                if (setK.find(next) == setK.end() && find(path.begin(), path.end(), next) == path.end()){
                    vector<int> newPath = path;
                    newPath.push_back(next);
                    q.push(make_pair(next, newPath));
                }
                else if (setK.find(next) != setK.end()){
                    vector<int> newPath = path;
                    newPath.push_back(next);
                    ans = newPath;
                    return ans;
                }
            }
        }
        return ans;
    }

    map<int, set<int>> tograph(vector<vector<int>> &m){
        map<int, set<int>> graph;
        for (auto &i: m){
            graph[i[0]].insert(i[1]);
            graph[i[1]].insert(i[0]);
        }
        return graph;
    }
    vector<int> findexits(int n, vector<vector<int>> &m, vector<int> &k){
        map<int, set<int>> graph = tograph(m);
        vector<int> ans;
        if (true){
            for (int start = 1; start <= graph.size(); start++){
                auto path = bfs(graph, start, k);
                ans.push_back(path.size() - 1);
            }
        }
        else{
            map<int, int> pathlist;
            for (auto &start: k){
                auto path = bfs(graph, start, k);
                pathlist[path.back()] = path.size() - 1;
            }
            for (int i = 1; i <= n; i++){
                if (pathlist.find(i) == pathlist.end()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(pathlist[i]);
                }
            }
        }
        return ans;
    }
};
/*
n = 10
m = [(6, 7), (7,5),(5,8),(8,1),(1,10),(10,3),(3,4),(4,9),(9,2)]
k = (10,8)

*/

int main(){
    int n = 10;
    vector<vector<int>> m = {{6, 7}, {7,5},{5,8},{8,1},{1,10},{10,3},{3,4},{4,9},{9,2}};
    vector<int> k = {10,8};
    Solution s;
    vector<int> ans = s.findexits(n, m, k);
    for (auto &i: ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
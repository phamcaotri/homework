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
/*
    def findexits(self, n, m, k):
        graph = self.tograph(m)
        if n <= len(k):
            for start in range(1, len(graph) + 1):
                yield len(next(self.bfs(graph, start, k))) - 1
        else:
            pathlist = {}
            for start in k:
                for path in self.bfs(graph, start, range(1, n + 1)):
                    pathlist[path[-1]] = len(path) - 1 if path[-1] not in pathlist else min(pathlist[path[-1]], len(path) - 1)
            for i in range(1, n + 1):
                if i not in pathlist:
                    yield -1
                else:
                    yield pathlist[i]
*/
    vector<int> findexits(int n, vector<vector<int>> &m, vector<int> &k){
        map<int, set<int>> graph = tograph(m);
        vector<int> ans;
        if (n <= k.size()){
            for (int start = 1; start <= graph.size(); start++){
                auto path = bfs(graph, start, k);
                ans.push_back(path.size() - 1);
            }
        }
        else{
            map<int, int> pathlist;
            for (auto &start: k){
                set<int> rangeN;
                for (int i = 1; i <= n; i++){
                    rangeN.insert(i);
                }
                for (auto &path: bfs(graph, start, rangeN)){
                    if (pathlist.find(path) == pathlist.end()){
                        pathlist[path] = path.size() - 1;
                    }
                    else{
                        pathlist[path] = min(pathlist[path], (int)path.size() - 1);
                    }
                }
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
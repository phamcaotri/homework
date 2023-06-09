#include <bits/stdc++.h>

using namespace std;


struct Graph {
    unordered_map<string, unordered_map<string, int>> dsKe;
    vector<string> dinh;
    unordered_map<string, int> index;
    int v, n;
    void Nhap() {
        cin >> v >> n;
        for (int i = 0; i < v; i++) {
            string c;
            cin >> c;
            dinh.push_back(c);
            index[c] = i;
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
            Dijkstra(begin, end);
        }
    }

    void Dijkstra(string begin, string end) {
        unordered_map<string, string> trace;
        unordered_map<string, bool> close;
        vector<pair<string, int>> open;
        unordered_map<string, int> weight;
        for (auto dinhKe : dinh)
            weight[dinhKe] = INT_MAX;
        bool found = false;
        int dinhDaDuyet = 0;
        weight[begin] = 0;
        open.push_back({begin, 0});
        auto minCompare = [&](pair<string, int> q1, pair<string, int> q2) {
            auto [node1, weight1] = q1;
            auto [node2, weight2] = q2;
            if (weight1 == weight2)
                return index[node1] > index[node2];
            return weight1 < weight2;
        };
        while (!open.empty()) {
            auto it = min_element(open.begin(), open.end(), minCompare);
            auto [node, w] = *it;
            open.erase(it);
            if (close[node])
                continue;
            close[node] = true;
            dinhDaDuyet ++;
            if (node == end) {
                found = true;
                break;
            }
            for (auto dinhKe : dinh) {
                if (!close[dinhKe] and dsKe[node][dinhKe] != 0) {
                    if (weight[dinhKe] > weight[node] + dsKe[node][dinhKe]) {
                        weight[dinhKe] = weight[node] + dsKe[node][dinhKe];
                        trace[dinhKe] = node;
                        open.push_back({dinhKe, weight[dinhKe]});
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
            cout << "\n" << dinhDaDuyet << " " << length << "\n";
        } else {
            cout <<"-unreachable-\n" << dinhDaDuyet << " " << 0 << "\n";
        }


    }
};



int main() {
    Graph g;
    g.Nhap();
    g.duyetGraph();
    return 0;
}
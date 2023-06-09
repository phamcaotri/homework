#include <bits/stdc++.h>

using namespace std;


struct Graph {
    vector<vector<int>> matranKe;
    vector<string> dinh;
    unordered_map<string, int> index;
    int v, n;
    void Nhap() {
        cin >> v >> n;
        matranKe.resize(v, vector<int>(v, 0));
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
                    matranKe[i][j] = x;
                
            }
        }

    }
    void duyetGraph() {

        for (int i = 0; i < n; i++) {
            string begin, end;
            cin >> begin >> end;
            Dijkstra(index[begin], index[end]);
        }
    }

    void Dijkstra(int begin, int end) {
        unordered_map<int, int> trace;
        vector<int> close(v, 0);
        vector<pair<int, int>> open;
        vector<int> weight(v, INT_MAX);
        bool found = false;
        int dinhDaDuyet = 0;
        weight[begin] = 0;
        open.push_back({begin, 0});
        auto minCompare = [&](pair<int, int> q1, pair<int, int> q2) {
            auto [node1, weight1] = q1;
            auto [node2, weight2] = q2;
            if (weight1 == weight2)
                return node1 > node2;
            return weight1 < weight2;
        };
        while (!open.empty()) {
            auto it = min_element(open.begin(), open.end(), minCompare);
            auto [node, w] = *it;
            open.erase(it);
            if (close[node])
                continue;
            close[node] ++;
            dinhDaDuyet ++;
            if (node == end) {
                found = true;
                break;
            }
            for (int dinhKe = 0; dinhKe < v; dinhKe ++) {
                if (!close[dinhKe] and matranKe[node][dinhKe] != 0) {
                    if (weight[dinhKe] > weight[node] + matranKe[node][dinhKe]) {
                        weight[dinhKe] = weight[node] + matranKe[node][dinhKe];
                        trace[dinhKe] = node;
                        open.push_back({dinhKe, weight[dinhKe]});
                    }
                    
                }   
            }
        }
        if (found) {
            int length = 0;
            int node = end;
            vector<string> path;
            while (node != begin) {
                path.push_back(dinh[node]);
                length += matranKe[trace[node]][node];
                node = trace[node];
            } 
            path.push_back(dinh[begin]);
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
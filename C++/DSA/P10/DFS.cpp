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
            DFS(index[begin], index[end]);
        }
    }

    void DFS(int begin, int end) {
        unordered_map<int, int> trace;
        vector<int> close(v, 0);
        stack<int> open;
        bool found = false;
        int dinhDaDuyet = 0;
        open.push(begin);
        while (!open.empty()) {
            int node = open.top();
            open.pop();
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
                    trace[dinhKe] = node;
                    open.push(dinhKe);
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
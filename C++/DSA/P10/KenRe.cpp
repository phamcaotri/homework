#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Graph {
    map<pair<int,int>,int> index;
    vector<pair<int,int>> reindex;
    int ds_dinh = 0;
    int m;
    int n;
    map<pair<int,int>,map<pair<int,int>, bool>> matranKe;
    void input(int m, int n) {
        vector<vector<bool>> matrix(m,vector<bool>(n, 1));
        this->m = m;
        this->n = n;
        int count = 0;
        int dinh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dinh;
                matrix[i][j] = dinh;
                if (!matrix[i][j]) {
                    index[{i,j}] = count ++;
                    reindex.push_back({i,j});
                    ds_dinh ++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (i + x >= 0 and i+x < m and j + y >= 0 and j+y < n and (x != 0 or y != 0) and matrix[i+x][j+y] == 0) {
                            matranKe[{i,j}][{i+x,j+y}] = 1;
                        }
                    }
                }
            }
        }
    }
    void distance(int x1, int y1, int x2, int y2) {
        pair<int,int> begin = {m-x1-1,y1};
        pair<int,int> end = {m-x2-1,y2};
        BFS(index[begin],index[end]);
        // BFS({m-x1-1,y1},{m-x2-1,y2});
    }

    void BFS(int begin, int end) {
        unordered_map<int, int> trace;
        vector<int> close(ds_dinh, 0);
        vector<int> open;
        bool found = false;
        int dinhDaDuyet = 0;
        open.push_back(begin);
        while (!open.empty()) {
            int node = *open.begin();
            open.erase(open.begin());
            if (close[node])
                continue;
            close[node] = 1;
            dinhDaDuyet ++;
            cout << dinhDaDuyet << endl;
            if (node == end) {
                found = true;
                break;
            }
            for (int dinhKe = 0; dinhKe < ds_dinh; dinhKe ++) {
                if (!close[dinhKe] and matranKe[reindex[node]][reindex[dinhKe]] != 0 and find(open.begin(), open.end(), dinhKe) == open.end()) {
                    trace[dinhKe] = node;
                    open.push_back(dinhKe);
                }
            }
        }
        if (found) {
            int length = 0;
            int node = end;
            while (node != begin) {
                length += 1;
                node = trace[node];
            } 
            cout << length;
        } else {
            cout << -1;
        }


    }

};

int main() {
    int m, n, x1, y1, x2, y2;
    cin >> m >> n >> x1 >> y1 >> x2 >> y2;
    Graph g;
    g.input(m, n);
    g.distance(x1,y1,x2,y2);
}
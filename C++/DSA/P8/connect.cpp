#include <bits/stdc++.h>

using namespace std;

struct Graph {
    map<int, map<int, bool>> dsKe;
    int e, v;
    void Nhap() {
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int x, y;
            cin >> x >> y;
            dsKe[x][y];
            dsKe[y][x];
            dsKe[x][x];
            dsKe[y][y];
        }
        int id;
        cin >> id;
        int count = 0;
        NhiemVirus(dsKe, id);
        for (int i = 1; i <= v; i++) {
            if (dsKe[i][i] == 1) {
                count ++;
            }
        }
        cout << count << endl;
        for (int i = 1; i <= v; i++) {
            if (dsKe[i][i] == 1) {
                cout << i << " ";
            }
        }
    }
    void NhiemVirus(map<int, map<int, bool>> &ds, int id) {
        for (auto &i : ds[id]) {
            if (i.second == false) {
                i.second = true;
                return NhiemVirus(ds, i.first);
            }
        }
    }
    bool isNotExist(int x) {
        if (dsKe.find(x) == dsKe.end()) {
            return true;
        }
        return false;
    }
    bool isKe(int x, int y) {
        if (isNotExist(x) or isNotExist(y)) {
            return false;
        }
        if (dsKe[x].find(y) != dsKe[x].end()) {
            return true;
        }
        return false;
    }
};



int main()
{
    Graph G;
    G.Nhap();
    return 0;
}

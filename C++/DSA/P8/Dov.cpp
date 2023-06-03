#include <bits/stdc++.h>

using namespace std;

struct Graph {
    map<string, set<string>> dsKe;
    vector<string> dsDinh;
    int v, e;
    void Nhap() {
        cin >> v >> e;
        for (int i = 0; i < v; i++) {
            string c;
            cin >> c;
            dsDinh.push_back(c);
        }
        for (int i = 0; i < e; i++) {
            string x, y;
            cin >> x >> y;
            dsKe[x].insert(y);
            dsKe[y].insert(x);
        }

    }
    void XuLy() {
        for (auto i : dsDinh) {
            cout << dsKe[i].size() << " ";
        }
    }
};



int main()
{
    Graph G;
    G.Nhap();
    G.XuLy();
    return 0;
}

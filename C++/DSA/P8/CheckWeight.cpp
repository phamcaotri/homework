#include <bits/stdc++.h>

using namespace std;

struct Graph {
    map<string, set<string>> dsKe;
    int e;
    void Nhap() {
        cin >> e;
        for (int i = 0; i < e; i++) {
            string x, y;
            cin >> x >> y;
            dsKe[x].insert(y);
            dsKe[y];
        }

    }
    void XuLy() {
        for (auto i : dsKe) {
            if (i.second.size() != dsKe.size() - 1) {
                cout << "FALSE";
                return;
            } 
        }
        cout << "TRUE";
        return;
    }
    bool isNotExist(string x) {
        if (dsKe.find(x) == dsKe.end()) {
            return true;
        }
        return false;
    }
    bool isKe(string x, string y) {
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
    G.XuLy();
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct Graph {
    map<string, map<string, int>> dsKe;
    int e, n;
    void Nhap() {
        cin >> e >> n;
        for (int i = 0; i < e; i++) {
            string x, y;
            int w;
            cin >> x >> y >> w;
            dsKe[x][y] = w;
            dsKe[y];
        }

        for (int i = 0; i < n; i++) {
            vector<string> ds;
            while(true) {
                string x;
                cin >> x;
                if (x == ".")
                    break;
                ds.push_back(x);
            }
            int sum = 0;
            bool isCycle = true;
            for (int j = 0; j < ds.size()-1; j++) {
                if (isKe(ds[j], ds[j+1])) {
                    sum += dsKe[ds[j]][ds[j+1]];
                } else {
                    cout << "FALSE" << endl;
                    isCycle = false;
                    break;
                }
            }
            if (isCycle) {
                cout << sum << endl;
            }

        }

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
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct Graph {
    unordered_map<string, set<string>> dsKe;
    int e, n;
    void Nhap() {
        cin >> e >> n;
        for (int i = 0; i < e; i++) {
            string x, y;
            cin >> x >> y;
            dsKe[x].insert(y);
            dsKe[y];
        }

    }
    void XuLy() {
        string x, y;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            switch (num) {
                case 1: {
                    
                    cin >> x >> y;
                    if (isKe(x, y)) {
                        cout << "TRUE";
                    } else {
                        cout << "FALSE";
                    }
                    break;
                }
                case 2: {
                    cin >> x;
                    cout << dsKe[x].size();
                    break;   
                }
                default: {
                    break;
                }
            }
            cout << '\n';
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
    G.XuLy();
    return 0;
}

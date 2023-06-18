#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    map<int,set<int>> m;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x) {
                m[i].insert(j);
                m[j].insert(i);
            }
        }
    }
    for (auto it : m) {
        cout << it.first << "->";
        for (auto i : it.second) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
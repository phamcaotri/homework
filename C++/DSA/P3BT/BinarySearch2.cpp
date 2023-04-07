#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        m[x] = 1;
    }
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        if (m.find(x) == m.end()) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n; cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        b[i] = -b[i];
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(v.begin(), v.end(), make_pair(a[i], b[i]));
        v.insert(it, make_pair(a[i], b[i]));
    }
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", v[i].first, -v[i].second);
    }
    return 0;
}
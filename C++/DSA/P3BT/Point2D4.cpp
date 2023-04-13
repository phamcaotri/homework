#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(pair<int,int> *s, int l, int r) {
    int i = l, j = r;
    int x = s[(l+r)/2].first;
    while (i <= j) {
        while (s[i].first < x) i++;
        while (s[j].first > x) j--;
        if (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    if (l < j) quickSort(s, l, j);
    if (i < r) quickSort(s, i, r);
}

int main() {
    int n; cin >> n;
    pair<int,int>* v = new pair<int, int>[n];
    
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[i] = make_pair(x, -y);
    }
    quickSort(v, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << -v[i].second << "\n";
    }
    return 0;
}
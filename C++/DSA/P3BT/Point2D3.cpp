// Cho một tập N điểm (x,y) trên mặt phẳng Oxy. Bạn hãy sắp xếp và in ra các điểm tăng dần theo x, nếu x bằng nhau thì sắp xếp các điểm giảm dần theo y.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void quickSort(vector<pair<int, int>> &s, int l, int r) {
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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int>> s;
    string buffer = "";
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        s.push_back(make_pair(x, -y));
    }
    //quickSort(s, 0, s.size()-1);
    for (const auto& i : s ) {
        buffer += to_string(i.first) + " " + to_string(-i.second) + "\n";
    }
    cout << buffer;
    return 0;
}
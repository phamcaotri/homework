#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> hs, hs2(n);
    vector<int> in;
    // bước 1: nhập những lần xếp hàng
    for (int i = 0; i < n; i++) {
        hs2[i] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        in.push_back(x);
    }
    // bước 2: xếp hàng từ cuối lên đầu
    while (!in.empty()) {
        if (hs2[in.back() - 1] != 0) {
            hs.push_back(in.back());
            hs2[in.back() - 1] = 0;
        }
        in.pop_back();
    }
    // bước 3: những ai chưa xếp hàng thì cho vào cuối hàng theo thứ tự tăng dần
    for (int i = 0; i < n; i++) {
        if (hs2[i] != 0) {
            hs.push_back(hs2[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << hs[i] << " ";
    }
    return 0;

};
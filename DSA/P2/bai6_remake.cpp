// include một số thư viện quan trọng
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// tìm kiếm nhị phân trong vector v
int findv(vector<int> v, int b) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == b) return mid;
        if (v[mid] < b) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    // khai báo vector v
    vector<int> v;
    // nhập vào cặp số a, b. nếu a = 1 thì thêm b vào vector v, nếu a = 2 thì tìm vị trí của b trong vector v (đã được sắp xếp)
    // nếu a = 0 thì không nhập b và dừng vòng lặp
    // nếu không tìm thấy b trong vector v, xuất ra 0
    // nếu tìm thấy b trong vector v, xuất ra vị trí của b trong vector v

    int a, b;
    do {
        cin >> a;
        if (a == 0) break;
        cin >> b;
        if (a == 1) {
            // nếu b đã có trong vector v thì xoá b đi
            if (findv(v, b) != -1) v.erase(v.begin() + findv(v, b));
            else {
                v.push_back(b);
                sort(v.begin(), v.end());
            }

        }
        else {
            // tìm vị trí của b trong vector v.
            cout << findv(v, b) + 1 << endl; }
    } while(true);

    return 0;
}
// nhận xét bộ nhớ tối đa chương trình sử dụng nếu không có quá 10 triệu cặp số a, b được nhập là: 80MB
// nhận xét thời gian tối đa chạy chương trình nếu không có quá 10 triệu cặp số a, b được nhập là: 0.1s
// nhận xét độ phức tạp của thuật toán tìm kiếm nhị phân trong vector v là: O(log n)
// nhận xét độ phức tạp của thuật toán sắp xếp vector v là: O(n log n)
// nhận xét độ phức tạp của chương trình là: O(n log n)

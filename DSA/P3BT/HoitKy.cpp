#include <iostream>
#include <vector>
using namespace std;

// hàm kiểm tra xem có tồn tại cách chia k chương
// để tổng số trang các chương không quá số trang tối đa
bool check(vector<int> a, int k, int limit) {
    int so_chuong = 1;
    int tong_trang = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > limit) {
            return false;
        }
        if (tong_trang + a[i] > limit) {
            so_chuong++;
            tong_trang = a[i];
        } else {
            tong_trang += a[i];
        }
    }
    return so_chuong <= k;
}


// hàm tính tổng số trang
int Sum(vector<int> a) {
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
    }
    return sum;
}

// hàm tìm kiếm để tìm số trang tối đa
int search(vector<int> a, int sum, int k) {
    for(int i = 1; i <= sum; i++) {
        if (check(a, k, i)) {
            return i;
        }
    }
    return 0;
}

int main() {
    int n, k; // n là số tập, k là số chương
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = Sum(a);
    cout << search(a, sum, k);
    

    return 0;
}
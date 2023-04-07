#include <iostream>
#include <vector>
using namespace std;

bool canDivide(vector<long>& trang, long k, long limit) {
    long num_chuong = 1;
    long chuong_sum = 0;
    for (long i = 0; i < trang.size(); i++) {
        if (trang[i] > limit) {
            return false;
        }
        if (chuong_sum + trang[i] > limit) {
            num_chuong++;
            chuong_sum = 0;
        }
        chuong_sum += trang[i];
    }
    return num_chuong <= k;
}

long findMaxtrang(vector<long>& trang, long k, long left, long right) {

    while (left <= right) {
        long mid = (left + right) / 2;
        if (canDivide(trang, k, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    long total = 0;
    long max_trang = 0;
    long n, k;
    cin >> n >> k;
    vector<long> trang(n);
    for (long i = 0; i < n; i++) {
        cin >> trang[i];
        total += trang[i];
        max_trang = max(max_trang, trang[i]);
    }
    cout << findMaxtrang(trang, k, max_trang, total);
    return 0;
}
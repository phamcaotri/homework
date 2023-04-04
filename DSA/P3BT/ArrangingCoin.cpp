// chương trình thực hiện công việc sau:
/*
1. tạo 1 mảng tổng tích luỹ từ 0 đến dưới 10^12, ví dụ 0 1 3 6 10 ....
2. nhập vào một số nguyên dương n (0 <= n <= 10^12)
3. tìm vị trí của n trong mảng tổng tích luỹ, ví dụ n = 10, vị trí của n trong mảng là 4
4. nếu không tìm thấy n trong mảng tổng tích luỹ thì in ra vị trí trước nó, ví dụ n = 9, vị trí của n trong mảng là 3

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(1000000);
    a[0] = 0;
    for (int i = 1; i < 1000000; i++) {
        a[i] = a[i-1] + i;
    }
    int i = 0;
    int left = 0, right = 1000000;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == n) {
            cout << mid;
            return 0;
        }
        else if (a[mid] < n) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << right;
    return 0;
}
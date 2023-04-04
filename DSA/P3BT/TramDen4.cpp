/*
Chương trình này thực hiện công việc sau:
1. Nhập vào số lượng test t ( 1 <= t <= 20)
2. Nhập vào số k ( 1 <= k <= 10^12)
3. ta có công thức liên hệ như sau: 2*k = m*n + (m+1)*(n+1), 1 <= m <= n, m, n là số tự nhiên.
4. cố định n = sqrt(k), dùng binary search để tìm m trong đoạn từ 1 đến n-1 sao cho 2*k = (m*n + (m+1)*(n+1))
    - nếu tìm được m thì tiếp tục quay lại bước 4, tìm m trong đoạn từ m+1 đến n-1, cho đến khi không tìm được m nào thì trả về m trước đó đã tìm được. nếu vậy, kết thúc tìm kiếm và trả về m n.
    - nếu không tìm được m thì giảm n xuống 1 đơn vị và quay lại bước 4.
5. nếu n = 1 thì trả về -1 -1;
7. lặp lại bước 2 cho đến khi hết test.

chương trình sẽ có hàm binary search để tìm m, nếu tìm thấy m thì trả về m, nếu không tìm thấy m thì trả về -1.
hàm grid để tìm m, n, nếu tìm thấy m n thoả yêu cầu thì trả về m n, nếu không tìm thấy thì trả về -1 -1.
*/


#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(long long k, long long n, long long left, long long right) {
    long long m = 1;
    while (left <= right) {
        m = (left + right) / 2;
        if (2*k == m*n + (m+1)*(n+1)) {
            return m;
        }
        else if (2*k < m*n+(m+1)*(n+1)) {
            right = m - 1;

        }
        else {
            left = m + 1;

        }
    }
    return -1;
}

void grid(long long k);

int main() {
    // nhập vào số lượng test t
    int t;
    cin >> t;
    // nhập vào các số k
    long long k;
    for (int i = 0; i < t; i++) {
        cin >> k;
        if (k <= 4) {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        if (k == 5) {
            cout << 1 << " " << 1 << endl;
            continue;
        }
        grid(k);
    }
}


void grid(long long k) {
    // cố định n = sqrt(k), dùng binary search để tìm m trong đoạn từ 1 đến n-1 sao cho 2*k = (m*n + (m+1)*(n+1))
    long long n = sqrt(k), m = sqrt(k)-1 ,i = 1;
    bool found = false;
    // nếu tìm được m thì tiếp tục quay lại bước 4, tìm m trong đoạn từ m+1 đến n-1, cho đến khi không tìm được m nào thì trả về m trước đó đã tìm được. nếu vậy, kết thúc tìm kiếm và trả về m n.
    while (not found) {
        m = binarySearch(k, n, 1, n-1);
        while (m != -1) {
            long long next_m = binarySearch(k, n, m+1, n-1);
            if (next_m == -1) {
                found = true;
                break;
            }
            else {
                m = next_m;
            }
        }
        // nếu không tìm được m thì giảm n xuống 1 đơn vị và quay lại bước 4.
        if (not found) {
            if (m*n + (m+1)*(n+1) < 2*k) {
                n  ++;
            } else {
                n --;
            }
        }


    }
    // nếu n = 1 thì trả về -1 -1;
    if (n == 1) {
        cout << -1 << " " << -1 << endl;
    }
    // nếu tìm được m thì trả về m n
    else {
        cout << m << " " << n << endl;
    }
}

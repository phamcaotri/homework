/*
Chương trình này thực hiện công việc sau:
1. Nhập vào số lượng test t ( 1 <= t <= 20)
2. Nhập vào số k ( 1 <= k <= 10^12)
3. ta có công thức liên hệ như sau: k = (m*n + (m+1)*(n+1))/2, 1 <= m <= n, m, n là số tự nhiên.
4. đầu tiên, ta cho m = sqrt(k) - 1, n = sqrt(k). sau đó lần lượt tăng m++ và n++ cho đến khi (m*n + (m+1)*(n+1))/2 >= k.
5. nếu (m*n + (m+1)*(n+1))/2 == k thì in ra m n theo cú pháp cout << m << ' ' << n << '\n';
6. nếu (m*n + (m+1)*(n+1))/2 > k thì:
    - lần lượt m--, n++ cho đến khi (m*n + (m+1)*(n+1))/2 <= k.
    - nếu (m*n + (m+1)*(n+1))/2 == k thì in ra m n theo cú pháp cout << m << ' ' << n << '\n';
    - nếu (m*n + (m+1)*(n+1))/2 < k thì lần lượt n+= 2 cho đến khi (m*n + (m+1)*(n+1))/2 >= k.
    - nếu (m*n + (m+1)*(n+1))/2 == k thì in ra m n theo cú pháp cout << m << ' ' << n << '\n';
    lặp lại bước 6 cho đến m = 1 và n = một số nào đó để (m*n + (m+1)*(n+1))/2 > k
7. lặp lại bước 2 cho đến khi hết test.
*/

#include <iostream>
#include <math.h>

using namespace std;


void grid(long long k) {
    if (k < 5) {
        cout << "-1 -1" << '\n';
        return;
    }
    if (k == 5) {
        cout << "1 1" << '\n';
        return;
    }
    long long m = sqrt(k) - 1, n = sqrt(k);
    while (m*n + (m+1)*(n+1) < 2*k) {
        m++;
        n++;
    }
    if (m*n + (m+1)*(n+1) == 2*k) {
        cout << m << ' ' << n << '\n';
        return;
    }

    while (m > 1 or m*n + (m+1)*(n+1) <= 2*k) {
        while (m*n + (m+1)*(n+1) > 2*k and m > 1) {
            m--;
            n++;
                        //cout << m << ' ' << n << '\n';

        }
        if (m*n + (m+1)*(n+1) == 2*k) {
            cout << m << ' ' << n << '\n';
            return;
        }
        n =(2*k-m-1)/(2*m+1);
        while (m*n + (m+1)*(n+1) < 2*k) {
            n +=2;
                        //cout << m << ' ' << n << '\n';
        }
        if (m*n + (m+1)*(n+1) == 2*k) {
            cout << m << ' ' << n << '\n';
            return;
        }

    }


    cout << "-1 -1" << '\n';


}

int main() {
    int t; cin >> t;
    long long k;
    for (long long i = 0; i < t; i++) {
        cin >> k;
        grid(k);
    }
    return 0;
}

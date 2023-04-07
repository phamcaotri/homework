#include <iostream>
#include <math.h>

#include <vector>
using namespace std;



void grid(double k) {
    double m = 1, n = 1;
    long long a = 1;
    while(a < 2.0*k/3) { 
        // binary search từ 1 đến sqrt(k)
        long long left = 1, right = sqrt(k);
        while (left <= right) {
            long long mid = (left + right) / 2;
            m = (2.0*k-1-mid)/(2.0*mid+1);
            if (m-mid==a) {
                cout << mid << ' ' << m << '\n';
                return;
            }
            if (m-mid > a) left = mid + 1;
            else right = mid - 1;
        }
        // for ( long long i = sqrt(k); i >= 1; i--) {
        //     m = (2.0*k-1-i)/(2.0*i+1);
        //     if (m-i == a) {
        //         cout << i << " " << m << '\n';
        //         return;
        //     }
        // }
        a++;
    }
    cout << "-1 -1" << '\n';

}

int main() {
    long t; cin >> t;
    double k;
    for (long i = 0; i < t; i++) {
        cin >> k;
        grid(k);
    }
    return 0;
}
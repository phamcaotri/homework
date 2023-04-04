#include <iostream>
#include <vector>
using namespace std;

// void grid(double k) {
//     double m = 1, n = 1;
//     while(true) {
//         m = (2.0*k-1-n)/(2*n+1);
//         if (m < 1) {
//             cout << "-1 -1" << endl;
//             break;
//         }
//         if (m == (long)m and n >= m) {
//             cout << m << " " << n << endl;
//             break;
//         }
//         n++;
//     }

// }

int finds(long long k, long long n) {
    long long left = 1, right = (2.0*k)/3;
    while (left <= right) {
        long long mid = (left + right) / 2;
        double m = (2.0*k-1-n)/(2.0*n+1);
        if (m == (long long) m) {
            cout << min((long long)m, n) << " " << max((long long)m, n) << '\n';
            return 0;
        }
        if (v[mid] < s) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void grid(float k) {
    float m = 1;
    long long n = (2/6)*k;

}

// m, n không bao giờ quá 2/3 của k (< 2/3*k)
// 1 (2) (3) 4 5 | 6 7 8 9
// (1) 2 3 4 5 (6) | 7 8 9 0
// 1 (2) 3 4 (5) 6 7 8 9 | 10 11 12 13 14
// 1 2 3 4 5 6 7 8 9 10 11 12 | 13 14 15 16 17 18 19
// {1} 2 3 4 5 6 7 (8) 9 10 11 12 13 {14} | 15 16 17 18 19 20 21 22

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 (33) 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 (66) 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100
int main() {
    int t; cin >> t;
    
    long long k;
    for (int i = 0; i < t; i++) {
        cin >> k;
        grid(k);
    }
    return 0;
}
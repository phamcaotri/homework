#include <iostream>
using namespace std;

struct bitmap {
    int n;
    int* a;
    bitmap(int n, int init) {
        this->n = n;
        a = new int[n/32 + 1];
    }
    void set(int i) {
        i %= n;
        a[i/32] |= (1 << (i%32));
    }
    int operator[](int i) {
        i %= n;
        return (a[i/32] >> (i%32)) & 1;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m = new int[50000000/32 + 1];
    int a, b;
    while (cin >> a >> b) {
        if (a == 1) {
            m[b/32] |= (1 << (b%32));
        } else {
            cout << ((m[b/32] >> (b%32)) & 1) << '\n';
        }
    }
    return 0;
}

    // void reset(int i) {
    //     a[i/32] &= ~(1 << (i%32));
    // }


// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int m[50000000/32 + 1];
//     int a, b;
//     while (cin >> a >> b) {
//         if (a == 1) {
//             m[b/32] |= (1 << (b%32));
//         } else {
//             cout << ((m[b/32] >> (b%32)) & 1) << '\n';
//         }
//     }
//     return 0;
// }
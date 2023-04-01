#include <iostream>
#include <vector>
using namespace std;

void grid(double k) {
    double m = 1, n = 1;
    while(true) {
        m = (2.0*k-1-n)/(2*n+1);
        if (m < 1) {
            cout << "-1 -1" << endl;
            break;
        }
        if (m == (int)m and n >= m) {
            cout << m << " " << n << endl;
            break;
        }
        n++;
    }

}

int main() {
    int t; cin >> t;
    double k;
    for (int i = 0; i < t; i++) {
        cin >> k;
        grid(k);
    }
    return 0;
}
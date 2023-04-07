
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000;
int main() {
    vector<int> a;
    int n;
    while (cin >> n) {
        if (n == -1) {
            if (a.size() > 0) {
                int max = *max_element(a.begin(), a.end());
                for (int i = 0; i < a.size(); i++) {
                    if (a[i] == max) {
                        a.erase(a.begin() + i);
                        i--;

                    }
                }
            }
        } else if (n == -2) {
            cout << a.size() << '\n';
            sort(a.begin(), a.end(), greater<int>());
            for (int i = 0; i < a.size(); i++) {
                cout << a[i] << "\n";
            }
            break;
        } else {
            if (a.size() < MAX) {
                a.push_back(n);
            }
        }
    }
    return 0;
}
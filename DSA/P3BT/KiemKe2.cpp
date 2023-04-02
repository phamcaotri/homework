#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n; cin >> n;
    string x;
    int count = 0;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (find(v.begin(), v.end(), x) == v.end()) {
            v[i] = x;
            count ++;
        }
        
    }
    cout << count;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    unordered_map<char, char> m;
    set<long long> s;
    long long a, b;

    do {
        cin >> a;
        if (a == 0) break;
        cin >> b;
        if (a == 1) {
            if (m.find(b) == m.end()) {
                s.insert(b);
                m[b] = 1;
            }
        }
        else {
            if (m.find(b) == m.end()) {
                cout << "0" << '\n';
            }
            else {
                cout << distance(s.begin(), s.lower_bound(b)) + 1 << '\n';
            }
        }
            
    } while(true);
    return 0;
}
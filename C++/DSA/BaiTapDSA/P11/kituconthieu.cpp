#include <iostream>
#include <map>

using namespace std;


int main() {
    int n; cin >> n;
    map<char, int> m;
    for (int i = 0; i < n; i++) {
        char s;
        cin >> s;
        s = tolower(s);
        m[s]++;
    }
    int count = 0;
    for (auto i : m) {
        if (i.second != 0 and isalpha(i.first)) {
            count++;
        }
    }
    cout << 26 - count << endl;
}
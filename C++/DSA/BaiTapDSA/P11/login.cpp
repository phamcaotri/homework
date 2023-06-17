#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    map<string, string> m;
    for (int i = 0; i < n; i++) {
        string id, pass;
        cin >> id >> pass;
        m[id] = pass;
    }
    for (int i = 0; i < q; i++) {
        string id;
        cin >> id;
        if (m[id] != "") {
            cout << m[id] << endl;
        }
        else {
            cout << "Chua Dang Ky!"  << endl;
        }
    }
    return 0;
}
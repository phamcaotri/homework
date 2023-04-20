#include <stack>
#include <iostream>

using namespace std;

int main() {
    stack<int> S;
    int n;
    cin >> n;
    while (n > 0) {
        S.push(n%2);
        n/=2;
    }
    while (!S.empty()) {
        cout << S.top();
        S.pop();
    }
    return 0;
}
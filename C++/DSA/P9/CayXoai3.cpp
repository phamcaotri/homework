#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> mangoes(n);
    for (int i = 0; i < n; i++) {
        cin >> mangoes[i];
    }

    vector<int> left_max(n);
    vector<int> right_max(n);

    left_max[0] = mangoes[0];
    right_max[n-1] = mangoes[n-1];

    for (int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i-1], mangoes[i-1]);
    }

    for (int i = n-2; i >= 0; i--) {
        right_max[i] = max(right_max[i+1], mangoes[i+1]);
    }

    set<int> visible_mangoes;

    for (int i = 0; i < n; i++) {
        if (mangoes[i] >= left_max[i] && mangoes[i] > right_max[i]) {
            visible_mangoes.insert(mangoes[i]);
        }
    }

    visible_mangoes.insert(mangoes[0]);
    visible_mangoes.insert(mangoes[n-1]);

    for (int x : visible_mangoes) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
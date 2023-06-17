/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    for (int i = 0; i <= n; i++) {
        if (m[i] == 0) {
            cout << i;
            return 0;
        }
    }
    return 0;
}
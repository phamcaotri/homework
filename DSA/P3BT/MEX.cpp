#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Sort(vector<int> &a, int left, int right) {
    int pivot = (left+right)/2;
    int mid = a[pivot];
    int i = left, j = right;
    while (i <= j) {
        while (a[i] < mid) {
            i ++;
        }

        while (a[j] > mid) {
            j --;  
        }

        if (i <= j) {
            swap(a[i], a[j]);
            i ++; 
            j --;
        }
    }
    if (left < j) Sort(a, left,j);
    if (right > i) Sort(a, i,right);
}

int main() {
    int n; cin >> n;
    int max_value = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > max_value) max_value = v[i];
    }

    Sort(v, 0, n-1);

    for (int i = 0; i < n; i++) {
        if (v[i] != i) {
            cout << i;
            return 0;
        }
    }
    cout << max_value + 1;
    return 0;
}
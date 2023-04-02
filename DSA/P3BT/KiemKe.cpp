#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void quickSort(vector<string> &v, int left, int right) {
    int pivot = (left + right) / 2;
    string mid = v[pivot];
    int i = left, j = right;
    while (i <= j) {
        while (v[i] < mid) i++;
        while (v[j] > mid) j--;
        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(v, left, j);
    if (right > i) quickSort(v, i, right);
}

int binarySearch(vector<string> v, string s) {
    int left = 0, right = v.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == s) return mid;
        if (v[mid] < s) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

int finds(vector<string> v, string s) {
    int left = 0, right = v.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == s) return mid;
        if (v[mid] < s) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    quickSort(v, 0, n - 1);
    for (int i = 0; i < v.size(); i++) {
        while (finds(v,v[i]) != -1 ) {
            v.erase(v.begin() + binarySearch(v, v[i]));
        }
        
    }
    cout << v.size();

    return 0;
}
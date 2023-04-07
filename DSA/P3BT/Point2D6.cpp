#include <iostream>
#include <string>
using namespace std;

void quickSort(int *a, int *b, int l, int r) {
    int i = l, j = r;
    int x = a[(l+r)/2];
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            i++;
            j--;
        }
    }
    if (l < j) quickSort(a, b, l, j);
    if (i < r) quickSort(a, b, i, r);
}

int main() {
    cin.tie (NULL);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    string buffer;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        b[i] = -b[i];
    }
    quickSort(a, b, 0, n-1);
    for (int i = 0; i < n; i++) {
        buffer += to_string(a[i]) + " " + to_string(-b[i]) + "\n";
    }
    cout << buffer;
    return 0;
}
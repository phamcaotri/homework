#include <iostream>
using namespace std;

void input(int a[], int n) {
    for (int i = 0; i< n; i++) {
        cin >> a[i];
    }
}

void output(int a[], int n) {
    for (int i = 0; i<n ; i++) {
        cout << a[i];
    }
}

int LinearSort(int a[], int n, int x) {
    for (int i = n-1; i >= 0; i--) {
        if (x == a[i])
            return i;
    }
    return -1;
}
int main() {
    int n, x;
    cin >> n;
    int *a = new int[n];
    input(a,n);
    do {
        cin >> x;
        if (x != -1) {
            cout << LinearSort(a,n,x) << '\n';
        }

    } while(x != -1);

    return 0;
}
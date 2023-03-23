
#include <iostream>

using namespace std;

void qSort(int *a, int left, int right) {
    int mid = a[(left+right)/2];
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
    if (left < j) qSort(a, left,j);
    if (right > i) qSort(a, i,right);
}

int main() {
    int n; cin >> n;
    int a[n];
    int b[n];
    int c[n];

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int j = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) % 2 == 0) {
            b[j] = a[i];
            j++;
        }

    }
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) % 2 == 1) {
            c[k] = a[i];
            k++;
        }

    }
    qSort(b,0,j-1);
    qSort(c,0,k-1);


    for (int i = 0; i < j; i++) {
        cout << b[i] << '\n';
    }
    for (int i = 0; i < k ; i++) {
        cout << c[i] << '\n';
    }


    return 0;
}
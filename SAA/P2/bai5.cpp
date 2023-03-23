
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


void sort(int *a, int n) {
    int *b = new int[n];
    int *c = new int[n];
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
    int m = k;
    j = 0; k = 0;
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) % 2 == 1) {
            a[i] = c[m-k-1];
            k++;
        }


        else {
            a[i] = b[j];
            j++;
        }
    }

    delete[] b;
    
}

int main(){
    int *a, n; cin >> n;
    a = new int [n];


    
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, n);
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}

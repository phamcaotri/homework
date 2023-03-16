#include <iostream>
using namespace std;

void input(int a[], int n) {
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void output(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}

void QuickSort(int a[], int left, int right) {
    int mid = a[(left+right)/2];
    int i = left, j = right;

    while (i < j) {
        while (a[i] < mid) {
            i ++;
        }

        while (a[j] > mid) {
            j --;  
        }

        if (i <= j) {
            swap(a[i], a[j]);
              
            i ++; j --;
        }
        
    }
    
    if (left < j) QuickSort(a,left,j);
    if (right > i) QuickSort(a,i,right);
}

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    input(a,n);
    QuickSort(a,0,n-1);
    output(a,n);
    return 0;
}

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

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
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            b[j] = a[i];
            j++;
        }

    }
    qSort(b,0,j-1);
    j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1)
            continue;
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

    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}

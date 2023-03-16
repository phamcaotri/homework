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

void SimpleSort(int a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0 ; j < n; j++)
            if (a[i] < a[j])
                swap(a[i],a[j]);
}

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    input(a,n);
    SimpleSort(a,n);
    output(a,n);
    return 0;
}

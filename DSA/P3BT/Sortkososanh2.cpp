#include <iostream>
using namespace std;


void my_sort(int* A, int n) {
    int max_val = A[0];
    int i = 0;
    while (i != n) {
        max_val = max(max_val, A[i++]);
    }

    int exp = 1;
    int* output = new int[n];

    i = 0;
    while (!(max_val / exp == 0)) {
        int count[10] = {0};
        int j = 0;
        while (j != n) {
            count[(A[j] / exp) % 10]++;
            j++;
        }

        j = 1;
        while (!(j == 10)) {
            count[j] += count[j-1];
            j++;
        }

        j = n-1;
        while ( j != -1) {
            output[--count[(A[j] / exp) % 10]] = A[j];
            j--;
        }

        j = 0;
        while (j != n) {
            A[j] = output[j];
            j++;
        }

        exp *= 10;
    }

    delete[] output;
}

int main(){
    int n;
    cin >> n;

    int *A = new int[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    my_sort (A, n);

    for(int i = 0; i < n; i++){
        cout << A[i] << " " ;
    }
}
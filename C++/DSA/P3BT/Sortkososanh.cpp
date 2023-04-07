
#include <iostream>
using namespace std;


int Max(int *A, int n){
    int max_value = A[0];

    int i = 0;
    while (not (i == n)) {
        max_value = max(A[i], max_value);
        i++;
    }
    return max_value;
}


void my_sort(int *a, int n){
    if (n == 0) return;
    int max_value = Max(a, n);
    int i = 0;
    int *B = new int[max_value+1];
    
    while (not ( i == max_value+1)) {
        B[i] = 0;
        i++;
    }
    i = 0;
    while (not ( i == n)) {
        B[a[i]] ++;
        i++;
    }
    int j = 0;
    i = 0;
    while ( not ( i == max_value+1)) {
        while (not ( B[i] == 0)) {
            a[j] = i;
            B[i] --;
            j++;
        }
        i++;
    }
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

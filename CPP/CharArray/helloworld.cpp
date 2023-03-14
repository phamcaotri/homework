#include <bits/stdc++.h>
using namespace std;
#define MAX 100

void NhapMaTran(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
}


void max_array(int a[], int n)
{
    int max_number = 0, counter = 0;
    for (int i = 0; i < n; i++)
        if (max_number < a[i])
            max_number = a[i];
    cout << max_number << "\n";
    for (int i = 0; i < n; i++)
        if (max_number == a[i])
            counter ++;
    cout << counter;

}


int main() {
    int a[MAX], n = 0;
    NhapMaTran(a, n);

    max_array(a, n);
    return 0;
}
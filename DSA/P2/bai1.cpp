#include <iostream>
#include <vector>
using namespace std;
void Sort(vector<int> &a,int n ,int left, int right, int &c) {
    int mid = a[(left+right)/2];
    int i = left, j = right;
    while (i <= j) {
        while (a[i] > mid) {
            i ++;
        }

        while (a[j] < mid) {
            j --;  
        }

        if (i <= j) {
            swap(a[i], a[j]);
            c++;
            i ++; 
            j --;
        }
    }
    if (left < j) Sort(a,n , left,j, c);
    if (right > i) Sort(a, n, i,right, c);
}

int main() {
    int n; cin >> n;
    int c = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Sort(a,n,0,n-1, c);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n' << "Number of times to swap 2 numbers: " << c;


    return 0;
}
#include <iostream>
#include <vector>
#define MAX 10000
using namespace std;
void Sort(vector<int> &a ,int left, int right) {
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
    if (left < j) Sort(a, left,j);
    if (right > i) Sort(a, i,right);
}

int binarySearch(vector<int> a,int start, int end, int x) {
    if (end < start)
        return 0;
    int mid = (end+start)/2;

    if (x == a[mid])
        return mid+1;
    else {
        if (x > a[mid])
            return binarySearch(a, mid+1,end,x);
        else
            return binarySearch(a,start,mid-1,x);
    }
}

int main() {
    vector<int> a(MAX), b(MAX), c(MAX);
    int n = 0, x = 0;
    do {
    cin >> a[n];
    if (a[n] == 0) break;
    cin >> b[n];
    n++;
    } while(true);

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            c[x] = b[i];
            Sort(c,0,x);
            x++;
        }
        else {
            cout << binarySearch(c,0,x,b[i]) << '\n';
        }
    }
    



    return 0;
}
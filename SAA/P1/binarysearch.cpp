#include <iostream>
using namespace std;

void input(int a[], int n) {
    for (int i = 0; i< n; i++) {
        cin >> a[i];
    }
}

void output(int a[], int n) {
    for (int i = 0; i<n ; i++) {
        cout << a[i];
    }
}

int BinarySearch(int a[], int x, int start, int end) {
    //tìm điểm nằm giữa
    if (end < start)
        return -1;
    int mid  =  (end+start)/2;

    if (x == a[mid])
        return mid;
    else {
        if (x > a[mid])
            return BinarySearch(a,x,mid+1,end);
        else
            return BinarySearch(a,x,start,mid-1);
    }
}
int main() {
    int n, m;
    cin >> n;
    int a[100], x[100];
    input(a,n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cout << BinarySearch(a,x[i],0,n-1) << '\n';
    }

    

    return 0;
}
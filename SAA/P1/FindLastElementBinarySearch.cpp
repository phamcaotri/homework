
#include <iostream>
using namespace std;





void inputArray(int *&a, int &n) {
    cin >> n;
    int *b = new int[n];
    a = b;
    for (int i = 0; i< n; i++) {
        cin >> a[i];
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
    
    // 
}
int binarySearch2(int a[], int n, int x) {
    int l = 0, r = n-1;
    int last = -1;
    do {
        if (BinarySearch(a,x,l,r) != -1)
        {
            last = BinarySearch(a,x,l,r);
            l = last+1;
        }
        else break;

    } while (true);
    return last;
    
    
}


int main()
{
    int n, *a = NULL;
    inputArray(a,n); //Luu y van de tham chieu cho con tro a va n

    // nhap cac gia tri can tim, neu nhap -1 thi ket thuc viec tim kiem
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1)break;
        cout<<binarySearch2(a,n,x)<<endl;

    }

    return 0;
}


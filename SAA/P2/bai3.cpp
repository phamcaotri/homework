#include <iostream>
using namespace std;

void inputArray(int *a, int &n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void merge(int *a, int start, int pivot, int end) {
    int *b = new int[end-start+1];
    int i = start, j = pivot +1, k = 0;
    while (i <= pivot and j <= end) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            k++;
            i++;
        }
        else {
            b[k] = a[j];
            k++;
            j++;

        }
    }
    for (i;i <= pivot; i++) {
        b[k] = a[i];
        k++;
    }
    for (j;j <= end; j++) {
        b[k] = a[j];
        k++;
    }

    k = 0;
    for (i = start; i <= end; i++) {
        a[i] = b[k];
        k++;
    }
    delete[] b;
}

void MergeSort(int *a, int start, int end) {
    int pivot = (start + end)/2;
    if (start < pivot) MergeSort(a, start,pivot);
    if (end > pivot +1 ) MergeSort(a, pivot+1,end);
    merge(a, start,pivot,end);
}


void outputArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}

int binarySearch(int *a, int n,int start, int end, int x) {
    if (end < start)
        return -1;
    int mid = (end+start)/2;

    if (x == a[mid])
        return mid;
    else {
        if (x > a[mid])
            return binarySearch(a, n, mid+1,end,x);
        else
            return binarySearch(a,n,start,mid-1,x);
    }
}


int main()
{
    int n; cin>>n;
    int *a = new int[n];
    inputArray(a,n);
    MergeSort(a,0,n-1);
    cout<<"Sorted Array: ";
    outputArray(a,n);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = binarySearch(a,n,0,n-1,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}


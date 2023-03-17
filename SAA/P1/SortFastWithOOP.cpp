#include <iostream>
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\Sort.h"

using namespace std;


int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    BubbleSort BubbleSort;
    BubbleSort.input(a,n);
    BubbleSort.setDelayTime(10);
    BubbleSort.SortAndDraw(a,n);

    /*
    QuickSort QuickSort;
    QuickSort.input(a,n);
    QuickSort.setDelayTime(10);
    QuickSort.SortAndDraw(a,n,0,n-1);
    */
    SimpleSort SimpleSort;
    SimpleSort.input(a,n);
    SimpleSort.setDelayTime(10);
    SimpleSort.SortAndDraw(a,n);
    return 0;
}


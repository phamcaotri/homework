#include <iostream>
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\Sort.h"

using namespace std;


int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    /*
    SimpleSort SimpleSort;
    SimpleSort.input(a,n);
    SimpleSort.setDelayTime(0);
    SimpleSort.SortAndDraw(a,n);

    BubbleSort BubbleSort;
    BubbleSort.input(a,n);
    BubbleSort.setDelayTime(0);
    BubbleSort.SortAndDraw(a,n);
    */
    QuickSort QuickSort1, QuickSort2;
    QuickSort1.input(a,n);
    QuickSort1.setDelayTime(10);
    QuickSort1.SortAndDraw2(a,n,0,n-1);
    QuickSort2.input(a,n);
    QuickSort2.setDelayTime(10);
    QuickSort2.SortAndDraw(a,n,0,n-1);


    MergeSort MergeSort;
    MergeSort.input(a,n);
    MergeSort.setDelayTime(50);
    MergeSort.SortAndDraw(a,n,0,n-1);

    return 0;
}


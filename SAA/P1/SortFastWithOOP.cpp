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
    QuickSort QuickSort;
    QuickSort.input(a,n);
    QuickSort.setDelayTime(100);
    QuickSort.SortAndDraw(a,n,0,n-1);


    return 0;
}


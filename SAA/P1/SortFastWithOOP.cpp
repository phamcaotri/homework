#include <iostream>
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\ArrayFunction.h"
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\QuickSort.h"
using namespace std;


int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    
    QuickSort QuickSort;
    QuickSort.input(a,n);
    QuickSort.setDelayTime(10);
    QuickSort.SortAndDraw(a,n,0,n-1);
    return 0;
}


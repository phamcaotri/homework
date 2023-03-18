#include <iostream>
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\Sort.h"

using namespace std;


int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    
    QuickSort qs1(a,n,10);
    qs1.createRamdomizeArray();
    qs1.SortAndDraw(0,n-1);

    return 0;
}


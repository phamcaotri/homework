#include <iostream>
#include <vector>
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\SortIndex.h"
using namespace std;


int main() {
    int n;
    cin >> n;
    // vector<int> a(n);
    
    QuickSort s1(n,10);
    s1.createShuffledArray();
    s1.SortAndDraw_RandomPivot(0,n-1);
    // MergeSort s2(a,n,10);
    // s2.createShuffledArray();
    // s2.SortAndDraw(0,n-1);

    return 0;
}


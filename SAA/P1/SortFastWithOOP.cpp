#include <iostream>
#include <vector>
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\SortIndex.h"
using namespace std;

int main() {
    int n = 50;

    //s1.SortAndDraw_RandomPivot(0,n-1);
    //for (int i = 10; i = 1000000000; i *= 10) {
        ShakeSort s1(n,500);
        s1.createShuffledArray();
        //auto start = high_resolution_clock::now();
        s1.SortAndDraw4();
        //auto stop = high_resolution_clock::now();
        //auto duration = duration_cast<nanoseconds>(stop - start);
        //cout << i << ", runtime: " << duration.count() << " ns" << '\n';
    //}
        // QuickSort s2(n,0);
        // s2.createShuffledArray();
        // s2.SortAndDraw(0,n-1);

    
    // MergeSort s2(a,n,10);
    // s2.createShuffledArray();
    // s2.SortAndDraw(0,n-1);

    return 0;
}

    
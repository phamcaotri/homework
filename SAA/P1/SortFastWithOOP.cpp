#include <iostream>
#include <vector>
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\SortIndex.h"
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\TimeMeasure.h"
using namespace std;

int main() {



    int n = 1000000000;
    if (0) {
        BubbleSort s1(n,1);
        s1.createTestArray();
        s1.measureTime();
        cout << s1.isSorted() << '\n';
    }
    if (0) {
        InterchangeSort s2(n,1);
        s2.createTestArray();
        s2.measureTime();
        cout << s2.isSorted() << '\n';
    }
    if (0) {
        SelectionSort s3(n,1);
        s3.createTestArray();
        s3.measureTime();
        cout << s3.isSorted() << '\n';
    }
    if (0) {
        QuickSort s4(n,1);
        s4.createTestArray();
        s4.measureTime(0,n-1);
        cout << s4.isSorted() << '\n';
    }
    if (0) {
        InsertionSort s5(n,10);
        s5.createTestArray();
        //s5.SortAndDraw();
        s5.measureTime();
        cout << s5.isSorted() << '\n';
    }
    if (0) {
        HeapSort s6(n,1);
        s6.createTestArray();
        //6.SortAndDraw();
        s6.measureTime();
        cout << s6.isSorted() << '\n';
    }
    if (0) {
        MergeSort s7(n,1);
        s7.createTestArray();
        s7.measureTime(0,n-1);
        cout << s7.isSorted() << '\n';
    }
    if (0) {
        ShakeSort s8(n,1);
        s8.createTestArray();
        s8.measureTime();
        cout << s8.isSorted() << '\n';
    }
    if (0) {
        SimpleSort s9(n,1);
        s9.createTestArray();
        s9.measureTime();
        cout << s9.isSorted() << '\n';
    }
    if (0) {
        QuickSortRP s10(n,1);
        s10.createTestArray();
        s10.measureTime(0,n-1);
        cout << s10.isSorted() << '\n';
    }
    if (0) {
        HeapSort_old s11(n,1);
        s11.createTestArray();
        s11.measureTime();
        cout << s11.isSorted() << '\n';
    }
    if (1) {
        CountSort s11(n,100);
        s11.createTestArray();
        //s11.SortAndDraw();
        s11.measureTime();
        cout << s11.isSorted() << '\n';
    }
    if (0) {
        InsertionSort2 s11(n,10);
        s11.createTestArray();
        //s11.SortAndDraw();
        s11.measureTime();
        cout << s11.isSorted() << '\n';
    }
    if (0) {
        InsertionSort3 s11(n,50);
        s11.createTestArray();
        //s11.SortAndDraw();
        s11.measureTime();
        cout << s11.isSorted() << '\n';
    }
    // if (1) {
    //     Sort s(&Sort::Bubble, n);
    //     s.measureTime();
    // }

    return 0;
}

    
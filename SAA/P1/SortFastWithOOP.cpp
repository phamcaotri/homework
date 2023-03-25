#include <iostream>
#include <vector>
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\SortIndex.h"
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\TimeMeasure.h"
using namespace std;

int main() {
    int n = 51944;
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
    if (1) {
        QuickSort s4(n,1);
        s4.createMoutainArray();
        s4.measureTime(0,n-1);
        cout << s4.isSorted() << '\n';
    }
    if (0) {
        InsertionSort s5(n,1);
        s5.createTestArray();
        s5.measureTime();
        cout << s5.isSorted() << '\n';
    }
    if (0) {
        HeapSort s6(n,1);
        s6.createTestArray();
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
    if (1) {
        QuickSortRP s10(n,1);
        s10.createMoutainArray();
        s10.measureTime(0,n-1);
        cout << s10.isSorted() << '\n';
    }
    // if (1) {
    //     Sort s(&Sort::Bubble, n);
    //     s.measureTime();
    // }

    return 0;
}

    
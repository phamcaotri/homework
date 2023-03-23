#include <iostream>
#include <vector>
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\SortIndex.h"
using namespace std;

int main() {
    int n = 50;
    if (0) {
        BubbleSort s1(n,1);
        s1.createShuffledArray();
        s1.SortAndDraw();
    }
    if (0) {
        InterchangeSort s2(n,1);
        s2.createShuffledArray();
        s2.SortAndDraw();
    }
    if (1) {
        SelectionSort s3(n,1);
        s3.createShuffledArray();
        s3.SortAndDraw();
    }

    return 0;
}

    
#include <iostream>
#include <vector>
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\SortIndex.h"
using namespace std;

int main() {
    int n = 50;

    InterchangeSort s1(n,10);
    s1.createShuffledArray();
    s1.SortAndDraw();
    s1.getArray();
    return 0;
}

    
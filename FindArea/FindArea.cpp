#include <iostream>
#include <math.h>
#include "Triangle.h"
using namespace std;


int main() {
    
    float w, h, l;
    cin >> w >> h >> l;
    Triangle A(w,h,l);
    cout << A.Area() <<'\n';
    return 0;
}
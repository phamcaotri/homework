#include <iostream>
using namespace std;

void t(int a = 0, int b = 0, int c = 0) {
    cout << a << ' ' << b << ' ' << c << endl;
}

int main() {
    t(1, 2, 3);
    t(, , 2);
    t(1);
    t();
    return 0;
}
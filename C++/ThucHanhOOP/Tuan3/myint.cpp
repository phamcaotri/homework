/*
định nghĩa kiểu dữ liệu int mới: MYINT
có phép cộng hoạt động như phép trừ và ngược lại
định nghĩa toán tử <<, *

*/

#include <iostream>
using namespace std;

class MYINT {
    private:
        int value;
    public:
        MYINT(int x) {
            value = x;
        }
        MYINT operator+(MYINT x) {
            return MYINT(value - x.value);
        }
        MYINT operator-(MYINT x) {
            return MYINT(value + x.value);
        }
        MYINT operator*(MYINT x) {
            return MYINT(value * x.value);
        }
        friend ostream& operator<<(ostream& os, MYINT x);

};

ostream& operator<<(ostream& os, MYINT x) {
    os << x.value << endl;
    return os;
}

int main() {
    MYINT a(4), b(5);
    cout << (a + b)*a;
    cout << a * b;
    system("pause");
    return 0;
}
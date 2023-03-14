#include <iostream>
using namespace std;

int gcd(int A, int B) {
    if (A == 0 and B == 0)
        return 1;
    if (A == 0)
        return B;
    if (B == 0)
        return A;
    return gcd(B, A%B);
}

struct PhanSo {
    int tu_so;
    int mau_so;

    bool DivideToZero() {
        if (mau_so == 0)
            return false;
        return true;
    }
};

PhanSo ChuanHoa(PhanSo A) {
    if(A.mau_so == 0)
        return A;
    if (A.tu_so/A.mau_so < 0) 
        return {-abs(A.tu_so),abs(A.mau_so)};
    if (A.tu_so < 0 and A.mau_so < 0)
        return {-A.tu_so,-A.mau_so};
    return A;
}

PhanSo Tong(PhanSo A, PhanSo B) {
    PhanSo C = {A.tu_so*B.mau_so+B.tu_so*A.mau_so, A.mau_so*B.mau_so};
    return ChuanHoa({C.tu_so/gcd(C.tu_so,C.mau_so),C.mau_so/gcd(C.tu_so,C.mau_so)});
}

PhanSo Hieu(PhanSo A, PhanSo B) {
    PhanSo C = {A.mau_so*B.mau_so-B.tu_so*A.mau_so, A.mau_so*B.mau_so};
    return ChuanHoa({C.tu_so/gcd(C.tu_so,C.mau_so),C.mau_so/gcd(C.tu_so,C.mau_so)});
}

PhanSo Tich(PhanSo A, PhanSo B) {
    PhanSo C = {A.tu_so*B.tu_so,A.mau_so*B.mau_so};
    return ChuanHoa({C.tu_so/gcd(C.tu_so,C.mau_so),C.mau_so/gcd(C.tu_so,C.mau_so)});
}

PhanSo Thuong(PhanSo A, PhanSo B) {
    PhanSo C = {A.tu_so*B.mau_so,A.mau_so*B.tu_so};
    return ChuanHoa({C.tu_so/gcd(C.tu_so,C.mau_so),C.mau_so/gcd(C.tu_so,C.mau_so)});
}

int main() {
    PhanSo A, B;
    cin >> A.tu_so >> A.mau_so >> B.tu_so >> B.mau_so;
    cout << "Tong = " << Tong(A,B).tu_so << "/" << Tong(A,B).mau_so << '\n';
    cout << "Hieu = " << Hieu(A,B).tu_so << "/" << Hieu(A,B).mau_so << '\n';
    cout << "Tich = " << Tich(A,B).tu_so << "/" << Tich(A,B).mau_so << '\n';
    if (A.DivideToZero() == 0 or B.DivideToZero() == 0) {
        cout << "Thuong = undefined" << '\n';
    }
    else
        cout << "Thuong = " << Thuong(A,B).tu_so << "/" << Thuong(A,B).mau_so << '\n';
    return  0;
}
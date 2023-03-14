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
    if ((float) A.tu_so/A.mau_so < 0) 
        return {-abs(A.tu_so),abs(A.mau_so)};
    if (A.tu_so < 0 and A.mau_so < 0)
        return {-A.tu_so,-A.mau_so};
    return A;
}

PhanSo Tong(PhanSo A, PhanSo B) {
    PhanSo C = {A.tu_so*B.mau_so+B.tu_so*A.mau_so, A.mau_so*B.mau_so};
    return ChuanHoa({C.tu_so/gcd(C.tu_so,C.mau_so),C.mau_so/gcd(C.tu_so,C.mau_so)});
}



int main() {
    int n;
    cin >> n;
    PhanSo* A = new PhanSo[n];
    for (int i = 0; i<n ; i++) {
        cin >> A[i].tu_so >> A[i].mau_so;
    }
    int i = 0;
        PhanSo max = A[0];
        PhanSo sum = A[0];
    for (i = 1; i<n ; i++) {
        if (((float) max.tu_so/max.mau_so) < ((float)A[i].tu_so/A[i].mau_so))
            max = A[i];
        sum = Tong(sum,A[i]);
        
    }
    cout << "sum = " << sum.tu_so << '/' << sum.mau_so << '\n';
    cout << "max = " << max.tu_so << '/' << max.mau_so;
    delete[] A;
    return 0;
}

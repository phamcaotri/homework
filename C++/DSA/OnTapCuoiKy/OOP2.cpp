#include <iostream>

using namespace std;

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

class PhanSo {
    private:
        int tu_so;
        int mau_so;

    public:
        PhanSo(int tu_so = 0, int mau_so = 1) {
            this->tu_so = tu_so;
            this->mau_so = mau_so;
        }

        friend istream& operator>>(istream& is, PhanSo& ps) {
            cout << "Nhap tu so: ";
            is >> ps.tu_so;
            cout << "Nhap mau so: ";
            is >> ps.mau_so;
            return is;
        }

        friend ostream& operator<<(ostream& os, PhanSo ps) {
            ps.normalize();
            if (ps.mau_so == 1) os << ps.tu_so;
            else os << ps.tu_so << "/" << ps.mau_so;
            return os;
        }

        friend PhanSo operator+(PhanSo a, PhanSo b) {
            PhanSo c;
            c.tu_so = a.tu_so * b.mau_so + b.tu_so * a.mau_so;
            c.mau_so = a.mau_so * b.mau_so;
            return c;
        }

        friend PhanSo operator-(PhanSo a, PhanSo b) {
            PhanSo c;
            c.tu_so = a.tu_so * b.mau_so - b.tu_so * a.mau_so;
            c.mau_so = a.mau_so * b.mau_so;
            return c;
        }

        friend PhanSo operator*(PhanSo a, PhanSo b) {
            PhanSo c;
            c.tu_so = a.tu_so * b.tu_so;
            c.mau_so = a.mau_so * b.mau_so;
            return c;
        }

        PhanSo& operator=(PhanSo ps) {
            this->tu_so = ps.tu_so;
            this->mau_so = ps.mau_so;
            return *this;
        }

        PhanSo& normalize() {
            int ucln = UCLN(this->tu_so, this->mau_so);
            this->tu_so /= ucln;
            this->mau_so /= ucln;
            return *this;
        }

};



int main() {
    PhanSo a, b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " + " << 1 << " = " << a + 1 << endl;
    cout << a << " * " << b << " = " << a * b << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class DonThuc {
    private:
        int he_so, so_mu;
    public:
        DonThuc(int he_so = 0, int so_mu = 0) {
            this->he_so = he_so;
            this->so_mu = so_mu;
        }
        void nhap() {
            cin >> he_so >> so_mu;
        }
        void xuat() const {
            cout << he_so << "x^" << so_mu << " ";
        }
        void setHeSo(int he_so) {
            this->he_so = he_so;
        }
        void setSoMu(int so_mu) {
            this->so_mu = so_mu;
        }
        int getHeSo() const {  
            return he_so;
        }
        int getSoMu() const {
            return so_mu;
        }
        float giaTri(float x) const {
            return he_so * pow(x, so_mu);
        }
        void daoHam() {
            he_so *= so_mu;
            so_mu--;
        }
        float daoHam(float x) const {
            return he_so * so_mu * pow(x, so_mu-1);
        }
        DonThuc operator + (const DonThuc &a) const {
            if (so_mu == a.so_mu) {
                return DonThuc(he_so + a.he_so, so_mu);
            }
            cout << "Khong cong duoc 2 don thuc nay!\n";
            return DonThuc(0, 0);
        }
};

int main() {
    DonThuc a, b;
    a.nhap();
    b.nhap();
    DonThuc c = a + b;
    c.xuat();
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PhanSo {
    private:
        int tu, mau;
    public:
        PhanSo(int tu = 0, int mau = 1) {
            this->tu = tu;
            this->mau = mau;
        }
        void nhap() {
            cin >> tu >> mau;
        }
        void xuat() {
            cout << tu << "/" << mau << '\n';
        }
        bool operator < (const PhanSo &a) const {
            return (tu*a.mau < a.tu*mau);
        }
        bool operator > (const PhanSo &a) const {
            return (tu*a.mau > a.tu*mau);
        }
        bool operator == (const PhanSo &a) const {
            return (tu*a.mau == a.tu*mau);
        }
};

class arrPhanSo {
    private:
        vector<PhanSo> v;
    public:
        void nhap() {
            int n; cin >> n;
            PhanSo a;
            for (int i = 0; i < n; i++) {
                a.nhap();
                v.push_back(a);
            }
        }
        void xuat() {
            for (auto i = v.begin(); i != v.end(); i++) {
                i->xuat();
            }
        }
        void sort() {
            ::sort(v.begin(), v.end());
        }
};
#include <bits/stdc++.h>
using namespace std;

struct PhanSo
{
    int tu_so;
    int mau_so;
};

void Nhap(PhanSo &a)
{
    cin >> a.tu_so >> a.mau_so;
}
PhanSo Nhap()
{
    PhanSo b;
    cin >> b.tu_so >> b.mau_so;
    return b;
}

int SoSanh(PhanSo a, PhanSo b)
{
    if ((float) a.tu_so/a.mau_so > (float) b.tu_so/b.mau_so)
        return 1;
    if ((float) a.tu_so/a.mau_so < (float) b.tu_so/b.mau_so)
        return -1;
    return 0;

}

int main() 
{
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    int kq = SoSanh(a, b);
    if (kq == 0)
        std::cout << "Hai phan so bang nhau.";
    else if (kq > 0)
        std::cout << "Phan so thu nhat LON hon phan so thu hai.";
    else
        std::cout << "Phan so thu nhat NHO hon phan so thu hai.";
    return 0;
}

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

PhanSo LamToiGian(int tu_so, int mau_so)
{   
    bool la_so_am = false;
    if ((float) tu_so/mau_so < 0)
        la_so_am = true;
    else
        la_so_am = false;
    tu_so = abs(tu_so);
    mau_so = abs(mau_so);
    for (int i = min(tu_so,mau_so); i >= 1 ; i--)
    {
        if (tu_so % i == 0 and mau_so % i == 0)
        {
            tu_so = tu_so / i;
            mau_so = mau_so / i;
            break;
        }

    }
    if (la_so_am)
        tu_so = -tu_so; 
    return {tu_so, mau_so};
}
PhanSo Cong(PhanSo a, PhanSo b)
{
    if ((float) a.tu_so/a.mau_so + (float) b.tu_so/b.mau_so == a.tu_so/a.mau_so + b.tu_so/b.mau_so)
        return {a.tu_so/a.mau_so + b.tu_so/b.mau_so, 1};
    else
        return LamToiGian(a.tu_so*b.mau_so+b.tu_so*a.mau_so,a.mau_so*b.mau_so);

}

void Xuat(PhanSo output)
{
    if (output.mau_so == 1)
        cout << output.tu_so;
    else
        cout << output.tu_so << "/" << output.mau_so; 
}

int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    Xuat(Cong(a, b));
    return 0;
}

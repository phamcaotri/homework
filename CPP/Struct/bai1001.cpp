    #include <bits/stdc++.h>
using namespace std;
#define MAXN 100

struct PhanSo
{
    int tu_so;
    int mau_so;
};

void Nhap(PhanSo a[], int &n)
{
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].tu_so >> a[i].mau_so;
    }
}
void LamToiGian(int &tu_so, int &mau_so)
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
}
void Xuat(PhanSo a[], int &n)
{
    for (int i = 0; i < n; i++)
    {

        if (a[i].mau_so == 0)
        {
            cout << "Khong thoa yeu cau bai toan" << '\n';
        }
        else if (a[i].tu_so == 0)
        {
            cout << 0 << '\n';
        }
        else if ( (a[i].tu_so % a[i].mau_so) == 0)
        {
            cout << a[i].tu_so / a[i].mau_so << '\n';
        }
        else
        {
            LamToiGian(a[i].tu_so, a[i].mau_so);
            cout << a[i].tu_so << "/" << a[i].mau_so << '\n';
        }
        
    }
}

int main() {
    PhanSo a[MAXN];
    int n;
    Nhap(a, n);
    Xuat(a, n);
    return 0;
}

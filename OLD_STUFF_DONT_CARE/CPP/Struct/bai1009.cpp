#include <bits/stdc++.h>
using namespace std;

struct DATHUC
{
    float he_so;
    int so_mu;
};

DATHUC *Nhap()
{
    int n = 0; cin >> n; cin.ignore();
    DATHUC *B = new DATHUC[100];
    int i = 0;
    for (; i < n; i++)
    {
        cin >> B[i].he_so >> B[i].so_mu;
    }
    B[i].so_mu = -1;
    return B;
}

void Xuat(DATHUC &B)
{
    DATHUC *C = &B;
    int i = 0;
    bool duoc_xuat = false;
    while (C[i].so_mu != -1)
    {
        if (duoc_xuat and C[i].he_so > 0)
            cout << "+";

        if (C[i].he_so == 0)
        {
            i++; continue;
        } 

        if (C[i].so_mu == 0)
        {
            cout << C[i].he_so;
            duoc_xuat = true;
            i++; continue;
        }    
        if (C[i].he_so == 1)
        {
            cout << "x^" << (C[i].so_mu == 1 ? : C[i].so_mu);
            duoc_xuat = true;
            i++; continue;
        }    
        if (C[i].he_so == -1)
        {
            cout << "-x^" << (C[i].so_mu == 1 ? : C[i].so_mu);
            duoc_xuat = true;
            i++; continue;
        }

        if (C[i].so_mu == 1)
        {
            cout << C[i].he_so << "x";
            duoc_xuat = true;
            i++; continue;
        }
        cout << C[i].he_so << "x^" << C[i].so_mu;             
        duoc_xuat = true;
        i++; continue;
    }
    if (!duoc_xuat)
        cout << "0";

}

double TinhDaThuc(DATHUC &B, double x)
{
    DATHUC *C = &B;
    int i = 0;
    double tong = 0;
    while (C[i].so_mu != -1)
    {   
        tong += C[i].he_so*pow(x,C[i].so_mu);
        i++;
    }
    return tong;
}


int main() {
    DATHUC *B; B = Nhap();
    cout << "Da thuc vua nhap la: "; Xuat(*B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(*B, x);
    return 0;
}

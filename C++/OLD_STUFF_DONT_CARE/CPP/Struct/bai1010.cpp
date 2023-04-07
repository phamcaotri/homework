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
        if (C[i].he_so == 1 and C[i].so_mu == 1)
        {
            cout << "x";
            duoc_xuat = true;
            i++; continue;
        }  
        if (C[i].he_so == -1 and C[i].so_mu == 1)
        {
            cout << "-x";
            duoc_xuat = true;
            i++; continue;
        }        
        if (C[i].he_so == 1)
        {
            cout << "x^" << C[i].so_mu;
            duoc_xuat = true;
            i++; continue;
        }    
        if (C[i].he_so == -1)
        {
            cout << "-x^" << C[i].so_mu;
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
void Xuat(DATHUC *C)
{
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
        if (C[i].he_so == 1 and C[i].so_mu == 1)
        {
            cout << "x";
            duoc_xuat = true;
            i++; continue;
        }  
        if (C[i].he_so == -1 and C[i].so_mu == 1)
        {
            cout << "-x";
            duoc_xuat = true;
            i++; continue;
        }        
        if (C[i].he_so == 1)
        {
            cout << "x^" << C[i].so_mu;
            duoc_xuat = true;
            i++; continue;
        }    
        if (C[i].he_so == -1)
        {
            cout << "-x^" << C[i].so_mu;
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

DATHUC *Tong2DaThuc(DATHUC *A, DATHUC *B)
{
    int i = 0, j = 0, k = 0;
    DATHUC *C = new DATHUC[100];
    while (A[i].so_mu != -1 or B[j].so_mu != -1)
    {
        if (A[i].so_mu > B[j].so_mu)
        {
            C[k].he_so = A[i].he_so;
            C[k].so_mu = A[i].so_mu;
            i++;
            k++;
        }
        else if (A[i].so_mu < B[j].so_mu)
        {
            C[k].he_so = B[j].he_so;
            C[k].so_mu = B[j].so_mu;
            j++;
            k++;
        }
        else
        {
            C[k].he_so = A[i].he_so+B[j].he_so;
            C[k].so_mu = A[i].so_mu;
            i++;
            j++;
            k++;
        }
    }
    C[k].so_mu = -1;
    return C;
}

int main() {
    DATHUC *A, *B;
    A = Nhap();
    B = Nhap();
    cout << "Da thuc A: "; Xuat(*A);
    cout << "\nDa thuc B: "; Xuat(*B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}

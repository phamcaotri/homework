#include <iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cstdio>

using namespace std;
struct ngay
{
    int ng;
    int thang;
    int nam;
};
struct HOPSUA
{
    char nhan_hieu[40];
    float trong_luong;
    ngay hang_su_dung;
};

void nhap1HopSua(HOPSUA &x)
{
    cin >> x.trong_luong >> x.hang_su_dung.ng >>x.hang_su_dung.thang >> x.hang_su_dung.nam;
    cin.ignore();
    cin.getline(x.nhan_hieu,40);
}

void nhapDSHopSua(HOPSUA a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        nhap1HopSua(a[i]);
    }
}

bool is_guess_right(HOPSUA a[],int n,char guess[])
{
    float max = 0;
    int index = 0;
    for (int i = 0; i <n; i++)
    {
        if (a[i].trong_luong > max)
        {
            max = a[i].trong_luong;
            index = i;
        }
    }
    if (strstr(a[index].nhan_hieu,guess) != NULL )
        return 1;
    return 0;
}


int main()
{
    HOPSUA a[100];
    int n;
    nhapDSHopSua(a,n);// Nhap danh sach cac hop sua
    char guess[40];
    cin >> guess;
    if (is_guess_right(a,n,guess))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

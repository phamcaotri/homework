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
int soSanh(ngay x, ngay y)
{
    if (x.nam > y.nam)
        return 1;
    else if (x.nam < y.nam)
        return -1;
    else if (x.thang > y.thang)
        return 1;
    else if (x.thang < y.thang)
        return -1;
    else if (x.ng > y.ng)
        return 1;
    else if (x.ng < y.ng)
        return -1;
    else return 0;
    
}

int soLuongQuaHan(HOPSUA a[], int n, ngay y)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (soSanh(a[i].hang_su_dung,y) < 0)
            count++;
            
    }    
    return count;
}


int main()
{
    HOPSUA a[100];
    int n;
    cout<<"Nhap danh sach hop sua: "<<endl;
    nhapDSHopSua(a,n);// Nhap danh sach cac hop sua
    cout<<"\nNhap ngay kiem tra: "<<endl;
    ngay y;
    cin>>y.ng>>y.thang>>y.nam;
    cout<<"\nSo luong hop sua qua han: "<<soLuongQuaHan(a,n,y);

    return 0;
}

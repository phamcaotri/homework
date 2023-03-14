#include <iostream>

using namespace std;

struct Diem
{
    int x;
    int y;
};

void nhapDSDiem(Diem a[],int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
}

void xuatDSDiem(Diem a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("(%d,%d)\n", a[i].x, a[i].y);
    }
}

string gocPhanTu(Diem M)
{
    int x =M.x, y = M.y;
    if (x == 0)
    {
        if (y == 0)
            return "la goc toa do";
        return "nam tren truc tung";
    }
    else
    {
        if (y == 0)
            return "nam tren truc hoanh";
        if (x > 0 and y > 0)
            return "thuoc goc phan tu thu I";
        if (x < 0 and y > 0)
            return "thuoc goc phan tu thu II";
        if (x < 0 and y < 0)
            return "thuoc goc phan tu thu III";
        if (x > 0 and y < 0)
            return "thuoc goc phan tu thu IV";
    }
    return " ";
}

void gocPhanTu(Diem a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"("<<a[i].x<<","<<a[i].y<<") " << gocPhanTu(a[i]) << '\n';

    }
}

int main()
{
    Diem a[100];
    int n;
    nhapDSDiem(a,n); // Nhap danh sach cach diem trong mat phang Oxy
    cout<<"Danh sach diem trong mat phang Oxy:\n";
    xuatDSDiem(a,n); // Xuat danh sach cac diem, moi diem tren 1 dong

    Diem M;
    cout<<"\nNhap mot diem de kiem tra: ";
    cin>>M.x>>M.y;
    cout<<"\nDiem ("<<M.x<<","<<M.y<<") "<<gocPhanTu(M); //Kiem tra diem co nam tren cac truc toa do hoac thuoc goc phan tu thu may trong mat phang Oxy

    cout<<"\nKiem tra toan bo danh sach diem da nhap:\n";
    gocPhanTu(a,n);

    return 0;
}

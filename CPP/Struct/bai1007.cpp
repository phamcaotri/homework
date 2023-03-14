
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};



void Nhap(SinhVien A[], int &n)
{
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin.getline(A[i].MASV,255);
        cin.getline(A[i].HoTen,255);
        cin.getline(A[i].NgaySinh,255);
        cin >> A[i].GioiTinh;
        cin >> A[i].DiemToan;
        cin >> A[i].DiemLy;
        cin >> A[i].DiemHoa; cin.ignore();
    }

}

void Xuat(SinhVien A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i].MASV << "	"
        << A[i].HoTen << "	"
        << A[i].NgaySinh << "	"
        << A[i].GioiTinh << "	"
        << A[i].DiemToan << "	"
        << A[i].DiemLy << "	"
        << A[i].DiemHoa << "	"
        << setprecision(3) << (float) (A[i].DiemToan + A[i].DiemLy + A[i].DiemHoa)/3 << '\n';
    }

}

void SapXepGiamTheoMASV(SinhVien A[], int n)
{
    SinhVien tmp;
    for (int i = n; i >= 0; i--)
        for (int j = 0; j < i; j++)
        {
            
            if ((stoi(A[j].MASV) < stoi(A[j+1].MASV)))
            {
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
}


int main() {
    SinhVien A[MAXN];
    int n;
    Nhap(A, n);
    SapXepGiamTheoMASV(A, n);
    Xuat(A, n);
    return 0;
}


#include <iomanip>
#include <iostream>
#include <stdio.h>
using namespace std;

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void Nhap(SinhVien &A)
{
    cin.getline(A.MASV,255);
    cin.getline(A.HoTen,255);
    cin.getline(A.NgaySinh,255);
    cin >> A.GioiTinh;
    cin >> A.DiemToan;
    cin >> A.DiemLy;
    cin >> A.DiemHoa;
}

void Xuat(SinhVien A)
{
    cout << A.MASV << "	"
        << A.HoTen << "	"
        << A.NgaySinh << "	"
        << A.GioiTinh << "	"
        << A.DiemToan << "	"
        << A.DiemLy << "	"
        << A.DiemHoa << "	"
        << setprecision(3) << (float) (A.DiemToan + A.DiemLy + A.DiemHoa)/3;
}

int main() {
    SinhVien A;
    Nhap(A);
    Xuat(A);
    return 0;
}

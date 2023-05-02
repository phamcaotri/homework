#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DiemCD {
    private:
        float DiemTotNghiep;
    public:
        float getDiemTotNghiep() {
            return DiemTotNghiep;
        }
        void setDiemTotNghiep(float DiemTotNghiep) {
            this->DiemTotNghiep = DiemTotNghiep;
        }
        void Nhap() {
            cout << "Nhap DiemTotNghiep: "; cin >> DiemTotNghiep;
        }

};

class DiemDH {
    private:
        string TenLuanVan;
        float  DiemLuanVan;
    public:
        string getTenLuanVan() {
            return TenLuanVan;
        }
        float getDiemLuanVan() {
            return DiemLuanVan;
        }
        void setTenLuanVan(string TenLuanVan) {
            this->TenLuanVan = TenLuanVan;
        }
        void setDiemLuanVan(float DiemLuanVan) {
            this->DiemLuanVan = DiemLuanVan;
        }
        void Nhap() {
            cout << "Nhap TenLuanVan: "; getline(cin, TenLuanVan);
            cout << "Nhap DiemLuanVan: "; cin >> DiemLuanVan;
        }
};

class SinhVien {
    private:
        string MSSV;
        string HoTen;
        string DiaChi;
        int TongSoTinChi;
        float DiemTB;
        string He;
        DiemCD CD;
        DiemDH DH;
    public:
        SinhVien() {};
        SinhVien(string MSSV, string HoTen, string DiaChi, int TongSoTinChi, float DiemTB, bool He) {
            this->MSSV = MSSV;
            this->HoTen = HoTen;
            this->DiaChi = DiaChi;
            this->TongSoTinChi = TongSoTinChi;
            this->DiemTB = DiemTB;
            this->He = He;
        }
        void Nhap() {
            cout << "Nhap MSSV: "; getline(cin, MSSV);
            cout << "Nhap HoTen: "; getline(cin, HoTen);
            cout << "Nhap DiaChi: "; getline(cin, DiaChi);
            cout << "Nhap TongSoTinChi: "; cin >> TongSoTinChi;
            cout << "Nhap DiemTB: "; cin >> DiemTB;
            cout << "Nhap He (DH/CD): "; cin >> He;
            cin.ignore();
            if (He == "DH") {
                DH.Nhap();
            } else {
                CD.Nhap();
            }
                
        }
        void Xuat() {
            cout << "MSSV: " << MSSV << endl;
            cout << "HoTen: " << HoTen << endl;
            cout << "DiaChi: " << DiaChi << endl;
            cout << "TongSoTinChi: " << TongSoTinChi << endl;
            cout << "DiemTB: " << DiemTB << endl;
            if (He == "DH") {
                cout << "He: Dai Hoc" << endl;
                cout << "TenLuanVan: " << DH.getTenLuanVan() << endl;
                cout << "DiemLuanVan: " << DH.getDiemLuanVan() << endl;
            } else {
                cout << "He: Cao Dang" << endl;
                cout << "DiemTotNghiep: " << CD.getDiemTotNghiep() << endl;
            }
        }
        float getTB() {
            return DiemTB;
        }
        bool duDieuKien() {
            if (He == "DH") {
                if (DiemTB >= 5 && TongSoTinChi >= 150 && DH.getDiemLuanVan() >= 5) {
                    return true;
                }
            } else {
                if (DiemTB >= 5 && TongSoTinChi >= 120 && CD.getDiemTotNghiep() >= 5) {
                    return true;
                }
            }
            return false;
        }
};

class TruongCNTT {
    private:
        vector<SinhVien> SV;
    public:
        void Nhap() {
            int n;
            cout << "Nhap so luong sinh vien: "; cin >> n;
            for (int i = 0; i < n; i++) {
                SinhVien x;
                cin.ignore();
                x.Nhap();
                SV.push_back(x);
            }

        }
        void Xuat() {
            for (int i = 0; i < SV.size(); i++) {
                SV[i].Xuat();
            }
        }
        int demSVDuDieuKien() {
            int dem = 0;
            for (int i = 0; i < SV.size(); i++) {
                if (SV[i].duDieuKien()) {
                    dem++;
                }
            }
            return dem;
        }
        SinhVien SVGioiNhat() {
            SinhVien x = SV[0];
            for (int i = 1; i < SV.size(); i++) {
                if (SV[i].getTB() > x.getTB()) {
                    x = SV[i];
                }
            }
            return x;
        }


};

int main() {
    TruongCNTT a;
    a.Nhap();
    a.Xuat();
    cout << "So luong sinh vien du dieu kien: " << a.demSVDuDieuKien() << endl;
    cout << "Sinh vien gioi nhat: " << endl;
    a.SVGioiNhat().Xuat();
    return 0;
}


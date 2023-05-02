#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Sach {
    private:
        string Loai;
        string MaSach;
        string TenSach;
        string NXB;
        int SoLuong;
        float DonGia;
        float Thue;
        bool TinhTrang; // 0: cu, 1: moi
    public:
        Sach() {};
        void Nhap() {
            cout << "Nhap Loai(SGK/STK): "; getline(cin, Loai);
            cout << "Nhap MaSach: "; getline(cin, MaSach);
            cout << "Nhap TenSach: "; getline(cin, TenSach);
            cout << "Nhap NXB: "; getline(cin, NXB);
            cout << "Nhap SoLuong: "; cin >> SoLuong;
            cout << "Nhap DonGia: "; cin >> DonGia;
            if (Loai == "SGK") {
                cout << "Nhap TinhTrang: "; cin >> TinhTrang;
            } else {
                cout << "Nhap Thue: "; cin >> Thue;
            }
        }
        void Xuat() {
            cout << "Loai: " << Loai << endl;
            cout << "MaSach: " << MaSach << endl;
            cout << "TenSach: " << TenSach << endl;
            cout << "NXB: " << NXB << endl;
            cout << "SoLuong: " << SoLuong << endl;
            cout << "DonGia: " << DonGia << endl;
            if (Loai == "SGK") {
                cout << "TinhTrang: " << TinhTrang << endl;
            } else {
                cout << "Thue: " << Thue << endl;
            }
        }
        float ThanhTien() {
            if (Loai == "SGK") {
                if (TinhTrang == 1) {
                    return SoLuong * DonGia;
                } else {
                    return SoLuong * DonGia * 0.5;
                }
            } else {
                return SoLuong * DonGia + Thue;
            }
        }
        string getLoai() {
            return Loai;
        }
        string getNXB() {
            return NXB;
        }

        friend bool operator<(Sach a, Sach b) {
            return a.ThanhTien() < b.ThanhTien();
        }

};

class ThuVien {
    private:
        vector<Sach> ListSach;
    public:
        void Nhap() {
            int n;
            cout << "Nhap so luong sach: "; cin >> n;
            for (int i = 0; i < n; i++) {
                Sach sach;
                cin.ignore();
                sach.Nhap();
                ListSach.push_back(sach);
            }
        }
        void Xuat() {
            for (int i = 0; i < ListSach.size(); i++) {
                ListSach[i].Xuat();
            }
        }
        float TongTienSGK() {
            float sum = 0;
            for (int i = 0; i < ListSach.size(); i++) {
                if (ListSach[i].getLoai() == "SGK") {
                    sum += ListSach[i].ThanhTien();
                }
            }
            return sum;
        }
        float TongTienSTK() {
            float sum = 0;
            for (int i = 0; i < ListSach.size(); i++) {
                if (ListSach[i].getLoai() == "STK") {
                    sum += ListSach[i].ThanhTien();
                }
            }
            return sum;
        }

        void SachReNhat() {
            sort(ListSach.begin(), ListSach.end());
            ListSach[0].Xuat();
            for (int i = 1; i < ListSach.size(); i++) {
                if (ListSach[i].ThanhTien() == ListSach[0].ThanhTien()) {
                    ListSach[i].Xuat();
                } else {
                    break;
                }
            }
        }

        void TimTheoNXB(string NXB) {
            for (int i = 0; i < ListSach.size(); i++) {
                if (ListSach[i].getNXB() == NXB) {
                    ListSach[i].Xuat();
                }
            }
        }

};

int main() {
    ThuVien thuVien;
    thuVien.Nhap();
    thuVien.Xuat();
    cout << "Tong tien SGK: " << thuVien.TongTienSGK() << endl;
    cout << "Tong tien STK: " << thuVien.TongTienSTK() << endl;
    cout << "Sach re nhat: " << endl;
    thuVien.SachReNhat();
    cout << "Nhap NXB: "; string NXB; 
    cin.ignore();
    getline(cin, NXB);
    thuVien.TimTheoNXB(NXB);
    return 0;
}
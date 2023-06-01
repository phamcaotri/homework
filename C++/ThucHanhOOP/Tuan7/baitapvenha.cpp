#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



class SanPham {
    protected:
        string maSoSP;
        string tieuDe;
        float giaBan;
    public:
        virtual void Nhap() {
            cout << "nhap ma so sp: ";
            cin >> maSoSP;
            cout << "nhap tieu de: ";
            cin >> tieuDe;
            cout << "nhap gia ban: ";
            cin   >> giaBan;
        }
        virtual void Xuat() {
            cout << "ma so san pham: " << maSoSP << endl;
            cout << "tieu de: " << tieuDe << endl;
            cout << "gia ban: " << giaBan << endl;
        }
        float getGiaBan() {
            return giaBan;
        }

};

class TranhAnh : public SanPham {
    private:
        float chieuRong;
        float chieuCao;
        string tenHoaSi;

    public:
        void Nhap() override {
            SanPham::Nhap();
            cout << "nhap chieu rong: ";
            cin   >> chieuRong;
            cout << "nhap chieu cao: ";
            cin   >> chieuCao;
            getline(cin, tenHoaSi);
        }
        void Xuat() override {
            SanPham::Xuat();
            cout << "chieu rong va chieu cao: " << chieuRong << "x" << chieuCao << endl;
            cout << "ten hoa si: " << tenHoaSi << endl;
        }
};

class CDAmNhac : public SanPham {
    private:
        string tenCaSi;
        string tenDVSX;
    public:
        void Nhap() override {
            SanPham::Nhap();
            cout << "ten ca si: ";
            cin.ignore();
            getline(cin, tenCaSi);
            cout << "ten don vi sx: ";
            getline(cin, tenDVSX);
        }
        void Xuat() override {
            SanPham::Xuat();
            cout << "ten ca si: " << tenCaSi << endl;
            cout << "ten don vi sx: " << tenDVSX << endl;
        }     
};

class KhachHang {
    private:
        string maKH;
        string tenKH;
        string sdt;
    public:
        void Nhap() {
            cout << "nhap ma khach hang: ";
            cin >> maKH;
            cout << "nhap ten khach hang: ";
            cin.ignore();
            getline(cin, tenKH);
            cout << "nhap sdt: ";
            cin >> sdt;

        }
        void Xuat() {
            cout << "ma khach hang: " << maKH << endl;
            cout << "ten khach hang: " << tenKH << endl;
            cout << "sdt: " << sdt << endl;
        }
};

class HoaDon {
    private:
        string maHoaDon;
        KhachHang kh;
        string ngayLap;
        vector<SanPham*> sp;
        float tongGia;
    public:
        void Nhap() {
            cout << "nhap ma hoa don: ";
            cin >> maHoaDon;
            kh.Nhap();
            cout << "nhap ngay lap: ";
            cin >> ngayLap;
            cout << "nhap so luong san pham: ";
            int n; cin   >> n;
            for (int i = 0; i < n; i++) {
                cout << "nhap san pham thu " << i+1 << ": " << endl;
                SanPham* new_sp = []() -> SanPham* {
                    cout << "nhap loai: (1, 2) ";
                    int loai; cin   >> loai;
                    switch (loai) {
                        case 1: return new TranhAnh;
                        case 2: return new CDAmNhac;
                        default: return NULL;
                    }
                }();
                new_sp->Nhap();
                sp.push_back(new_sp);
            }
            TinhTongGia();

        }
        void Xuat() {
            cout << "ma hoa don: " << maHoaDon << endl;
            kh.Xuat();
            cout << "ngay lap: " << ngayLap << endl;
            for (int i = 0; i < sp.size(); i ++) {
                sp[i]->Xuat();
            }
            cout << "tong gia: " << tongGia << endl;
        }
        void TinhTongGia() {
            tongGia = 0;
            for (int i = 0; i < sp.size(); i ++) {
                tongGia += sp[i]->getGiaBan();
            }
        }
        float getTongGia() {
            return tongGia;
        }
        KhachHang getKhachHang() {
            return kh;
        }
        
};



class CuaHang {
    private:
        vector<HoaDon> hd;
    public:
        void Nhap() {
            cout << "nhap so luong hoa don: ";
            int n; cin   >> n;
            for (int i = 0; i < n; i++) {
                cout << "nhap hoa don thu " << i+1 << ": " << endl;
                HoaDon new_hd;
                new_hd.Nhap();
                hd.push_back(new_hd);
            }
        }
        void Xuat() {
            for (int i = 0; i < hd.size(); i++) {
                hd[i].Xuat();
            }

        }
        float TongThuNhap() {
            float tongThuNhap = 0;
            for (int i = 0; i < hd.size(); i++) {
                tongThuNhap += hd[i].getTongGia();
                                
            }
            return tongThuNhap;
        }
        vector<KhachHang> KhachHangMuaNhieuNhat() {
            if (hd.size() == 0) return vector<KhachHang>();
            vector<KhachHang> x;
            HoaDon hdMuaNhieuNhat = hd[0];
            for (int i = 1; i < hd.size(); i++) {
                if (hd[i].getTongGia() > hdMuaNhieuNhat.getTongGia()) {
                    hdMuaNhieuNhat = hd[i];
                }
            }            
            for (int i = 0; i < hd.size(); i++) {
                if (hd[i].getTongGia() == hdMuaNhieuNhat.getTongGia()) {
                    x.push_back(hd[i].getKhachHang());
                }
            }
            return x;
        }
};

int main() {
    CuaHang ch;
    ch.Nhap();
    ch.Xuat();
    cout << "Tong thu nhap cua cua hang la: ";
    cout << ch.TongThuNhap() << endl;
    cout << "Khach hang mua nhieu nhat la: ";
    auto x = ch.KhachHangMuaNhieuNhat();
    for (int i = 0; i < x.size(); i++) {
        x[i].Xuat();
    }
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Sung {
    protected:
        string tenSung;
        int soDan;
        float satThuong;
        float tocDoBan;
        const float thoiGianNapDan = 2;
        int soLuongBanDan;
        float doHaoMon;
    public:
        Sung(string tenSung, int soDan, float satThuong, float tocDoBan) {
            this->tenSung = tenSung;
            this->soDan = soDan;
            this->satThuong = satThuong;
            this->tocDoBan = tocDoBan;            
        }
        virtual void Nhap() {
            cin >> soLuongBanDan;
            cin >> doHaoMon;
        }
        virtual void Xuat(float thoiGianBan) {
            cout << tenSung << ": " << getTongSatThuong(thoiGianBan) << endl;
        }
        virtual float getTongSatThuong(float thoiGianBan) {
            float tongSatThuong = 0;
            int danTrongBangHienTai = soDan;
            while (true) {
                if (thoiGianBan <= 0) return tongSatThuong;
                if (soLuongBanDan <= 0) return tongSatThuong;
                if (danTrongBangHienTai == 0) {
                    danTrongBangHienTai = soDan;
                    thoiGianBan -= thoiGianNapDan;
                    soLuongBanDan --;
                    continue;
                } 
                tongSatThuong += satThuong;
                danTrongBangHienTai --;
                thoiGianBan -= 1.0/tocDoBan;
            }
        }
};

class SungNgan : public Sung {
    public:
        using Sung::Sung;
        void Nhap() override {
            Sung::Nhap();
            satThuong *= doHaoMon;
            if (doHaoMon != 1) {
                tocDoBan /= 2.0;
            }
        }

};

class SungTruong : public Sung {
    private:
        float satThuongCongThem;
    public:
        using Sung::Sung;
        void Nhap() override {
            Sung::Nhap();
            satThuong *= doHaoMon;
            if (doHaoMon != 1) {
                tocDoBan /= 2;
            }
            cin >> satThuongCongThem;
            satThuong += satThuongCongThem;
        }
};

class SungBanTia : public Sung {
    public:
        using Sung::Sung;
        void Nhap() override {
            Sung::Nhap();
            satThuong *= doHaoMon;
            if (doHaoMon != 1) {
                tocDoBan /= 2;
            }
        }
        float getTongSatThuong(float thoiGianBan) override {
            float tongSatThuong = 0;
            int danTrongBangHienTai = soDan;
            while (true) {
                if (thoiGianBan <= 0) return tongSatThuong;
                if (soLuongBanDan <= 0) return tongSatThuong;
                if (danTrongBangHienTai == 0) {
                    danTrongBangHienTai = soDan;
                    thoiGianBan -= thoiGianNapDan;
                    soLuongBanDan --;
                    continue;
                } 
                tongSatThuong += satThuong;
                danTrongBangHienTai --;
                thoiGianBan -= 1.0/tocDoBan +1;
            }
        }
};

class QuanLySung {
    private:
        vector<Sung*> sung;
        float tgBan;

    public:
        void Nhap() {
            int soLuong;
            cin >> soLuong;
            for (int i = 0; i < soLuong; i++) {
                Sung* new_sung = []() -> Sung* {
                    int loai;
                    cin >> loai;
                    switch (loai) {
                        case 1: return new SungNgan("G18", 12, 2, 1);
                        case 2: return new SungNgan("M500", 5, 4, 0.5);
                        case 3: return new SungTruong("MP40", 20, 3, 5);
                        case 4: return new SungTruong("AK", 30, 5, 1);
                        case 5: return new SungBanTia("SVD", 10, 5, 0.5);
                        case 6: return new SungBanTia("AWM", 5, 10, 0.5);
                        default: return NULL;
                    }
                }();
                new_sung->Nhap();
                sung.push_back(new_sung);
            }
            cin >> tgBan;
        }
        void Xuat() {
            for (int i = 0; i < sung.size(); i++) {
                sung[i]->Xuat(tgBan);
            }

        }
};

int main() {
    QuanLySung ql;
    ql.Nhap();
    ql.Xuat();
    return 0;
}

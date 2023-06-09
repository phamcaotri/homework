#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class ThapPhao {
    protected:
        float size;
        int so_dan;
        int so_kip_lai;
    public:
        virtual float getDamage(int) = 0;
        void Nhap() {
            cin >> so_kip_lai;
            cin >> so_dan;
        }
        int getSoKipLai() {
            return so_kip_lai;
        }
        int getSoDan() {
            return so_dan;
        }
};

class ML20S : public ThapPhao {
    public:
        ML20S() {
            size = 152;
        }
        float getDamage(int so_dan_ban) override {
            return so_kip_lai / 4.0 * size * (so_dan-so_dan_ban);
        }
};

class F34 : public ThapPhao {
    public:
        F34() {
            size = 76.2;
        }
        float getDamage(int so_dan_ban) override {
            return 3 * size * (so_dan-so_dan_ban);
        }
};

class D25T : public ThapPhao {
    public:
        D25T() {
            size = 122; 
        }

        float getDamage(int so_dan_ban) override {
            return 3 * size * (so_dan-so_dan_ban);
        }
};

class M65L : public ThapPhao {
    public:
        M65L() {
            size = 130;
        }
        float getDamage(int so_dan_ban) override {
            return so_kip_lai / 4.0 * size * (so_dan - so_dan_ban);
        }
};

class DongCo {
    protected:
        int hp;
        float xang;
        float km_da_di;
        float khoi_luong_tan;
    public:

        virtual float getTieuThuXang() = 0;
        void setKmDaDi(int x) {
            km_da_di = x;
        }
        void Nhap() {
            cin >> khoi_luong_tan;
        }
        float getKhoiLuongTan() {
            return khoi_luong_tan;
        }
};

class V2 : public DongCo {
    public:
        V2() {
            hp = 500;
        }
        float getTieuThuXang() override {
            return 450.0 / khoi_luong_tan * km_da_di / 100.0;
        }
};

class V2K : public DongCo {
    public:
        V2K() {
            hp = 600;
        }
        float getTieuThuXang() override {
            return 450.0 / khoi_luong_tan * km_da_di / 100.0;
        }
};

class _2DG8M : public DongCo {
    public:
        _2DG8M() {
            hp = 1000;
        }
        float getTieuThuXang() override {
            return 400.0 / khoi_luong_tan * km_da_di / 100.0;
        }
};

class Tank {
    protected:
        string ten;
        float so_xang;
        int so_dan_ban;
        ThapPhao* tp;
        DongCo* dc;
    public:
        void Nhap() {
            dc->Nhap();
            tp->Nhap();
            cin >> so_xang;
        }
        string getTen() {
            return ten;
        }
        float getKhoiLuongTan() {
            return dc->getKhoiLuongTan();
        }
        int getSoDan() {
            return tp->getSoDan();
        }
        float getSoXang() {
            return so_xang;
        }
        float getDamage() {
            return tp->getDamage(so_dan_ban);
        }
        int getSoKipLai() {
            return tp->getSoKipLai();
        }
        virtual float getPerformance() = 0;

        void setSoDanBan(int x) {
            so_dan_ban = x;
        }
        void setKmDaDi(int x) {
            dc->setKmDaDi(x);
        }
        virtual ~Tank() {
            delete tp;
            delete dc;
        }
};

class SU152 : public Tank {
    public:
        SU152() {
            ten = "SU152";
            tp = new ML20S();
            dc = new V2K();
        }
        float getPerformance() override {
            int so_dan_con_lai = tp->getSoDan() - so_dan_ban;
            return 1.0*so_dan_con_lai / tp->getSoDan();
        }
};

class KV2 : public Tank {
    public:
        KV2() {
            ten = "KV2";
            tp = new F34();
            dc = new V2();
        }
        float getPerformance() override {
            int so_dan_con_lai = tp->getSoDan() - so_dan_ban;
            return 1.0*so_dan_con_lai / tp->getSoDan();
        }
};

class IS : public Tank {
    public:
        IS() {
            ten = "IS";
            tp = new D25T();
            dc = new V2K();
        }
        float getPerformance() override {
            int so_xang_con_lai = so_xang - dc->getTieuThuXang();
            return 1.0*so_xang_con_lai / so_xang;
        }
};

class Object279 : public Tank {
    public:
        Object279() {
            ten = "Object279";
            tp = new M65L();
            dc = new _2DG8M();
        }
        float getPerformance() override {
            return tp->getSoKipLai() / 4.0;
        }
};

class XuLy {
    private:
        vector<Tank*> ds_tank;
    public:
        void Nhap() {
            int n; cin >> n;
            ds_tank.resize(n);
            for (int i = 0; i < n; i++) {
                ds_tank[i] = []() -> Tank* {
                    int loai; cin >> loai;
                    switch (loai) {
                        case 1: return new SU152;
                        case 2: return new KV2;
                        case 3: return new IS;
                        case 4: return new Object279;
                        default: return NULL;
                    }
                }();
            ds_tank[i]->Nhap();
            }
            int km_da_di;
            int so_dan_ban;
            cin >> km_da_di;
            cin >> so_dan_ban;
            for (int i = 0; i < ds_tank.size(); i++) {
                ds_tank[i]->setSoDanBan(so_dan_ban);
                ds_tank[i]->setKmDaDi(km_da_di);
            }

        }
        void Xuat() {
            for (int i = 0; i < ds_tank.size(); i++) {
                cout << ds_tank[i]->getTen() << ", weight: ";
                cout << ds_tank[i]->getKhoiLuongTan() << ", number of crews: ";
                cout << ds_tank[i]->getSoKipLai() << ", damage: ";
                cout << ds_tank[i]->getDamage() << ", performance: ";
                cout << ds_tank[i]->getPerformance()*100 << "%\n";
            }
        }
        ~XuLy() {
            for (int i = 0; i < ds_tank.size(); i++) {
                delete ds_tank[i];
            }
        }
};

int main() {
    XuLy xe;
    xe.Nhap();
    xe.Xuat();
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const float PI = 3.14;

class Chai {
    protected:
    
    public:
        virtual float TheTich() = 0;
        virtual float DienTich() = 0;
        virtual void Nhap() = 0;

};

class ChaiTruTron : public Chai {
    private:
        int chieu_cao;
        int ban_kinh;
    public:
        float TheTich() override {
            return PI * ban_kinh * ban_kinh * chieu_cao;
        }
        float DienTich() override {
            // xung quanh
            return ban_kinh * chieu_cao * 2 * PI;
        }
        void Nhap() override {
            cin >> chieu_cao >> ban_kinh;
        }

};

class ChaiHCN : public Chai {
    private:
        int chieu_cao;
        int chieu_dai;
        int chieu_rong;
    public:
        float TheTich() override {
            return chieu_dai * chieu_rong * chieu_cao;
        }
        float DienTich() override {
            return 2 * (chieu_dai * chieu_rong + chieu_dai * chieu_cao + chieu_rong * chieu_cao);
        }
        void Nhap() override {
            cin >> chieu_dai >> chieu_rong >> chieu_cao;
        }
};

class ChaiLP : public Chai {
    private:
        int do_dai_canh;
    public:
        float TheTich() override {
            return do_dai_canh * do_dai_canh * do_dai_canh;
        }
        float DienTich() override {
            return 6 * do_dai_canh * do_dai_canh;
        }
        void Nhap() override {
            cin >> do_dai_canh;
        }
};

class DapChai {
    private:
        int so_chai;
        Chai** chai;
    public:
        void Nhap() {
            cin >> so_chai;
            chai = new Chai*[so_chai];
            for (int i = 0; i < so_chai; i++) {
                int loai_chai; cin >> loai_chai;
                if (loai_chai == 1) {
                    chai[i] = new ChaiTruTron();
                    chai[i]->Nhap();
                    continue;
                }
                if (loai_chai == 2) {
                    chai[i] = new ChaiHCN();
                    chai[i]->Nhap();
                    continue;
                }
                if (loai_chai == 3) {
                    chai[i] = new ChaiLP();
                    chai[i]->Nhap();
                    continue;
                }
            }
        }

        float TongTheTich() {
            float tong = 0;
            for (int i = 0; i < so_chai; i++) {
                tong += chai[i]->TheTich();
            }
            return tong/10;
        }

        float TongDienTich() {
            float tong = 0;
            for (int i = 0; i < so_chai; i++) {
                tong += chai[i]->DienTich();
            }
            return tong;
        }

        void Xuat() {
                cout << "Dien tich chai vo: " << TongDienTich() << endl;
                cout << "Luong nuoc tren mat dat: " << TongTheTich() << endl;

        }
};


int main() {
   DapChai dapchai;
    dapchai.Nhap();
    dapchai.Xuat();
    return 0;
}

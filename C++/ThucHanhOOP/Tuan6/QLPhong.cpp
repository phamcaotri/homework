#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Phong {
    protected:
        //int loai_phong; // 1: lythuyet, 2: thuchanh, 3: giangduong
        string ten_phong;
        int tang;
        int so_phong;
        int suc_chua;
    public:
        virtual void Nhap() {
            cin >> ten_phong;
            cin >> tang;
            cin >> so_phong;
            cin >> suc_chua;
        }
        int getSucChua() {
            return suc_chua;
        }
        int getTang() {
            return tang;
        }
        int getSoPhong() {
            return so_phong;
        }
        string getTenPhong() {
            return ten_phong;
        }
};

class PhongLT : public Phong {
    private:
        bool co_may_lanh;
    public:
        void Nhap() override {
            Phong::Nhap();
            cin >> co_may_lanh;
        }

};

class PhongTH : public Phong {
    private:
        int so_may_tinh;
    public:
        void Nhap() override {
            Phong::Nhap();
            cin >> so_may_tinh;
        }

};

class PhongGD : public Phong {
    private:
        int so_may_chieu;
    public:
        void Nhap() override {
            Phong::Nhap();
            cin >> so_may_chieu;
        }

};
class QuanLyPhong {
    private:
        vector<Phong*> ds_phong;
        int suc_chua;

    public:
        void Nhap() {
            int so_phong;
            cin >> so_phong;
            ds_phong.resize(so_phong);
            for (int i = 0; i < so_phong; i++) {
                ds_phong[i] = []() -> Phong* {
                    int loai_phong;
                    cin >> loai_phong;
                    if (loai_phong == 1) {
                        return new PhongLT();
                    } else if (loai_phong == 2) {
                        return new PhongTH();
                    } else {
                        return new PhongGD();
                    }
                }();
                ds_phong[i]->Nhap();
            } 
            cin >> suc_chua;
        }
        void Xuat() {
            cout << TongSucChua() << endl;
            cout << TenPhongKhitNhat() << endl;
        }
        int TongSucChua() {
            int sum = 0;
            for (int i = 0; i < ds_phong.size(); i++) {
                sum += ds_phong[i]->getSucChua();
            }
            return sum;
        }
        string TenPhongKhitNhat() {
            auto DieuKienSort = [](Phong* a, Phong* b) {
                if (a->getTang() == b->getTang()) {
                    if (a->getSoPhong() == b->getSoPhong()) {
                        return a->getSucChua() > b->getSucChua();
                    } else {
                        return a->getSoPhong() < b->getSoPhong();
                    }
                } else {
                    return a->getTang() < b->getTang();
                }
            };
            stable_sort(ds_phong.begin(), ds_phong.end(), DieuKienSort);
            for (int i = 0; i < ds_phong.size(); i++) {
                if (ds_phong[i]->getSucChua() >= suc_chua) {
                    return ds_phong[i]->getTenPhong();
                }
            }
            return "NULL";
        }
};

int main() {
    QuanLyPhong phong;
    phong.Nhap();
    phong.Xuat();    
    return 0;
}


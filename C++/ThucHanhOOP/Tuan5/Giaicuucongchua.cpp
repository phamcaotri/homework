#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class HoangTu {
private:
    int tien;
    int tri_tue;
    int suc_manh;
public:
    void Nhap() {
        cin >> tien >> tri_tue >> suc_manh;
    }
    void Xuat() {
        cout << tien << " " << tri_tue << " " << suc_manh;
    }
    int getTien() {
        return tien;
    }
    int getTriTue() {
        return tri_tue;
    }
    int getSucManh() {
        return suc_manh;
    }
    void setTien(int tien) {
        this->tien = tien;
    }
    void setTriTue(int tri_tue) {
        this->tri_tue = tri_tue;
    }
    void setSucManh(int suc_manh) {
        this->suc_manh = suc_manh;
    }

};

class Cong {
private:
    int loai;
public:
    Cong(int loai) {
        this->loai = loai;
    }
    virtual void Nhap() = 0;
    virtual bool isPass(HoangTu&) = 0;

};

class CongGiaoThuong : public Cong {
private:
    int don_gia;
    int so_hang;
public:
    CongGiaoThuong(int loai) : Cong(loai) {

    }
    void Nhap() override {
        cin >> don_gia >> so_hang;
    }
    bool isPass(HoangTu& h) override {
        if (h.getTien() - don_gia * so_hang < 0) {
            return false;
        }
        h.setTien(h.getTien() - don_gia * so_hang);
        return true;
    }
};

class CongHocThuat : public Cong {
private:
    int chi_so_tri_tue;
public:
    CongHocThuat(int loai) : Cong(loai) {

    }
    void Nhap() {
        cin >> chi_so_tri_tue;
    }
    bool isPass(HoangTu& h) override {
        if (h.getTriTue() < chi_so_tri_tue) {
            return false;
        }
        return true;
    }
};

class CongSucManh : public Cong {
private:
    int chi_so_suc_manh;
public:
    CongSucManh(int loai) : Cong(loai) {

    }
    void Nhap() {
        cin >> chi_so_suc_manh;
    }
    bool isPass(HoangTu& h) override {
        if (h.getSucManh() < chi_so_suc_manh) {
            return false;
        }
        h.setSucManh(h.getSucManh() - chi_so_suc_manh);
        return true;
    }

};

class Game {
private:
    HoangTu hoang_tu;
    vector<Cong*> cong;
public:
    void Nhap() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int loai; cin >> loai;
            if (loai == 1) {
                CongGiaoThuong* c = new CongGiaoThuong(loai);
                c->Nhap();
                cong.push_back(c);
            }
            else if (loai == 2) {
                CongHocThuat* c = new CongHocThuat(loai);
                c->Nhap();
                cong.push_back(c);
            }
            else if (loai == 3) {
                CongSucManh* c = new CongSucManh(loai);
                c->Nhap();
                cong.push_back(c);
            }
        }
        hoang_tu.Nhap();
    }
    void Xuat() {
        for (int i = 0; i < cong.size(); i++) {
            if (!cong[i]->isPass(hoang_tu)) {
                cout << -1;
                return;
            }
        }
        hoang_tu.Xuat();

    }

};

int main() {
    Game game;
    game.Nhap();
    game.Xuat();
    return 0;
}

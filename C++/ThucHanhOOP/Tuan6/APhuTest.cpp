#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <functional>
using namespace std;

class APhu {
    private:
        float hp;
    public:
        virtual void Nhap() {
            cin >> hp;
        }
        float getHp() {
            return hp;
        }
        void changeHp(float x) {
            hp += x;
        }
};

class VuKhi {
    protected:
        float atk;
        int soLuotSuDung;

        APhu* a;
    public:
        VuKhi(APhu* a) {
            this-> a = a;
        }
        virtual void Nhap() {
            cin >> atk;
            cin >> soLuotSuDung;
        }
        virtual float DmgCal() = 0;
        int getSoLuotSuDung() {
            return soLuotSuDung;
        }
};

class Dao : public VuKhi {
    private:
        float chieuDai;
    public:
        using VuKhi::VuKhi;
        void Nhap() override {
            VuKhi::Nhap();
            cin >> chieuDai;
        }
        float DmgCal() override {
            soLuotSuDung--;
            return atk * chieuDai;
        }
};

class CungTen : public VuKhi {
    private:
        int soMuiTen;
    public:
        using VuKhi::VuKhi;
        void Nhap() override {
            VuKhi::Nhap();
            cin >> soMuiTen;
        }
        float DmgCal() override {
            soLuotSuDung -= 2;
            return atk * soMuiTen / 2.0;
        }
};

class TayKhong : public VuKhi {
    public:
        TayKhong(APhu* a) : VuKhi(a) {
            atk = 0;
            soLuotSuDung = 1;
        }
        void Nhap() override {
            return;
        }
        float DmgCal() override {
            float st = 10/100.0 * a->getHp();
            a->changeHp(-st);
            return st;
            
        }
};

class ThuDu {
    protected:
        float hp;
        float atk;
    public:
        virtual void Nhap() {
            cin >> hp;
            cin >> atk;
        }
        virtual float DmgCal() = 0;

        float getHp() {
            return hp;
        }
        void changeHp(float x) {
            hp += x;
        }

};

class BoTot : public ThuDu {
    private:
        int soLanChiuDanh;
    public:
        void Nhap() override {
            ThuDu::Nhap();
            cin >> soLanChiuDanh;
        }
        float DmgCal() override {
            soLanChiuDanh--;
            if (soLanChiuDanh == 0) return 0;
            if (hp <= 0) return 0;
            return atk;
        }
};

class Ho : public ThuDu {
    public:
        void Nhap() override {
            ThuDu::Nhap();
        }
        float DmgCal() override {
            if (hp <= 0) return 0;
            return atk*1.5;
        }
};

class Battle {
    private:
        APhu* a;
        list<VuKhi*> v;
        list<ThuDu*> t;
    public:
        void Nhap() {
            a = new APhu();
            a->Nhap();
            int n; cin >> n;
            for (int i = 0; i < n; i++) {
                VuKhi* vk = [&]() -> VuKhi* {
                    int type; cin >> type;
                    switch (type) {
                        case 1: return new Dao(a);
                        case 2: return new CungTen(a);
                        default: return NULL;
                    }
                }();
                vk->Nhap();
                v.push_back(vk);
            }
            v.push_back(new TayKhong(a));
            int m; cin >> m;
            for (int i = 0; i < m; i++) {
                ThuDu* td = []() -> ThuDu* {
                    int type; cin >> type;
                    switch (type) {
                        case 1: return new BoTot();
                        case 2: return new Ho();
                        default: return NULL;
                    }
                }();
                td->Nhap();
                t.push_back(td);
            }
        }
        bool Action() {
            cout << "Luot\tHp A Phu\tSt A Phu\tHp Thu Du\tSt Thu Du\n";
            int luot = 1;
            while (true) {
                if (a->getHp() <= 0) return false;
                if (t.size() == 0) return true;

                float dmgAPhu = v.front()->DmgCal();
                if (v.front()->getSoLuotSuDung() <= 0) {
                    v.pop_front();
                }
                t.front()->changeHp(-dmgAPhu);
                float dmgThuDu = t.front()->DmgCal();
                Print(luot, dmgAPhu, dmgThuDu);
                luot++;
                if (dmgThuDu <= 0) {
                    t.pop_front();
                    continue;
                }
                a->changeHp(-dmgThuDu);
            }
        }

        void Print(int luot, float dmgAPhu, float dmgThuDu) {
            cout << luot << '\t';
            cout << a->getHp() << "\t\t" ;
            cout << dmgAPhu << "\t\t";
            cout << t.front()->getHp() << "\t\t";
            cout << dmgThuDu << '\n';
        }
        void Xuat() {
            if (Action()) {
                cout << "A Phu chien thang, hp con lai: " << a->getHp();
                cout << ", so luong vu khi con lai: " << v.size()-1;
                
            } else {
                cout << "A Phu that bai, so thu du con lai: " << t.size();
            }
        }
};



int main() {
    Battle bt;
    bt.Nhap();
    bt.Xuat();
    return 0;
}
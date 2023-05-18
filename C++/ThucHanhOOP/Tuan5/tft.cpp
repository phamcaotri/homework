#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Tuong {
    protected:
        int sao;
        int atk;
        int luot;
        int tong_atk;
    public:
        Tuong(int sao = 1, int atk = 0) {
            this-> sao = sao;
            this-> atk = atk;
            luot = 0;
            tong_atk = 0;
        }
        void Nhap() {
            cin >> atk;
        }
        int& getLuot() {
            return luot;
        }
        int& getAtk() {
            return atk;
        }
        int& getTongAtk() {
            return tong_atk;
        }
        int getSao() {
            return sao;
        }
        virtual int Skill(int) = 0;

        virtual Tuong* newTuong(int sao, int atk) = 0;
};

class Shaco : public Tuong {
    public:
        using Tuong::Tuong;
        int Skill(int x) {
            return (atk+x) * 2;
        }
        Shaco* newTuong(int sao, int atk) {
            return new Shaco(sao, atk);
        }

};

class Zed : public Tuong {
    public:
        using Tuong::Tuong;
        int Skill(int x) {
            if (getLuot() % 3 == 0 and getLuot() != 0) {
                return (atk+x) * 3;
            }
            return atk+x;
        }
        Zed* newTuong(int sao, int atk) {
            return new Zed(sao, atk);
        }

};


class Game {
    private:
        int luot;
        vector<multimap<int, Tuong*>> DStuong; // loai, <sao, tuong>
    public:
        Game() {
            luot = 0;
        }
        void Nhap() {
            int n; cin >> n >> luot;
            for (int i = 0; i < n; i++) {
                int loai; cin >> loai;
                DStuong.resize(loai);
                    if (loai == 1) {
                        Shaco* t = new Shaco();
                        t->Nhap();
                        DStuong[0].insert(make_pair(1, t));
                    } else {
                        Zed* t = new Zed();
                        t->Nhap();
                        DStuong[1].insert(make_pair(1, t));
                    }  
            }
            for (int i = 0; i < luot; i++) {
                // int loai; cin >> loai;
                // DStuong.resize(loai);
                // if (n > 0) {
                //     if (loai == 1) {
                //         Shaco* t = new Shaco();
                //         t->Nhap();
                //         DStuong[0].insert(make_pair(1, t));
                //     } else {
                //         Zed* t = new Zed();
                //         t->Nhap();
                //         DStuong[1].insert(make_pair(1, t));
                //     }  
                //     n--;

                // }
                CapNhatLuot();
                NangCap();
                TinhDamage();
                
            }
        }

        void TinhDamage() {
            int atk_bo_sung = 0;
            if (CoDu2LoaiTuong()) {
                atk_bo_sung = 10;
                for (int i = 0; i < DStuong.size(); i++) {
                    for (auto& [sao, tuong] : DStuong[i]) {
                        tuong->getTongAtk() += tuong->Skill(atk_bo_sung);
                    }
                }
            } else {
                for (int i = 0; i < DStuong.size(); i++) {
                    for (auto& [sao, tuong] : DStuong[i]) {
                        tuong->getTongAtk() += tuong->getAtk();
                    }
                }
            }


        }

        bool CoDu2LoaiTuong() {
            if (DStuong.size() >= 2) {
                return true;
            }
            return false;
        }

        void NangCap() {
            for (int i = 0; i < DStuong.size(); i++) {
                if (DStuong[i].count(1) == 3) {
                    int new_atk = 0;
                    for (auto& [sao, tuong] : DStuong[i]) {
                        new_atk += tuong->getAtk();
                    }
                    new_atk *= 2; 
                    DStuong[i].insert(make_pair(2, DStuong[i].begin()->second->newTuong(2, new_atk)));
                    DStuong[i].erase(1);
                }
                if (DStuong[i].count(2) == 3) {
                    int new_atk = 0;
                    for (auto& [sao, tuong] : DStuong[i]) {
                        new_atk += tuong->getAtk();
                    }
                    new_atk *= 3;
                    DStuong[i].erase(2);
                    DStuong[i].insert(make_pair(3, DStuong[i].begin()->second->newTuong(3, new_atk)));
                }
            }
            
        }

        void CapNhatLuot() {
            for (int i = 0; i < DStuong.size(); i++) {
                for (auto& [sao, tuong] : DStuong[i]) {
                    tuong->getLuot()++;
                }
            }
        }
        void Xuat() {
            for (int i = 0; i < DStuong.size(); i++) {
                for (auto& [sao, tuong] : DStuong[i]) {
                    if (i == 0) {
                        cout << "Shaco - " << tuong->getTongAtk() << endl;
                    } else {
                        cout << "Zed - " << tuong->getTongAtk() << endl;
                    }
                }
            }
        }


};

int main() {
    Game g;
    g.Nhap();
    g.Xuat();
    return 0;
}

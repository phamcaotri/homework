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
            if (getLuot() % 3 == 0) {
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
        vector<tuple< int, int, Tuong*>> DStuong; // [stt] <loai, sao, tuong>
    public:
        Game() {
            luot = 0;
        }
        void Nhap() {
            int n; cin >> n >> luot;
            for (int i = 0; i < n; i++) {
                int loai; cin >> loai;
                    if (loai == 1) {
                        Shaco* t = new Shaco();
                        t->Nhap();
                        DStuong.push_back(make_tuple(1, 1, t));
                    } else {
                        Zed* t = new Zed();
                        t->Nhap();
                        DStuong.push_back(make_tuple(2, 1, t));
                    }  
                NangCap();
                //Xuat2();
                // if (CoDu2LoaiTuong()) {
                //     cout << "\nNhan buff 10" << endl;
                // }
            }
            for (int i = 0; i < luot; i++) {
                CapNhatLuot();
                TinhDamage();


                // cout << "Luot " << i+1 << ":" << endl;
                // cout << "Sat thuong: " << endl;
                // Xuat3();
                // cout << "Tong sat thuong: " << endl;
                // Xuat();
                // cout << endl;
                
            }
        }

        void TinhDamage() {
            int atk_bo_sung = 0;
            if (CoDu2LoaiTuong()) {
                atk_bo_sung = 10;
                for (auto& [loai, sao, tuong] : DStuong) {
                    tuong->getTongAtk() += tuong->Skill(atk_bo_sung);
                }
            } else {
                for (auto& [loai, sao, tuong] : DStuong) {
                    tuong->getTongAtk() += tuong->Skill(0);
                }
            }


        }

        bool CoDu2LoaiTuong() {
            if (countTuong(1) >= 1 and countTuong(2) >= 1) {
                return true;
            }
            return false;
        }
        int countTuong(int this_loai, int this_sao) {
            int count = 0;
            for (auto [loai, sao, tuong] : DStuong) {
                if (this_loai == loai and this_sao == sao) {
                    count++;
                }
            }
            return count;
        }
        int countTuong(int this_loai) {
            int count = 0;
            for (auto [loai, sao, tuong] : DStuong) {
                if (this_loai == loai) {
                    count++;
                }
            }
            return count;
        }

        void deleteTuong(int this_loai, int this_sao) {
            int tong_atk = 0;
            int n = 3;
            auto first_it = DStuong.begin();
            for (auto it = DStuong.begin(); it != DStuong.end(); ) {
               auto& [loai, sao, tuong] = *it;
                if (this_loai == loai and this_sao == sao) {
                    tong_atk += tuong->getAtk();
                    if (n == 3) {
                        first_it = DStuong.erase(it);
                    } else {
                        DStuong.erase(it);
                    }
                     
                     
                     n--;
                     if (n == 0) {
                        auto new_tuong = tuong->newTuong(this_sao + 1, tong_atk*(this_sao+1));
                        DStuong.insert(first_it, make_tuple(this_loai, this_sao + 1, new_tuong));
                        return;
                     }
                     it = DStuong.begin();
                } else {
                     it++;
                } 
            }
        }
        void NangCap() {
            for (auto it = DStuong.begin(); it != DStuong.end();) {
                auto [loai, sao, tuong] = *it;
                if (sao == 1) {
                    if (countTuong(loai, 1) == 3) {
                        deleteTuong(loai, 1);
                        it = DStuong.begin();
                        
                    } else {
                        it++;
                    }
                } else if (sao == 2) {
                    if (countTuong(loai, 2) == 3) {
                        deleteTuong(loai, 2);
                        it = DStuong.begin();
                    } else {
                        it++;
                    }
                } else {
                    it++;
                }

            }
        }

        void CapNhatLuot() {
            for (auto& [loai, sao, tuong] : DStuong) {
                tuong->getLuot()++;
            }
        }
        void Xuat() {
            for (auto& [loai, sao, tuong] : DStuong) {
                    if (loai == 1) {
                        cout << "Shaco - " << tuong->getTongAtk() << endl;
                    } else {
                        cout << "Zed - " << tuong->getTongAtk() << endl;
                    }
            }
        }
        void Xuat2() {
            for (auto& [loai, sao, tuong] : DStuong) {
                    if (loai == 1) {
                        cout << tuong->getSao() << "* "<< "Shaco - " << tuong->getAtk() << endl;
                    } else {
                        cout << tuong->getSao() << "* "<< "Zed - " << tuong->getAtk() << endl;
                    }
            }
        }
        void Xuat3() {
            for (auto& [loai, sao, tuong] : DStuong) {
                    if (loai == 1) {
                        cout << tuong->getSao() << "* "<< "Shaco - " << tuong->Skill(10) << endl;
                    } else {
                        cout << tuong->getSao() << "* "<< "Zed - " << tuong->Skill(10) << endl;
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

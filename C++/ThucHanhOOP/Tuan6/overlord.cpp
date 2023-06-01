
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Character {
    protected:
        string name;
        float hp;
        float atk;
        float def;
        vector<int> guild;

    public:
        virtual void Nhap() {
            cin >> name;
            cin >> hp;
            cin >> atk;
            cin >> def;
        }
        void Xuat() {
            cout << name << ' ' << hp << '\n';
        }
        float getAtk() {
            return atk;
        }
        float getDef() {
            return def;
        }
        float getHp() {
            return hp;
        }
        void changeHp(float x) {
            hp += x;
        }
        virtual void UpdateGuild(vector<int> x) {
            guild = x;
        }

};

class NhanLoai : public Character {
    protected:
        string job;
    public:
        void Nhap() override {
            Character::Nhap();
            cin >> job;
        }
};

class Human : public NhanLoai {
};

class Elf : public NhanLoai {
    public:
        void Nhap() override {
            NhanLoai::Nhap();
            def += def*50/100.0;
        }
};
    
class BanNhan : public Character {
    protected:
        string racial;
    public:
        void Nhap() override {
            Character::Nhap();
            cin >> racial;
        }        
};

class Orc : public BanNhan {
    public:
        void Nhap() override {
            BanNhan::Nhap();
            hp += hp*50/100.0;
        }
};

class Golbin : public BanNhan {
    public:
        void Nhap() override {
            BanNhan::Nhap();
            atk += atk*10/100.0;
        }
};

class DiHinh : public Character {
};

class Vampire : public DiHinh {
    public:
        void Nhap() override {
            DiHinh::Nhap();
        }
        void UpdateGuild(vector<int> x) override {
            Character::UpdateGuild(x);
            int soHuman = guild[0] + guild[1];
            hp += soHuman*hp*10/100.0;
        }
};

class Devil : public DiHinh {
    public:
        void Nhap() override {
            Character::Nhap();
        }
        void UpdateGuild(vector<int> x) override {
            Character::UpdateGuild(x);
            int soDevil = guild[5];
            atk += soDevil*atk*10/100.0;
            def += soDevil*def*10/100.0;
        }
};


class BossBattle {
    private:
        vector<Character*> c;
        Character * boss;
    public:
        void Nhap() {
            int n; cin >> n;
            c.resize(n);
            vector<int> guild(6,0);
            for (int i = 0; i < n; i++) {
                c[i] = [ & ]() -> Character* {
                    int loai; cin >> loai;
                    guild[loai-1]++;
                    switch (loai) {
                        case 1: return new Human;
                        case 2: return new Elf;
                        case 3: return new Orc;
                        case 4: return new Golbin;
                        case 5: return new Vampire;
                        case 6: return new Devil;
                        default: return NULL;
                    }
                }();
                c[i]->Nhap();

            }
            for (int i = 0; i < n; i++) {
                c[i]->UpdateGuild(guild);
            }
            boss = new Character;
            boss->Nhap();
            auto HpThapDenCao = [](Character* a, Character* b) {
                return a->getHp() < b->getHp();
            };
            stable_sort(c.begin(), c.end(), HpThapDenCao);
            
        }
        void Xuat() {
            if (Action() == 1) {
                for (int i = 0; i < c.size(); i++) {
                    if (c[i]->getHp() > 0) c[i]->Xuat();
                }
            } else {
                boss->Xuat();
            }
        }
        float DmgCal(Character* a, Character* b) {
            if (a->getHp() <= 0)
                return 0;
            float atk = a->getAtk();
            if (atk == 0) return 0;
            float def = b->getDef();
            float st = atk - def;
            if (st <= 0) return 0;
            return st;
        }

        bool Action() {
            int turn = 1;
            while (turn <= 100) {
                for (int i = 0; i < c.size(); i++) {
                    float stBoss = DmgCal(c[i], boss);
                    boss->changeHp(-stBoss);
                    if (boss->getHp() <= 0) {
                        return 1;
                    }
                }
                Character* cHpThapNhat = [&]() -> Character* {
                    if (c.size() > 0) return c[0];
                    return NULL;
                }();
                if (cHpThapNhat == NULL) return 0;
                float stCharacter = DmgCal(boss, cHpThapNhat);
                cHpThapNhat->changeHp(-stCharacter);
                if (c[0]->getHp() <= 0) {
                    c.erase(c.begin());
                }
                turn ++;
            }
            return 0;
        }
};

int main() {
    BossBattle bt;
    bt.Nhap();
    bt.Xuat();
    return 0;   
}
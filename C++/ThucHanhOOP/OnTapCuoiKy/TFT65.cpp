#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


enum Class {
    CONG_NGHE = 1,
    TIEN_CONG = 2,
};

enum Type {
    DEFAULT = 0,
    DAU_SI = 1,
};

class Character {
    protected:
        string name;
        Type type;
        Class character_class;
        int value;
        float atk;
        float def;
        float total_dmg = 0;

        vector<Character*> team;

    public:
        void input() {
            cin >> atk >> def;
        }
        void output() {
            cout << name << " - sat thuong gay ra: " << total_dmg << endl;
        }
        virtual float skill() = 0;
        int get_value() {
            return value;
        }
        void update_team(vector<Character*> team) {
            this->team = team;
        }
        int count_class() {
            map<string, int> count;
            for (int i = 0; i < team.size(); i++) {
                if (team[i]->character_class == character_class) {
                    count[team[i]->get_name()]++;
                }
            }
            return count.size();
        }
        int count_type() {
            map<string, int> count;
            for (int i = 0; i < team.size(); i++) {
                if (team[i]->type == type) {
                    count[team[i]->get_name()]++;
                }
            }
            return count.size();
        }
        void set_total_dmg(float dmg) {
            total_dmg += dmg;
        }
        string get_name() {
            return name;
        }
};

class HeDauSi {
    public:
        float bonus_def(int numberof_sametype) {
            if (numberof_sametype == 2) {
                return 15;
            }
            if (numberof_sametype >= 3) {
                return 30;
            }
            return 0;
        }

};

class TocTienCong {
    public:
        float bonus_atk(int numberof_sametype) {
            if (numberof_sametype >= 2) {
                return 30;
            }
            return 0;
        }
};

class TocCongNghe {
    public:
        float bonus_atk(int numberof_sametype) {
            if (numberof_sametype >= 2) {
                return 15;
            }
            return 0;
        }
        float bonus_def(int numberof_sametype) {
            if (numberof_sametype >= 2) {
                return 15;
            }
            return 0;
        }
};

class Jarvan : public Character, public HeDauSi, public TocCongNghe {
    public:
        Jarvan() {
            name = "Jarvan";
            type = DAU_SI;
            character_class = CONG_NGHE;
            value = 1;
        }
        float skill() override {
            float new_def = def + HeDauSi::bonus_def(count_type()) + TocCongNghe::bonus_def(count_class());
            return new_def * 2;
        }
};

class Reksai : public Character, public HeDauSi, public TocTienCong {
    private:
        int turn = 0;
    public:
        Reksai() {
            name = "Reksai";
            type = DAU_SI;
            character_class = TIEN_CONG;
            value = 2;
        }
        float skill() override {
            turn++;
            float new_atk = atk + TocTienCong::bonus_atk(count_class());
            if (turn % 4 == 0 and turn != 1) {
                return new_atk * 2;
            }
            return new_atk;
        }
};

class Sivir : public Character, public TocCongNghe {
    public:
        Sivir() {
            name = "Sivir";
            type = DEFAULT;
            character_class = CONG_NGHE;
            value = 4;
        }
        float skill() override {
            float new_atk = atk + TocCongNghe::bonus_atk(count_class());
            return new_atk * 2;
        }
};

class Illaoi : public Character, public HeDauSi, public TocTienCong {
    public:
        Illaoi() {
            name = "Illaoi";
            type = DAU_SI;
            character_class = TIEN_CONG;
            value = 1;
        }
        float skill() override {
            float new_atk = atk + TocTienCong::bonus_atk(count_class());
            float new_def = def + HeDauSi::bonus_def(count_type());
            return (new_atk + new_def) / 2.0;
        }
};

class Battle {
    private:
        vector<Character*> characters;
        int numberof_turns;
    public:
        void input() {
            int character_size;
            cin >> character_size >> numberof_turns;
            for (int i = 0; i < character_size; i++) {
                int type;
                cin >> type;
                Character* c;
                switch (type) {
                    case 1:
                        c = new Jarvan();
                        break;
                    case 2:
                        c = new Reksai();
                        break;
                    case 3:
                        c = new Sivir();
                        break;
                    case 4:
                        c = new Illaoi();
                        break;
                }
                c->input();
                characters.push_back(c);
            }
            for (int i = 0; i < character_size; i++) {
                characters[i]->update_team(characters);
            }
        }
        void output() {
            for (int i = 0; i < numberof_turns; i++) {
                for (int j = 0; j < characters.size(); j++) {
                    characters[j]->set_total_dmg(characters[j]->skill());
                }
            }
            int sum_value = 0;
            for (int i = 0; i < characters.size(); i++) {
                characters[i]->output();
                sum_value += characters[i]->get_value();
            }
            cout << "Tong gia tri: " << sum_value << endl;
        }
};

int main() {
    Battle bt;
    bt.input();
    bt.output();
    return 0;
}

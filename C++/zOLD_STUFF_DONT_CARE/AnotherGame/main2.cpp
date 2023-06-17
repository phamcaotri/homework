#include <bits/stdc++.h>
using namespace std;

const string GAME_DATA_PATH = "game_data.txt";

class Skill {
    private:
        int damage;
        string name;
    public:
        Skill() {
            damage = 0;
            name = "";
        }
        Skill(int damage, string name) {
            this->damage = damage;
            this->name = name;
        }
        int get_damage() {
            return damage;
        }
        string get_name() {
            return name;
        }
};

class Stat {
    private:
        int value;
        int level;
    public:
        Stat() {
            value = 0;
            level = 0;
        }
        Stat(int value, int level) {
            this->value = value;
            this->level = level;
        }
        int get_value() {
            return value;
        }
        int get_level() {
            return level;
        }
        void add_value(int value) {
            this->value += value;
        }
        void add_level(int level) {
            this->level += level;
        }
};

class Character {
    private:
        int hp;
        int atk;
        int def;
        int exp;
        int gold;
    public:
        Character() {
            hp = 0;
            atk = 0;
            def = 0;
            exp = 0;
            gold = 0;
        }
        Character(int hp, int atk, int def, int exp, int gold) {
            this->hp = hp;
            this->atk = atk;
            this->def = def;
            this->exp = exp;
            this->gold = gold;
        }
        void add_exp(int exp) {
            this->exp += exp;
        }
        void add_gold(int gold) {
            this->gold += gold;
        }
        bool is_dead() {
            return hp <= 0;
        }
        int attack(shared_ptr<Character> other) {
            int damage = round(atk * (1.0 - other->get_def() / (20.0 + other->get_def() + exp)));
            if (damage < 0) {
                damage = 0;
            }
            other->add_hp(-damage);
            return damage;
        }

        int get_exp() {
            return exp;
        }
        int get_gold() {
            return gold;
        }
        int get_hp() {
            return hp;
        }
        int get_atk() {
            return atk;
        }
        int get_def() {
            return def;
        }
        void add_hp(int hp) {
            this->hp += hp;
        }
        void add_atk(int atk) {
            this->atk += atk;
        }
        void add_def(int def) {
            this->def += def;
        }
};

class BattleInfo {
    private:
        int exp = 0;
        int gold = 0;
        string result = "";
    public:
        void add(BattleInfo other) {
            exp += other.get_exp();
            gold += other.get_gold();
            result = other.get_result();
        }
        void add(int exp, int gold) {
            this->exp += exp;
            this->gold += gold;
        }
        int get_exp() {
            return exp;
        }
        int get_gold() {
            return gold;
        }
        void set_result(string result) {
            this->result = result;
        }
        string get_result() {
            return result;
        }
};



class GameInterface {
    public:
        void show_upgrades(shared_ptr<Character> player ,vector<string> choices) {
            cout << "Your current stats: " << endl;
            cout << "Hp: " << player->get_hp() << endl;
            cout << "Atk: " << player->get_atk() << endl;
            cout << "Def: " << player->get_def() << endl;
            cout << "\nChoose an upgrade: " << endl;
            for (int i = 0; i < choices.size(); i++) {
                cout << i + 1 << ". " << choices[i] << endl;
            }
        }
        int show_choice(vector<string> choices) {
            int choice;
            do {
                cin >> choice;
            } while (choice < 1 or choice > choices.size());
            return choice - 1;
        }
        void show_result(BattleInfo result) {
            cout << "You got " << result.get_exp() << " exp" << endl;
            cout << "You got " << result.get_gold() << " gold" << endl;
        }
        void show_final_result(BattleInfo result) {
            cout << "You " << result.get_result() << " the game" << endl;
            cout << "You got " << result.get_exp() << " exp" << endl;
            cout << "You got " << result.get_gold() << " gold" << endl;
        }
        int show_battle_choices(vector<shared_ptr<Character>> Enemy) {
            cout << "Choose an enemy: " << endl;
            for (int i = 0; i < Enemy.size(); i++) {
                cout << i + 1 << ". " << Enemy[i]->get_hp() << " hp, " << Enemy[i]->get_atk() << " atk, " << Enemy[i]->get_def() << " def" << endl;
            }
            int choice;
            do {
                cin >> choice;
            } while (choice < 1 or choice > Enemy.size());
            return choice - 1;
        }
        void show_battle_info(shared_ptr<Character> player, vector<shared_ptr<Character>> Enemy) {
            cout << "Your hp: " << player->get_hp() << endl;
            cout << "Your atk: " << player->get_atk() << endl;
            cout << "Your def: " << player->get_def() << endl;
        }
};

class Battle {
    private:
        BattleInfo battle_info;
        GameInterface interface;
        vector<shared_ptr<Character>> Enemy;
    public:
        Battle() {}
        Battle(vector<shared_ptr<Character>> Enemy) {
            this->Enemy = Enemy;
        }
        BattleInfo run(shared_ptr<Character> player) {
            int turn = 0;
            BattleInfo result;
            while (true) {
                turn++;
                if (Enemy.size() == 0) {
                    battle_info.set_result("win");
                    return battle_info;
                }
                if (player->is_dead() or turn > 100) {
                    battle_info.set_result("lose");
                    return battle_info;
                }
                interface.show_battle_info(player, Enemy);
                cout << "\nTurn " << turn << endl;
                cout << "Your turn" << endl;
                int choice = interface.show_battle_choices(Enemy);
                system("cls");
                result = battle(player, Enemy[choice]);
                battle_info.add(result);
                if (Enemy[choice]->is_dead()) {
                    Enemy.erase(Enemy.begin() + choice);
                }
                cout << "Enemy turn" << endl;
                for (int i = 0; i < Enemy.size(); i++) {
                    cout << "Enemy " << i + 1 << " attacks" << endl;
                    result = battle(Enemy[i], player);
                    if (player->is_dead()) {
                        battle_info.set_result("lose");
                        return battle_info;
                    }
                    battle_info.add(result);
                }

            }
        }
        BattleInfo battle(shared_ptr<Character> attacker, shared_ptr<Character> defender) {
            BattleInfo result;
            int damage = attacker->attack(defender);
            cout << "Attacker dealt " << damage << " damage" << endl;
            if (defender->is_dead()) {
                cout << "Defender is dead" << endl;
                result.add(defender->get_exp(), defender->get_gold());
            }
            return result;
        }
};

class FileReader {
    public:

        shared_ptr<Character> get_player_data() {
            shared_ptr<Character> player = make_shared<Character>(100, 10, 10, 0, 0);
            return player;
        }

        vector<shared_ptr<Battle>> get_battle_list_data() {
            vector<shared_ptr<Battle>> battle_list;
            shared_ptr<Character> enemy1 = make_shared<Character>(50, 5, 5, 10, 10);
            shared_ptr<Character> enemy2 = make_shared<Character>(50, 5, 5, 10, 10);
            battle_list.push_back(make_shared<Battle>(vector<shared_ptr<Character>>{enemy1, enemy2}));
            enemy1 = make_shared<Character>(50, 10, 5, 10, 10);
            enemy2 = make_shared<Character>(70, 5, 10, 10, 10);
            battle_list.push_back(make_shared<Battle>(vector<shared_ptr<Character>>{enemy1, enemy2}));
            enemy1 = make_shared<Character>(60, 10, 10, 15, 15);
            enemy2 = make_shared<Character>(100, 5, 10, 25, 25);
            battle_list.push_back(make_shared<Battle>(vector<shared_ptr<Character>>{enemy1, enemy2}));
            enemy1 = make_shared<Character>(150, 5, 10, 30, 30);
            battle_list.push_back(make_shared<Battle>(vector<shared_ptr<Character>>{enemy1}));
            enemy1 = make_shared<Character>(200, 15, 20, 50, 50);
            battle_list.push_back(make_shared<Battle>(vector<shared_ptr<Character>>{enemy1}));
            enemy1 = make_shared<Character>(100, 5, 15, 30, 30);
            enemy2 = make_shared<Character>(100, 5, 15, 30, 30);
            shared_ptr<Character> enemy3 = make_shared<Character>(50, 10, 25, 30, 30);
            battle_list.push_back(make_shared<Battle>(vector<shared_ptr<Character>>{enemy1, enemy2, enemy3}));
            enemy1 = make_shared<Character>(50, 5, 50, 40, 40);
            enemy2 = make_shared<Character>(200, 5, 5, 40, 40);
            enemy3 = make_shared<Character>(50, 10, 25, 30, 30);
            shared_ptr<Character> enemy4 = make_shared<Character>(50, 10, 25, 30, 30);
            battle_list.push_back(make_shared<Battle>(vector<shared_ptr<Character>>{enemy1, enemy2, enemy3, enemy4}));
            enemy1 = make_shared<Character>(500, 20, 0, 70, 70);
            battle_list.push_back(make_shared<Battle>(vector<shared_ptr<Character>>{enemy1}));
            enemy1 = make_shared<Character>(500, 15, 30, 80, 80);
            battle_list.push_back(make_shared<Battle>(vector<shared_ptr<Character>>{enemy1}));
            enemy1 = make_shared<Character>(999, 30, 100, 100, 100);
            battle_list.push_back(make_shared<Battle>(vector<shared_ptr<Character>>{enemy1}));
            return battle_list;
        }
        
};

class UpgradeSystem {
    private:
        vector<string> choices;
    public:
        UpgradeSystem(shared_ptr<Character> player) {
            choices.push_back("atk + " + to_string( (int) round(10 + player->get_exp() * 0.1)));
            choices.push_back("def + " + to_string( (int) round(20 + player->get_exp() * 0.2)));
            choices.push_back("hp + " + to_string( (int) round(50 + player->get_exp() * 0.3)));
        }
        vector<string> get_choices() {
            return choices;
        }
        void upgrade(shared_ptr<Character> player, int choice) {
            if (choice == 0) {
                player->add_atk(round(10 + player->get_exp() * 0.1));
            }
            if (choice == 1) {
                player->add_def(round(20 + player->get_exp() * 0.2));
            }
            if (choice == 2) {
                player->add_hp(round(50 + player->get_exp() * 0.3));
            }
            
        }
};


class Game {
    private:
        shared_ptr<Character> player;
        vector<shared_ptr<Battle>> battle_list;
        BattleInfo final_result;
        GameInterface interface;
    public:
        void init(string path) {
            FileReader reader;
            player = reader.get_player_data();
            for (auto& battle_data : reader.get_battle_list_data()) {
                battle_list.push_back(battle_data);
            }
        }
        void run() {
            for (auto& battle : battle_list) {
                UpgradeSystem upgrade_system(player);
                interface.show_upgrades(player, upgrade_system.get_choices());
                int choice = interface.show_choice(upgrade_system.get_choices());
                upgrade_system.upgrade(player, choice);
                BattleInfo result = battle->run(player);
                final_result.add(result);
                if (result.get_result() == "lose") {
                    break;
                }
                interface.show_result(result);
                player->add_exp(result.get_exp());
                player->add_gold(result.get_gold());

            }
            interface.show_final_result(final_result);
        }
};

int main() {
    Game game;
    game.init(GAME_DATA_PATH);
    game.run();
}
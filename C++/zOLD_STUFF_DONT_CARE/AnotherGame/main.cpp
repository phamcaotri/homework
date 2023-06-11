#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <chrono>
#include <thread>
#include <utility>
#include <map>
using namespace std;

const string MAIN_DATA_FILE = "main_data.txt";


class FileReader {
    protected:
        ifstream file;
        int pos = 0;
    public:
        FileReader(string file_name) {
            file.open(file_name);
        }
        ~FileReader() {
            file.close();
        }
        virtual string read() = 0;

        streampos get_pos() {
            return pos;
        }
        void set_pos(int pos) {
            this->pos = pos;
        }
        void reset_pos() {
            pos = 0;
        }
        streampos go_to_string(string str) {
            
        }
        streampos go_to_line(int line) {
        }
};

class ReadAll : public FileReader {
    private:
        const char COMMENT_CHAR = '#';
    public:
        ReadAll(string file_name) : FileReader(file_name) {}
        string read() override {
            string data;
            char ch;
            while (file.get(ch)) {
                if (ch == COMMENT_CHAR) {
                    file.ignore(1000, '\n');
                    continue;
                }
                data += ch;
            }
            return data;
        }
};

class ReadLine : public FileReader {
    public:
        ReadLine(string file_name) : FileReader(file_name) {}
        string read() override {
            string line;
            getline(file, line);
            return line;
        }
};

class ReadUntil : public FileReader {
    private:
        char end_char;
    public:
        ReadUntil(string file_name, char end_char) : FileReader(file_name) {
            this->end_char = end_char;
        }
        string read() override {
            string data;
            char ch;
            while (file.get(ch)) {
                if (ch == end_char) {
                    break;
                }
                data += ch;
            }
            return data;
        }
};



class FileWriter {
    private:
        ofstream file;
        string file_name;
    public:
        FileWriter(string file_name) {
            this->file_name = file_name;
        }
        ~FileWriter() {
            file.close();
        }
        void write(string data) {
            file.open(file_name);
            file << data;
        }
};

#define GREEN(x) "\033[32m" x "\033[0m"
#define RED(x) "\033[31m" x "\033[0m"
#define BLUE(x) "\033[34m" x "\033[0m"
#define YELLOW(x) "\033[33m" x "\033[0m"
#define MAGENTA(x) "\033[35m" x "\033[0m"
#define CYAN(x) "\033[36m" x "\033[0m"

typedef function<bool(string&)> TestFunc;;
class Test {
    private:
        vector<pair<string, TestFunc>> tests;
        int passed = 0;
        int failed = 0;
    public:
        void init() {
            passed = 0;
            failed = 0;
            tests.clear();
        }
        void add_list(vector<pair<string, TestFunc>>& list) {
            for (int i = 0; i < list.size(); i++) {
                tests.push_back(list[i]);
            }
        }
        void run() {
            vector<pair<string, string>> failed_tests;
            cout << "===============================" << endl;
            for (int i = 0; i < tests.size(); i++) {
                auto [name, func] = tests[i];
                string error_msg = "";

                cout << "[RUN TEST " << i + 1 << "/" << tests.size() << "] ";
                auto start = chrono::high_resolution_clock::now();
                if ((func)(error_msg)) {
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
                    cout << GREEN("[PASSED] ") << " " << name << " " << duration.count() << " ms" << endl;
                    passed++;
                } else {

                    cout << RED("[FAILED] ") << " " << name << endl;
                    failed_tests.push_back({name, error_msg});
                    failed++;
                }
            }
            cout << "===============================" << endl;
            cout << "FAILED TESTS: " << failed_tests.size() << endl;
            for (int i = 0; i < failed_tests.size(); i++) {
                auto [name, error_msg] = failed_tests[i];
                cout << RED("[FAILED] ") << " " << name << endl;
                cout << error_msg << endl;
            }

            cout << "===============================" << endl;
            cout << "TOTAL TESTS: " << tests.size() << endl;
            cout << GREEN("PASSED: ") << passed << endl;
            cout << RED("FAILED: ") << failed << endl;
            cout << "===============================" << endl;
        }
};

const string UNIT_TEST_READFILE = "unit_test_readfile.txt";
const string UNIT_TEST_WRITEFILE = "unit_test_writefile.txt";


bool unit_test_readall(string& msg) {
    string expected = "THIS IS LINE 1\nthis is line 3";
    ReadAll reader(UNIT_TEST_READFILE);
    string data = reader.read();
    if (data == expected) {
        return true;
    }
    msg = "Expected:\n" + expected + "\nGot:\n" + data; 
    msg += "\nFile: " + UNIT_TEST_READFILE;
    return false;
}

bool unit_test_readline(string& msg) {
    string expected = "THIS IS LINE 1";
    ReadLine reader(UNIT_TEST_READFILE);
    string data = reader.read();
    if (data == expected) {
        return true;
    }
    msg = "Expected: " + expected + "\nGot: " + data;
    msg += "\nFile: " + UNIT_TEST_READFILE;
    return false;
}

bool unit_test_readuntil(string& msg) {
    string expected = "THIS IS LINE ";
    ReadUntil reader(UNIT_TEST_READFILE, '1');
    string data = reader.read();
    if (data == expected) {
        return true;
    }
    msg = "Expected: " + expected + "\nGot: " + data;
    msg += "\nFile: " + UNIT_TEST_READFILE;
    return false;
}
bool unit_test_writefile(string& msg) {
    string expected = "THIS IS LINE 1\nthis is line 3";
    {
        FileWriter writer(UNIT_TEST_WRITEFILE);
        writer.write("THIS IS LINE 1\n");
        writer.write("# THIS IS LINE 2\n");
        writer.write("this is line 3");
    }
    ReadAll reader(UNIT_TEST_WRITEFILE);
    string data = reader.read();
    if (data == expected) {
        FileWriter writer(UNIT_TEST_WRITEFILE);
        writer.write("");
        return true;
    }
    msg = "Expected:\n" + expected + "\nGot:\n" + data; 
    msg += "\nFile: " + UNIT_TEST_WRITEFILE;
    return false;
}

vector<pair<string, TestFunc>> test_funcs = {
    {"ReadAll", unit_test_readall},
    {"ReadLine", unit_test_readline},
    {"ReadUntil", unit_test_readuntil},
    {"WriteFile", unit_test_writefile},
};

class BasicInfo {
    private:
        string name;
        string description;
        string image;
    public:
        BasicInfo() {
            name = "";
            description = "";
            image = "";
        }
        BasicInfo(string name, string description = "", string image = "") {
            this->name = name;
            this->description = description;
            this->image = image;
        }
        string get_name() {
            return name;
        }
        string get_description() {
            return description;
        }
        string get_image() {
            return image;
        }
};

class StastInfo {
    private:
        int hp;
        int mp;
        int attack;
        int defense;
        int speed;
    public:
        StastInfo() {
            hp = 0;
            mp = 0;
            attack = 0;
            defense = 0;
            speed = 0;
        }
        StastInfo(int hp, int mp, int attack, int defense, int speed) {
            this->hp = hp;
            this->mp = mp;
            this->attack = attack;
            this->defense = defense;
            this->speed = speed;
        }
        int get_hp() {
            return hp;
        }
        int get_mp() {
            return mp;
        }
        int get_attack() {
            return attack;
        }
        int get_defense() {
            return defense;
        }
        int get_speed() {
            return speed;
        }

};

class Skill {
    protected:
        BasicInfo basic_info;
        int mp_cost;
        int cooldown;
        int level;
    public:
        Skill () {
            mp_cost = 0;
            cooldown = 0;
            level = 0;
        }
        Skill(BasicInfo basic_info, int mp_cost, int cooldown, int level) {
            this->basic_info = basic_info;
            this->mp_cost = mp_cost;
            this->cooldown = cooldown;
            this->level = level;
        }
        Skill(string name, string description, int damage, int mp_cost) {
            this->basic_info = BasicInfo(name, description);
            this->mp_cost = mp_cost;
            this->cooldown = cooldown;
            this->level = level;
        }
};

class GameData {
    private:
        string file_name;
        ReadUntil reader;
        //FileWriter writer;
    public:
        GameData(string file_name) : reader(file_name, '\n') {
            this->file_name = file_name;
        }
        BasicInfo get_player_basic_info() {
            streampos pos = reader.go_to_string("PLAYER_INFO");
            string name = reader.read(pos);
            string description = reader.read(pos);
            string image = reader.read(pos);
            return BasicInfo(name, description, image);
        }
        StastInfo get_player_stats_info() {
            streampos pos = reader.go_to_string("PLAYER_STATS");
            int hp = stoi(reader.read(pos));
            int mp = stoi(reader.read(pos));
            int attack = stoi(reader.read(pos));
            int defense = stoi(reader.read(pos));
            int speed = stoi(reader.read(pos));
            return StastInfo(hp, mp, attack, defense, speed);
        }        
        vector<Skill> get_player_skills() {
            ReadUntil reader(file_name, '\n');
            streampos pos = reader.go_to_string("PLAYER_SKILLS");
            vector<Skill> skills;
            string name = reader.read(pos);
            string description = reader.read(pos);
            string image = reader.read(pos);
            int skill_count = stoi(reader.read(pos));
            for (int i = 0; i < skill_count; i++) {
                string name = reader.read(pos);
                string description = reader.read(pos);
                int damage = stoi(reader.read(pos));
                int mp_cost = stoi(reader.read(pos));
                skills.push_back(Skill(name, description, damage, mp_cost));
            }
            return skills;
        }

};

class Character {
    protected:
        BasicInfo basic_info;
        StastInfo stast_info;
        vector<Skill> skills;
    public:
        Character() {
            basic_info = BasicInfo();
            stast_info = StastInfo();
            skills.clear();
        }
        Character(BasicInfo basic_info, StastInfo stast_info, vector<Skill> skills) {
            this->basic_info = basic_info;
            this->stast_info = stast_info;
            this->skills = skills;
        }
        BasicInfo get_basic_info() {
            return basic_info;
        }
        StastInfo get_stast_info() {
            return stast_info;
        }
        vector<Skill> get_skills() {
            return skills;
        }
        void set_basic_info(BasicInfo basic_info) {
            this->basic_info = basic_info;
        }
        void set_stast_info(StastInfo stast_info) {
            this->stast_info = stast_info;
        }
        void set_skills(vector<Skill> skills) {
            this->skills = skills;
        }
        void add_skill(Skill skill) {
            skills.push_back(skill);
        }


};

class SingleTargetSkill {
    protected:
        Character* target;
    public:
        SingleTargetSkill() {
            target = NULL;
        }
        SingleTargetSkill(Character* target) {
            this->target = target;
        }
        Character* get_target() {
            return target;
        }
};

class MultiTargetSkill {
    protected:
        vector<Character*> targets;
    public:
        MultiTargetSkill() {
            targets.clear();
        }
        MultiTargetSkill(vector<Character*> targets) {
            this->targets = targets;
        }
        vector<Character*> get_targets() {
            return targets;
        }
};

class BuffSkill : public Skill, public SingleTargetSkill {
    protected:
        int duration;
    public:
        BuffSkill(BasicInfo basic_info, int mp_cost, int cooldown, int level, int duration) : Skill(basic_info, mp_cost, cooldown, level) {
            this->duration = duration;
        }
        int get_duration() {
            return duration;
        }
};

class MultiBuffSkill : public Skill, public MultiTargetSkill {
    protected:
        int duration;
    public:
        MultiBuffSkill(BasicInfo basic_info, int mp_cost, int cooldown, int level, int duration) : Skill(basic_info, mp_cost, cooldown, level) {
            this->duration = duration;
        }
        int get_duration() {
            return duration;
        }
};

class DebuffSkill : public Skill, public SingleTargetSkill {
    protected:
        int duration;
    public:
        DebuffSkill(BasicInfo basic_info, int mp_cost, int cooldown, int level, int duration) : Skill(basic_info, mp_cost, cooldown, level) {
            this->duration = duration;
        }
        int get_duration() {
            return duration;
        }
};

class MultiDebuffSkill : public Skill, public MultiTargetSkill {
    protected:
        int duration;
    public:
        MultiDebuffSkill(BasicInfo basic_info, int mp_cost, int cooldown, int level, int duration) : Skill(basic_info, mp_cost, cooldown, level) {
            this->duration = duration;
        }
        int get_duration() {
            return duration;
        }
};

class AttackSkill : public Skill, public SingleTargetSkill {
    protected:
        int damage;
    public:
        AttackSkill(BasicInfo basic_info, int mp_cost, int cooldown, int level, int damage) : Skill(basic_info, mp_cost, cooldown, level) {
            this->damage = damage;
        }
        int get_damage() {
            return damage;
        }
};

class MultiAttackSkill : public Skill, public MultiTargetSkill {
    protected:
        int damage;
    public:
        MultiAttackSkill(BasicInfo basic_info, int mp_cost, int cooldown, int level, int damage) : Skill(basic_info, mp_cost, cooldown, level) {
            this->damage = damage;
        }
        int get_damage() {
            return damage;
        }
};

class HealSkill : public Skill, public SingleTargetSkill {
    protected:
        int heal;
    public:
        HealSkill(BasicInfo basic_info, int mp_cost, int cooldown, int level, int heal) : Skill(basic_info, mp_cost, cooldown, level) {
            this->heal = heal;
        }
        int get_heal() {
            return heal;
        }
};

class MultiHealSkill : public Skill, public MultiTargetSkill {
    protected:
        int heal;
    public:
        MultiHealSkill(BasicInfo basic_info, int mp_cost, int cooldown, int level, int heal) : Skill(basic_info, mp_cost, cooldown, level) {
            this->heal = heal;
        }
        int get_heal() {
            return heal;
        }
};

class PassiveSkill : public Skill, public SingleTargetSkill {
    protected:
        int duration;
    public:
        PassiveSkill(BasicInfo basic_info, int mp_cost, int cooldown, int level, int duration) : Skill(basic_info, mp_cost, cooldown, level) {
            this->duration = duration;
        }
        int get_duration() {
            return duration;
        }
};

class ShieldSkill : public Skill, public SingleTargetSkill {
    protected:
        int duration;
        int shield;
    public:
        ShieldSkill(BasicInfo basic_info, int mp_cost, int cooldown, int level, int duration, int shield) : Skill(basic_info, mp_cost, cooldown, level) {
            this->duration = duration;
            this->shield = shield;
        }
        int get_duration() {
            return duration;
        }
        int get_shield() {
            return shield;
        }
};

class MultiShieldSkill : public Skill, public MultiTargetSkill {
    protected:
        int duration;
        int shield;
    public:
        MultiShieldSkill(BasicInfo basic_info, int mp_cost, int cooldown, int level, int duration, int shield) : Skill(basic_info, mp_cost, cooldown, level) {
            this->duration = duration;
            this->shield = shield;
        }
        int get_duration() {
            return duration;
        }
        int get_shield() {
            return shield;
        }
};

class BasicAttack : public AttackSkill {
    public:
        using AttackSkill::AttackSkill;
};





class DamageCalculator {
    public:
        static int calculate_damage(Character* attacker, Character* defender, AttackSkill* skill) {
            int damage = skill->get_damage();
            damage += attacker->get_stast_info().get_attack();
            damage -= defender->get_stast_info().get_defense();
            return damage;
        }
};

class Player : public Character {
    public:
        using Character::Character;
};

class Enemy : public Character {
    public:
        using Character::Character;
};

class CharacterFactory {
    // private:
    //     GameData game_data;
    // public:
    //     CharacterFactory(GameData game_data) {
    //         this->game_data = game_data;
    //     }
    //     Player create_player() {

    //     }
    //     Enemy create_enemy() {

    //     }
};

class SkillFactory {
    // private:
    //     GameData game_data;
    // public:
    //     SkillFactory(GameData game_data) {
    //         this->game_data = game_data;
    //     }
    //     Skill create_skill(string skill_name) {

    //     }
};

class Battle {
    // private:
    //     Player player;
    //     vector<Enemy> enemies;
    // public:
    //     Battle(Player player, vector<Enemy> enemies) {
    //         this->player = player;
    //         this->enemies = enemies;
    //     }
    //     void run() {

    //     }
};

class Game {
    private:
        GameData* game_data;
        Player* player;
        vector<Enemy*> enemies;
    public:
        void init(string file_name) {
            game_data = new GameData(file_name);
            player = new Player(game_data->get_player_basic_info(), game_data->get_player_stats_info(), game_data->get_player_skills());
            enemies.clear();
        }
        void run() {

        }
};

int main() {
    Test test;
    test.init();
    test.add_list(test_funcs);
    test.run();


    Game game;
    game.init(MAIN_DATA_FILE);
    game.run();


    return 0;
}


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
    public:
        FileReader(string file_name) {
            file.open(file_name);
            if (!file.is_open()) {
                cout << "Error opening file: " << file_name << endl;
                exit(1);
            }
        }
        ~FileReader() {
            file.close();
        }
        virtual string read() = 0;

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
            file.open(file_name);
        }
        ~FileWriter() {
            file.close();
        }
        void write(string data) {
            file << data;
        }
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
        void change_hp(int value) {
            hp += value;
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

class Character;


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
        Skill(string name, string description, int mp_cost, int cooldown, int level) {
            this->basic_info = BasicInfo(name, description);
            this->mp_cost = mp_cost;
            this->cooldown = cooldown;
            this->level = level;
        }
        void apply(Character* character) {
            //
        }
        string get_name() {
            return basic_info.get_name();
        }
};

class Team {
    private:
        string name;
        list<Character*> characters;
    public:
        void add_character(Character* character) {
            characters.push_back(character);
        }
        void remove_character(Character* character) {
            characters.remove(character);
        }
        void skill_apply(Skill* skill) {
            for (auto character : characters) {
                skill->apply(character);
            }
        }

};



class Character {
    protected:
        BasicInfo basic_info;
        StastInfo stast_info;
        list<Skill*> skills;
    public:
        Character() {
            basic_info = BasicInfo();
            stast_info = StastInfo();
            skills.clear();
        }
        Character(BasicInfo basic_info, StastInfo stast_info, list<Skill*> skills) {
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
        list<Skill*> get_skills() {
            return skills;
        }
        void set_basic_info(BasicInfo basic_info) {
            this->basic_info = basic_info;
        }
        void set_stast_info(StastInfo stast_info) {
            this->stast_info = stast_info;
        }
        void set_skills(list<Skill*> skills) {
            this->skills = skills;
        }
        void add_skill(Skill* skill) {
            skills.push_back(skill);
        }
        void remove_skill(Skill* skill) {
            skills.remove(skill);
        }
        void skill_apply(Skill* skill) {
            skill->apply(this);
        }
        void use_skill(int index, Character* character) {
            skills[index]->apply(character);
        }
        string get_name() {
            return basic_info.get_name();
        }
        void attack(Character* character) {
            character->be_attacked(stast_info.get_attack());
        }
        void be_attacked(int attack) {
            stast_info.change_hp(-attack);
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

class DataProcess {
    private:
        string data;
        int pos;
    public:
        DataProcess() {
            data = "";
            pos = 0;
        }
        DataProcess(string data) {
            this->data = data;
            pos = 0;
        }
        void set_data(string data) {
            this->data = data;
        }
        void reset_pos() {
            pos = 0;
        }
        string getline() {
            string line = "";
            while (data[pos] != '\n' && pos < data.length()) {
                line += data[pos];
                pos++;
            }
            pos++;
            return line;
        }
        // this brings pos to the end of the given string, or the end of the data if the string is not found
        void go_to_string(string str) {
            pos = data.find(str);
            if (pos == string::npos) {
                pos = data.length();
                return;
            }
            pos += str.length();
        }

};

class GameData {
    private:
        DataProcess data;
        BasicInfo get_character_basic_info(string header) {
            data.reset_pos();
            data.go_to_string(header);
            string name = data.getline();
            string description = data.getline();
            string image = data.getline(); 
            return BasicInfo(name, description, image);
        }
        StastInfo get_character_stats_info(string header) {
            data.reset_pos();
            data.go_to_string(header);
            int hp = stoi(data.getline());
            int mp = stoi(data.getline());
            int attack = stoi(data.getline());
            int defense = stoi(data.getline());
            int speed = stoi(data.getline());
            return StastInfo(hp, mp, attack, defense, speed);
        }        
        list<Skill*> get_character_skills(string header) {
            data.reset_pos();
            data.go_to_string(header);
            list<Skill*> skills;
            int skill_count = stoi(data.getline());
            for (int i = 0; i < skill_count; i++) {
                string name = data.getline();
                string description = data.getline();
                int cooldown = stoi(data.getline());
                int mp_cost = stoi(data.getline());
                int level = stoi(data.getline());
                skills.push_back(new Skill(BasicInfo(name, description, ""), mp_cost, cooldown, level));
            }
            return skills;
        }
    public:
        GameData(string file_name) {
            ReadAll reader(file_name);
            data.set_data(reader.read());
        }
        Player get_player_info() {
            BasicInfo basic_info = get_character_basic_info("PLAYER_INFO\n");
            StastInfo stats_info = get_character_stats_info("PLAYER_STATS\n");
            list<Skill*> skills = get_character_skills("PLAYER_SKILLS\n");
            return Player(basic_info, stats_info, skills);
        }

        vector<Enemy*> get_enemies_info() {
            vector<Enemy*> enemies;
            data.reset_pos();
            data.go_to_string("ENEMIES\n");
            int enemy_count = stoi(data.getline());
            for (int i = 0; i < enemy_count; i++) {
                BasicInfo basic_info = get_character_basic_info("ENEMY_INFO\n");
                StastInfo stats_info = get_character_stats_info("ENEMY_STATS\n");
                list<Skill*> skills = get_character_skills("ENEMY_SKILLS\n");
                enemies.push_back(new Enemy(basic_info, stats_info, skills));
            }
            return enemies;
        }
};

class Battle {
        private:
            Player* player;
            vector<Enemy*> enemies;
        public:
            Battle(Player* player, vector<Enemy*> enemies) {
                this->player = player;
                this->enemies = enemies;
            }
            void run() {
                cout << "Battle started!" << endl;
                cout << "Player: " << player->get_name() << endl;
                cout << "Enemies: " << endl;
                for (int i = 0; i < enemies.size(); i++) {
                    cout << enemies[i]->get_name() << endl;
                }
                while (true) {
                    cout << "What do you want to do?" << endl;
                    cout << "1. Attack" << endl;
                    cout << "2. Skills" << endl;
                    cout << "3. Items" << endl;
                    cout << "4. Run" << endl;
                    int choice;
                    cin >> choice;
                    if (choice == 1) {
                        cout << "Who do you want to attack?" << endl;
                        for (int i = 0; i < enemies.size(); i++) {
                            cout << i + 1 << ". " << enemies[i]->get_name() << endl;
                        }
                        int enemy_choice;
                        cin >> enemy_choice;
                        player->attack(enemies[enemy_choice - 1]);
                        for (int i = 0; i < enemies.size(); i++) {
                            enemies[i]->attack(player);
                        }
                    }
                    else if (choice == 2) {
                        cout << "Which skill do you want to use?" << endl;
                        list<Skill*> skills = player->get_skills();
                        int i = 1;
                        for (auto it = skills.begin(); it != skills.end(); it++) {
                            cout << i << ". " << (*it)->get_name() << endl;
                            i++;
                        }
                        int skill_choice;
                        cin >> skill_choice;
                        player->use_skill(skills.begin(), skill_choice - 1, enemies);
                        for (int i = 0; i < enemies.size(); i++) {
                            enemies[i]->attack(player);
                        }
                    }
                    else if (choice == 3) {
                        cout << "Which item do you want to use?" << endl;
                        list<Item*> items = player->get_items();
                        int i = 1;
                        for (auto it = items.begin(); it != items.end(); it++) {
                            cout << i << ". " << (*it)->get_name() << endl;
                            i++;
                        }
                        int item_choice;
                        cin >> item_choice;
                        player->use_item(items.begin(), item_choice - 1);
                        for (int i = 0; i < enemies.size(); i++) {
                            enemies[i]->attack(player);
                        }
                    }
                    else if (choice == 4) {
                        cout << "You ran away!" << endl;
                        break;
                    }
                    else {
                        cout << "Invalid choice!" << endl;
                    }
                }
            }
};

class Game {
    private:
        GameData* game_data;
        Player* player;
        vector<Enemy*> enemies;
    public:
        void init(string file_name) {
            game_data = new GameData(file_name);
            player = new Player(game_data->get_player_info());
            enemies = game_data->get_enemies_info();
        }
        void run() {
            Battle battle(player, enemies);
            battle.run();
        }
};


#define GREEN(x) "\033[32m" x "\033[0m"
#define RED(x) "\033[31m" x "\033[0m"
#define BLUE(x) "\033[34m" x "\033[0m"
#define YELLOW(x) "\033[33m" x "\033[0m"
#define MAGENTA(x) "\033[35m" x "\033[0m"
#define CYAN(x) "\033[36m" x "\033[0m"

typedef function<bool(string&)> TestFunc;
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

bool check_main_data_valid(string& msg) {
    ReadAll reader(MAIN_DATA_FILE);
    string data = reader.read();
    if (data.size() == 0) {
        msg = "File is empty";
        return false;
    }
    if (data.find("PLAYER_INFO") == string::npos || data.find("PLAYER_STATS") == string::npos || data.find("PLAYER_SKILLS") == string::npos) {
        msg = "File does not contain valid player data";
        return false;
    }
    return true;
}

vector<pair<string, TestFunc>> test_funcs = {
        {"ReadAll", unit_test_readall},
        {"ReadLine", unit_test_readline},
        {"ReadUntil", unit_test_readuntil},
        {"WriteFile", unit_test_writefile},
        {"CheckMainDataValid", check_main_data_valid},
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


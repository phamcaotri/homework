#ifndef WINDOWS_H
#define WINDOWS_H

#include <iostream>
#include <string>
#include <vector>
#include "Constant.h"
#include "GameInterface.h"
using std::cout, std::endl, std::string, std::vector;
class GameInterface;
// return pointer to the function option
class Option {
    private:
        string name;
        void (GameInterface::*function)();
    public:
        Option() {}
        Option(string name, void (GameInterface::*function)()) {
            this->name = name;
            this->function = function;
        }
        string getName() {
            return name;
        }
        void (GameInterface::*getFunction())() {
            return function;
        }
};

class Windows {
    private:
        string title;
        vector<string> menu_options;
    public:
        Windows(string title = DEFAULT_NONAME) {
            this->title = title;
        }
        void clearScreen() {
            cout << "\033[2J\033[1;1H";
        }
        int getNumberOfMenuOptions() {
            return menu_options.size();
        }
        void printTitle() {
            cout << "==============================" << endl;
            cout << title << endl;
            cout << "==============================" << endl;
        }
        void showMenu() {
            cout << "==============================" << endl;
            for (int i = 0; i < menu_options.size(); i++) {
                cout << i + 1 << ". " << menu_options[i] << endl;
            }
        }
        void addMenuOption(string option) {
            menu_options.push_back(option);
        }
};

#endif
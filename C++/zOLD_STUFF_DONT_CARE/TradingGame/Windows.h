#ifndef WINDOWS_H
#define WINDOWS_H

#include <iostream>
#include <string>
#include <vector>
#include "Constant.h"
#include "GameInterface.h"
using std::cout, std::endl, std::string, std::vector;

class Windows {
    private:
        string title;
        vector<string> menu_options;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        Windows(string title = DEFAULT_NONAME) {
            this->title = title;
        }
// ------------------------- GETTER -------------------------
        int getNumberOfMenuOptions() {
            return menu_options.size();
        }
        void addMenuOption(string option) {
            menu_options.push_back(option);
        }
// ------------------------- METHOD -------------------------
        void clearScreen() {
            cout << "\033[2J\033[1;1H";
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
            cout << "==============================" << endl;
        }
        void pause() {
            cout << "==============================" << endl;
            cout << "Press any key to continue..." << endl;
        }

};

#endif
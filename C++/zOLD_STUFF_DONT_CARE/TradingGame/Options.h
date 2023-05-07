#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include <vector>
using std::string, std::vector;

#include "Constant.h"
#include "UserInput.h"

template <class Default>
class Options {
    private:
        vector<std::pair<string, bool (Default::*)(int)>> options;
        std::pair<string, bool (Default::*)(int)> option_zero;
    public:
// ------------------------- CONSTRUCTOR -------------------------
        Options() {
            options = vector<std::pair<string, bool (Default::*)(int)>>();
        }
        Options(vector<std::pair<string, bool (Default::*)(int)>> options) {
            this->options = options;
        }
        Options(Options& options) {
            this->options = options.options;
        }
// ------------------------- GETTERS, SETTERS ---------------------
        string getOptionName(int index) {
            if (index < 0 || index >= options.size()) {
                return "";
            }
            return options[index].first;
        }
        int size() {
            return options.size();
        }
        bool getChoice(Default* object, int parameter = 0) {
            cout << "==============================" << endl;
            showOptions();
            cout << "==============================" << endl;
            cout << "Enter choice: ";
            int choice;
            UserInput input;
            input.getInt(choice,0);
            clearScreen();
            bool isReturn = run(choice-1,object, parameter);
            if (isReturn) {
                return RETURN;
            } else {
                return NO_RETURN;
            }
        }
// ------------------------- ADD, REMOVE --------------------------
        void addOption(string option, bool (Default::*function)(int), bool isZero = false) {
            if (isZero) {
                option_zero = std::make_pair(option, function);
            } else {
                options.push_back(std::make_pair(option, function));
            }
        }
        void removeOption(string option) {
            for (int i = 0; i < options.size(); i++) {
                if (options[i].first == option) {
                    options.erase(options.begin() + i);
                }
            }
        }
// ------------------------- PRINT --------------------------
        
        void clearScreen() {
            cout << "\033[2J\033[1;1H";
        }
        void showOptions() {
            for (int i = 0; i < options.size(); i++) {
                cout << i+1 << ". " << options[i].first << endl;
            }
            if (option_zero.first != "") {
                cout << "0. " << option_zero.first << endl;
            }
        }
        bool run(int index, Default* object, int parameter = 0) {
            if (index < 0 || index >= options.size()) {
                return RETURN;
            }
            return (object->*options[index].second)(parameter);
        }
};
#endif
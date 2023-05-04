#ifndef USERINPUT_H
#define USERINPUT_H

#include <iostream>
#include <string>
#include <vector>
using std::cin, std::cout, std::endl, std::string, std::vector;

class UserInput {
    private:
        string raw_input;
        vector<string> prased_input;
    public:
        UserInput() {}
        void getRawInput() {
            getline(cin, raw_input);
        }
        void praseInput() {
            prased_input.clear();
            string temp = "";
            for (int i = 0; i < raw_input.length(); i++) {
                if (raw_input[i] == ' ') {
                    prased_input.push_back(temp);
                    temp = "";
                } else {
                    temp += raw_input[i];
                }
            }
            prased_input.push_back(temp);
        }
        vector<string> getInput() {
            getRawInput();
            praseInput();
            return prased_input;
        }
        int getInt() {
            int result;
            cin >> result;
            cin.ignore();
            return result;
        }


};
#endif
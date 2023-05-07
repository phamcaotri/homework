#ifndef USERINPUT_H
#define USERINPUT_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::cin, std::cout, std::endl, std::string, std::vector;

class UserInput {
    private:
        string input;
        std::stringstream ss;
    public:
// ------------------------- METHOD -------------------------
        void getInput() {
            input = "";
            getline(cin, input);
            ss = std::stringstream(input);
        }
        // this will prevent the user input breaking the game
        void getInt(int& output) {
            getInput();
            ss >> output;
            if (ss.fail()) {
                cout << "Invalid input, try again:" << endl;
                return getInt(output);
            }
        }
        void getInt(int& output, int defaultValue) {
            getInput();
            ss >> output;
            if (ss.fail()) {
                output = defaultValue;
            }
        }
        void getPairInt(int& output1, int& output2) {
            getInput();
            ss >> output1;
            if (ss.fail()) {
                cout << "Invalid input, try again:" << endl;
                return getPairInt(output1, output2);
            }
            if (ss.eof()) {
                return;
            } else {
                ss >> output2;
                if (ss.fail()) {
                    cout << "Invalid input, try again:" << endl;
                    return getPairInt(output1, output2);
                }
            }
        }
        void getPairInt(int& output1, int& output2, int defaultValue1, int defaultValue2) {
            getInput();
            ss >> output1;
            if (ss.fail()) {
                output1 = defaultValue1;
                output2 = defaultValue2;
                return;
            }
            if (ss.eof()) {
                return;
            } else {
                ss >> output2;
                if (ss.fail()) {
                    output1 = defaultValue1;
                    output2 = defaultValue2;
                    return;
                }
            }
        }
        void getChar(char& output) {
            getInput();
            ss >> output;
            if (ss.fail()) {
                return getChar(output);
            }
        }
};

#endif
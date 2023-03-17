//Draw.h
#ifndef DRAW_H
#define DRAW_H
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Sort.h"
using namespace std;

class Draw : public Sort{
    private:
        int ms = 0;
    public:

        void setDelayTime(int ms) {
            if (ms >= 0)
                this -> ms = ms;
            else
                this -> ms = 0;
        }

        void toDraw(int a[], int n, int max_value, int pivot, int i, int j) {
            
            string buffer;
            system("cls");
            for (int k = max_value; k > 0; k--) {
                for (int l = 0; l < n; l++) {
                    if (a[l] >= k) {
                        if (l == pivot) {
                            if (a[l] < 10)
                                buffer += "\033[32m" + to_string(a[l]) + " " + "\033[0m";
                            else
                                buffer += "\033[32m" + to_string(a[l]) + "\033[0m";
                        }
                        else if (l == i || l == j) {
                            if (a[l] < 10)
                                buffer += "\033[31m" + to_string(a[l]) + " " + "\033[0m";
                            else
                                buffer += "\033[31m" + to_string(a[l]) + "\033[0m";
                        }
                        else {
                            if (a[l] < 10)
                                buffer += to_string(a[l]) + " ";
                            else
                                buffer += to_string(a[l]);
                        }
                    }
                    else {
                        buffer.append("  ");
                    }

                    buffer.append(" ");
                }
                buffer.append("\n");

            }
            for (int m = 0; m < n; m++) {
                buffer.append("---");
            }
            buffer += "so so sanh: "+ to_string(count_compare) + ", so swap: " + to_string(count_swap);
            cout << buffer;
            this_thread::sleep_for(std::chrono::milliseconds(ms));
        }
};



#endif
//Draw.h
#ifndef DRAW_H
#define DRAW_H
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "ArrayFunction.h"
using namespace std;

class Draw : public ArrayFunction {
    private:
        
    protected:
        int ms = 0;
        int count_compare = 0;
        int count_swap = 0;
        int count_access_array = 0;
    public:
// CONSTRUCTORS ----------------------------------------------------
        Draw() {}
        Draw(vector<int> a, int n, int ms = 0) : ArrayFunction(a,n) {
            this -> ms = ms;
        }
        Draw(int n, int ms = 0) : ArrayFunction(n) {
            this -> ms = ms;
        }
// GETTER - SETTER METHODS ------------------------------------------
        int getNumberOfCompare() {
            return count_compare;
        }

        int getNumberOfSwap() {
            return count_swap;
        }

        void setDelayTime(int ms) {
            if (ms >= 0)
                this -> ms = ms;
            else
                this -> ms = 0;
        }
        int getDelayTime() {
            return ms;
        }
        
// OTHER METHODS ----------------------------------------------------
 
        void toDraw(int pivot, int i, int j) {
            
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
                        buffer += "  ";
                    }

                    buffer += " ";
                }
                buffer += "\n";

            }
            for (int m = 0; m < n; m++) {
                buffer += "--";
            }
            buffer += "so so sanh: "+ to_string(count_compare) + ", so swap: " + to_string(count_swap) + ", so truy cap mang: " + to_string(count_access_array);
            cout << buffer;
            this_thread::sleep_for(std::chrono::milliseconds(ms));
        }
};



#endif
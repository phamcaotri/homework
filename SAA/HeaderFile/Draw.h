//Draw.h
#ifndef DRAW_H
#define DRAW_H
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "ArrayFunction.h"
#include "SortAnalyze.h"
using namespace std;
using namespace std::chrono;

class Draw : public ArrayFunction, public SortAnalyze {
    private:
        string buffer;

    protected:
        int ms = 0;

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

        int getDelayTime() {
            return ms;
        }
        void setDelayTime(int ms) {
            if (ms >= 0)
                this -> ms = ms;
            else
                this -> ms = 0;
        }


// OTHER METHODS ----------------------------------------------------
 
        void toDraw(int pivot, int i, int j) {
            buffer.clear();
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
            if (ms < 50)
                cout << "\033[1;1H" << buffer; //move pointer to 1:1
            else {
                system("cls");
                cout << buffer;
            }
            this_thread::sleep_for(milliseconds(ms));
        }
};



#endif
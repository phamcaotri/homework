#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Year {
    protected:
        int year;

        bool isLeapYear() {
            if (year% 4 == 0 and year % 100 != 0)
                return true;
            return false;
        }

};

class Month : public Year{
    protected:
        int month;


        bool have31Day() {
            if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12)
                return true;
            return false;
        }
        void plusMonth() {
            if (month == 12) {
                month = 1;
                year ++;
            }
            month ++;
        }
    public:
        bool isValidMonth() {
            if (month < 1 or month > 12)
                return false;
            return true;
        }

};

class Day : public Month {
    protected:
        int day;

    public:
        void input() {
            cin >> day >> month >> year;
        }

        void output() {
            cout << day << '/' << month << '/' << year;
        }
        int maxDay() {
            if (isLeapYear() and month == 2)
                return 29;
            else if (not isLeapYear() and month == 2)
                return 28;
            else if (have31Day())
                return 31;
            return 30;
        }
        bool isValidDay() {
            if (day < 1 or day > maxDay())
                return false;
            return true;
        }   
        void plusDay() {
            if (day == 29 and isLeapYear() and month == 2) {
                day = 1;
                plusMonth();
                return;
            } else
            if (day == 28 and not isLeapYear() and month == 2) {
                day = 1;
                plusMonth();
                return;
            } else
            if (day == 31 and have31Day()) {
                day = 1;
                plusMonth();
                return;
            } else
            if (day == 30 and not have31Day()) {
                day = 1;
                plusMonth();
                return;
            } else day++;
            
        }
};
int main() {
    Day a;
    a.input();
    if (not a.isValidDay() or not a.isValidMonth()) {
        cout << "ERROR";
        return 0;
    }
    a.plusDay();
    a.output();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

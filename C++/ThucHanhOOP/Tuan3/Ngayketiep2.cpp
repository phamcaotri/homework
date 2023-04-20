#include <iostream>
using namespace std;

class Day {
    private:
        int day;
        int month;
        int year;
        int dayNumber;
    public:
        Day(int x, int y , int z) {
            day = x;
            month = y;
            year = z;
            dayNumberGenerate();
        }
        Day(int x = 0) {
            dayNumber = x;
        }
        int CheckDayOfMonth() {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                return 31;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                return 30;
            }
            else if (month == 2) {
                if ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0) {
                    return 29;
                }
                else {
                    return 28;
                }
            }
            return 0;
        }
        void input() {
            cin >> day >> month >> year;
            day = abs(day);
            month = abs(month);
            year = abs(year);
            this->month = (this->month) % 12; if (this->month == 0) this->month = 12;
            if (this->day > CheckDayOfMonth())
            {
                this->day = 1;
            }
            dayNumberGenerate();
        }
        int dayNumberGenerate() {
            int dayNumber = 0;
            int leap = 0;
            for (int i = 0; i < year; i++) {
                if ((i % 4 == 0 and i % 100 != 0) or i % 400 == 0) {
                    dayNumber += 366;
                    leap ++;
                }
                else
                    dayNumber += 365;
            }
            for (int i = 1; i < month; i++) {
                if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12)
                    dayNumber += 31;
                else if (i == 2) {
                    if ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0)
                        dayNumber += 29;
                    else
                        dayNumber += 28;
                }
                else
                    dayNumber += 30;
            }
            dayNumber += day;
            this -> dayNumber = dayNumber;
            return dayNumber;
        }
        int khoangCach(Day x) {
            return abs(x.dayNumber - dayNumber);
        }
        Day operator+(int x) {
            Day t;
            t.dayNumber = dayNumber + x;
            return t;
        }
        Day operator-(int x) {
            Day t;
            t.dayNumber = dayNumber - x;
            return t;
        }

};

int main() {
    Day t;
    t.input();
    
    //cout << t.dayNumberGenerate() << endl;
    int n = 0; 
    do {
        cin >> n;
        if (n == 1) {
            int x; cin >> x;
            t = t + x;

        }
        else if (n == 2) {
            int x; cin >> x;
            t = t - x;
        }
        else if (n == 3) {
            Day s;
            s.input();
            cout << t.khoangCach(s);
            break;
        }
    } while (n == 1 || n == 2);

    return 0;
}
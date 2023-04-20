/*
nhập vào ngày, tháng, năm t
nhập vào n
nếu n = 1 thì nhập x, tăng t lên x ngày
nếu n = 2 thì nhập x, giảm t xuống x ngày
nếu n = 3 thì nhập ngày tháng năm s, tính số ngày giữa t và s, kết thúc lặp
nếu n khác 1, 2, 3 lặp lại nhập n

*/

#include <iostream>
using namespace std;

class Year {
    protected:
        long year;
    public:
        Year(long x = 0) {
            year = x;
        }
        Year operator+(Year x) {
            return year + x.year;
        }
        Year operator-(Year x) {
            return year - x.year;
        }
};

class Month : public Year {
    protected:
        long month;
    public:
        Month(long x = 0) {
            month = x;
        }
        void check() {
            if (month > 12) {
                month -= 12;
                year++;
            }
        }
        Month operator+(Month x) {
            Month y;
            y.month = month + x.month;
            y.year = year;
            y.check();
            return y;
        }
        Month operator-(Month x) {
            Month y;
            y.month = month - x.month;
            y.year = year;
            y.check();
            return y;
        }
};

class Day : public Month {
    private:
        long day;
    public:
        Day(long x = 0) {
            day = x;
        }
        long CheckDayOfMonth() {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                return 31;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                return 30;
            }
            else if (month == 2) {
                if (year % 4 == 0) {
                    return 29;
                }
                else {
                    return 28;
                }
            }
            return 0;
        }

        long CheckDayOfYear() {
            if (year % 4 == 0) {
                return 366;
            }
            else {
                return 365;
            }
        }
        
        void check() {
            if (day > CheckDayOfYear()) {
                day -= CheckDayOfYear();
                year+= 1;
                check();
            }
            else if (day > CheckDayOfMonth()) {
                day -= CheckDayOfMonth();
                month += 1;
                check();
            } else if (day < 1) {
                day += CheckDayOfMonth();
                month-= 1;
                check();
            }

        }


        long khoangCach(Day x) {
            long y = 0;
            if (x > *this) {
                y = x.day - day;
                y += (x.month - month) * CheckDayOfMonth();
                y += (x.year - year) * CheckDayOfYear();
            }
            else {
                y = day - x.day;
                y += (month - x.month) * CheckDayOfMonth();
                y += (year - x.year) * CheckDayOfYear();
            }
            return y;
        }

        void chuanHoa() {
            day = abs(day);
            month = abs(month);
            year = abs(year);
            this->month = (this->month) % 12; if (this->month == 0) this->month = 12;
            if (this->day > CheckDayOfMonth())
            {
                this->day = 1;
            }
        }
        Day operator+(Day x) {
            Day y;
            y.day = day + x.day;
            y.month = month;
            y.year = year;
            y.check();
            return y;
        }
        Day operator-(Day x) {
            Day y;
            y.day = day - x.day;
            y.month = month;
            y.year = year;
            y.check();
            return y;
        }
        bool operator>(Day x) {
            if (year > x.year) {
                return true;
            }
            else if (year == x.year) {
                if (month > x.month) {
                    return true;
                }
                else if (month == x.month) {
                    if (day > x.day) {
                        return true;
                    }
                }
            }
            return false;
        }

        friend istream& operator>>(istream& is, Day& x);
};

istream& operator>>(istream& is, Day& x) {
    is >> x.day >> x.month >> x.year;
    return is;
}

int main() {
    Day t; cin >> t;
    long n = 0; 
    do {
        cin >> n;
        if (n == 1) {
            long x; cin >> x;
            t = t + x;

        }
        else if (n == 2) {
            long x; cin >> x;
            t = t - x;
        }
        else if (n == 3) {
            Day s; cin >> s;
            cout << t.khoangCach(s);
            break;
        }
    } while (n == 1 || n == 2);

    return 0;
}



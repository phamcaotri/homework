#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Clock {
    private:
        int hour;
        int minute;
        int second;
        int totalSecond;
    public:
        Clock(int h = 0, int m = 0, int s = 0) {
            hour = h;
            minute = m;
            second = s;
            totalSecond = h*3600 + m*60 + s;
        }
        void input() {
            cin >> hour >> minute >> second;
            totalSecond = hour*3600 + minute*60 + second;
        }
        void output() {
            cout << hour << ' ' << minute << ' ' << second;
        }
        void totalSecondToClock() {
            hour = totalSecond / 3600;
            minute = (totalSecond % 3600) / 60;
            second = (totalSecond % 3600) % 60;
        }
        void operator++() {
            totalSecond ++;
            totalSecondToClock();
        }
        void operator--() {
            totalSecond --;
            totalSecondToClock();
        }
        Clock operator+(int x) {
            Clock a;
            a.totalSecond = totalSecond + x;
            a.totalSecondToClock();
            return a;
        }
        Clock operator-(int x) {
            Clock a;
            a.totalSecond = totalSecond - x;
            a.totalSecondToClock();
            return a;
        }

};

int main() {
    Clock a;
    a.input();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "++") {
            ++a;
        } else if (s == "--") {
            --a;
        } else if (s == "+") {
            int x; cin >> x;
            a = a + x;
        } else if (s == "-") {
            int x; cin >> x;
            a = a - x;
        }

    }
    a.output();
    return 0;
}


#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Time {
    private:
        int hours;
        int minutes;
        int seconds;
    public:

        // time will be normalized
        Time(int hours = 0, int minutes = 0, int seconds = 0) {
            this->hours = hours;
            this->minutes = minutes;
            this->seconds = seconds;

            normalize();
        }
        Time& operator=(const Time& other) {
            this->hours = other.hours;
            this->minutes = other.minutes;
            this->seconds = other.seconds;
            return *this;
        }
        bool operator==(const Time& other) {
            return this->hours == other.hours && this->minutes == other.minutes && this->seconds == other.seconds;
        }
        bool operator!=(const Time& other) {
            return !(*this == other);
        }

        void normalize() {
            int total_seconds = hours * 3600 + minutes * 60 + seconds;
            hours = total_seconds / 3600;
            minutes = (total_seconds % 3600) / 60;
            seconds = total_seconds % 60;
        }


        Time operator+(const Time& other) {
            int total_seconds = seconds + other.seconds;
            int total_minutes = minutes + other.minutes;
            int total_hours = hours + other.hours;

            return Time(total_hours, total_minutes, total_seconds);
        }

        Time operator+(int seconds) {
            int total_seconds = this->seconds + seconds;
            int total_minutes = minutes;
            int total_hours = hours;

            return Time(total_hours, total_minutes, total_seconds);
        }

        Time operator-(const Time& other) {
            int total_seconds = seconds - other.seconds;
            int total_minutes = minutes - other.minutes;
            int total_hours = hours - other.hours;

            return Time(total_hours, total_minutes, total_seconds);
        }

        Time operator-(int seconds) {
            int total_seconds = this->seconds - seconds;
            int total_minutes = minutes;
            int total_hours = hours;

            return Time(total_hours, total_minutes, total_seconds);
        }

        void displayTime() {
            cout << hours << "h " << minutes << "m " << seconds << "s" << endl;
        }

        // time input will be normalized
        void inputTime() {
            cout << "Enter the time (xxh yym zzs format): ";
            cin >> hours >> minutes >> seconds;

            normalize();
        }      
};

int main() {
    // start timer
    auto start = chrono::steady_clock::now();
    int t1;
    while (t1 != 10000 * 3600 ) {
        t1++;
    }
    // end timer
    auto end = chrono::steady_clock::now();
    cout << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
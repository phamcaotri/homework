// TimeMeasure.h
#ifndef TIMEMEASURE_H
#define TIMEMEASURE_H
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

class TimeMeasure {
    public:
    // Khai báo một con trỏ hàm có kiểu void (Sort::*)() để trỏ đến các hàm sort không có tham số và không trả về giá trị
    virtual void Sort() {}
    virtual void Sort(int, int) {}


    // Khai báo một phương thức để đo thời gian chạy của hàm sort
    void measureTime() {
        auto start = high_resolution_clock::now();
        Sort();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout <<"runtime: " << fixed << duration.count()/1000000000.0 << " s" << '\n';
    }
    void measureTime(int left, int right) {
        auto start = high_resolution_clock::now();
        Sort(left, right);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout <<"runtime: " << fixed << duration.count()/1000000000.0 << " s" << '\n';
    }
};

#endif
// TimeMeasure.h

// Chức năng của class TimeMeasure: Gọi hàm sort để tính thời gian chạy

#ifndef TIMEMEASURE_H
#define TIMEMEASURE_H
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

class TimeMeasure{
    public:
    // Khai báo một phương thức ảo để sort
    virtual void Sort() {}
    virtual void Sort(int, int) {}


    // Khai báo một phương thức để đo thời gian chạy của hàm sort
    double measureTime(int n) {
        auto start = high_resolution_clock::now();
        // Do có 2 loại hàm sort, không có đệ quy và có đệ quy, nên gọi hết cả 2. Chương trình sẽ không chạy hàm không đúng tham số của nó
        Sort();
        Sort(0,n-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        return duration.count()/1000000000.0;
    }
// /1000000000.0


};

#endif
// SortAlgorithm.h
/*
Chức năng của class SortAlgorithm:
1. Class trung gian giữa các class sắp xếp và các class khác
2. Cung cấp các phương thức lấy và đặt runtime
*/
#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H
#include "SortIndex.h"
#include "SortList.h"
#include "ArrayFunction.h"
#include "TimeMeasure.h"

class SortAlgorithm : public ArrayFunction, public TimeMeasure {
    protected:
        double runtime;
    public:
        using ArrayFunction::ArrayFunction;
        virtual string getName() = 0;
        // get runtime
        double getRuntime() {
            return runtime;
        }
        // set runtime
        void setRuntime(double runtime) {
            this -> runtime = runtime;
        }

};
#endif
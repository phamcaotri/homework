// SortAlgorithm.h
#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H
#include "SortIndex.h"
#include "SortList.h"
#include "ArrayFunction.h"
#include "TimeMeasure.h"

// create virtual class SortAlgorithm
class SortAlgorithm : public ArrayFunction, public TimeMeasure {
    protected:
        double runtime;
    public:
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
// SortAnalyze.h
#ifndef SORTANALYZE_H
#define SORTANALYZE_H

class SortAnalyze {
    protected:
        int count_compare = 0;
        int count_swap = 0;
        int count_access_array = 0;
    public:

// CONSTRUCTORS ----------------------------------------------------


// VIRTUAL METHODS -------------------------------------------------


// GETTER - SETTER METHODS -----------------------------------------

        int getNumberOfCompare() {
            return count_compare;
        }

        int getNumberOfSwap() {
            return count_swap;
        }

// OTHER METHODS ---------------------------------------------------


};

#endif
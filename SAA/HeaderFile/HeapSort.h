// HeapSort.h
#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "Draw.h"

// class Heap {
//     private:
//         int value;
//         int father = 0;
//         int self;
//         int left_child;
//         int right_child;
//     public:
//         int getFather() {
//             return father;
//             }
//         int getSelf() {
//             return self;
//         }
//         void setSelf(int self = 0) {
//             this -> self = self;
//             if (self > 0)
//                 father = (self-1)/2;
//             left_child = 2*self + 1;
//             right_child = 2*self + 2;
//         }

//         int getLeftChild() {
//             return left_child;
//         }
//         int getRightChild() {
//             return right_child;
//         }


// };


class HeapSort : public Draw {
    private:
        void reLocation(int self, int father) {
            if (self == 0)
                return;
            if (a[self] > a[father])
                swap(a[self],a[father]);
            else
                return;
            return reLocation(father, (father-1)/2);
        }
        void Heapify() {
            for (int i = 1 ; i < n; i++) {
                    reLocation(i,(i-1)/2);

            }
        }

public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw;


// OTHER METHODS ---------------------------------------------------



        void Sort() {
            Heapify();
            for (int i = 1 ; i < n; i++) {
                cout << a[i];
            }
        }
};



#endif
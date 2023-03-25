// HeapSort_old.h
#ifndef HEAPSORT_OLD_H
#define HEAPSORT_OLD_H
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


class HeapSort_old : public Draw {
    private:
        
        void upArrange(int self, int father) {
            if (self == 0)
                return;
            if (a[self] > a[father])
                swap(a[self],a[father]);
            else
                return;
            return upArrange(father, (father-1)/2);
        }
        void Heapify() {
            for (int i = 1 ; i < n; i++) {
                    upArrange(i,(i-1)/2);

            }
        }
        void HeapifyAndDraw() {
            for (int i = 1 ; i < n; i++) {
                                                            toDraw(i,(i-1)/2,-1);
                    upArrange(i,(i-1)/2);
                                                            toDraw(i,(i-1)/2,-1);


            }
        }
        void downArrange(int n, int self, int left_child, int right_child) {
            if (right_child >= n)
                if (left_child >= n)
                    return;
                else {
                    swap(a[self],a[left_child]);
                    return;
                }
                    

            else {
                if (a[left_child] > a[right_child] and a[self] < a[left_child]) {
                    swap(a[self],a[left_child]);
                    return downArrangeAndDraw(n, left_child,2*left_child+1,2*left_child+2);
                }
                if (a[left_child] < a[right_child] and a[self] < a[right_child]) {
                    swap(a[self],a[right_child]);
                    return downArrangeAndDraw(n, right_child,2*right_child+1,2*right_child+2);
                }
            }


        }
        void downArrangeAndDraw(int n, int self, int left_child, int right_child) {
            if (right_child >= n)
                if (left_child >= n)
                    return;
                else {
                    swap(a[self],a[left_child]);
                    return;
                }
                    

            else {
                if (a[left_child] > a[right_child] and a[self] < a[left_child]) {
                    swap(a[self],a[left_child]);
                    return downArrangeAndDraw(n, left_child,2*left_child+1,2*left_child+2);
                }
                if (a[left_child] < a[right_child] and a[self] < a[right_child]) {
                    swap(a[self],a[right_child]);
                    return downArrangeAndDraw(n, right_child,2*right_child+1,2*right_child+2);
                }
            }


        }

public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw;


// OTHER METHODS ---------------------------------------------------



        void Sort() {
            Heapify();
            for (int i = 1 ; i < n; i++) {
                swap(a[0],a[n-i]);
                downArrange(n-i,0,1,2);   
            }
            if (a[0] > a[1])
                swap(a[0],a[1]);            

        }
        void SortAndDraw() {
            HeapifyAndDraw();
            for (int i = 1 ; i < n; i++) {  
                swap(a[0],a[n-i]);
                downArrangeAndDraw(n-i,0,1,2);
                                                            toDraw(n-i,-1,-1);
                
            }
            if (a[0] > a[1])
                swap(a[0],a[1]);
                                                            toDraw(0,-1,-1);
        }
};



#endif
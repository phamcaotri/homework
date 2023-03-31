// HeapSort.h
#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "SortAlgorithm.h"

class HeapSort : public SortAlgorithm {
    private:
        void heapifyUp(int self, int father) {
            if (a[self] > a[father]) {
                swap(a[self], a[father]);
                heapifyUp(father, (father-1)/2);
            }
        }


        // hàm khởi tạo cây heap
        void Heapify() {
            for (int i = 1 ; i < n; i++) {
                    heapifyUp(i,(i-1)/2);

            }
        }
        // hàm khôi phục tính đúng đắn của cây heap
        void heaplifyDown(int n, int self, int left_child, int right_child) {
            int largest = self;
            if (left_child < n and a[left_child] > a[largest])
                largest = left_child;
            if (right_child < n and a[right_child] > a[largest])
                largest = right_child;
            if (largest != self) {
                swap(a[self], a[largest]);
                heaplifyDown(n, largest, 2*largest+1, 2*largest+2);
            }
        }

public:
// CONSTRUCTORS ----------------------------------------------------



// OTHER METHODS ---------------------------------------------------

        string getName() {
            return "Heap Sort";
        }

        void Sort() {
            Heapify(); // khởi tạo cây heap
            for (int i = 1 ; i < n; i++) {
                swap(a[0],a[n-i]); // đưa phần tử lớn nhất về cuối mảng
                heaplifyDown(n-i,0,1,2);   // khôi phục tính đúng đắn của cây heap
            }          

        }

};



#endif
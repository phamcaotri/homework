// HeapSort.h
#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "Draw.h"

class HeapSort : public Draw {
    private:
        void heapifyUp(int self, int father) {
            if (a[self] > a[father]) {
                swap(a[self], a[father]);
                heapifyUp(father, (father-1)/2);
            }
        }

        void heapifyUpAndDraw(int self, int father) {
            if (a[self] > a[father]) {
                                                            toDraw(self,father,-1);
                swap(a[self], a[father]);
                                                            toDraw(self,father,-1);
                heapifyUp(father, (father-1)/2);
            }
        }
        //sử dụng hàm này để tạo cây heap cũng là một cách, hoạt động tốt nếu dữ liệu đầu vào tuần tự
        void Heapify() {
            for (int i = 1 ; i < n; i++) {
                    heapifyUp(i,(i-1)/2);

            }
        }
        void HeapifyAndDraw() {
            for (int i = 1 ; i < n; i++) {
                                                            toDraw(i,(i-1)/2,-1);
                    heapifyUpAndDraw(i,(i-1)/2);
                                                            toDraw(i,(i-1)/2,-1);


            }
        }
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

        void heaplifyDownAndDraw(int n, int self, int left_child, int right_child) {
            int largest = self;
            if (left_child < n and a[left_child] > a[largest])
                largest = left_child;
            if (right_child < n and a[right_child] > a[largest])
                largest = right_child;
            if (largest != self) {
                                                            toDraw(self,largest,-1);
                swap(a[self], a[largest]);
                                                            toDraw(self,largest,-1);
                heaplifyDown(n, largest, 2*largest+1, 2*largest+2);
            }
        }

public:
// CONSTRUCTORS ----------------------------------------------------
        using Draw::Draw;


// OTHER METHODS ---------------------------------------------------

        string getName() {
            return "Heap Sort";
        }

        void Sort() {
            Heapify();
            for (int i = 1 ; i < n; i++) {
                swap(a[0],a[n-i]);
                heaplifyDown(n-i,0,1,2);   
            }          

        }
        void SortAndDraw() {
            HeapifyAndDraw();
            for (int i = 1 ; i < n; i++) {  
                swap(a[0],a[n-i]);
                heaplifyDownAndDraw(n-i,0,1,2);
                                                            toDraw(n-i,-1,-1);
                
            }

        }
};



#endif
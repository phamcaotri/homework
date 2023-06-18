#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

// maximum value of n
const int MAX = 2000000000;

class ArrayFunction {
    protected:

        int max_value = 0;
        int min_value = 0;
        int n = 1;
        vector<int> a;

    public:

// GETTER - SETTER METHODS -----------------------------------------

        // input n. return false if input is invalid
        bool setN(int n = 1) {
            if (n < 0 or n > MAX)
                return false;
            a.resize(n);
            this -> n = n;
            return true;
        }
        // trả về mảng a và tình trạng sắp xếp của mảng
        void getArray() {
            string buffer;
            cout << '\n';
            for (int i = 0; i < n; i++) {
                buffer += to_string(a[i]) + " ";
            }
            buffer += "\n";
            cout << buffer;
            if (isSorted()) {
                cout << "Sorted Array." << '\n';
            } else {
                cout << "Unsorted Array." << '\n';
            }
        }


// OTHER METHODS ---------------------------------------------------

        int max() {
            int max = a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] > max) {
                    max = a[i];
                }
            }
            return max;
        }

        int min() {
            int min = a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] < min) {
                    min = a[i];
                }
            }
            return min;
        }

        bool isSorted() {
            for (int i = 1; i < n; i++) {
                if (a[i] < a[i-1]) {
                    return false;
                }
            }
            return true;
        }

        void createShuffledArray() {
            srand(time(NULL));
            // randomize the array with n elements, each element is in range [-10000, 10000]
            for (int i = 0; i < n; i++) {
                a[i] = rand() % 20001 - 10000;
            }
            max_value = max();
            min_value = min();
        }     
};

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

class SortList {
    private:
        // danh sách các thuật toán
        vector<SortAlgorithm*> list;

    public:
        void menu() {
            // yêu cầu người dùng nhập số nguyên n dưới 2 tỷ, nếu không thỏa mãn yêu cầu, yêu cầu nhập lại
            int n;
            cout << "Enter number n between 0 and 2 billion: ";
            do {
                cin >> n;
                if (n < 0 or n > MAX)
                    cout << "Please enter a number n between 0 and 2 billion again: ";
            } while (n < 0 or n > MAX);


            for (int i = 0; i < list.size(); i++) {
                cout << i+1 << ": " << list[i] -> getName() << '\n';
            }
            // yêu cầu người dùng nhập số nguyên trong khoảng 1 đến số lượng thuật toán, nếu không thỏa mãn yêu cầu, yêu cầu nhập lại
            int choice;
            cout << "Choose an algorithm: ";
            do {
                cin >> choice;
                if (choice < 1 or choice > list.size())
                    cout << "Please choose a number in the list again: ";
            } while (choice < 1 or choice > list.size());
            
            if (n == 0) {
                cout << "Array is empty" << endl;
                return;
            }
            timeMeasure(n, choice-1);
        }   

        void addAlgorithm(SortAlgorithm* algorithm) {
            list.push_back(algorithm);
        }
        // add multiple algorithms
        void addAlgorithms(vector<SortAlgorithm*> algorithms) {
            for (int i = 0; i < algorithms.size(); i++)
                list.push_back(algorithms[i]);
        }

        void timeMeasure(int n, int algorithm) {
            list[algorithm] -> setN(n);
            list[algorithm]-> createShuffledArray();
            list[algorithm] -> setRuntime(list[algorithm] -> measureTime(n));
            list[algorithm] -> getArray();
            cout << list[algorithm] -> getName() << " runtime: " << fixed << list[algorithm] -> getRuntime() << " s" << endl;
            
        }

        void timeMeasureAllAlgorithms(int n) {
            for (int i = 0; i < list.size(); i++) {
                list[i] -> setN(n);
                list[i]-> createShuffledArray();
                cout << list[i] -> getName() << ": ";
                list[i] -> setRuntime(list[i] -> measureTime(n));
                cout << list[i] -> getName() << " runtime: " << list[i] -> getRuntime() << " s" << endl;
                cout << ((list[i] -> isSorted()) ? ("is Sorted") : ("not Sorted")) << endl << endl;
            }
        }

        // hàm xếp hạng các thuật toán theo thời gian chạy bằng getRuntime()
        void rankAlgorithms() {
            for (int i = 0; i < list.size(); i++) {
                for (int j = i+1; j < list.size(); j++) {
                    if (list[i] -> getRuntime() > list[j] -> getRuntime()) {
                        SortAlgorithm* temp = list[i];
                        list[i] = list[j];
                        list[j] = temp;
                    }
                }
            }
        }

        void printRank() {
            rankAlgorithms();
            for (int i = 0; i < list.size(); i++) {
                cout << i+1 << ". " << list[i] -> getName() << ": " << list[i] -> getRuntime() << "s" << endl;
            }
        }
        


};

class BinaryInsertionSort : public SortAlgorithm {
    private:
        int BinarySearch(int x, int start, int end) {
            if (end < start)
                return start;
            int mid  =  (end+start)/2;
            if (x == a[mid])
                return mid;
            else {
                if (x > a[mid])
                    return BinarySearch(x,mid+1,end);
                else
                    return BinarySearch(x,start,mid-1);
            }
        }

    public:
// CONSTRUCTORS ----------------------------------------------------

// OTHER METHODS ---------------------------------------------------

        string getName() {
            return "Binary Insertion Sort";
        }
        
        void Sort() {
            for (int i = 1; i < n ; i++) {
                int x = a[i]; 
                int k = BinarySearch(x,0,i-1); // tìm vị trí chèn
                for (int j = i-1; j >= k; j--) { // dời các phần tử sang phải
                    a[j+1] = a[j];
                }
                a[k] = x; // chèn phần tử x vào vị trí k
            }
        }
};

class BubbleSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Bubble Sort";
        }

        void Sort() {
            bool swapped = true;
            for (int i = 1; i < n and swapped ; i++) {
                swapped = false;
                for (int j = 0; j < n-i ; j++)
                    if (a[j] > a[j+1]) { // đổi chỗ 2 phần tử nếu sai thứ tự
                        swap(a[j],a[j+1]);
                        swapped = true;
                    }
            }
        }
};

class CountSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Counting Sort";
        }
        
        void Sort() {
            // nếu có số âm, thì chuyển tất cả các số về dương
            if (min_value < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] -= min_value;
                }
                max_value -= min_value;
            }
            vector<int> b(max_value+1,0); // mảng b để lưu số lần xuất hiện của các phần tử
            for (int i = 0; i < n; i++) {
                b[a[i]]++; // đếm số lần xuất hiện của các phần tử
            }
            int j = 0;
            for (int i = 0; i < max_value+1; i++) { // in kết quả lại mảng a
                while (b[i] > 0) {
                    a[j] = i;
                    b[i] --;
                    j++;
                }
            }
            // nếu có số âm, thì chuyển về lại
            if (min_value < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] += min_value;
                }
            }
        }

    

};

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
                swap(a[self], a[largest]); // đổi chỗ phần tử lớn nhất với phần tử cha
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

class InsertionSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Insertion Sort";
        }

        void Sort() {
            for (int i = 1; i < n ; i++) {
                int j = i-1;
                int x = a[i]; // lấy phần tử thứ i
                for (; j >= 0 and x < a[j]; j--) { // dời các phần tử sang phải
                    a[j+1] = a[j];
                }
                a[j+1] = x; // chèn phần tử x vào vị trí
            }
        }


};

class InterchangeSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------

        string getName() {
            return "Interchange Sort";
        }
        
        void Sort() {
            for (int i = 0; i < n-1 ; i++)
                for (int j = i+1; j < n; j++) 
                    if (a[i] > a[j]) // đổi chỗ 2 phần tử nếu sai thứ tự
                        swap(a[i],a[j]);
        }

};

class MergeSort : public SortAlgorithm {


    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------

        string getName() {
            return "Merge Sort";
        }
        
        void Sort(int start, int end) {
            int pivot = (start + end)/2; // tìm trục
            if (start < pivot) Sort(start,pivot); // sắp xếp nửa trái
            if (end > pivot +1 ) Sort(pivot+1,end); // sắp xếp nửa phải
            merge(start,pivot,end); // gộp 2 nửa lại
        }


    private:
        // hàm gộp 2 nửa lại
        void merge(int start, int pivot, int end) {
            vector<int> b(end-start+1);
            int i = start, j = pivot +1, k = 0;
            while (i <= pivot and j <= end) { // gộp 2 nửa lại
                if (a[i] < a[j]) {
                    b[k] = a[i];
                    k++;
                    i++;
                }
                else {
                    b[k] = a[j];
                    k++;
                    j++;
                }
            }
            for (i;i <= pivot; i++) { // nếu nửa trái còn phần tử, thì gộp vào
                b[k] = a[i];
                k++;
            }
            for (j;j <= end; j++) { // nếu nửa phải còn phần tử, thì gộp vào
                b[k] = a[j];
                k++;
            }
            k = 0;
            for (i = start; i <= end; i++) { // gán lại mảng a
                a[i] = b[k];
                k++;
            } 
        }

};

class QuickSort : public SortAlgorithm {
    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Quick Sort";
        }
        
        void Sort(int left, int right) {
            int pivot = (left+right)/2; // tìm trục
            int mid = a[pivot]; // giá trị trục
            int i = left, j = right; 
            while (i <= j) { // phân đoạn
                while (a[i] < mid) {
                    i ++;
                }
                while (a[j] > mid) {
                    j --;  
                }
                if (i <= j) { // đổi chỗ
                    swap(a[i], a[j]);
                    i ++; 
                    j --;
                }
            }
            if (left < j) Sort(left,j); // đệ quy
            if (right > i) Sort(i,right); // đệ quy
        }
};

class RadixSort : public SortAlgorithm {
    private:


    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Radix Sort";
        }

        void Sort() {
            // nếu có số âm, thì chuyển tất cả các số về dương
            if (min_value < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] -= min_value;
                }
                max_value -= min_value;
            }
            // tính số chữ số của số lớn nhất
            int max_digit = to_string(abs(max_value)).size();
            vector<vector<int>> b(10,vector<int> (n)); // mảng b để lưu các phần tử
            for (int base = 1; base < pow(10,max_digit); base *= 10) {
                vector<int> c(10,0); // mảng c để lưu số lần xuất hiện của các phần tử
                for (int i = 0; i < n; i++) {
                    int index = (a[i]/(base))%10;
                    b[index][c[index]] = a[i]; // chèn phần tử trong mảng a vào mảng b
                    c[index] ++;
                }
                int k = 0;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < c[i]; j++ ) {
                        a[k] = b[i][j]; // chèn kết quả lại mảng a
                        k++;
                    }
                }
            }
            // nếu có số âm, thì chuyển về lại
            if (min_value < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] += min_value;
                }
            }
        }


};

class SelectionSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


// OTHER METHODS ---------------------------------------------------
        string getName() {
            return "Selection Sort";
        }
        
        void Sort() {
            for (int i = 0; i < n - 1; i++) {
                int min = i;
                for (int j = i+1; j < n; j++) {         
                    if (a[min] > a[j]) // tìm phần tử nhỏ nhất
                        min = j;   
                }
                swap(a[i],a[min]); // đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên của mảng hiện hành
            }


        }

};

class ShakeSort : public SortAlgorithm {
    private:

    public:
// CONSTRUCTORS ----------------------------------------------------


        string getName() {
            return "Shake Sort";
        }
        
        void Sort() {
            bool swapped;
            for (int i = 0; i < n/2 ; i++) {
                swapped = false;
                for (int j = i; j < n-i-1; j++) { // chạy từ đầu đến cuối                  
                    if (a[j] > a[j+1]) {    // đổi chỗ 2 phần tử nếu sai thứ tự
                        swap(a[j],a[j+1]); 
                        swapped = true;
                    }
                }
                for (int j = n-i-1 ; j > i ; j--) { // chạy từ cuối đến đầu
                    if (a[j] < a[j-1]) {    // đổi chỗ 2 phần tử nếu sai thứ tự
                        swap(a[j],a[j-1]);
                        swapped = true;
                    }
                }
                if (not swapped) // nếu mảng đã được sắp xếp thì dừng
                    break;
            }
        }

};

class ShellSort : public SortAlgorithm {
    private:

    public:


        string getName() {
            return "Shell Sort";
        }

        void Sort() {
            // chia mảng thành các phần tử k giảm dần
            // sắp xếp các phần tử k đó theo insertion sort
            // lặp lại đến khi k = 1
            for (int k = n/2; k > 0; k /= 2 )
                for (int i = k; i < n; i++)
                    for (int j = i; j >= k and a[j] < a[j-k]; j -= k) {
                        swap(a[j],a[j-k]);

                }
            }

};







int main() {
    // Liệt kê các thuật toán sắp xếp
    vector<SortAlgorithm*> algorithms;
    algorithms.push_back(new SelectionSort);
    algorithms.push_back(new InterchangeSort);
    algorithms.push_back(new InsertionSort);
    algorithms.push_back(new BinaryInsertionSort);
    algorithms.push_back(new BubbleSort);
    algorithms.push_back(new ShakeSort);
    algorithms.push_back(new CountSort);
    algorithms.push_back(new QuickSort);
    algorithms.push_back(new MergeSort);
    algorithms.push_back(new HeapSort);
    algorithms.push_back(new ShellSort);
    algorithms.push_back(new RadixSort);
    SortList list;
    list.addAlgorithms(algorithms);

    char choice;
    do {
        list.menu();
        cout << "Do you want to continue? (y/n): ";
        do {
            cin >> choice;
            if (choice != 'y' and choice != 'n')
                cout << "Please enter y or n" << endl;
        } while (choice != 'y' and choice != 'n');
    } while (choice != 'n' and choice == 'y');
    cout << "Goodbye!" << endl;
    return 0;
}
  
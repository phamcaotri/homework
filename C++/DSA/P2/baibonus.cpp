#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int getInteger(string welcome) {
    cout << welcome << '\n';
    int n;
    do {
        cin >> n;
        if (n < 1 or n > 100000000) {
            cout << "Invalid input, please try again: ";
        }
        else return n;
    } while (true);
    return n;
}

void generateArray(vector<int> &a, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % n + 1; //a + rand() % (b-a+1) -> [a,b]
    }
}

void outputArray(vector<int> a, int n) {
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}

void Menu() {
    cout << '\n';
    cout << "---------- MENU ----------" << '\n';
    cout << "1. Quick Sort" << '\n';
    cout << "2. Merge Sort" << '\n';
    cout << "3. Binary Heap Sort" << '\n';
    cout << "4. Bubble Sort" << '\n';
    cout << "5. Insertion Sort" << '\n';
    cout << "6. Interchange Sort" << '\n';
    cout << "7. Selection Sort" << '\n';
    cout << "8. Shake Sort" << '\n';
    cout << "9. Simple Sort" << '\n';
}

void QuickSort(vector<int> a, int left, int right) {
    int mid = a[(left+right)/2];
    int i = left, j = right;
    while (i <= j) {
        while (a[i] < mid) {
            i ++;
        }

        while (a[j] > mid) {
            j --;  
        }

        if (i <= j) {
            swap(a[i], a[j]);
            i ++; 
            j --;
        }
    }
    if (left < j) QuickSort(a,left,j);
    if (right > i) QuickSort(a, i,right);
}

void BubbleSort(vector<int> a , int n) {
    bool swapped = true;
    for (int i = 1; i < n and swapped ; i++) {
        swapped = false;
        for (int j = 0; j < n-i ; j++)
            if (a[j] > a[j+1]) {
                swap(a[j],a[j+1]);
                swapped = true;
            }

    }


}
void upArrange(vector<int> a, int self, int father) {
    if (self == 0)
        return;
    if (a[self] > a[father])
        swap(a[self],a[father]);
    else
        return;
    return upArrange(a, father, (father-1)/2);
}

void downArrange(vector<int> a, int n, int self, int left_child, int right_child) {
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
            return downArrange(a, n, left_child,2*left_child+1,2*left_child+2);
        }
        if (a[left_child] < a[right_child] and a[self] < a[right_child]) {
            swap(a[self],a[right_child]);
            return downArrange(a, n, right_child,2*right_child+1,2*right_child+2);
        }
    }


}

void Heapify(vector<int> a, int n) {
    for (int i = 1 ; i < n; i++) {
            upArrange(a, i,(i-1)/2);

    }
}

void HeapSort(vector<int> a, int n) {
    Heapify(a, n);
    for (int i = 0 ; i < n-2; i++) {
        swap(a[0],a[n-i-1]);
        downArrange(a, n-i-1,0,1,2);
    }

}


void merge(vector<int> a, int start, int pivot, int end) {
            vector<int> b(end-start+1);
            int i = start, j = pivot +1, k = 0;
            while (i <= pivot and j <= end) {
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
            for (i;i <= pivot; i++) {
                b[k] = a[i];
                k++;
            }
            for (j;j <= end; j++) {
                b[k] = a[j];
                k++;
            }

            k = 0;
            for (i = start; i <= end; i++) {
                a[i] = b[k];
                k++;
            }
                
        }

void MergeSort(vector<int> a,int start, int end) {
    int pivot = (start + end)/2;
    if (start < pivot) MergeSort(a,start,pivot);
    if (end > pivot +1 ) MergeSort(a, pivot+1,end);
    merge(a, start,pivot,end);
}



void runSort(vector<int> a,int n, int c) {
    generateArray(a,n);
    if (c == 1) {
        clock_t start = clock();
        QuickSort(a,0,n-1);
        clock_t end = clock();
        cout << "Time: " << (double) (end-start)/CLOCKS_PER_SEC << "s" << '\n';
        return;
    } else if (c == 2) {
        clock_t start = clock();
        MergeSort(a,0,n-1);
        clock_t end = clock();
        cout << "Time: " << (double) (end-start)/CLOCKS_PER_SEC << "s" << '\n';
        return;        
    } else if (c == 3) {
        clock_t start = clock();
        HeapSort(a,n);
        clock_t end = clock();
        cout << "Time: " << (double) (end-start)/CLOCKS_PER_SEC << "s" << '\n';
        return;  
    } else if (c == 4) {
        clock_t start = clock();
        BubbleSort(a,n);
        clock_t end = clock();
        cout << "Time: " << (double) (end-start)/CLOCKS_PER_SEC << "s" << '\n';
        return;
    } else if (c == 5) {

    } else if (c == 6) {

    } else if (c == 7) {

    } else if (c == 8) {
    
    } else if (c == 9) {

    } else {
        cout << "Invalid input! ";
        return;
    }

}


int main() {

do {
    int n = getInteger("Please enter an number in range 1 to 100000000: ");
    vector<int> a(n);


        //outputArray(a,n);
        Menu();
        cout << "Please choose an algorithm: ";
        int choose; cin >> choose;
        runSort(a, n, choose);
        cout << "Do you want to continue? (y/n): ";
        
        string command;
        do {
            cin.ignore();
            cin >> command;
            if (command == "n") {
                cout << "See you again!";
                return 0;
            }
                
            else if (command == "y") {
                break;
            }
            else cout << "Invalid input! Try again: " << '\n';
        } while(true);
    } while (true);
    cout << "See you again!";
    return 0;
}


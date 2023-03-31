#include "SortList.h"
#include "SortIndex.h"

int main() {
    // Liệt kê các thuật toán sắp xếp
    vector<SortAlgorithm*> algorithms;
    // algorithms.push_back(new SelectionSort);
    // algorithms.push_back(new InterchangeSort);
    // algorithms.push_back(new InsertionSort);
    // algorithms.push_back(new BinaryInsertionSort);
    // algorithms.push_back(new BubbleSort);
    // algorithms.push_back(new ShakeSort);
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
  
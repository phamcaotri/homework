#include "SortList.h"
#include "SortIndex.h"

int main() {

    vector<SortAlgorithm*> algorithms;
    //algorithms.push_back(new BubbleSort);
        // algorithms.push_back(new CountSort);
        // algorithms.push_back(new HeapSort);
    //algorithms.push_back(new BinaryInsertionSort);
    //algorithms.push_back(new InsertionSort);
    //algorithms.push_back(new InterchangeSort);
        // algorithms.push_back(new MergeSort);
        //algorithms.push_back(new QuickSort);
    //algorithms.push_back(new SelectionSort);
    //algorithms.push_back(new ShakeSort);
        // algorithms.push_back(new ShellSort);
        algorithms.push_back(new RadixSort);
    SortList list;
// add algorithms to list
    list.addAlgorithms(algorithms);
// time measure all algorithms
    list.timeMeasureAllAlgorithms(10000, "shuffled array");
    list.rankAlgorithms();

    return 0;
}
  
#include "SortList.h"
#include "SortIndex.h"

int main() {

    vector<SortAlgorithm*> algorithms;
    //algorithms.push_back(new BubbleSort);
    algorithms.push_back(new CountSort);
    algorithms.push_back(new HeapSort);
    //algorithms.push_back(new InsertionSort);
    //algorithms.push_back(new InsertionSort2);
    //algorithms.push_back(new InsertionSort3);
    //algorithms.push_back(new InterchangeSort);
    algorithms.push_back(new MergeSort);
    algorithms.push_back(new QuickSort);
    algorithms.push_back(new QuickSortRP);
    //algorithms.push_back(new SelectionSort);
    //algorithms.push_back(new SimpleSort);
    //algorithms.push_back(new ShakeSort);
    //algorithms.push_back(new InPlaceMergeSort);
    //algorithms.push_back(new ShellSort);
    algorithms.push_back(new ShellSort2);
    SortList list;
// add algorithms to list
    list.addAlgorithms(algorithms);
// time measure all algorithms
    list.timeMeasureAllAlgorithms(50000000, "shuffled array");
    list.rankAlgorithms();

// time measure one algorithm
    // ShellSort2 s(99,100);
    // s.createShuffledArray();
    // s.SortAndDraw();
    list.printRank();
    return 0;
}
  
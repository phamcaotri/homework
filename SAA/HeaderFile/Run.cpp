#include "SortList.h"
#include "SortIndex.h"

int main() {
    BubbleSort s1;
    SortList list;
    list.addAlgorithm(&s1);
    list.runAllAlgorithms(50000);
    return 0;
}
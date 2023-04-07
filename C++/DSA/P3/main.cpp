#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList l;
    l + 1 + 2 + 3;
    l.print();
    l.addAfter(l.findX(2), 4);
    l.print();
}
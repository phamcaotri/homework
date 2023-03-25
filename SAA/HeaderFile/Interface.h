//Interface.h
#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <vector>
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\SortIndex.h"
#include "C:\Users\caotr\Documents\GitHub\homework\SAA\HeaderFile\TimeMeasure.h"
using namespace std;

class Interface : public ArrayFunction {
    private:
        int mode = 1;
    public:
        // return true if user want to input it themself
        bool welcomeText() {
            cout << "\nBy default, we using random input. You can type input yourself by enter 'y'. \nElse, you can enter number n: ";
            char user_input = ' ';

            do {
                cin >> user_input;
                if (user_input == 'y') {
                    cout << "\nPlease enter number n and array a[n]: ";
                    do {
                        if (not setArray()) {
                            cout << "\nInvalid input. Try again: ";
                        } else {
                            chooseMode();
                            chooseSorting();
                            return true;
                        } 
                    } while (true);
                } else if (isdigit(user_input)) {
                    do {
                        if (not setN()) {
                            cout << "\nInvalid input. Try again: ";
                        } else {
                            chooseRandomType();
                            chooseMode();
                            chooseSorting();
                            return false;
                        }

                    } while (true);
                } else {
                    cout << "\nInvalid input. Try again: ";
                }
            } while (true);



        }

        void chooseRandomType() {
            cout << "\n 1. createSufffledArray() \n 2. createRandomizeArray() \n 3. createTestArray() \n 4. createMountainArray() \n 5. createReverseArray() \n";
            char user_input = ' ';

            do {
                cin >> user_input;
                if (user_input == '1') {
                    createShuffledArray();
                    break;
                }
                if (user_input == '2') {
                    createRamdomizeArray();
                    break;
                }
                if (user_input == '3') {
                    createTestArray();
                    break;
                }
                if (user_input == '4') {
                    createMoutainArray();
                    break;
                }
                if (user_input == '5') {
                    createReverseArray();
                    break;
                }
                cout << "\nInvalid input. Try again: ";
            } while (true);

        }
        void chooseMode() {
            cout << "\n 1. Sort and Measure \n 2. Sort and Draw \n";
            char user_input = ' ';

            do {
                cin >> user_input;
                if (user_input == '1') {
                    mode = 1;
                    break;
                }
                if (user_input == '2') {
                    mode = 2;
                    break;

                }
                cout << "\nInvalid input. Try again: ";
            } while (true);            
        }

        void chooseSorting() {
            cout << "\n ";
            cout << "\n---------- MENU ----------" << '\n';
            cout << "1. Quick Sort" << '\n';
            cout << "2. Merge Sort" << '\n';
            cout << "3. Binary Heap Sort" << '\n';
            cout << "4. Bubble Sort" << '\n';
            cout << "5. Insertion Sort" << '\n';
            cout << "6. Interchange Sort" << '\n';
            cout << "7. Selection Sort" << '\n';
            cout << "8. Shake Sort" << '\n';
            cout << "9. Simple Sort" << '\n';
            char user_input = ' ';
            do {
                cin >> user_input;
                if (user_input == '1') {
                    QuickSort s(n);
                    s.getArray();
                    s.measureTime();
                    cout << s.isSorted() << '\n';
                    break;
                }
                if (user_input == '2') {
                    MergeSort s(this -> a, this -> n);
                    s.measureTime();
                    cout << s.isSorted() << '\n';
                    break;
                }
                if (user_input == '3') {
                    HeapSort s(this -> a, this -> n);
                    s.measureTime();
                    cout << s.isSorted() << '\n';
                    break;
                }
                if (user_input == '4') {
                    BubbleSort s(this -> a, this -> n);
                    s.measureTime();
                    cout << s.isSorted() << '\n';
                    break;
                }
                if (user_input == '5') {
                    InsertionSort s(this -> a, this -> n);
                    s.measureTime();
                    cout << s.isSorted() << '\n';
                    break;
                }
                if (user_input == '6') {
                    InterchangeSort s(this -> a, this -> n);
                    s.measureTime();
                    cout << s.isSorted() << '\n';
                    break;
                }
                if (user_input == '7') {
                    SelectionSort s(this -> a, this -> n);
                    s.measureTime();
                    cout << s.isSorted() << '\n';
                    break;
                }
                if (user_input == '8') {
                    ShakeSort s(this -> a, this -> n);
                    s.measureTime();
                    cout << s.isSorted() << '\n';
                    break;
                }
                if (user_input == '9') {
                    SimpleSort s(this -> a, this -> n);
                    s.measureTime();
                    cout << s.isSorted() << '\n';
                    break;
                }
                cout << "\nInvalid input. Try again: ";
            } while (true);

        }
};


#endif
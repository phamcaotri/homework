// SortList.h
#ifndef SORTLIST_H
#define SORTLIST_H
#include "SortIndex.h"
#include "SortAlgorithm.h"
class SortList {
    private:
        // list of algorithms, each algorithm is a pointer to a class, which is a child of Draw class
        vector<SortAlgorithm*> list;

    public:
        // create a menu of algorithms, user can choose which algorithm to use
        void menu() {
            // yêu cầu người dùng nhập số nguyên n dưới 2 tỷ, nếu không thỏa mãn yêu cầu, yêu cầu nhập lại
            int n;
            cout << "Enter n between 0 and 2 billion: ";
            do {
                cin >> n;
                if (n < 0 or n > MAX)
                    cout << "Please enter a number between 0 and 2 billion again: ";
            } while (n < 0 or n > MAX);


            for (int i = 0; i < list.size(); i++) {
                cout << i+1 << ": " << list[i] -> getName() << '\n';
            }
            // user input a number to choose an algorithm, if the number is not in the list, the program will ask user to input again
            int choice;
            cout << "Choose an algorithm: ";
            do {
                cin >> choice;
                if (choice < 0 or choice > list.size())
                    cout << "Please choose a number in the list again: ";
            } while (choice < 1 or choice > list.size());
            

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
            list[algorithm] -> measureTime(n);
            list[algorithm] -> getArray();
        }

        void timeMeasureAllAlgorithms(int n) {
            for (int i = 0; i < list.size(); i++) {
                list[i] -> setN(n);
                list[i]-> createShuffledArray();
                cout << list[i] -> getName() << ": ";
                list[i] -> setRuntime(list[i] -> measureTime(n));
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

#endif
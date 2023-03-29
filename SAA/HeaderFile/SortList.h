// SortList.h
#ifndef SORTLIST_H
#define SORTLIST_H
#include "SortIndex.h"
#include "SortAlgorithm.h"
class SortList {
    private:
        // list of algorithms, each algorithm is a pointer to a class, which is a child of Draw class
        vector<SortAlgorithm*> list;
        // hàm gọi các cách random mảng khác nhau thông qua đầu vào là array_type
        void randomArray(SortAlgorithm* algorithm, string array_type) {
            if (array_type == "test array") {
                algorithm -> createTestArray();
            }
            else if (array_type == "random array") {
                algorithm -> createRamdomizeArray();
            }
            else if (array_type == "shuffled array") { 
                algorithm -> createShuffledArray();
            }
            else if (array_type == "mountain array") { 
                algorithm -> createMoutainArray();
            }
        }

    public:
        void addAlgorithm(SortAlgorithm* algorithm) {
            list.push_back(algorithm);
        }
        // add multiple algorithms
        void addAlgorithms(vector<SortAlgorithm*> algorithms) {
            for (int i = 0; i < algorithms.size(); i++)
                list.push_back(algorithms[i]);
        }
        void timeMeasure(int n, int algorithm, string array_type = "test array") {
            list[algorithm] -> setN(n);
            randomArray(list[algorithm], array_type);
            list[algorithm] -> measureTime(n);
            cout << list[algorithm] -> isSorted() << endl << endl;
        }

        void timeMeasureAllAlgorithms(int n, string array_type = "test array") {
            for (int i = 0; i < list.size(); i++) {
                list[i] -> setN(n);
                randomArray(list[i], array_type);
                cout << list[i] -> getName() << ": ";
                list[i] -> setRuntime(list[i] -> measureTime(n));
                cout << list[i] -> isSorted() << endl << endl;
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
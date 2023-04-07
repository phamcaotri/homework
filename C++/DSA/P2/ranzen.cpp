#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    for (int i = 0; i < 1000; i++) {
        int num = 1 + rand() % 2; // generate a random number between 1 and 2
        cout << num << " ";

        num = rand() % 1000000000; // generate a random number between 0 and 1 billion
        cout << num << " ";
    }


    cout << "0\n"; // end the sequence with 0
    return 0;
}
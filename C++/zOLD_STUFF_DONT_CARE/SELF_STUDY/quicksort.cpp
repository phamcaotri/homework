#include <iostream>
using namespace std;
// all fun stuff in c++ std (no other libs than iostream)

class AX {
    public:
        void getter() {

        }
};

int getArea(int x, int y) {
    return x*y;
}
int main() {
    AX asd;
    asd.getter();
    int height = 0;
    int width = 0;
    getArea(height, width);
    
    // using of auto    
    auto arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // using of range based for loop
    cout << "range based for loop of auto:" << endl;
    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    // using of decltype
    cout << "copying auto to decltype:" << endl;
    decltype(arr) arr2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto i : arr2) {
        cout << i << ' ';
    }
    cout << endl;
    decltype(0.1) z = 0.1;
    cout << "decltype(0.1) x = ";
    cout << z << endl;

    auto ptr = &arr;
    decltype(ptr) ptr2 = &arr;

    auto funcPointer = &main;
    decltype(funcPointer) funcPointer2 = &main;
    // using of sizeof
    cout << "sizeof(arr) = " << sizeof(arr) << endl;
    cout << "sizeof(arr2) = " << sizeof(arr2) << endl;
    cout << "sizeof(ptr) = " << sizeof(ptr) << endl;
    cout << "sizeof(ptr2) = " << sizeof(ptr2) << endl;
    cout << "sizeof(funcPointer) = " << sizeof(funcPointer) << endl;
    cout << "sizeof(funcPointer2) = " << sizeof(funcPointer2) << endl;

    // using of typeid
    cout << "typeid(arr).name() = " << typeid(arr).name() << endl;
    // abs function
    cout << abs(-1);
    cout << endl;

    
    typedef add_const<int> x;
    cout << is_const<x>::value << endl;
    cout << is_const<x>::type() << endl;
    cout << is_const<x>::value_type() << endl;
    cout << is_const<x>::type::value_type() << endl;
    cout << is_const<x>::type::value << endl;
    cout << is_const<x>() << endl;


}
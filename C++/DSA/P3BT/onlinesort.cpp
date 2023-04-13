#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    int a, b;

    do {
        scanf("%d", &a);
        if (!a) break;
        scanf("%d", &b);
        auto it = lower_bound(v.begin(), v.end(), b);
        if (a == 1) {
            
            if (it == v.end() or *it != b)
                v.insert(it, b);
        }
        else {
            if (it == v.end() or *it != b)
                printf("0\n");
            else {
                
                printf("%d\n", it - v.begin() + 1);
            }
                
        }

            
    } while(true);
    return 0;
}
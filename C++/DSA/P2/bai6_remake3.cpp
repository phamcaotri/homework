#include <stdio.h>
#include <set>

using namespace std;

int main() {
    set<int> s;
    int a, b;

    do {
        scanf("%d", &a);
        if (!a) break;
        scanf("%d", &b);
        if (a == 1) {
            s.emplace(b);
        }
        else {
            auto it = s.find(b);
            if (it == s.end())
                printf("0\n");
            else
                printf("%d\n", distance(s.begin(), it) + 1);
        }

            
    } while(true);
    return 0;
}
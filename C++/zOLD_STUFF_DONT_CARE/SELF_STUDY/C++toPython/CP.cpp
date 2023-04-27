// chương trình này sẽ là 1 header file, nhằm define một số hàm để biến giao diện C++ thành giao diện Python
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>

#define print(x) std::cout << x << std::endl
#define input(x) std::cin >> x
#define for(i, n) for(int i = 0; i < n; i++)
#define forfor(i,j, n, m) for(i, n) for(j, m)
#define main() int main()
#define vector(x, n) std::vector<x>(n)
#define vector2d(x, a, n, m) std::vector<std::vector<x>> a (n, std::vector<x>(m))
#define set(x) std::set<x>
#define map(x, y) std::map<x, y>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[";
    for(i , v.size()) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& v) {
    os << "[";
    for(i , v.size()) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}


main() {
    int n, m;
    input(m >> n);
    vector2d(int, a, n, m);
    forfor(i, j, n, m) {
        input(a[i][j]);
    }
    print(a);
    return 0;
}

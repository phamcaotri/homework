
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long x, y;
    Point(long x, long y) {
        this->x = x;
        this->y = y;
    }
    bool operator < (const Point &p) const {
        if (x == p.x) return y > p.y;
        return x < p.x;
    }
    bool operator > (const Point &p) const {
        if (x == p.x) return y < p.y;
        return x > p.x;
    }
};

void Sort(auto left, auto right) {
    if (left >= right) return;
    auto pivot = left + (right - left) / 2;
    auto i = left, j = right;
    while (i <= j) {
        while (*i < *pivot) {
            i ++;
        }

        while (*j > *pivot) {
            j --;  
        }

        if (i <= j) {
            swap(*i, *j);
            i ++; 
            j --;
        }
    }
    if (left < j) Sort(left,j);
    if (right > i) Sort(i,right);
}


int main() {
    long n;
    cin >> n;
    vector<Point> v;
    long x, y;
    for (long i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(Point(x, y));
    }
    Sort(v.begin(), v.end());
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << i->x << " " << i->y << '\n';
    }
    return 0;
}
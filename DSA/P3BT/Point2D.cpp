#include <iostream>
#include <set>
using namespace std;

struct Polong2D {
    long x, y;
    Polong2D(long x, long y) {
        this->x = x;
        this->y = y;
    }
    bool operator < (const Polong2D &p) const {
        if (x == p.x) return y > p.y;
        return x < p.x;
    }
};


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long n;
    cin >> n;
    set<Polong2D> v;
    long x, y;
    for (long i = 0; i < n; i++) {
        cin >> x >> y;
        v.insert(Polong2D(x, y));
    }
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << i->x << " " << i->y << '\n';
    }

    return 0;
}
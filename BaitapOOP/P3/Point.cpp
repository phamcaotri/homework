
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point {
    private:
        float x;
        float y;
    public:
        Point(float x = 0, float y = 0) {
            this->x = x;
            this->y = y;
        }
        float getX() {
            return x;
        }
        float getY() {
            return y;
        }
        void setX(float x) {
            this->x = x;
        }
        void setY(float y) {
            this->y = y;
        }
        void getPoint() {
            cout << "(" << x << "," << y << ")" << endl;
        }
        void setPoint(float x, float y) {
            this->x = x;
            this->y = y;
        }
        void inputPoint() {
            cin >> x >> y;
        }

        void multiXY() {
            x *= 2;
            y *= 2;
        }
        void backToOrigin() {
            x = 0;
            y = 0;
        }
        void ChiThi(int i) {
            if (i == 1) {
                multiXY();
                return;
            }
            if (i == 2) {
                backToOrigin();
                return;
            }
            if (i == 3) {
                int k, d;
                cin >> k >> d;
                if (k == 0) {
                    x += d;
                    return;
                } else {
                    y += d;
                    return;
                }
                return;
            }
        }


};

int main() {
    Point p;
    p.inputPoint();
    int n;
    cin >> n; // số lượng chỉ thị
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; // chỉ thị thứ x
        p.ChiThi(x);
    }
    p.getPoint();
    return 0;
}
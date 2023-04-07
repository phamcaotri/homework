#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const float PI = 3.14;

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
        void move(float dx, float dy) {
            x += dx;
            y += dy;
        }
};

class Polygon {
    private:
        vector<Point> points;
    public:
        Polygon() {}

        void addPoint() {
            Point p;
            p.inputPoint();
            points.push_back(p);
        }
        void getPolygon() {
            for (int i = 0; i < points.size(); i++) {
                points[i].getPoint();
            }
        }

        float DienTich() {
            float s = 0;
            for (int i = 0; i < points.size() - 1; i++) {
                s += (points[i].getX() * points[i + 1].getY() - points[i + 1].getX() * points[i].getY());
            }
            s += (points[points.size() - 1].getX() * points[0].getY() - points[0].getX() * points[points.size() - 1].getY());
            return abs(s / 2);
        }
};

int main() {
    int n; cin >> n;
    Polygon p;
    for (int i = 0; i < n; i++) {
        p.addPoint();
    }
    cout << p.DienTich() << endl;
    

}
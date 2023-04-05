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

class TamGiac {
    private:
        Point a;
        Point b;
        Point c;
    public:
        TamGiac(Point a = 0, Point b = 0, Point c = 0) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        void getTamGiac() {
            a.getPoint();
            b.getPoint();
            c.getPoint();
        }
        void setTamGiac(Point a, Point b, Point c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        void inputTamGiac() {
            a.inputPoint();
            b.inputPoint();
            c.inputPoint();
        }
        void TinhTien() {
            float goc_d, goc_r, d, tinhtien_x, tinhtien_y;
            cin >> goc_d >> d;
            goc_r = goc_d * PI / 180;
            tinhtien_x = d * cos(goc_r);
            tinhtien_y = d * sin(goc_r);
            a.move(tinhtien_x, tinhtien_y);
            b.move(tinhtien_x, tinhtien_y);
            c.move(tinhtien_x, tinhtien_y);
        }
};  

int main() {
    TamGiac tg;
    tg.inputTamGiac();
    tg.TinhTien();
    tg.getTamGiac();

}
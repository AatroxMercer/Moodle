#include <cstdio>
#include <iostream>
using namespace std;

class Pointer {
    private:
        double _x, _y;

    public:
        Pointer() {}
        Pointer(double x, double y) {
            _x = x;
            _y = y;
        }

        void set(double x, double y) {
            _x = x;
            _y = y;
        }
        void setX(double x) {
            _x = x;
        }
        void setY(double y) {
            _y = y;
        }

        double getX() {
            return _x;
        }
        double getY() {
            return _y;
        }
};

class Rectangle {
    private:
        Pointer _left, _right;

    public:
        Rectangle() {}
        Rectangle(Pointer left, Pointer right) {
            set(left, right);
        }

        void set(Pointer left, Pointer right) {
            _left = left;
            _right = right;
        }
        void setLeft(Pointer left) {
            _left = left;
        }
        void setright(Pointer right) {
            _right = right;
        }

        double deltaX() {
            return _right.getX() - _left.getX();
        }
        double deltaY() {
            return _right.getY() - _left.getY();
        }

        double perimeter() {
            return 2 * (deltaY() + deltaX());
        }

        double area() {
            return deltaX() * deltaY();
        }
};

int main(int argc, char const *argv[])
{
    double tempX, tempY;
    Pointer tempPointer;
    Rectangle rectangle;

    cin >> tempX >> tempY;
    tempPointer.set(tempX, tempY);
    rectangle.setLeft(tempPointer);
    cin >> tempX >> tempY;
    tempPointer.set(tempX, tempY);
    rectangle.setright(tempPointer);

    cout << rectangle.perimeter() << " " << rectangle.area() << endl;

    return 0;
}
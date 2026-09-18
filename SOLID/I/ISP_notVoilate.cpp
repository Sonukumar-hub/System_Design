#include <iostream>
using namespace std;

// Interface for 2D shapes
class TwoDShape {
public:
    virtual double area() = 0;
};

// Interface for 3D shapes
class ThreeDShape {
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};


// Square is a 2D shape
class Square : public TwoDShape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override {
        return side * side;
    }
};


// Rectangle is a 2D shape
class Rectangle : public TwoDShape {
private:
    double length, width;

public:
    Rectangle(double l, double w)
        : length(l), width(w) {}

    double area() override {
        return length * width;
    }
};


// Cube is a 3D shape
class Cube : public ThreeDShape {
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double area() override {
        return 6 * side * side;
    }

    double volume() override {
        return side * side * side;
    }
};


int main() {

    TwoDShape* square = new Square(5);
    TwoDShape* rectangle = new Rectangle(4, 6);
    ThreeDShape* cube = new Cube(3);

    cout << square->area() << endl;
    cout << rectangle->area() << endl;
    cout << cube->area() << endl;
    cout << cube->volume() << endl;

    delete square;
    delete rectangle;
    delete cube;

    return 0;
}
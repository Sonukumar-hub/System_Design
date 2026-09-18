#include <iostream>
#include <stdexcept>

using namespace std;

// Single interface for all shapes
class Shape {
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

// Square is a 2D shape but is forced to implement volume()
class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override {
        return side * side;
    }

    double volume() override {
        throw logic_error("Volume not applicable for square");
    }
};


class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w)
        : length(l), width(w) {}

    double area() override {
        return length * width;
    }

    double volume() override {
        throw logic_error("Volume not applicable for rectangle");
    }
};


class Cube : public Shape {
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

    Shape* square = new Square(5);
    Shape* rectangle = new Rectangle(4, 6);
    Shape* cube = new Cube(3);

    cout << "Square Area: " << square->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;

    delete square;
    delete rectangle;
    delete cube;

    return 0;
}
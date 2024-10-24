#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Shapes {
public:
    virtual double area() = 0;
};

class Circle : public Shapes{
public:
    Circle(double radius) : radius(radius) {}

    virtual double area() {
        return M_PI * radius * radius;
    }

private:
    double radius;
};

class Square : public Shapes {
public:
    Square(double side) : side(side) {}

    virtual double area() {
        return side * side;
    }

private:
    double side;
};

class Triangle : public Shapes {
public:
    Triangle(double base, double height) : base(base), height(height) {}

    virtual double area() {
        return 0.5 * base * height;
    }

private:
    double base;
    double height;
};

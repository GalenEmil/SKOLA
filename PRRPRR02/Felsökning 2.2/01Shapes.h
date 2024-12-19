#pragma once

#include <iostream>
#include <sstream>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

using namespace std;

class Shape2D {
public:
    virtual float getArea() = 0;
    virtual void printDetails() = 0;
    virtual string getShortDetails() = 0;
};

class Rectangle : public Shape2D {
public:
    Rectangle(float w, float h) : width(w), height(h) {};

    virtual void printDetails() {
        cout << "Rectangle (" << width << " by " << height << ")" << endl;
    };

    virtual float getArea() {
        return width * height;
    };

    virtual string getShortDetails() {
        stringstream ss;
        ss << "Rect(" << width << ", " << height << ")";
        return ss.str();
    };

    static Shape2D *build() {
        float width, height;
        cout << "What is the width? ";
        cin >> width;
        cout << "What is the height? ";
        cin >> height;

        return new Rectangle(width, height);
    };

private:
    float width, height;
};

class Circle : public Shape2D {
public:
    Circle(float r) : radius(r) {};

    virtual void printDetails() {
        cout << "Circle (radius " << radius << ")" << endl;
    };

    virtual float getArea() {
        return M_PI * radius * radius;
    };

    virtual string getShortDetails() {
        stringstream ss;
        ss << "Circle(" << radius << ")";
        return ss.str();
    };

    static Shape2D *build() {
        float radius;
        cout << "What is the radius? ";
        cin >> radius;

        return new Circle(radius);
    };

private:
    float radius;
};

class ShapeCollection {
public:
    void clearShapes() {
        shapes.clear();
    };

    void addShape(Shape2D *shape) {
        shapes.push_back(shape);
    };

    void printAllShapes() {
        /*Kollar om */
        if(shapes.size() == 0) {
            cout << "None!" << endl;
            return;
        }

        for(int i = 0; i <= (shapes.size() - 1); ++i) {
            cout << shapes[i]->getShortDetails();
            if(i != shapes.size() - 1) {
                cout << ",";
            }
        }
        cout << endl;
    };

    float getTotalArea() {
        float totalArea = 0;
        cout << "---------------------------------" << endl;

        for(Shape2D *shape : shapes) {
            if(shape != nullptr){
                totalArea += shape->getArea();
            }
            }
        cout << "Total area of all the shapes: " << totalArea << endl;
        return totalArea;
    };
private:
    vector<Shape2D *> shapes;
};
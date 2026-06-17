#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string position, color;
    double borderThickness;
public:
    Shape(string pos, string col, double border) {
        position = pos;
        color = col;
        borderThickness = border;
    }
    virtual void draw() {
        cout << "Drawing shape at " << position << " with color " << color << endl;
    }
    virtual double calculateArea() { return 0; }
    virtual double calculatePerimeter() { return 0; }
};

class Circle : public Shape {
    double radius;
public:
    Circle(string pos, string col, double border, double r) : Shape(pos, col, border), radius(r) {}
    void draw() override {
        cout << "Drawing Circle at " << position << " with radius " << radius << endl;
    }
    double calculateArea() override {
        return M_PI * radius * radius;
    }
    double calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(string pos, string col, double border, double w, double h) : Shape(pos, col, border), width(w), height(h) {}
    void draw() override {
        cout << "Drawing Rectangle at " << position << " with width " << width << " and height " << height << endl;
    }
    double calculateArea() override {
        return width * height;
    }
    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
    double base, height, side1, side2, side3;
public:
    Triangle(string pos, string col, double border, double b, double h, double s1, double s2, double s3) 
        : Shape(pos, col, border), base(b), height(h), side1(s1), side2(s2), side3(s3) {}
    void draw() override {
        cout << "Drawing Triangle at " << position << " with base " << base << " and height " << height << endl;
    }
    double calculateArea() override {
        return 0.5 * base * height;
    }
    double calculatePerimeter() override {
        return side1 + side2 + side3;
    }
};

int main() {
    Circle c("(5,5)", "Black", 1.0, 3.0);
    Rectangle r("(4,2)", "Blue", 1.5, 4.0, 6.0);
    Triangle t("(1,2)", "Gray", 2.0, 5.0, 4.0, 3.0, 4.0, 5.0);
    
    c.draw();
    cout << "Circle Area: " << c.calculateArea() << " ** Perimeter: " << c.calculatePerimeter() << endl;
    
    r.draw();
    cout << "Rectangle Area: " << r.calculateArea() << " ** Perimeter: " << r.calculatePerimeter() << endl;
    
    t.draw();
    cout << "Triangle Area: " << t.calculateArea() << " ** Perimeter: " << t.calculatePerimeter() << endl;
    
    return 0;
}


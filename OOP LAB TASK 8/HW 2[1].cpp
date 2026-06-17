#include <iostream>
using namespace std;

class Shape {
    float area;
public:
    void setArea(float a) {
        area = a;
    }

    float Area() const {
        return area;
    }

    Shape operator+(const Shape& s) {
        Shape result;
        result.area = area + s.area;
        return result;
    }
};

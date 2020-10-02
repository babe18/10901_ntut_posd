#ifndef RECTANGLE_H
#define  RECTANGLE_H
#include "shape.h"
#include <math.h>

class Rectangle: public Shape {
    double _length;
    double _width;
public:
    Rectangle(double length, double width): _length(length), _width(width) {
        // If the rectangle can't be successfully created,
        // handle the exception by throwing string "This is not a rectangle!"
        if(_length<=0 || _width<=0)
          throw std::string("This is not a rectangle!");

    }

    double area() const {
        // return the area of the Rectangle.
        double val = _width * _length;
        double _area = (int)(val * 1000) / 1000.0;

        return _area;
    }

    double perimeter() const {
        // return the perimeter of the Rectangle.
        double a = (_width + _length) * 2;
        double b = (int)(a * 1000) / 1000.0;
        return b;
    }

    std::string info() const {
        // return the info of the Rectangle.
        // ex. Rectangle (3.712, 4.000)
        std::string s1 = "Rectangle ";
        char s2[50];
        sprintf(s2, "(%.3f, %.3f)", floor(_length*1000)/1000, floor(_width*1000)/1000);

        return s1 + s2;
    }
};

#endif

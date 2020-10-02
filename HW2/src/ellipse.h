#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"
#include <math.h>

class Ellipse: public Shape{
    double _semiMajorAxes;
    double _semiMinorAxes;

public:
    Ellipse(double semiMajorAxes, double semiMinorAxes): _semiMajorAxes(semiMajorAxes),  _semiMinorAxes(semiMinorAxes) {
        // If the ellipse can't be successfully created,
        // handle the exception by throwing string "This is not a ellipse!"
        if(area()<=0.0 || semiMajorAxes <= 0 || semiMinorAxes <=0 || semiMajorAxes < semiMinorAxes)
          throw std::string("This is not an ellipse!");
    }

    double area() const {
        // return the area of the Ellipse.
        // L=2πb+4(a-b)
        double a = M_PI * _semiMajorAxes * _semiMinorAxes;
        double area = (int)(a * 1000) / 1000.0;
        return area;
    }

    double perimeter() const {
        // return the perimeter of the Ellipse.
        double aa = (2*M_PI*_semiMinorAxes) + 4 * (_semiMajorAxes-_semiMinorAxes);
        double perimeter = (int)(aa * 1000) / 1000.0;
        return perimeter;
    }

    std::string info() const {
        // return the info of the Ellipse.
        // ex. Ellipse (3.712, 4.000)
        std::string s = "Ellipse ";
        char a[50];
        sprintf(a, "(%.3f, %.3f)", floor(_semiMajorAxes*1000)/1000, floor(_semiMinorAxes*1000)/1000);
        return s + a;
    }
};

#endif
#ifndef ELLIPSE_H
#define  ELLIPSE_H
#include "shape.h"
#include <math.h>

class Ellipse: public Shape{
    double _semiMajorAxes;
    double _semiMinorAxes;
public:
    Ellipse(double semiMajorAxes, double semiMinorAxes): _semiMajorAxes(semiMajorAxes),  _semiMinorAxes(semiMinorAxes) {
        // If the ellipse can't be successfully created,
        // handle the exception by throwing string "This is not a ellipse!"
        if(semiMajorAxes <= 0 || semiMinorAxes <=0 || semiMajorAxes < semiMinorAxes)
          throw std::string("This is not a ellipse!");
    }

    double area() const {
        // return the area of the Ellipse.
        double a = M_PI * _semiMajorAxes * _semiMinorAxes;
        double b = (int)(a * 1000) / 1000.0;
        return b;
    }

    double perimeter() const {
        // return the perimeter of the Ellipse.
        // L=2πb+4(a-b)
        double a = (2*M_PI*_semiMinorAxes) + 4 * (_semiMajorAxes-_semiMinorAxes);
        double _perim = (int)(a * 1000) / 1000.0;
        return _perim;
    }

    std::string info() const {
        // return the info of the Ellipse.
        // ex. Ellipse (3.712, 4.000)
        std::string _info = "Ellipse ";
        char a[30];
        sprintf(a, "(%.3f, %.3f)", floor(_semiMajorAxes*1000)/1000.0, floor(_semiMinorAxes*1000)/1000.0);
        return _info + a;
    }
};

#endif

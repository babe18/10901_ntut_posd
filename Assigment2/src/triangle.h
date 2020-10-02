#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <math.h>
#include "shape.h"
#include "two_dimensional_coordinate.h"

class Triangle: public Shape{
    double _x1, _y1, _x2, _y2, _x3, _y3;
    double _e1, _e2, _e3;
public:
    Triangle(std::vector<TwoDimensionalCoordinate*> vectors) {
        // If the triangle can't be successfully created,
        // handle the exception by throwing string "This is not a triangle!"
        if(vectors.size() != 3)
          throw std::string("This is not a triangle!");

        _x1 = vectors[0]->getX(); _y1 = vectors[0]->getY();
        _x2 = vectors[1]->getX(); _y2 = vectors[1]->getY();
        _x3 = vectors[2]->getX(); _y3 = vectors[2]->getY();

        if(_x1==_x2&&_y1==_y2||_x1==_x3&&_y1==_y3||_x2==_x3&&_y2==_y3)
          throw std::string("This is not a triangle!");

        double side12 = (_y1-_y2)/(_x1-_x2);
        double side13 = (_y1-_y3)/(_x1-_x3);
        double side23 = (_y2-_y3)/(_x2-_x3);


        if(_x1==_x2 && _x2==_x3 || _y1==_y2 && _y2==_y3)
            throw std::string("This is not a triangle!");
        if(side12 == side13 || side13==side23)
            throw std::string("This is not a triangle!");


        _e1 = sqrt((_x1-_x2) * (_x1-_x2) + (_y1-_y2) * (_y1-_y2));
        _e2 = sqrt((_x1-_x3) * (_x1-_x3) + (_y1-_y3) * (_y1-_y3));
        _e3 = sqrt((_x2-_x3) * (_x2-_x3) + (_y2-_y3) * (_y2-_y3));
    }

    double area() const {
        // return the area of the Triangle.
        double val = abs((_x1*(_y2-_y3) + _x2*(_y3-_y1) + _x3*(_y1-_y2))/2);
        double _area = (int)(val * 1000) / 1000.0;
        return _area;
    }

    double perimeter() const {
        // return the perimeter of the Triangle.
        double val = _e1 + _e2 + _e3;
        double _perim = (int)(val * 1000) / 1000.0;
        return _perim;
    }

    std::string info() const {
        // return the info of the Triangle.
        // ex. Triangle ([0.000, 0.000], [0.000, -3.141], [-4.000, 0.000])
        std::string _info = "Triangle ";
        char values[100];
        sprintf(values, "([%.3f, %.3f], [%.3f, %.3f], [%.3f, %.3f])", floor(_x1*1000)/1000, floor(_y1*1000)/1000, floor(_x2*1000)/1000, floor(_y2*1000)/1000, floor(_x3*1000)/1000, floor(_y3*1000)/1000);
        return _info + values;
    }
};

#endif

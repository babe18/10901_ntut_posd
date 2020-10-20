#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include <sstream>

#include "shape.h"
#include "two_dimensional_coordinate.h"

#ifndef TRIANGLE
#define TRIANGLE
class Triangle: public Shape {
private:
    double _sideA, _sideB, _sideC;
    std::vector<TwoDimensionalCoordinate*> _vectors;
    bool IsTriangle(std::vector<TwoDimensionalCoordinate*> vectors) {
        _sideA = sqrt(pow(vectors[0]->getX() - vectors[1]->getX(), 2) + pow(vectors[0]->getY() - vectors[1]->getY(), 2));
        _sideB = sqrt(pow(vectors[1]->getX() - vectors[2]->getX(), 2) + pow(vectors[1]->getY() - vectors[2]->getY(), 2));
        _sideC = sqrt(pow(vectors[2]->getX() - vectors[0]->getX(), 2) + pow(vectors[2]->getY() - vectors[0]->getY(), 2));
        
        if (_sideA + _sideB > _sideC && _sideA + _sideC > _sideB && _sideB + _sideC > _sideA) 
            return true;
        return false;
    }

    std::string doubleToString(TwoDimensionalCoordinate* coordinate) const {
        char buffer[50];
        sprintf(buffer, "[%.3f, %.3f]", floor(coordinate->getX()*1000)/1000, floor(coordinate->getY()*1000)/1000);
        std::string str(buffer);
        return str;
    }

public: 
    Triangle(std::vector<TwoDimensionalCoordinate*> vectors) {
        if (vectors.size() == 3 && IsTriangle(vectors))
        {
            _vectors = vectors;
        }
        else {
            throw std::string("This is not a triangle!");
        }
        // If the triangle can't be successfully created,
        // handle the exception by throwing string "This is not a triangle!"
    }
    
    double area() const {
        double s = (_sideA + _sideB + _sideC) / 2.0;
        double answer = sqrt(s * (s-_sideA) * (s-_sideB) * (s-_sideC));
        return answer;
        // return the area of the Triangle.
    }
    
    double perimeter() const {
        return _sideA + _sideB + _sideC;
        // return the perimeter of the Triangle.
    }    

    std::string info() const {
        std::stringstream sString;
        sString << "Triangle ("<< doubleToString(_vectors[0]) << ", " << doubleToString(_vectors[1]) << ", " << doubleToString(_vectors[2]) << ")";
        return sString.str();
        // return the info of the Triangle.
        // ex. Triangle ([0.000, 0.000], [0.000, -3.141], [-4.000, 0.000])
    }

    ~Triangle() {
        for (auto p: _vectors)
            delete p;
        _vectors.clear();
    }
};
#endif
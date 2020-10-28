#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<cmath>
#include"shape.h"
#include<string>


class Rectangle: public Shape {
public:
    Rectangle(std::string id,double length, double width): Shape(id) {
        _length = length;
        _width = width;
        strlength = std::to_string(length);
        strwidth = std::to_string(width);
        str_an ="Rectangle ("+strlength.erase(strlength.length()-3,strlength.length()-1)+", "+strwidth.erase(strwidth.length()-3,strwidth.length()-1)+")";

        if(length<=0||width<=0)
          throw std::string("This is not a rectangle!");
        // If the rectangle can't be successfully created,
        // handle the exception by throwing string "This is not a rectangle!"
    }

    Rectangle(std::string id,double length, double width,std::string color): Shape(id,color) {
        _length = length;
        _width = width;
        strlength = std::to_string(length);
        strwidth = std::to_string(width);
        str_an ="Rectangle ("+strlength.erase(strlength.length()-3,strlength.length()-1)+", "+strwidth.erase(strwidth.length()-3,strwidth.length()-1)+")";

        if(length<=0||width<=0)
          throw std::string("This is not a rectangle!");
    }

    double area() const {
        return _length*_width;
        // return the area of the Rectangle.
    }

    double perimeter() const {
        return 2*_length+2*_width;
        // return the perimeter of the Rectangle.
    }

    std::string info() const {
      return str_an;
        // return the info of the Rectangle.
        // ex. Rectangle (3.712, 4.000)
    }
    std::string type() const {
      std::string type_name = "Rectangle";
      return type_name;
    }
private:
    double _length,_width;
    std::string str_an,strlength,strwidth;
};
#endif

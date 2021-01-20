#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "./shape.h"
#include <sstream>
#include "shape_visitor.h"

class Rectangle : public Shape {
public:
  Rectangle(double width, double height) {
    _width = width;
    _height = height;
  }

  double area() const {
    return _width * _height;
  }

  void accept(ShapeVisitor &sv) {
    sv.visitRectangle(this);
  }
  
  std::string toString(std::string s) const {
    std::stringstream ss;
    ss << s << "rect " << _width << " " << _height <<"\n";
    return ss.str();
  }
  
  std::string toString() const {
    std::stringstream ss;
    ss << "rect " << _width << " " << _height <<"\n";
    return ss.str();
  }

private:
  //data members
  double _width, _height;
};
#endif

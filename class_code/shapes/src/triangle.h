#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "./shape.h"
#include <math.h>
#include <sstream>
#include "shape_visitor.h"

class Triangle : public Shape {
public:
  Triangle(double a, double b, double c):_a(a),_b(b),_c(c) {} // constructor initialization

  double area() const {
    double s = (_a + _b + _c) / 2;
    return sqrt(s * (s - _a) * (s - _b) * (s - _c));
  }
  void accept(ShapeVisitor &sv) {
    sv.visitTriangle(this);
  }

  std::string toString(std::string s) const {
    std::stringstream ss;
    ss << s << "tri " << _a << " " << _b << " " << _c << "\n";
    return ss.str();
  }
  
  std::string toString() const {
    std::stringstream ss;
    ss << "tri " << _a << " " << _b << " " << _c << "\n";
    return ss.str();
  }

private:
  double _a, _b, _c;
};
#endif

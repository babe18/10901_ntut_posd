#ifndef TOSTRING_VISITOR_H
#define TOSTRING_VISITOR_H
#include "shape_visitor.h"
#include <string>

class Rectangle;
class Triangle;
class MixedShape;
class Shape;

class ToStringVisitor : public ShapeVisitor {
public:
    void visitRectangle(Rectangle *r);
    void visitTriangle(Triangle *t);
    void visitMixedShape(MixedShape *m);
    std::string getResult();
private:
    std::string _result;
    std::string _indent;
};

#endif
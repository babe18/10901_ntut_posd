#ifndef FIND_FIRST_VISITOR_H
#define FIND_FIRST_VISITOR_H

#include "shape_visitor.h"

class Rectangle;
class Triangle;
class MixedShape;
class Shape;

typedef bool (*BoolOnShape)(Shape *);

class FindFirstVisitor : public ShapeVisitor {

public:
  FindFirstVisitor(BoolOnShape f): _f(f), _result(nullptr) {}
  void visitRectangle(Rectangle *rect);
  void visitTriangle(Triangle *tri);
  void visitMixedShape(MixedShape *ms);
  Shape * getResult();
private:
  BoolOnShape _f;
  Shape *_result;
};


#endif

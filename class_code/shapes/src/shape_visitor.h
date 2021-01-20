#ifndef SHAPE_VISITOR_H
#define SHAPE_VISITOR_H

class Rectangle;
class Triangle;
class MixedShape;

class ShapeVisitor {
public:
  virtual void visitRectangle(Rectangle *r) = 0;
  virtual void visitTriangle(Triangle *t) = 0;
  virtual void visitMixedShape(MixedShape *m) = 0;
};

#endif

#ifndef SHAPE_H
#define SHAPE_H

#include "iterator.h"
#include "null_iterator.h"
#include "shape_visitor.h"

class Shape {
public:
  virtual void add(Shape * shape) {
    throw (std::string)"Can't support this operation.";
  }
  virtual double area() const = 0;
  virtual Iterator * createIterator() const {
    return new NullIterator();
  };
  virtual void accept(ShapeVisitor &sv) {}
  virtual ~Shape(){};
  virtual std::string toString(std::string s) const{ return s;}
  virtual std::string toString() const{ return "";}
};

class AreaSmaller {
public:
  bool operator()(Shape * a, Shape * b) {
    return a->area() < b->area();
  }
};

#endif

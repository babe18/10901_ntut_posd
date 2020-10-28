#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include "shape.h"
#include <cmath>
#include <string>
#include <deque>
#include <list>


template <class Filter>
std::deque<Shape*> filterShape(Shape* shape, Filter filter) {
    Iterator * shapeIterator = shape->createIterator();
    std::deque<Shape*> dqshapes1;
    std::deque<Shape*> dqshapes2;

    if(shapeIterator->isDone())
      throw std::string ("Only compound shape can filter shape!");

    for(shapeIterator->first();!shapeIterator->isDone();shapeIterator->next()){
      if(!shapeIterator->currentItem()->createIterator()->isDone())
        dqshapes2 = filterShape(shapeIterator->currentItem(),filter);

      if(filter(shapeIterator->currentItem()))
        dqshapes1.push_back(shapeIterator->currentItem());
    }
    // access the shape with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return the shapes under the input shape tree sturcture that match the given filter.
    // throw std::string "Only compound shape can filter shape!" when the input shape is not iterable.
    std::deque<Shape*>::iterator it = dqshapes2.begin();
    for(it;it!=dqshapes2.end();it++){
      dqshapes1.push_back(*it);
    }

    return dqshapes1;
}


Shape* getShapeById(Shape* shape, std::string id) {
    Iterator * it = shape->createIterator();
    if(it->isDone()){
      throw std::string("Only compound shape can get shape!");
    }
    return shape->getShapeById(id);
    // access the shape with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return a shape under the input shape tree sturcture that matches the id.
    // throw std::string "Only compound shape can get shape!" when the input shape is not iterable.
    // throw std::string "Expected get shape but shape not found" when no shape found with the given id.
}

class AreaFilter {
public:
    AreaFilter(double upperBound, double lowerBound) {
      _upperBound = upperBound;
      _lowerBound = lowerBound;
    }
    bool operator() (Shape* shape) const {
      return shape->area() <= _upperBound && _lowerBound <= shape->area();
    }
private:
    double _upperBound,_lowerBound;
};

class PerimeterFilter {
public:
    PerimeterFilter(double upperBound, double lowerBound) {
      _upperBound = upperBound;
      _lowerBound = lowerBound;
    }
    bool operator() (Shape* shape) const {
      return _upperBound >= shape->perimeter() && shape->perimeter() >=_lowerBound;
    }
private:
      double _upperBound,_lowerBound;
};
//
class ColorFilter {
public:
    ColorFilter(std::string color) {
      _color = color;
    }
    bool operator() (Shape* shape) const {
      return shape->color() == _color;
    }
private:
  std::string _color;
};
//
class TypeFilter {
public:
    TypeFilter(std::string type) {
      _type = type;
    }
    bool operator() (Shape* shape) const {
      return shape->type() == _type;
    }
private:
  std::string _type;
};
#endif

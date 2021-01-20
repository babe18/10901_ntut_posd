#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <deque>
#include "shape.h"
#include <list>
using namespace std;
Shape* getShapeById(Shape* shape, std::string id){
  Iterator * it = shape->createIterator();
    if(it->isDone()){
      throw std::string("Only compound shape can get shape!");
  }
  bool NoMatch = 1;
  for (it->first(); !it->isDone(); it->next()) {
          if (id == it->currentItem()->id()){
              NoMatch = 0;
              break;
          }
          else if (!it->currentItem()->createIterator()->isDone())
            return it->currentItem()->getShapeById(id);
  }
  if(NoMatch){
    throw std::string("Expected get shape but shape not found");
  }
  return it->currentItem();
}
template <class Filter>
std::deque<Shape*> filterShape(Shape* shape, Filter filter) {
  Iterator * it = shape->createIterator();
  std::deque<Shape*> _shape1;
  std::deque<Shape*> _shape2;
  if(it->isDone()){
      throw std::string ("Only compound shape can filter shape!");
    }
  for (it->first();!it->isDone(); it->next()){
      if(!(it->currentItem()->createIterator()->isDone())){
        _shape2 = filterShape(it->currentItem(), filter);
      }
      if(filter(it->currentItem())){
        _shape1.push_back(it->currentItem());
      }

    }
  std::deque<Shape*>::iterator ite = _shape2.begin();
  for ( ite; ite != _shape2.end(); ite++){
      _shape1.push_back(*ite);
  }
  return  _shape1;
}



class AreaFilter {
public:
      AreaFilter(double upperBound, double lowerBound): _upperBound(upperBound),_lowerBound(lowerBound) {}
      bool operator() (Shape* shape) const {
      return ((_lowerBound <= shape->area()) && (shape->area() <= _upperBound));
      }
private:
    double _upperBound,_lowerBound;
};

class PerimeterFilter {
public:
    PerimeterFilter(double upperBound, double lowerBound): _upperBound(upperBound),_lowerBound(lowerBound){}
    bool operator() (Shape* shape) const {
      return ((_lowerBound <= shape->perimeter()) && (shape->perimeter() <= _upperBound));
    }
private:
      double _upperBound,_lowerBound;
};

class ColorFilter {
public:
    ColorFilter(std::string color):_color(color){}
    bool operator() (Shape* shape) const {
      return (shape->color() == _color);
    }
private:
        string _color;
};

class TypeFilter {
public:
    TypeFilter(std::string type):_type(type){}
    bool operator() (Shape* shape) const {
      return (shape->type() == _type);
    }
private:
        string _type;
};

#endif

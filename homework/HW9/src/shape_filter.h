#pragma once

#ifndef SHAPE_FILTER_H
#define SHAPE_FILTER_H
#include "filter.h"
#include "shape.h"
#include <list>

typedef bool (*Predicate)(Shape *);

class ShapeFilter : public Filter {
public:
    ShapeFilter(Predicate pred): _p(pred) {}

    Filter* setNext(Filter* filter) {
      _f = filter;
      return _f;
    }

    std::list<Shape*> push(std::list<Shape*> shapes) {
      std::list<Shape*> result;
      _shapes = shapes;
      for(auto ite : _shapes){
        if(_p(ite)){
          result.push_back(ite);
        }
        if(_f){
          result = _f->push(result);
        }
      }
      return result;
    }

private:
    Predicate _p;
    Filter * _f = nullptr;
    std::list<Shape*> _shapes;
};

#endif

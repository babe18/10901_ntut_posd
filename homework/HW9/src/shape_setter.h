#ifndef SHAPE_SETTER_H
#define SHAPE_SETTER_H
#include "filter.h"
#include "shape.h"
#include <list>

typedef void (*Setter)(Shape*);

class ShapeSetter : public Filter {
public:

    ShapeSetter(Setter set): _s(set) {}

    Filter* setNext(Filter* filter) {
      _f = filter;
      return _f;
    }

    std::list<Shape*> push(std::list<Shape*> shapes) {
      std::list<Shape*> result;
      _shapes = shapes;
      for(auto ite : _shapes){
        _s(ite);
        result.push_back(ite);
        if(_f){
          result = _f->push(result);
        }
      }
      return result;
    }

private:
    Setter _s;
    Filter * _f = nullptr;
    std::list<Shape*> _shapes;
};

#endif

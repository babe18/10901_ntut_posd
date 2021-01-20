#ifndef SHAPE_ITERATOR_H
#define SHAPE_ITERATOR_H

#include "shape.h"
#include "iterator.h"

template<class ForwardIterator>
class ShapeIterator : public Iterator {

public:
  ShapeIterator(ForwardIterator begin, ForwardIterator end):
    _begin(begin), _end(end){
      first();
  }

  Shape * currentItem() const {
    return * _current;
  }

  void next() {
    _current ++;
  }

  bool isDone() const {
    return _current == _end;
  }

  void first() {
    _current = _begin;
  }

private:
  ForwardIterator _begin;
  ForwardIterator _end;
  ForwardIterator _current;
};

typedef bool (* fn)(Shape * a);

template<class Iterator, class Constraint>
Shape * findFirst(Iterator * it, Constraint constraint) {

  for(it->first(); !it->isDone(); it->next()) {
    Shape * s = it->currentItem();
    if(constraint(s))
      return s;
    Iterator * ita = s->createIterator();
    if(!ita->isDone()) {
      Shape * ss = findFirst(ita, constraint);
      if(ss)
        return ss;
    }
  }
  return nullptr;
}

#endif

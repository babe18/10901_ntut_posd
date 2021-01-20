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

    void first() {
        _current = _begin;
        // initialize iterator.
    }

    void next() {
      if(isDone()){
        throw std::string ("Moving past the end!");
      }
      _current ++;
        // move iterator to next position,
    }

    bool isDone() const {
      return _current == _end;
        // return true when iterator reach the end of the structure.
    }

    Shape* currentItem() const {
          return * _current;
        // return the shape that iterator currently point at.
    }
private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;
};

#endif

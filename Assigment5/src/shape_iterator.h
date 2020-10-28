#ifndef SHAPE_ITERATOR_H
#define SHAPE_ITERATOR_H
#include "iterator.h"
#include <string>
#include "shape.h"
#include <list>

template<class ForwardIterator>
class ShapeIterator : public Iterator {
public:
    ShapeIterator(ForwardIterator begin, ForwardIterator end) {
        _begin = begin;
        _end = end;
        _currentItem = begin;
    }

    void first() {
        _currentItem = _begin;
    }

    void next() {
        if(_currentItem == _end)
        throw std::string ("Moving past the end!");
        else
          _currentItem ++;
    }

    bool isDone() const {
        return _currentItem == _end;
    }

    Shape* currentItem() const {
        return *_currentItem;
    }

private:
  std::list<Shape*>::const_iterator _currentItem;
  std::list<Shape*>::const_iterator _begin;
  std::list<Shape*>::const_iterator _end;
};
#endif

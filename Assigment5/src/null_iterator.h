#ifndef NULL_ITERATOR_H
#define NULL_ITERATOR_H
#include "shape.h"
#include "iterator.h"
#include <string>

class NullIterator : public Iterator {
public:
  void first(){
    throw std::string("No child member!");
  }
  void next() {
    throw std::string("No child member!");
  }

  bool isDone() const {
    return true;
  }

  Shape* currentItem() const {
    throw std::string("No child member!");
  }
};
#endif

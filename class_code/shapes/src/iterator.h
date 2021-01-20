#ifndef ITERATOR_H
#define ITERATOR_H

class Shape;

class Iterator {
public :
  virtual Shape * currentItem() const = 0;

  virtual void next() = 0;

  virtual bool isDone() const = 0;

  virtual void first() = 0;
};
#endif

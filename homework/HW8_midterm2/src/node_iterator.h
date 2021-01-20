#ifndef NODE_ITERATOR_H
#define NODE_ITERATOR_H
#include "node.h"
#include "iterator.h"

template<class ForwardIterator>
class NodeIterator : public Iterator {
public:
  NodeIterator(ForwardIterator begin, ForwardIterator end):
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

    Node* currentItem() const {
          return * _current;
        // return the shape that iterator currently point at.
    }
private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;
};

#endif

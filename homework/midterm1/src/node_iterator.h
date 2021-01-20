#ifndef NODE_ITERATOR_H
#define NODE_ITERATOR_H
#include "iterator.h"
#include <string>
#include "node.h"
#include <list>

template<class ForwardIterator>
class NodeIterator : public Iterator {
public:
    NodeIterator(ForwardIterator begin, ForwardIterator end) {
        _begin = begin;
        _end = end;
        first();
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

    Node* currentItem() const {
      return * _currentItem;
    }
private:
  ForwardIterator _begin,_end,_currentItem;
};
#endif

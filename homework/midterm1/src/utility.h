#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include "node.h"
#include <cmath>
#include <string>
#include <deque>
#include <list>


template <class Filter>
std::deque<Node*> filterNode(Node* node, Filter filter) {
    Iterator * nodeIterator = node->createIterator();
    std::deque<Node*> dqnode1;
    std::deque<Node*> dqnode2;

    if(nodeIterator->isDone())
      throw std::string ("Only folder can filter node!");

    for(nodeIterator->first();!nodeIterator->isDone();nodeIterator->next()){

      if(filter(nodeIterator->currentItem()))
        dqnode1.push_back(nodeIterator->currentItem());
      if(!nodeIterator->currentItem()->createIterator()->isDone()){
        dqnode2 = filterNode(nodeIterator->currentItem(),filter);
        std::deque<Node*>::iterator it = dqnode2.begin();
        for(it;it!=dqnode2.end();it++){
          dqnode1.push_back(*it);
        }
      }

    }



    return dqnode1;
}

class SizeFilter {
public:
    SizeFilter(double upperBound, double lowerBound) {
      _upperBound = upperBound;
      _lowerBound = lowerBound;
    }
    bool operator() (Node* node) const {
      return _upperBound >= node->size() && node->size() >= _lowerBound;
    }
private:
  double _upperBound,_lowerBound;
};
#endif

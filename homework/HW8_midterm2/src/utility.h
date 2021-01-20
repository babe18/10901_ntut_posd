#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <deque>
#include "node.h"
#include <list>
using namespace std;
template <class Filter>
std::deque<Node*> filterNode(Node* node, Filter filter) {
  Iterator * it = node->createIterator();
  std::deque<Node*> _node1;
  std::deque<Node*> _node2;
  if(it->isDone()){
      throw std::string ("Only folder can filter node!");
    }
  for (it->first();!it->isDone(); it->next()){

      if(filter(it->currentItem())){
        _node1.push_back(it->currentItem());
      }
      if(!(it->currentItem()->createIterator()->isDone())){
        _node2 = filterNode(it->currentItem(), filter);
        std::deque<Node*>::iterator ite = _node2.begin();
        for ( ite; ite != _node2.end(); ite++){
            _node1.push_back(*ite);
        }
      }
    }

  return  _node1;
}



class SizeFilter {
public:
    SizeFilter(double upperBound, double lowerBound): _upperBound(upperBound),_lowerBound(lowerBound) {}
    bool operator() (Node* node) const {
       return ((_lowerBound <= node->size()) && (node->size() <= _upperBound));
    }
private:
    double _upperBound,_lowerBound;
};
#endif

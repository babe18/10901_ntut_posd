#ifndef SORT_H
#define SORT_H
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <functional>
using namespace std;

template <typename RandomAccessIterator, typename Compare>
void quickSort(RandomAccessIterator first,RandomAccessIterator last,Compare compare)
{
  std::vector<Shape*>::iterator it;
  int count = 0;
  int pivot = 0;
  for (it = first; it != last; ++it){
    count++;
  }
  MyQuickSort(first,0,count,compare);
}

template <typename RandomAccessIterator, typename Compare>
void MyQuickSort(std::vector<Shape*>::iterator it,RandomAccessIterator first,RandomAccessIterator last,Compare compare)
{
  if(first < last){
    int pivot = Partition(it,first,last,compare);
    MyQuickSort(it,first,pivot,compare);
    MyQuickSort(it,pivot+1,last,compare);
  }
}

template <typename RandomAccessIterator, typename Compare>
int Partition(std::vector<Shape*>::iterator it,RandomAccessIterator first,RandomAccessIterator last,Compare compare)
{
//  std::vector<Shape*> _v;
//  it=_v.begin();
  Shape *pivot=*(it+last-1);
  int i=first - 1;
  for(int j=first;j<last;j++){
    if(compare(*(it+j),pivot)){
      i++;
      swap((*(it+i)),(*(it+j)));
    }
  }
  i++;

  swap((*(it+i)),(*(it+last-1)));
  return i;
}

// implement following call back function
bool areaAscendingCompare(Shape *a, Shape *b){
  return a->area() < b->area();
};
bool areaDescendingCompare(Shape *a, Shape *b){
  return a->area() > b->area();
};
bool perimeterAscendingCompare(Shape* a,Shape* b){
  return a->perimeter() < b->perimeter();
};
bool perimeterDescendingCompare(Shape* a,Shape* b){
  return a->perimeter() > b->perimeter();
};

class AscendingCompare{
public:
    AscendingCompare(string instruction): _instruction(instruction){}
    bool operator()(Shape* a,Shape*b){
      if(_instruction=="area"){
        return a->area() < b->area();
      }
      else if(_instruction=="perimeter"){
        return a->perimeter() < b->perimeter();
      }
      else{
        cout<<"no any instruction"<<endl;
        return false;
      }
    }
private:
  string _instruction;
};
class DescendingCompare{
public:
    DescendingCompare(string instruction): _instruction(instruction){}
    bool operator()(Shape* a,Shape*b){
      if(_instruction=="area"){
        return a->area() > b->area();
      }
      else if(_instruction=="perimeter"){
        return a->perimeter() > b->perimeter();
      }
      else{
        cout<<"no any instruction"<<endl;
        return false;
      }
    }
  private:
    string _instruction;
};

#endif

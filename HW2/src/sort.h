#ifndef SORT_H
#define SORT_H

struct DescendingPerimeterObj {
  bool operator() (Shape * a, Shape * b) { return a->perimeter() > b->perimeter();}
} desPerimeterObject;

bool areaAscendingCompare(Shape *a, Shape *b) {
  return ( a->area() < b->area() );
};

bool areaDescendingCompare(Shape *a, Shape *b) {
  return ( a->area() > b->area() );
};

bool perimeterAscendingCompare(Shape *a, Shape *b) {
  return ( a->perimeter() < b->perimeter() );
};

bool perimeterDescendingCompare(Shape *a, Shape *b) {
  return ( a->perimeter() > b->perimeter() );
};


class AscendingCompare{
  public:
    bool operator()(Shape * a, Shape * b) {
      if(_feature == std::string("area"))
        { return a->area() < b->area();}
      if(_feature == std::string("perimeter"))
        { return a->perimeter() < b->perimeter();}
    }
    AscendingCompare(std::string feature): _feature(feature) {}
  private:
    std::string _feature;
};

class DescendingCompare{
  public:
    bool operator()(Shape * a, Shape * b) {
      if(_feature == std::string("area"))
        { return a->area() > b->area();}
      if(_feature == std::string("perimeter"))
        { return a->perimeter() > b->perimeter();}
    }
    DescendingCompare(std::string feature): _feature(feature) {}
  private:
    std::string _feature;
};



template <class RandomAccessIterator, class Compare>
void quickSort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
  if(std::distance(first, last) > 1) {
    RandomAccessIterator pivot = partit(first, last, comp);
    quickSort(first, pivot, comp);
    quickSort(pivot+1, last, comp);
  }
}

template <class RandomAccessIterator, class Compare>
RandomAccessIterator partit(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
  RandomAccessIterator i = first-1;
  RandomAccessIterator pvt = std::prev(last,1);
  for (RandomAccessIterator j = first; j < pvt; j++){
    if (comp(*j, *pvt)){
      *i++;
      std::swap(*i, *j);
    }
  }
  *i++;
  std::swap(*i, *pvt);
  return i;
}

#endif

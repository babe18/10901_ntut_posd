#include "shape.h"

#ifndef SORT
#define SORT
/*
    Ascending 升冪
    Descending 降冪
*/
bool areaAscendingCompare(Shape *a, Shape *b) {
    return a->area() < b->area();
};

bool areaDescendingCompare(Shape *a, Shape *b) {
    return a->area() > b->area();
};

bool perimeterAscendingCompare(Shape *a, Shape *b) {
    return a->perimeter() < b->perimeter();
};

bool perimeterDescendingCompare(Shape *a, Shape *b) {
    return a->perimeter() > b->perimeter();
};

template <class RandomAccessIterator, class Compare>
void quickSort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    size_t flag = std::distance(first, last);
    if (flag <= 1)
        return;

    RandomAccessIterator p = last;

    p--;

    RandomAccessIterator left  = first;
    RandomAccessIterator right = p;
    while (left != right) {
        while (!comp(*p, *left)  && left != right)
            left++;
        while (!comp(*right, *p) && left != right)
            right--;
        if (left != right)
            std::iter_swap(left, right);
    }

    if (p != left && comp(*p, *left))
        std::iter_swap(p, left);

    quickSort(first,  left, comp);
    quickSort(++left, last, comp);
}

class AscendingCompare {
private:
    std::string const _feature;
public:
    AscendingCompare(std::string feature): _feature(feature) {}
    bool operator()(Shape *a, Shape *b) {
        if (_feature == "area")
            return areaAscendingCompare(a, b);
        return perimeterAscendingCompare(a, b);
    }
};

class DescendingCompare {
private:
    std::string const _feature;
public:
    DescendingCompare(std::string feature): _feature(feature) {}
    bool operator()(Shape *a, Shape *b) {
        if (_feature == "area")
            return areaDescendingCompare(a, b);
        return perimeterDescendingCompare(a, b);
    }
};

#endif // SORT
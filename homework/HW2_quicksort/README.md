# **Pattern Oriented Software Design 2020 Fall Assignment 2**  

## **Notice**  
* **Due on Tuesday, September 29, 2020 23:59.**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **For return string of number, should be in form of `%3f`.**  

## **Score**

1. Unit tests written by yourself: 30%.  
2. Unit tests written by TA: 50%.  
3. Implementaion of `quickSort()`: 20%.  

## **Useful Reference**
[C++ Vector](http://www.cplusplus.com/reference/vector/vector/)  
[C++ Sort](http://www.cplusplus.com/reference/algorithm/sort/)  
[C++ Function Templates](http://www.cplusplus.com/doc/oldtutorial/templates/)  
[QuickSort Wiki](https://en.wikipedia.org/wiki/Quicksort)  

## **Requirement**  
1. Modify exception handling of class `Ellipse`.  
*  Change the exception string into "This is not an ellipse!"  
*  Make sure semiMajorAxes >= semiMinorAxes. If not, throw exception "This is not an ellipse!" in constructor.   

2. Implement `quickSort()` in `sort.h` and write corresponding unit test in `ut_sort.h`.  
```
template <class RandomAccessIterator, class Compare>
void quickSort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {}
```
* `Compare`: Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool. It should be able to accpet `Lambda Expressions`, `Funtion`, `Object` and you should write test that covers them. (You may reference [C++ Sort](http://www.cplusplus.com/reference/algorithm/sort/))  
* `RandomAccessIterator`: Random-access iterators to the initial and final positions of the sequence to be sorted. (You may reference [C++ Sort](http://www.cplusplus.com/reference/algorithm/sort/))  
* `quickSort()`: Implement a quicksort function **WITHOUT using any sorting function from c/c++ library**, you should write the sorting algorithm by yourself. (You may reference [QuickSort Wiki](https://en.wikipedia.org/wiki/Quicksort))  

3. Implement the following function in `sort.h`.  

```
bool areaAscendingCompare(Shape *a, Shape *b) {};

bool areaDescendingCompare(Shape *a, Shape *b) {};

bool perimeterAscendingCompare(Shape *a, Shape *b) {};

bool perimeterDescendingCompare(Shape *a, Shape *b) {};

```
* The following is the example usage of compare funtion.  
```
    quickSort(shapes.begin(), shapes.end(), areaAscendingCompare);
```

4. Implement class `AscendingCompare` and `DescendingCompare` in `sort.h`.
```
class AscendingCompare{
  public:
    AscendingCompare(std::string feature): _feature(feature) {}
};

class DescendingCompare{
  public:
    DescendingCompare(std::string feature): _feature(feature) {}
};
```
* `feature`: is the feature of shape you wanted to compare, meaning "area" and "perimeter".  
* The following is the example usage of compare object.  
```
    quickSort(shapes.begin(), shapes.end(), AscendingCompare("area"));
```

## **File Structure**
This time your directory structure should be like:
```
{學號}_hw
    ├── bin
    │   └── ut_main
    ├── src
    │   ├── shape.h
    │   ├── ellipse.h
    │   ├── rectangle.h
    │   ├── triangle.h
    │   ├── sort.h
    │   └── two_dimensional_coordinate.h
    ├── test
    │   ├── ut_main.cpp
    │   ├── ut_ellipse.h
    │   ├── ut_rectangle.h
    │   ├── ut_sort.h
    │   └── ut_triangle.h
    └── makefile
```
# **Pattern Oriented Software Design 2020 Fall Assignment 5**  

## **Notice**  
* **Due on Tuesday October 27 2020, 23:59.**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **You should add unit test for each requirment under corresponding ut_file.**  
* **DO NOT use any Type Checking or Dynamic Type that would violate OCP to implement Composite pattern and Iterator pattern, -40 point if you do so.**  

## **Score**  
1. Source Code(Implementation + unit test): 40%.  
2. Unit tests written by TA: 60%.  

## **Useful Reference**  
[Composite Pattern](https://refactoring.guru/design-patterns/composite)  
[Iterator Pattern](https://refactoring.guru/design-patterns/iterator)  
[Factory Pattern](https://refactoring.guru/design-patterns/factory-method)  
[Open–closed principle](http://joelabrahamsson.com/a-simple-example-of-the-openclosed-principle/)  
[std::list](http://www.cplusplus.com/reference/list/list/)  
[std::deque](http://www.cplusplus.com/reference/deque/deque/)  
[List vs Vector](https://www.geeksforgeeks.org/difference-between-vector-and-list/)  
[Deque vs Vector](https://www.geeksforgeeks.org/deque-vs-vector-in-c-stl/)  
[Const vs Regular iterators](https://www.geeksforgeeks.org/const-vs-regular-iterators-in-c-with-examples/)  

## **Requirement**  
1. Add `type()` and `createIterator()` in `Shape`.  
   For this assigment you will practice to declare the `Shape` class in `shape.h` and implemtation in `shape.cpp`,  
   and your `Shape` interface will be same as following.  
```
class Shape {
public:
        Shape(std::string id);

        Shape(std::string id, std::string color);

        std::string id() const;

        std::string color() const;

        virtual double area() const = 0;

        virtual double perimeter() const = 0;
  
        virtual std::string info() const = 0;
    
        virtual std::string type() const = 0;

        virtual void addShape(Shape* shape);

        virtual void deleteShapeById(std::string id);

        virtual Shape* getShapeById(std::string id) const;
        
        virtual Iterator* createIterator() const;

        virtual ~Shape();

private:
        std::string _id, _color;
};
```
* `type()`: type of shape is "Ellipse", "Rectangle", "Triangle", "Compound Shape".  
* `createIterator()`: return "NullIterator".  

2. Add the following function in `CompoundShape` and modify (Not overloading) the constructor as following.  
```
class CompoundShape {
    CompoundShape(std::string id, std::list<Shape*> shapes) {}
    Iterator* createIterator() const {
        // return ShapeIterator
    }
}
```

3. Add `Iterator` class interface in `iterator.h`.  
```
class Iterator {
public:
    virtual void first() = 0;
    
    virtual void next() = 0;
    
    virtual bool isDone() const = 0;
    
    virtual Shape* currentItem() const = 0;
};
```

4. Implement `NullIterator` class in `null_iterator.h` and the corresponding unit test in `ut_iterator.h`.  
```
class NullIterator : public Iterator {
public:
    void first() {
        // throw std::string "No child member!"
    }

    void next() {
        // throw std::string "No child member!"
    }
    
    bool isDone() const {
        // return true
    }
    
    Shape* currentItem() const {
        // throw std::string "No child member!"
    }
};
```

5. Implement `ShapeIterator` class in `shape_iterator.h` and the corresponding unit test in `ut_iterator.h`.  
```
template<class ForwardIterator>
class ShapeIterator : public Iterator {
public:
    ShapeIterator(ForwardIterator begin, ForwardIterator end) {
        // initialize iterator.
    }
    
    void first() {
        // initialize iterator.
    }
    
    void next() {
        // move iterator to next position,
        // throw std::string "Moving past the end!" when iterator move over the range of the structure.
    }
    
    bool isDone() const {
        // return true when iterator reach the end of the structure.
    }
    
    Shape* currentItem() const {
        // return the shape that iterator currently point at.
    }
};
```

6. Implement following function in `utility.h` and the corresponding unit test in `ut_utility.h`.  
```
Shape* getShapeById(Shape* shape, std::string id) {
    // access the shape with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return a shape under the input shape tree sturcture that matches the id.
    // throw std::string "Only compound shape can get shape!" when the input shape is not iterable.
    // throw std::string "Expected get shape but shape not found" when no shape found with the given id.
}
```
* Example usage of `getShapeById()`:  
```
 getShapeById(compoundShape_0, 2);
  
  CompoundShape(id:0) <=== will never return compoundShape_0 itself
  │
  ├── CompoundShape(id:1)
  │    │
  │    └── Triangle(id:2) <=== return this
  │
  ├── Ellipse(id:3)
  │
  └── Rectangle(id:4)

  id will be unique, so there will only be one shape to return.
```
7. Implement following funtion and class in `utility.h` and the corresponding unit test in `ut_utility.h`.  
```
template <class Filter>
std::deque<Shape*> filterShape(Shape* shape, Filter filter) {
    // access the shape with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return the shapes under the input shape tree sturcture that match the given filter.
    // throw std::string "Only compound shape can filter shape!" when the input shape is not iterable.
}

class AreaFilter {
    AreaFilter(double upperBound, double lowerBound) {}
    bool operator() (Shape* shape) const {}
};

class PerimeterFilter {
    PerimeterFilter(double upperBound, double lowerBound) {}
    bool operator() (Shape* shape) const {}
};

class ColorFilter {
    ColorFilter(std::string color) {}
    bool operator() (Shape* shape) const {}
};

class TypeFilter {
    TypeFilter(std::string type) {}
    bool operator() (Shape* shape) const {}
};
```
* Example usage of `filterShape()` with the filter class:  
```
filterShape(compoundShape_0, AreaFilter(10, 5));
// return shapes that area in range of 10 >= && 5 <=, but don't include compoundShape_0 itself.

filterShape(compoundShape_0, PerimeterFilter(10, 5));
// return shapes that perimeter in range 10 >= && 5 <=, but don't include compoundShape_0 itself.

filterShape(compoundShape_0, ColorFilter("white"));
// return shapes that color match "white", but don't include compoundShape_0 itself.

filterShape(compoundShape_0, TypeFilter("Compound Shape"));
// return shapes that type match "Compound Shape", but don't include compoundShape_0 itself.
```

#### File structure:  
```
├── bin
│   └── ut_main
├── src
│   ├── shape.h
│   ├── shape.cpp
│   ├── ellipse.h
│   ├── rectangle.h
│   ├── triangle.h
│   ├── compound_shape.h
│   ├── iterator.h
│   ├── null_iterator.h
│   ├── shape_iterator.h
│   ├── utility.h
│   └── two_dimensional_coordinate.h
├── test
│   ├── ut_main.cpp
│   ├── ut_ellipse.h
│   ├── ut_rectangle.h
│   ├── ut_triangle.h
│   ├── ut_iterator.h
│   ├── ut_utility.h
│   └── ut_compound_shape.h
└── makefile

```
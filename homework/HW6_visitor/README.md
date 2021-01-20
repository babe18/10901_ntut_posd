# **Pattern Oriented Software Design 2020 Fall Assignment 6**  

## **Notice**  
* **Due on Tuesday November 10 2020, 23:59.**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **You should add unit test for each requirment under corresponding ut_file.**  

## **Score**  
1. Source Code(Implementation + unit test): 40%.  
2. Unit tests written by TA: 60%.  

## **Useful Reference**  
[Visitor Pattern](https://refactoring.guru/design-patterns/visitor)  

## **Requirement**  
1. Add function `accept()` in `Shape` as following.  
````
class Shape {
public:
    virtual void accept(Visitor* visitor) = 0;
}
````
2. Add interface class `Visitor` with overloading function in `visitor.h`.  
```
class Visitor {
public:
    virtual void visit(Ellipse* ellipse) = 0;

    virtual void visit(Triangle* triangle) = 0;

    virtual void visit(Rectangle* rectangle) = 0;

    virtual void visit(CompoundShape* compoundShape) = 0;
};
```
3. Implement `AreaVisitor` in `area_visitor.h` and write the unit test in `ut_visitor.h`.  
```
class AreaVisitor : public Visitor {
public:
    void visit(Ellipse* ellipse) {
        // caculate the area of Ellipse.
        // DO NOT use ellipse->area() to get area directly.
        // you may add public function for Ellipse to get it's data members.
    }

    void visit(Triangle* triangle) {
        // caculate the area of Triangle.
        // DO NOT use triangle->area() to get area directly.
        // you may add public function for Triangle to get it's data members.
    }

    void visit(Rectangle* rectangle) {
        // caculate the area of Rectangle.
        // DO NOT use rectangle->area() to get area directly.
        // you may add public function for Rectangle to get it's data members.
    }

    void visit(CompoundShape* compoundShape) {
        // caculate the area of CompoundShape.
        // DO NOT use compoundShape->area() to get area directly.
        // you may add public function for CompoundShape to get it's data members.
    }

    double area() const {
        // return area;
    }
};
```
4. Implement `InfoVisitor` in `info_visitor.h` and write the unit test in `ut_visitor.h`.  
```
class InfoVisitor : public Visitor {
public:
    void visit(Ellipse* ellipse) {
        // create info of ellipse, same way as ellipse->info().
        // DO NOT use ellipse->info() to get info directly.
        // you may add public function for Ellipse to get it's data members.
    }

    void visit(Triangle* triangle) {
        // create info of ellipse, same way as triangle->info().
        // DO NOT use triangle->info() to get info directly.
        // you may add public function for Triangle to get it's data members.
    }

    void visit(Rectangle* rectangle) {
        // create info of rectangle, same way as rectangle->info().
        // DO NOT use rectangle->info() to get info directly.
        // you may add public function for Rectangle to get it's data members.
    }

    void visit(CompoundShape* compoundShape) {
        // create info of compoundShape, same way as compoundShape->info().
        // DO NOT use compoundShape->info() to get info directly.
        // you may add public function for CompoundShape to get it's data members.
    }

    std::string info() const {
        // return info;
    }
};
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
│   ├── visitor.h
│   ├── area_visitor.h
│   ├── info_visitor.h
│   └── two_dimensional_coordinate.h
├── test
│   ├── ut_main.cpp
│   ├── ut_ellipse.h
│   ├── ut_rectangle.h
│   ├── ut_triangle.h
│   ├── ut_compound_shape.h
│   ├── ut_iterator.h
│   ├── ut_utility.h
│   └── ut_visitor.h
└── makefile

```
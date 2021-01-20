# **Pattern Oriented Software Design 2020 Fall Assignment 9**  

## **Notice**  
* **Due on Tuesday December 29 2020, 23:59.**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **You should add unit test for each requirment under corresponding ut_file.**  

## **Score**  
1. `ShapeFilter` (source code + TA test): 50%.  
2. `ShapeSetter` (source code + TA test): 50%.  
3. -10% for each fail TA unit test.  

## **Useful Reference**  
[Pipes and Filters Pattern](https://homepages.fhv.at/thjo/lecturenotes/sysarch/pipes-and-filters.html)  
[Lambda expressions](https://en.cppreference.com/w/cpp/language/lambda)  

## **Requirement**  
1. Add function `setColor()` in class Shape as following.  
```
    void setColor(std::string color);
    // for setting color.
```

2. Add class `Filter` in `filter.h`.  
```
class Filter {
public:
    virtual Filter* setNext(Filter* filter) = 0;

    virtual std::list<Shape*> push(std::list<Shape*> shapes) = 0;
};
```

3. Add class `ShapeFilter` in `shape_filter.h` and corresponding unit test in `ut_filter.h`.  
   The purpose of `ShapeFilter` is to filter out shape with it's attributes.  
```
class ShapeFilter : public Filter {
public:

    ShapeFilter(Predicate pred) {}
        // `Predicate` is a template name for lambda,
        //  you may use your own name.

    Filter* setNext(Filter* filter) {
        // seeting next filter.
    }

    std::list<Shape*> push(std::list<Shape*> shapes) {
        // push down filtered data and return result.
    }

};
```
* Example:
```
std::list<Shape*> data = {// lots of shapes};

Filter* areaFilter = new ShapeFilter([](Shape* shape) {return shape->area() <= 30;});
Filter* perimeterFilter = new ShapeFilter([](Shape* shape) {return shape->perimeter() >= 15;});
Filter* colorFilter = new ShapeFilter([](Shape* shape) {return shape->color() == "black";});

areaFilter->setNext(perimeterFilter)->setNext(colorFilter);
std::list<Shape*> results = areaFilter->push(data);
```

4. Add class `ShapeSetter` in `shape_setter.h` and corresponding unit test in `ut_filter.h`.  
   The purpose of `ShapeSetter` is to set a new attributes for shape due to the old one.  

```
class ShapeSetter : public Filter {
public:

    ShapeSetter(Setter set) {}
        // `Setter` is a template name for lambda,
        //  you may use your own name.

    Filter* setNext(Filter* filter) {
        // seeting next filter.
    }

    std::list<Shape*> push(std::list<Shape*> shapes) {
        // push down setted data and return result.
    }
};
```
* Example:
```
std::list<Shape*> data = {// lots of shapes};

Filter* areaFilter = new ShapeFilter([](Shape* shape) {return shape->area() < 30;});
Filter* perimeterFilter = new ShapeFilter([](Shape* shape) {return shape->perimeter() > 150;});
Filter* colorSetter = new ShapeSetter([](Shape* shape) {shape->setColor("black");});

areaFilter->setNext(perimeterFilter)->setNext(colorSetter);
std::list<Shape*> results = areaFilter->push(data);
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
│   ├── scanner.h
│   ├── shape_builder.h
│   ├── shape_parser.h
│   ├── filter.h
│   ├── shape_filter.h
│   ├── shape_setter.h
│   └── two_dimensional_coordinate.h
├── test
│   ├── ut_main.cpp
│   ├── ut_ellipse.h
│   ├── ut_rectangle.h
│   ├── ut_triangle.h
│   ├── ut_compound_shape.h
│   ├── ut_iterator.h
│   ├── ut_utility.h
│   ├── ut_visitor.h
│   ├── ut_scanner.h
│   ├── ut_shape_builder.h
│   ├── ut_shape_parser.h
│   └── ut_filter.h
└── makefile

```
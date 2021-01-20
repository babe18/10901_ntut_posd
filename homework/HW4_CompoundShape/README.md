# **Pattern Oriented Software Design 2020 Fall Assignment 4**  

## **Notice**  
* **Due on Tuesday October 13 2020, 23:59.**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **You should add unit test for each newly add requirment under corresponding ut_file.**  

## **Score**
1. Usage of Iterator in vector: 10%.  
2. Unit tests written by yourself: 40%.  
3. Unit tests written by TA: 50%.  

## **Useful Reference**  
[Composite pattern](https://en.wikipedia.org/wiki/Composite_pattern)  
[Iterators in C++](https://www.geeksforgeeks.org/iterators-c-stl/)  
[C++ Overloading](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm)  
[Makefile](https://mropengate.blogspot.com/2018/01/makefile.html)  

## **Requirement**   

1. Add the following function in `Shape`, add the implementations in `shape.cpp` if needed.   
 ```
class Shape {
public:
    Shape(std::string id); // interface for default color "white".
    Shape(std::string id, std::string color); // interface for color input by user.
    std::string id() const; // return id of shape.
    std::string color() const; // return color of shape.
    virtual void addShape(Shape *shape); // throw std::string "Only compound shape can add shape!"
    virtual void deleteShapeById(std::string id); // throw std::string "Only compound shape can delete shape!"
    virtual Shape* getShapeById(std::string id); // throw std::string "Only compound shape can get shape!"
};
```
*  `color`: is input as "red", "blue", "yellow" etc.

2. Modify interface of `Ellipse`, `Rectangle`, `Triangle` into the following.  
   (Now you will have two interface for each of these three shapes.)

```
Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes) 
Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes, std::string color)

Rectangle(std::string id, double length, double width)
Rectangle(std::string id, double length, double width, std::string color)

Triangle(std::string id, vector<TwoDimensionalCoordinate*> coordinates)
Triangle(std::string id, vector<TwoDimensionalCoordinate*> coordinates, std::string color)
```

3. Implement `CompoundShape` class in `compound_shape.h` and the corresponding unit test in `ut_compound_shape.h`.  
```
class CompoundShape : public Shape {
public:
        CompoundShape(std::string id, std::vector<Shape*>* shapes) {
            // The default color of compound shape should be "transparent".
            
            // When there's no shape contain in the compound shape,
            // should throw std::string "This is not a compound shape!"
        }

        double area() const {
            // return sum of all containing shapes area.
        }

        double perimeter() const { 
            // return sum of all containing shapes perimeter.
        }
    
        std::string info() const {
            // return list of all containing shapes info with wrapped of "CompoundShape {}".
            // ex."Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}"
        }
        
        void addShape(Shape* shape) {
            // add shape into compound shape.
        }
        
        void deleteShapeById(std::string id) {
            // search and delete a shape through id,
            // search all the containing shapes and the tree structure below,
            // if no match of id, throw std::string "Expected delete shape but shape not found"
        }
        
        Shape* getShapeById(std::string id) {
            // search and return a shape through id,
            // search all the containing shapes and the tree structure below,
            // if no match of id, throw std::string "Expected get shape but shape not found"
        }
}
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
│   └── two_dimensional_coordinate.h
├── test
│   ├── ut_main.cpp
│   ├── ut_ellipse.h
│   ├── ut_rectangle.h
│   ├── ut_triangle.h
│   └── ut_compound_shape.h
└── makefile

```
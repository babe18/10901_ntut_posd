# **Pattern Oriented Software Design 2020 Fall Assignment 1**  

## **Notice**  
* **Due on (Tuesday, September 22, 2020 23:59).**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **For return type of double, should be assert to accuracy `%3f`.**  
* **For retrun string of number, should be in form of `%3f`. ex:"3.141", "2.000".**  

## **Score**
1. Unit tests written by yourself: 50%.  
2. Unit tests written by TA: 50%.(-10 for each fail test)  

## **Useful Reference**
[C++ Pointers](https://www.programiz.com/cpp-programming/pointers)  
[C++ vector](http://www.cplusplus.com/reference/vector/vector/)  
[C++ Exception Handling](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm)   
[Inheritance in C++](https://www.geeksforgeeks.org/inheritance-in-c/)  
[Makefile Wiki](https://en.wikipedia.org/wiki/Makefile)  
[Makefile Tutorial](https://ssl-gitlab.csie.ntut.edu.tw/posd2020f_hw/makefile_tutorial)  
[Googletest Primer](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)  

## **Requirement**  
**Note: Each class below are the skeleton. You should finish implementation by yourself.**  

1. `Shape` is an abstract class , don't modify it!!!  
```
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
};
```

2. Implement `Rectangle` and functions inherit from `Shape`.  
   Write correspond unit test for the class in file `ut_rectangle.h` under `test` folder.  
```
class Rectangle: public Shape {
public: 
    Rectangle(double length, double width) {
        // If the rectangle can't be successfully created,
        // handle the exception by throwing string "This is not a rectangle!"
    }
    
    double area() const {
        // return the area of the Rectangle.
    }
    
    double perimeter() const {
        // return the perimeter of the Rectangle.
    }
    
    std::string info() const {
        // return the info of the Rectangle.
        // ex. Rectangle (3.712, 4.000)
    }
}
```
* Example for exception handling:
```
    try {
        Rectangle(0, 1); ==> the argument should > 0 or the rectangle can't be build.
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
    
    ASSERT_NO_THROW(Rectangle(1, 1));
```

* Example for info test:
```
    Rectangle rectangle(3.712, 4);
    ASSERT_EQ("Rectangle (3.712, 4.000)", rectangle.info());
```

3. Implement `Ellipse` and functions inherit from `Shape`.  
   Write correspond unit test for the class in file `ut_ellipse.h` under `test` folder.  
```
class Ellipse: public Shape{
public: 
    Ellipse(double semiMajorAxes, double semiMinorAxes) {
        // If the ellipse can't be successfully created,
        // handle the exception by throwing string "This is not a ellipse!"
    }
    
    double area() const {
        // return the area of the Ellipse.
    }
    
    double perimeter() const {
        // return the perimeter of the Ellipse.
    }
    
    std::string info() const {
        // return the info of the Ellipse.
        // ex. Ellipse (3.712, 4.000)
    }
}
```
* Use `M_PI` in <math.h> for caculation of `π`.  


4. Implement `Triangle` and functions inherit from `Shape`.  
   Write correspond unit test for the class in file `ut_triangle.h` under `test` folder.  
```
class Triangle: public Shape{
public: 
    Triangle(std::vector<TwoDimensionalCoordinate*> vectors) {
        // If the triangle can't be successfully created,
        // handle the exception by throwing string "This is not a triangle!"
    }
    
    double area() const {
        // return the area of the Triangle.
    }
    
    double perimeter() const {
        // return the perimeter of the Triangle.
    }
    
    std::string info() const {
        // return the info of the Triangle.
        // ex. Triangle ([0.000, 0.000], [0.000, -3.141], [-4.000, 0.000])
    }
}
```
5. Implement `TwoDimensionalCoordinate`.  
```
class TwoDimensionalCoordinate {
public:
    TwoDimensionalCoordinate(double x, double y):{}

    double getX() {
        // return x;
	}

	double getY() {
		// return y;
	}
};
```
* Example for Triangle with TwoDimensionalCoordinate:
```
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Triangle triangle(triangleVector);
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle.info());
```

6. Write correspond makefile to generate binary file for all ut file named `ut_main` under the `bin` folder.  

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
    │   └── two_dimensional_coordinate.h
    ├── test
    │   ├── ut_main.cpp
    │   ├── ut_ellipse.h
    │   ├── ut_rectangle.h
    │   └── ut_triangle.h
    └── makefile

```
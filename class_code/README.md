# Pattern Oriented Software Design Fall, 2020

- Instructor: Prof Y C Cheng
- Office hours: 15:10 - 17:00 Monday, 15:10-17:00 Tue, 14:00-16:00 Wed
- Room 1531, S&T

### TA  
- Alan Chu and Eric Guan
- Office hours:  Mon, 10~12 a.m., Tue, 2~4 p.m.  
- Office location: Lab 1321, Tech Building
- Contact: posd2020ta@gmail.com
- Homework page: https://ssl-gitlab.csie.ntut.edu.tw/posd2020f_hw/posd2020f_assignment

## Synopsis

We will learn object-oriented design patterns by solving problems in class:
- Review of C++/OOP - Problem 1
  - git/gitlab/jenkins
  - unit testing with googletest  
  - strong-styled pair programming/mob programming
  - STL, lambda
- Design patterns: an object-oriented shape manipulation program -
  - Composite, Iterator, Visitor, Builder,  Interpreter, and Pipes and Filters (POSA)
  - GUI (with wxWidgets) MVC, Observer, Mediator, and Adapter

## Textbook:
Gamma, Erich, et al. Design patterns: elements of reusable object-oriented software. Pearson Education, 1994.

## Reference:
[The Principles of OOD](http://butunclebob.com/ArticleS.UncleBob.PrinciplesOfOod)

## Grading policy

- Homework 40%
- Programming Midterm x2, 20% each
  - first midterm: Wed, 28 Oct 2020, 6:00pm - 9:00pm, @lab 1222, 1223
  - second midterm: Wed, 9 Dec 2020, 6:00pm - 9:00pm, @lab 1222, 1223
- Final Wed, Jan 13 2021, 10:10am - 11:40 am (written, open book: ___The textbook only___) 20%, @classroom building 2, 207

## Problems:

### Problem 1: sorting shapes

A simple geometry application called _geo_ is needed to sort shapes such as triangles, circles, rectangles and others. As a command line application, _geo_ reads shapes from an input file, sorts the shapes by area or perimeter in increasing order or decreasing order, and write the result to an output file. For example,
```
geo input.txt output.txt area inc
```
sorts the shapes in file _input.txt_ in increasing order by area, and writes the result to the file _output.txt_. And
```
geo input.txt output.txt perimeter dec
```
sorts the shapes in file _input.txt_ in decreasing order by perimeter, and writes the result to the file _output.txt_.

## Problem 2: Shape manipulation

A program for manipulating geometric shapes is needed. With the program, the user creates/deletes/modifies simple shapes such as square, circle, triangle, and convex polygons. Individual shapes will have properties such as area, perimeter, color and so on. Compound shapes can be formed from individual shapes. Area and perimeter properties are still needed on compound shapes. A compound shape can include other compound shapes. The following operations on shapes are needed.

- Add shapes to a compound shape;
- Delete shapes from a compound shape;
- Move shapes out of a compound shape;
- Move shapes from a compound shape to another compound shape;
- Select shapes by Boolean expression on the properties area, perimeter, color and type; and
- Load/store shapes from/into a file.

## Week 1

```c++
#include <gtest/gtest.h>

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
```

## Week 2

- analysis and planning with HTSI, And/Or tree
- Adding Shape on top of Rectangle and Triangle
  - testing subtype polymorphism
- containers(array) - iterators - algorithms (sort)
- fixture, setup, teardown, TEST_F

## Week 3

- Problem 2
  - MixedShape
  - add (structuring responsibility)
    - separate containers for each type of shapes?
    - one container for all kinds of shapes
    - one container for all kind of shapes, including MixedShape
  - area (domain specific responsibility)
  - unit testing for MixedShape
    - MixedShape as a MixedShape object
    - MixedShape as a Shape object
    - Aggregation (or composition) of Shape objects
    - add as a responsibility of Shape? Uniformity vs exception

Reading:
- Composite pattern
- [Open-Closed Principle](http://butunclebob.com/ArticleS.UncleBob.PrinciplesOfOod)

## Week 4

- Iterator: accessing shapes inside a MixedShape
  - external iterator: std::vector<T>::iterator
  - internal iterator: array.each {block} (Python, Ruby); ArrayList.forEach(action) (Java)
  - find_first(constraint): finding the first shape satisfying constraint

Reading:
- Iterator pattern

## Week 5

- Open-closed principle (how to avoid typecasting?)
- Looking back
- Program to an interface, not an implementation
- iterator, null iterator, and shape iterator
- Factory method pattern

## Week 6

- find_first
- Visitor
- pattern classifications

## Week 7: midterm I

## Week 8

- Visitor, GoF
  - consequences
  - double dispatch vs single dispatch
  - shape as string
    - extract visitor base class

## Week 9

-Visitor, continued
  - the failing test ```TEST_F(StringTest, MboxToString)```: how do we deal with indentation?
    - make MixedShape::toString take an additional argument for indentation; modify it and propagate it down when appropriate
    - do this somewhere else where we could manage the indentation easily: Visitor Consequences, point 5.

## Week 10 

- Builder. GoF
  - Director (Shape Parser)
    - Parser relies on Scanner to get meaningful tokens such as "rect", "3", "mixed", "{"
    - Scanner makes Parser simpler
    - Parser reads a "program" in the Shape language describable with a _context free grammar_ (CFG)
  - Builder (Shape Builder)
    - deals with creation and assembly of shapes
    - make use of a push-down automata (i.e., stack) to build shapes according to the CFG  

## Week 11 - More patterns

- Singleton
- SRP
- Adapter
- Template Method (to be continued)

## Week 12 

- Design review
- Bring in the parser and scanner
  - scanners knows how to get next tokens
  - parser know the syntax 
  - builder know how to create and assemble shapes
  - exercise: error handling

## Week 13 Midterm 2

## Week 14

- Filters and Pipes [POSAv1](https://www.amazon.com/Pattern-Oriented-Software-Architecture-System-Patterns/dp/0471958697)

A simple filters and pipes
- filters with visitors
- filter member function (with data stream as argument) as pipes 

alternatively:

stream with member functions serving as filters
  - member function filters produce new stream leaving original stream unchanged 

## Week 15

- design review
- Alexander's patterns
- more architecture patterns

## Week 16
- Decorator
- Strategy
- Template method

## Week 17

- Term project presentation by Stanley Zhong
- DIP
- GoF, How to Select a Design Pattern?
  - Table 1.2
  - Causes of redesign starting on page 24 

## Week 18 

__Final Exam: 10:00am - 11:30am, Wednesday 1/13/2021, classroom 207__
__Open book: only allowing textbook GoF, papers DIP, OCP, SRP__
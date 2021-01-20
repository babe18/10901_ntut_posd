# **Pattern Oriented Software Design 2020 Fall Assignment 7**  

## **Notice**  
* **Due on Tuesday December 1 2020, 23:59.**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **You should add unit test for each requirment under corresponding ut_file.**  

## **Score**  
1. `Scanner` (source code + TA test): 30%.  
2. `ShapeBuilder` (source code + TA test): 30%.  
3. `ShapeParser` (source code + TA test): 40%.  
4. -5% for each fail TA unit test.  

## **Useful Reference**  
[Builder Pattern](https://refactoring.guru/design-patterns/builder)  
[Pushdown Automata](https://www.tutorialspoint.com/automata_theory/pushdown_automata_introduction.htm)  
[std::stack](http://www.cplusplus.com/reference/stack/stack/)  
[std::deque](http://www.cplusplus.com/reference/deque/deque/)  

## **Requirement**  
1. Modify `CompoundShape` constructor, now it's available to accpet empty std::list<Shape*> without throwing exception.  

2. Add class `Scanner` in `scanner.h` and corresponding unit test in `ut_scanner.h`.  
```
class Scanner {
public:
    Scanner(std::string input) {}
    
    std::string nextToken() {
        // return next token.
        // throw exception std::string "next char doesn't exist." if next token not found.
    }
};
```
* Purpose of the scanner is to scan through the input and able to send out each token by nextToken().  
* Ignore the token which is illegal. 
* DO NOT use regular expression to implement. 
* For input of `Ellipse` it should be in form of `Ellipse (%.3f, %.3f)`.  
* For input of `Rectangle` it should be in form of `Rectangle (%.3f, %.3f)`.  
* For input of `Triangle` it should be in form of `Triangle (%.3f, %.3f, %.3f, %.3f, %.3f, %.3f)`.  
* For input of `Compound Shape` it should be in form of `CompoundShape {}`.  
* Each Shape should be separate with `,`.  
* Example:
```
TEST(Scanner, ellipse) {
    Scanner scanner("Ellipse (4.000, 3.000)");

    ASSERT_EQ("Ellipse", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());

    try {
        scanner.nextToken();
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("next char doesn't exist.", e);
    }
}
```

3. Add class `ShapeBuilder` in `shape_builder.h` and corresponding unit test in `ut_shape_builder.h`.  
```
class ShapeBuilder {
public:
    ShapeBuilder() {}
    
    void buildRectangle(double length, double width) {
        // build a rectangle with an unique id and push in a std::stack.
    }
    
    void buildEllipse(double semiMajorAxes, double semiMinorAxes) {
        // build a ellipse with an unique id and push in a std::stack.
    }
    
    void buildTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        // build a triangle with an unique id and push in a std::stack.
    }
    
    void buildCompoundShapeBegin() {
        // for notifing beginning of a Compound Shape.
    }
    
    void buildCompoundShapeEnd() {
        // for notifing ending of a Compound Shape.
    }
    
    std::deque<Shape*> getResult() {
        // return result.
    }
};
```
* Example:  
```
TEST(ShapeBuilderTest, build_triangle) {
    ShapeBuilder sb;
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    std::deque<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[0]->info());
}
```

4. Add class `ShapeParser` in `shape_parser.h` and corresponding unit test in `ut_shape_parser.h`.  
```
class ShapeParser {
public:
    ShapeParser(std::string input) {
        // initialize a scanner for handling input.
        // initialize a shape builder for handling building shape.
    }
    
    void parser() {
        // using Scanner::nextToken() to get all information to determine what to build,
        // and provide the argument the shape needed.
        // use functions in ShapeBuilder to build out the shape.
        // the shape with invalid argument should be ignored (see example bellow).
    }
    
    std::deque<Shape*> getResult() {
        // return result.
    }
};
```
* Example:  
```
TEST(ShapeParserTest, parser_triangle) {
    ShapeParser sp("Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[0]->info());
}
```
* Example with invalid argument that should be ignored:  
```
TEST(ShapeParserTest, parser_multi_simple_shapes_with_one_shape_contain_invalid_argument_that_should_be_ignored) {

    ShapeParser sp("Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Ellipse (4.200, 3.700, 12.502), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(3, results.size());

    EXPECT_EQ("Rectangle (3.000, 4.000)", results[0]->info());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results[1]->info());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[2]->info());
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
│   └── ut_shape_parser.h
└── makefile

```
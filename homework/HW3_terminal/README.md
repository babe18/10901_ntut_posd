# **Pattern Oriented Software Design 2020 Fall Assignment 3**  

## **Notice**  
* **Due on Tuesday, October 6, 2020 23:59.**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **For any output of double, it should be in the form of `%.3f`**  
* **Please use the `quickSort()` that implement in assigment 2 for this assigment**.  

## **Score**
1. Unit tests written by yourself: 30%.  
2. Unit tests written by TA: 40%.  
3. Correctness of `geo`: 30%.  

## **Useful Reference**
[Regular Expression Wiki](https://en.wikipedia.org/wiki/Regular_expression)  
[C++ Regular Expressions](http://www.cplusplus.com/reference/regex/)  

## **Requirement**  
1. For this assigment you will finish [Problem 1: sorting shapes](https://ssl-gitlab.csie.ntut.edu.tw/yccheng/posd2020f#problem-1-sorting-shapes) that mention in class. A simple geometry application called _geo_ is needed to sort shapes such as triangles, ellipse and rectangles. As a command line application, _geo_ reads shapes from an input file, sorts the shapes by area or perimeter in increasing order or decreasing order, and write the result to an output file. For example,
```
bin/geo input.txt output.txt area inc
```

2. Implement a `main` function in `main.cpp` to handle input from terminal.  
   The input will be as following example:  
   [input.txt](https://ssl-gitlab.csie.ntut.edu.tw/posd2020f_hw/posd2020f_assignment/blob/HW3/input.txt)  
   [output.txt](https://ssl-gitlab.csie.ntut.edu.tw/posd2020f_hw/posd2020f_assignment/blob/HW3/output.txt)  
   ```bin/geo input.txt output.txt area inc```  
   `argv[0]`: The path of binary file.  
   `argv[1]`: The full name of input file.  
   `argv[2]`: The full name of output file.  
   `argv[3]`: The feature of shape that sorting basis on.  
   `argv[4]`: The 'inc' for increasing, 'dec' for decreasing.  

3. Implement class `Terminal` in `terminal.h`, `Terminal` is for handling the input and generate output, and add unit test in `ut_terminal.h`, the test should covered the rules that mention bellow.  
```
class Terminal {
public:
    Terminal(std::string input) {}
    std::string showResult() {}
}
```
* Example:
```
Terminal terminal("Rectangle (2, 2) Rectangle (1, 1) area inc");
ASSERT_EQ("1.000\n4.000", terminal.showResult());
```

* The form of the input string should be `{Shape}`+`{Feature to sort}`+`{Order}`, if any of condition missing, the constructure should handle the exception by throwing std::string "invalid input".  

  Valid:  
    ```
    Rectangle (3.7, 4.2) Ellipse (4, 3) Triangle ([0,-3], [-3,0], [0,-4]) area inc
    ``` 
  Invalid:  
    ```
    Rectangle (3.7, 4.2) Ellipse (4, 3) area
    Rectangle (3.7, 4.2) Ellipse (4, 3) inc
    area inc
    ```   

4. Rules for the input string:  
* `{Shape}` will be in the form of `{Shape Type}` + `{SPACE}` + `{Argument}`.  
  The first letter of `{Shape Type}` should be capital.
  There must be at least one `{SPACE}` between `{Shape Type}` and `{Argument}`.  
  The `{Argument}` must be wrapped by `()` and the number must be split by `,`, but the `{SPACE}` can be ignored.  
  Valid:  
  ```
  Rectangle (3, 4)
  Rectangle     (3, 4)
  Rectangle (3,4)
  Rectangle (  3,4  )
  ```
  Invalid:  
  ```
  Rectangle(3, 4) 
  rectangle (3, 4)
  RRRectangle (3, 4)
  Rectangle(3!4)
  Rectangle(3,@4)
  Rectangle(3, 4_)
  Rectangle @#(3, 4)
  Rectangle(3, 4, 5)
  ```
* `{Shape}` connect each other with at least one `{SPACE}`.  
  Valid:  
  ```
  Rectangle (3.7, 4.2) Ellipse (4, 3)
  Rectangle (3.7, 4.2)   Ellipse (5, 4)
  ```
 * If `{Shape}` is invalid, ignore the invalide `{Shape}` and sort the remaining.  
   Example:  
  ```
  Terminal terminal("Rectangle (2, 2) Rectangle (1, 1) Ellipse$%^&(1, 1) area inc");
  ASSERT_EQ("1.000\n4.000", terminal.showResult());

  Terminal terminal("Rectangle (2, 2) Rectangle (1, 1) Ellipse (-1, -1) area inc");
  ASSERT_EQ("1.000\n4.000", terminal.showResult());
  ```
* If all `{Shape}` is invalid, meaning the `{Shape Type}` condition is missing, throw std::string "invalid input" in constructor.  
  Example:  
  ```
  try {
        Terminal("Rectangle (0, 0) Ellipse (-1, -1) area inc");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
  ```
  
5. Rules for the _output_ string:  
* Each output `{Feature}` should be in the form of `%.3f` and connect each other with `\n`.  
  But the string shouldn't end up with `\n`.    
  Valid:  
  ```
  24.000\n15.800\n12.000
  ```
  Invalid:  
  ```
  24.389  \n  15.800
  25.389\n15.800\n
  25.24\n$^15.800\n
  ```
  
6. Modify makfile to generate binary file `geo` under "bin" folder.  
   The example usage `geo`:  
   [input.txt](https://ssl-gitlab.csie.ntut.edu.tw/posd2020f_hw/posd2020f_assignment/blob/HW3/input.txt)  
   [output.txt](https://ssl-gitlab.csie.ntut.edu.tw/posd2020f_hw/posd2020f_assignment/blob/HW3/output.txt)  
   ```
   bin/geo input.txt output.txt area inc
   ```

## **File Structure**
This time your directory structure should be like:
```
{學號}_hw
    ├── bin
    │   ├── geo
    │   └── ut_main
    ├── src
    │   ├── main.cpp
    │   ├── ellipse.h
    │   ├── shape.h
    │   ├── sort.h
    │   ├── rectangle.h
    │   ├── triangle.h
    │   ├── terminal.h
    │   └── two_dimensional_coordinate.h
    ├── test
    │   ├── ut_main.cpp
    │   ├── ut_ellipse.h
    │   ├── ut_rectangle.h
    │   ├── ut_sort.h
    │   ├── ut_terminal.h
    │   └── ut_triangle.h
    │
    ├── makefile
    │
    ├── input.txt
    │
    └── output.txt

```
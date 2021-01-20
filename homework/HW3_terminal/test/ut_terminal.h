#include <gtest/gtest.h>
#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"
#include "../src/rectangle.h"
#include "../src/ellipse.h"
#include "../src/sort.h"
#include "../src/terminal.h"
#include <stdexcept>
#include <algorithm>

TEST(TerminalTest, InvalidInputNoShape)
{
  try {
      Terminal("area inc");
      FAIL();
  }catch(string e) {
      ASSERT_EQ("invalid input", e);
  }
}
TEST(TerminalTest, InvalidInputShapeLowerCap)
{
  try {
      Terminal("rectangle (3.7, 4.2)  area inc");
      FAIL();
  }catch(string e) {
      ASSERT_EQ("invalid input", e);
  }
}
TEST(TerminalTest, InvalidInputShapeNoSpace)
{
  try {
      Terminal("Rectangle(3.7, 4.2) area inc");
      FAIL();
  }catch(string e) {
      ASSERT_EQ("invalid input", e);
  }
}
TEST(TerminalTest, InvalidInputEllipseException)
{
  try {
        Terminal("Ellipse (-1, -1) area inc");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}
TEST(TerminalTest, InvalidInputEllipseArgumentError)
{
  try {
        Terminal("Ellipse (-1, 5) area inc");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}
TEST(TerminalTest, InvalidInputRectangleException)
{
  try {
          Terminal("Rectangle (2.125, -2.125)  perimeter inc");
          FAIL();
      }catch(string e) {
          ASSERT_EQ("invalid input", e);
      }
}
TEST(TerminalTest, InvalidInputTriangleArgumentError)
{
  try {
          Terminal("Rectangle (0, 0)  perimeter inc");
          FAIL();
      }catch(string e) {
          ASSERT_EQ("invalid input", e);
      }
}
TEST(TerminalTest, InvalidInputTriangleException)
{
  try {
          Terminal("Triangle([0, 0], [3, 0], [0, 4])  perimeter inc");
          FAIL();
      }catch(string e) {
          ASSERT_EQ("invalid input", e);
      }
}
TEST(TerminalTest, InvalidInputNoFeatureToSort)
{
  try {
          Terminal("Triangle([0, 0], [3, 0], [0, 4])  inc");
          FAIL();
      }catch(string e) {
          ASSERT_EQ("invalid input", e);
      }
}
TEST(TerminalTest, InvalidInputNoOrder)
{
  try {
          Terminal("Triangle([0, 0], [3, 0], [0, 4])  area");
          FAIL();
      }catch(string e) {
          ASSERT_EQ("invalid input", e);
      }
}
TEST(TerminalTest, AreaIncreasing)
{
  Terminal terminal("Rectangle (2, 2) Rectangle (1, 1) Triangle ([0, 0], [3, 0], [0, 4]) area inc");
  ASSERT_EQ("1.000\n4.000\n6.000", terminal.showResult());
}
TEST(TerminalTest, AreaDecreasing)
{
  Terminal terminal("Rectangle (2, 2) Rectangle (1, 1) Triangle ([0, 0], [3, 0], [0, 4]) area dec");
  ASSERT_EQ("6.000\n4.000\n1.000", terminal.showResult());
}
TEST(TerminalTest, PerimeterIncreasing)
{
  Terminal terminal("Rectangle (2, 2) Ellipse (3, 1) Triangle ([0, 0], [3, 0], [0, 4]) perimeter inc");
  ASSERT_EQ("8.000\n12.000\n14.283", terminal.showResult());
}
TEST(TerminalTest, PerimeterDecreasing)
{
  Terminal terminal("Rectangle (2, 2) Ellipse (3, 1) Triangle ([0, 0], [3, 0], [0, 4]) perimeter dec");
  ASSERT_EQ("14.283\n12.000\n8.000", terminal.showResult());
}
TEST(TerminalTest, AreaIncreasingWithOneShapeExceptionIgnore)
{
  Terminal terminal("Rectangle(2, 2) Rectangle (1, 1) Triangle ([0, 0], [3, 0], [0, 4]) area dec");
  ASSERT_EQ("6.000\n1.000", terminal.showResult());
}
TEST(TerminalTest, AreaIncreasingWithOneShapeErrorArgumentIgnore)
{
  Terminal terminal("Rectangle (-1, 2) Rectangle (1, 1) Triangle ([0, 0], [3, 0], [0, 4]) area dec");
  ASSERT_EQ("6.000\n1.000", terminal.showResult());
}

#include "iostream"
#include "../src/rectangle.h"
using namespace std;

TEST(Rectangle, TestRectangle){
  Rectangle rectangle(3.712, 4);
  ASSERT_EQ(14.848, rectangle.area());
  ASSERT_EQ(15.424, rectangle.perimeter());
  ASSERT_EQ("Rectangle (3.712, 4.000)", rectangle.info());
}

TEST(Rectangle, TestRectanglefail){
  try {
    Rectangle(0, 1);
  }catch(std::string e) {
      ASSERT_EQ("This is not a rectangle!", e);
  }
  ASSERT_NO_THROW(Rectangle(1, 1));
}

#include "../src/rectangle.h"

TEST(RECT, CreateReactangle){
  Rectangle rectangle(3.33333,4.55555);
  ASSERT_EQ(15.185, rectangle.area());
  ASSERT_EQ(15.777, rectangle.perimeter());
  ASSERT_EQ("Rectangle (3.333, 4.555)", rectangle.info());
}

TEST(RECT, CreateRectFail){
  try{
    Rectangle rect(3,0);
    FAIL();
  }
  catch(std::string msg){
    ASSERT_EQ("This is not a rectangle!", msg);
  }
}

#include "../src/rectangle.h"

TEST(RECT, CreateReactangle){
  Rectangle rectangle(10.99999, 30.66666);
  ASSERT_EQ(337.332, rectangle.area());
  ASSERT_EQ(83.333, rectangle.perimeter());
  ASSERT_EQ("Rectangle (10.999, 30.666)", rectangle.info());
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

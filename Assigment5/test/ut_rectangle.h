#include "../src/rectangle.h"

TEST(Shapes, CreateRectangle){
  Rectangle rectangle("1",3.712,4.000);
  ASSERT_EQ(14.848, rectangle.area());
  ASSERT_EQ(15.424, rectangle.perimeter());
  ASSERT_EQ("Rectangle (3.712, 4.000)", rectangle.info());

  try {
      Rectangle rectangle("1",0, 1.000);
      FAIL();
  }catch(std::string e) {
      ASSERT_EQ("This is not a rectangle!", e);
  }
  try {
      Rectangle rectangle("1",-1.234, 1.000);
      FAIL();
  }catch(std::string e) {
      ASSERT_EQ("This is not a rectangle!", e);
  }

  ASSERT_NO_THROW(Rectangle rectangle("1",1, 1));


}

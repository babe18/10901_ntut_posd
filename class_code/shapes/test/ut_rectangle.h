#include "../src/rectangle.h"

TEST(Shapes, CreateRectangle) {
  Rectangle rectangle(3, 4.5);
  ASSERT_EQ(13.5, rectangle.area());
}

TEST(Shapes, RectangelTest){
  Shape * rectangle1 = new Rectangle(2, 4.5);
  Shape * rectangle2 = new Rectangle(3, 4.5);
  try{
    rectangle1->add(rectangle2);
    FAIL();
  }
  catch(std::string e){
    ASSERT_EQ("Can't support this operation.", e);
  }

  //memory leak
  delete rectangle1;
  delete rectangle2;
}

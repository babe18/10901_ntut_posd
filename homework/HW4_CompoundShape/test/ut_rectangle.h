#include "../src/rectangle.h"

TEST (Rectangle, ExceptionForLengthIsZero)
{
    try {
    Rectangle("1",0,3.712);
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}
TEST (Rectangle, ExceptionForWidthIsZero)
{
    try {
    Rectangle("1",4,0);
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}
TEST (Rectangle, ExceptionForLengthLessThanZero)
{
    try {
    Rectangle("1",-4,3);
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}
TEST (Rectangle, ExceptionForWidthLessThanZero)
{
    try {
    Rectangle("1",4,-3);
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}
TEST (Rectangle, AreaInt)
{
  Rectangle rectangle("1",4,3);
  ASSERT_NEAR(12, rectangle.area(), 0.001);
}
TEST (Rectangle, AreaDouble)
{
  Rectangle rectangle("1",4.5,3.5);
  ASSERT_NEAR(15.75, rectangle.area(), 0.001);
}
TEST (Rectangle, PerimeterInt)
{
  Rectangle rectangle("1",4,3);
  ASSERT_NEAR(14, rectangle.perimeter(), 0.001);
}
TEST (Rectangle, PerimeterDouble)
{
  Rectangle rectangle("1",4.5,3.5);
  ASSERT_NEAR(16, rectangle.perimeter(), 0.001);;
}
TEST (Rectangle, Info)
{
  Rectangle rectangle("1",4,3.712);
  ASSERT_EQ("Rectangle (4.000, 3.712)", rectangle.info());
}
TEST (Rectangle, RedColor)
{
  Rectangle rectangle("1",4,3.712,"red");
  ASSERT_EQ("red", rectangle.color());
}
TEST (Rectangle, DefaultColor)
{
  Rectangle rectangle("1",4,3.712);
  ASSERT_EQ("white", rectangle.color());
}
TEST (Rectangle, ExceptionForAddShape)
{
  try {
    Rectangle rectangle("1",4,3.712);
    Shape * rectangle1 = new Rectangle("4",12,4);
    rectangle.addShape(rectangle1);
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can add shape!", e);
  }
}
TEST (Rectangle, ExceptionForDeleteShape)
{
  try {
    Rectangle rectangle("1",4,3.712);
    rectangle.deleteShapeById("1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can delete shape!", e);
  }
}
TEST (Rectangle, ExceptionForGetShapeById)
{
  try {
    Rectangle rectangle("1",4,3.712);
    rectangle.getShapeById("1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can get shape!", e);
  }
}

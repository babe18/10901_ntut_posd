#include "../src/rectangle.h"

TEST (Rectangle, exception_for_length_is_zero)
{
    try {
    Rectangle("1",0,3.712);
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}
TEST (Rectangle, exception_for_width_is_zero)
{
    try {
    Rectangle("1",4,0);
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}
TEST (Rectangle, exception_for_length_less_than_zero)
{
    try {
    Rectangle("1",-4,3);
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}
TEST (Rectangle, exception_for_width_less_than_zero)
{
    try {
    Rectangle("1",4,-3);
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}
TEST (Rectangle, no_exception_constructor_with_default_color)
{
  Rectangle rectangle("1",4,3.712);
  ASSERT_EQ("white", rectangle.color());
}
TEST (Rectangle, no_exception_constructor_with_custom_color)
{
  Rectangle rectangle("1",4,3.712,"red");
  ASSERT_EQ("red", rectangle.color());
}

TEST (RectangleTestSuite, id)
{
  Rectangle rectangle("1",4,3);
  ASSERT_EQ("1", rectangle.id());
}
TEST (RectangleTestSuite, default_color)
{
  Rectangle rectangle("1",4,3.712);
  ASSERT_EQ("white", rectangle.color());
}
TEST (RectangleTestSuite, custom_color)
{
  Rectangle rectangle("1",4,3.712,"red");
  ASSERT_EQ("red", rectangle.color());
}
TEST (RectangleTestSuite, area)
{
  Rectangle rectangle("1",4,3);
  ASSERT_NEAR(12, rectangle.area(), 0.001);
}
TEST (RectangleTestSuite, perimeter)
{
  Rectangle rectangle("1",4,3);
  ASSERT_NEAR(14, rectangle.perimeter(), 0.001);
}
TEST (RectangleTestSuite, Info)
{
  Rectangle rectangle("1",4,3.712);
  ASSERT_EQ("Rectangle (4.000, 3.712)", rectangle.info());
}
TEST (RectangleTestSuite, type)
{
  Rectangle rectangle("1",4,3.712);
  ASSERT_EQ("Rectangle", rectangle.type());
}
TEST (RectangleTestSuite, exception_for_add_shape)
{
  try {
    Rectangle rectangle("1",4,3.712);
    Shape * rectangle1 = new Rectangle("4",12,4);
    rectangle.addShape(rectangle1);
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can add shape!", e);
  }
}
TEST (RectangleTestSuite, exception_for_delete_shape)
{
  try {
    Rectangle rectangle("1",4,3.712);
    rectangle.deleteShapeById("1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can delete shape!", e);
  }
}
TEST (RectangleTestSuite, exception_for_get_shape_by_id)
{
  try {
    Rectangle rectangle("1",4,3.712);
    rectangle.getShapeById("1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can get shape!", e);
  }
}

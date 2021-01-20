#include "../src/ellipse.h"
TEST (Ellipse, constructor_with_default_color)
{
  Ellipse e("1",4,3.712);
  ASSERT_EQ("white", e.color());
}
TEST (EllipseTestSuite, constructor_with_custom_color)
{
  Ellipse e("1",4,3.712,"red");
  ASSERT_EQ("red", e.color());
}
TEST (EllipseTestSuite, exception_for_semi_major_axis_is_zero)
{
    try {
    Ellipse("1",0,3.712);
    }catch(std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}
TEST (EllipseTestSuite, exception_for_semi_minor_axis_is_zero)
{
    try {
    Ellipse("1",4,0);
    }catch(std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}
TEST (EllipseTestSuite, exception_for_semi_major_axis_less_than_zero)
{
    try {
    Ellipse("1",-4,1);
    }catch(std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}
TEST (EllipseTestSuite, exception_for_semi_minor_axis_less_than_zero)
{
    try {
    Ellipse("1",4,-11);
    }catch(std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}
TEST (EllipseTestSuite,id)
{
  Ellipse e("1",4,3.712);
  ASSERT_EQ("1", e.id());
}
TEST (EllipseTestSuite,default_color)
{
  Ellipse e("1",4,3.712);
  ASSERT_EQ("white", e.color());
}
TEST (EllipseTestSuite,custom_color)
{
  Ellipse e("1",4,3.712,"red");
  ASSERT_EQ("red", e.color());
}
TEST (EllipseTestSuite, area)
{
  Ellipse e("1",4,3);
  ASSERT_NEAR(37.699, e.area(), 0.001);
}
TEST (EllipseTestSuite, perimeter)
{
  Ellipse e("1",4,3);
  ASSERT_NEAR(22.849, e.perimeter(), 0.001);
}
TEST (EllipseTestSuite, Info)
{
  Ellipse e("1",4,3.712);
  ASSERT_EQ("Ellipse (4.000, 3.712)", e.info());
}
TEST (EllipseTestSuite, type)
{
  Ellipse e("1",4,3.712);
  ASSERT_EQ("Ellipse", e.type());
}
TEST (EllipseTestSuite, exception_for_add_shape)
{
  try {
    Ellipse e("1",4,3.712);
    Shape * Ellipse1 = new Ellipse("4",12,4);
    e.addShape(Ellipse1);
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can add shape!", e);
  }
}
TEST (EllipseTestSuite, exception_for_delete_shape)
{
  try {
    Ellipse e("1",4,3.712);
    e.deleteShapeById("1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can delete shape!", e);
  }
}
TEST (EllipseTestSuite, exception_for_get_shape_by_id)
{
  try {
    Ellipse e("1",4,3.712);
    e.getShapeById("1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can get shape!", e);
  }
}

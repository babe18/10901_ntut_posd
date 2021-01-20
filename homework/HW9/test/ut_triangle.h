#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"
TEST (Triangle, no_exception_constructor)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Triangle triangle("2",triangleVector);
  ASSERT_NEAR(6, triangle.area(), 0.001);
  ASSERT_NEAR(12, triangle.perimeter(), 0.001);
  ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle.info());
}
TEST (TriangleTestSuite, exception_for_coordinate_less_than_three)
{
  try {
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(3, 0);
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(&t1);
    triangleVector.push_back(&t2);
    Triangle triangle("2",triangleVector);
    Shape * rectangle1 = new Rectangle("4",12,4);
    triangle.addShape(rectangle1);
  }catch(std::string e) {
      ASSERT_EQ("This is not a triangle!", e);
  }
}
TEST (TriangleTestSuite, exception_for_coordinate_more_than_three)
{
  try {
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(3, 0);
    TwoDimensionalCoordinate t3(0, 4);
    TwoDimensionalCoordinate t4(0, 4);
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(&t1);
    triangleVector.push_back(&t2);
    triangleVector.push_back(&t3);
    triangleVector.push_back(&t4);
    Triangle triangle("2",triangleVector);
    Shape * rectangle1 = new Rectangle("4",12,4);
    triangle.addShape(rectangle1);
  }catch(std::string e) {
      ASSERT_EQ("This is not a triangle!", e);
  }
}
TEST (TriangleTestSuite, default_color)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Triangle triangle("2",triangleVector);
  ASSERT_EQ("white", triangle.color());
}
TEST (TriangleTestSuite, custom_color)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Triangle triangle("2",triangleVector,"red");
  ASSERT_EQ("red", triangle.color());
}
TEST (TriangleTestSuite, id)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Triangle triangle("2",triangleVector);
  ASSERT_EQ("2", triangle.id());
}
TEST (TriangleTestSuite, area)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Triangle triangle("2",triangleVector);
  ASSERT_NEAR(6, triangle.area(), 0.001);
}
TEST (TriangleTestSuite, perimeter)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Triangle triangle("2",triangleVector);
  ASSERT_NEAR(12, triangle.perimeter(), 0.001);
}
TEST (TriangleTestSuite, Info)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Triangle triangle("2",triangleVector);
  ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle.info());
}
TEST (TriangleTestSuite, type)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Triangle triangle("2",triangleVector);
  ASSERT_EQ("Triangle", triangle.type());
}
TEST (TriangleTestSuite, exception_for_add_shape)
{
  try {
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(3, 0);
    TwoDimensionalCoordinate t3(0, 4);
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(&t1);
    triangleVector.push_back(&t2);
    triangleVector.push_back(&t3);
    Triangle triangle("2",triangleVector);
    Shape * rectangle1 = new Rectangle("4",12,4);
    triangle.addShape(rectangle1);
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can add shape!", e);
  }
}
TEST (TriangleTestSuite, exception_for_delete_shape)
{
  try {
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(3, 0);
    TwoDimensionalCoordinate t3(0, 4);
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(&t1);
    triangleVector.push_back(&t2);
    triangleVector.push_back(&t3);
    Triangle triangle("2",triangleVector);
    triangle.deleteShapeById("1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can delete shape!", e);
  }
}
TEST (TriangleTestSuite, exception_for_get_shape_by_id)
{
  try {
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(3, 0);
    TwoDimensionalCoordinate t3(0, 4);
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(&t1);
    triangleVector.push_back(&t2);
    triangleVector.push_back(&t3);
    Triangle triangle("2",triangleVector);
    triangle.getShapeById("1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can get shape!", e);
  }
}

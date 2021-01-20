#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"

TEST (Triangle, ConstructorNoException)
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

TEST (Triangle, AreaInt)
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
TEST (Triangle, AreaDouble)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3.5, 0);
  TwoDimensionalCoordinate t3(0, 4.5);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Triangle triangle("2",triangleVector);
  ASSERT_NEAR(7.875, triangle.area(), 0.001);
}
TEST (Triangle, PerimeterInt)
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
TEST (Triangle, PerimeterDouble)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3.5, 0);
  TwoDimensionalCoordinate t3(0, 4.5);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Triangle triangle("2",triangleVector);
  ASSERT_NEAR(13.700, triangle.perimeter(), 0.001);;
}
TEST (Triangle, Info)
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
TEST (Triangle, RedColor)
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
TEST (Triangle, DefaultColor)
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
TEST (Triangle, ExceptionForAddShape)
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
TEST (Triangle, ExceptionForDeleteShape)
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
TEST (Triangle, ExceptionForGetShapeById)
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

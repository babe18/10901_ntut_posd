#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"

TEST(Shapes, Createtriangle){

  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(new TwoDimensionalCoordinate(0.000, 0.000));
  triangleVector.push_back(new TwoDimensionalCoordinate(0.000, -3.141));
  triangleVector.push_back(new TwoDimensionalCoordinate(-4.000, 0.000));
  Triangle triangle("3",triangleVector);
  ASSERT_EQ(6.282, triangle.area());
  ASSERT_EQ(12.226, triangle.perimeter());
  ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.141], [-4.000, 0.000])", triangle.info());



}

TEST(Shapes, testCreatetriangle){

  try {
      std::vector<TwoDimensionalCoordinate*> triangleVector;
      triangleVector.push_back(new TwoDimensionalCoordinate(0.000, 0.000));
      triangleVector.push_back(new TwoDimensionalCoordinate(0.000, -3.141));
      triangleVector.push_back(new TwoDimensionalCoordinate(0.000, -4.000));
            Triangle triangle("3",triangleVector);
      FAIL();
  }catch(std::string e) {
      ASSERT_EQ("This is not a triangle!", e);
  }
  try {
      std::vector<TwoDimensionalCoordinate*> triangleVector;
      triangleVector.push_back(new TwoDimensionalCoordinate(0.000, 0.000));
      triangleVector.push_back(new TwoDimensionalCoordinate(0.000, -3.141));
      triangleVector.push_back(new TwoDimensionalCoordinate(0.000, -3.141));
      Triangle triangle("3",triangleVector);
      FAIL();
  }catch(std::string e) {
      ASSERT_EQ("This is not a triangle!", e);
  }

  try {
      std::vector<TwoDimensionalCoordinate*> triangleVector;
      triangleVector.push_back(new TwoDimensionalCoordinate(0.000, 0.000));
      triangleVector.push_back(new TwoDimensionalCoordinate(0.000, -3.141));
      Triangle triangle("3",triangleVector);
      FAIL();
  }catch(std::string e) {
      ASSERT_EQ("This is not a triangle!", e);
  }

  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(new TwoDimensionalCoordinate(0.000, 0.000));
  triangleVector.push_back(new TwoDimensionalCoordinate(0.000, -3.141));
    triangleVector.push_back(new TwoDimensionalCoordinate(4.000, 0.000));
  ASSERT_NO_THROW(Triangle triangle("3",triangleVector));


}

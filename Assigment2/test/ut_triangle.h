#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"

TEST(TRIANGLE, CreateTriangle){
  try {
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
  triangleVector.push_back(new TwoDimensionalCoordinate(3.4567, 0));
  triangleVector.push_back(new TwoDimensionalCoordinate(0, 4.8765));
  Triangle triangle(triangleVector);

  ASSERT_EQ(8.428, triangle.area());
  ASSERT_EQ(14.310,triangle.perimeter());
  ASSERT_EQ("Triangle ([0.000, 0.000], [3.456, 0.000], [0.000, 4.876])", triangle.info());
  }

  catch(std::string msg) {
    ASSERT_EQ("This is not a triangle!", msg);
  }
}

TEST(TRIANGLE, CreateTriangleFail){
  //less than 3 points
  try {
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
  triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
  Triangle triangle(triangleVector);
  FAIL();
  }
  catch(std::string msg){
    ASSERT_EQ("This is not a triangle!", msg);
  }
  // more the 3 points
  try {
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
  triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
  triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
  triangleVector.push_back(new TwoDimensionalCoordinate(6, 4));
  Triangle triangle(triangleVector);
  FAIL();
  }
  catch(std::string msg){
    ASSERT_EQ("This is not a triangle!", msg);
  }
  // vertical or horizontal slope
  try{
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 1));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Triangle triangle(triangleVector);
    FAIL();
  }
  catch(std::string msg){
    ASSERT_EQ("This is not a triangle!", msg);
  }
  // three points with same slope
  try{
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(1, 1));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 3));
    Triangle triangle(triangleVector);
    FAIL();
  }
  catch(std::string msg){
    ASSERT_EQ("This is not a triangle!", msg);
  }
  // same points
  try{
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 2));
    Triangle triangle(triangleVector);
    FAIL();
  }
  catch(std::string msg){
    ASSERT_EQ("This is not a triangle!", msg);
  }
}

#include "../src/shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/sort.h"

class ShapeSort : public ::testing::Test {
protected:
  void SetUp() override {
     triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
     triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
     triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
     r34 = new Rectangle(3, 4);
     r22 = new Rectangle(2, 2);
     r28 = new Rectangle(2, 8);
     e21 = new Ellipse(2,1);
     t345 = new Triangle(triangleVector);
  }

  void TearDown() override {
      delete r34;
      delete r22;
      delete r28;
      delete e21;
      delete t345;
  }

  Shape * r34;
  Shape * r22;
  Shape * r28;
  Shape * t345;
  Shape * e21; //area 6.283, perimeter 10.283
  std::vector<TwoDimensionalCoordinate*> triangleVector;
};

TEST_F(ShapeSort, AscendingByAreaUsingFunction) {
  Shape * shapes[5] = {r28, e21, r22, r34, t345};
  quickSort(shapes, shapes+5, areaAscendingCompare);
  EXPECT_EQ(4, shapes[0]->area());
  EXPECT_EQ(6, shapes[1]->area());
  EXPECT_EQ(6.283, shapes[2]->area());
  EXPECT_EQ(12, shapes[3]->area());
  EXPECT_EQ(16, shapes[4]->area());
}

TEST_F(ShapeSort, DescendingByAreaUsingFunction) {
  Shape * shapes[5] = {r28, e21, r22, r34, t345};
  quickSort(shapes, shapes+5, areaDescendingCompare);
  EXPECT_EQ(16, shapes[0]->area());
  EXPECT_EQ(12, shapes[1]->area());
  EXPECT_EQ(6.283, shapes[2]->area());
  EXPECT_EQ(6, shapes[3]->area());
  EXPECT_EQ(4, shapes[4]->area());
}

TEST_F(ShapeSort, AscendingByPerimeterUsingFunction){
    Shape * shapes[5] = {r28, e21, r22, r34, t345};
    quickSort(shapes, shapes+5, perimeterAscendingCompare);
    EXPECT_EQ(8, shapes[0]->perimeter());
    EXPECT_EQ(10.283, shapes[1]->perimeter());
    EXPECT_EQ(12, shapes[2]->perimeter());
    EXPECT_EQ(14, shapes[3]->perimeter());
    EXPECT_EQ(20, shapes[4]->perimeter());
}

TEST_F(ShapeSort, DescendingByPerimeterUsingFunction){
    Shape * shapes[5] = {r28, e21, r22, r34, t345};
    quickSort(shapes, shapes+5, perimeterDescendingCompare);
    EXPECT_EQ(20, shapes[0]->perimeter());
    EXPECT_EQ(14, shapes[1]->perimeter());
    EXPECT_EQ(12, shapes[2]->perimeter());
    EXPECT_EQ(10.283, shapes[3]->perimeter());
    EXPECT_EQ(8, shapes[4]->perimeter());
}

TEST_F(ShapeSort, AscendingByAreaUsingLambda) {
  Shape * shapes[5] = {r28, e21, r22, r34, t345};
  quickSort(shapes, shapes+5, [](Shape * a, Shape * b) { return a->area() < b->area(); });
  EXPECT_EQ(4, shapes[0]->area());
  EXPECT_EQ(6, shapes[1]->area());
  EXPECT_EQ(6.283, shapes[2]->area());
  EXPECT_EQ(12, shapes[3]->area());
  EXPECT_EQ(16, shapes[4]->area());
}

TEST_F(ShapeSort, DescendingByPerimeterUsingObject){
    Shape * shapes[5] = {r28, e21, r22, r34, t345};
    quickSort(shapes, shapes+5, desPerimeterObject);
    EXPECT_EQ(20, shapes[0]->perimeter());
    EXPECT_EQ(14, shapes[1]->perimeter());
    EXPECT_EQ(12, shapes[2]->perimeter());
    EXPECT_EQ(10.283, shapes[3]->perimeter());
    EXPECT_EQ(8, shapes[4]->perimeter());
}

TEST_F(ShapeSort, AscendingByAreaUsingLambdaOnArray) {
  std::array<Shape *, 5> shapes = {r28, e21, r22, r34, t345};
  quickSort(shapes.begin(), shapes.end(), [](Shape * a, Shape * b) { return a->area() < b->area(); });
  EXPECT_EQ(4, shapes[0]->area());
  EXPECT_EQ(6, shapes[1]->area());
  EXPECT_EQ(6.283, shapes[2]->area());
  EXPECT_EQ(12, shapes[3]->area());
  EXPECT_EQ(16, shapes[4]->area());
}

TEST_F(ShapeSort, AscendingByAreaUsingFeature) {
  std::array<Shape *, 5> shapes = {r28, e21, r22, r34, t345};
  quickSort(shapes.begin(), shapes.end(), AscendingCompare("area"));
  EXPECT_EQ(4, shapes[0]->area());
  EXPECT_EQ(6, shapes[1]->area());
  EXPECT_EQ(6.283, shapes[2]->area());
  EXPECT_EQ(12, shapes[3]->area());
  EXPECT_EQ(16, shapes[4]->area());
}

TEST_F(ShapeSort, AscendingByPerimeterUsingFeature) {
  std::array<Shape *, 5> shapes = {r28, e21, r22, r34, t345};
  quickSort(shapes.begin(), shapes.end(), AscendingCompare("perimeter"));
  EXPECT_EQ(8, shapes[0]->perimeter());
  EXPECT_EQ(10.283, shapes[1]->perimeter());
  EXPECT_EQ(12, shapes[2]->perimeter());
  EXPECT_EQ(14, shapes[3]->perimeter());
  EXPECT_EQ(20, shapes[4]->perimeter());
}

TEST_F(ShapeSort, DescendingByAreaUsingFeature) {
  std::array<Shape *, 5> shapes = {r28, e21, r22, r34, t345};
  quickSort(shapes.begin(), shapes.end(), DescendingCompare("area"));
  EXPECT_EQ(16, shapes[0]->area());
  EXPECT_EQ(12, shapes[1]->area());
  EXPECT_EQ(6.283, shapes[2]->area());
  EXPECT_EQ(6, shapes[3]->area());
  EXPECT_EQ(4, shapes[4]->area());
}

TEST_F(ShapeSort, DescendingByPerimeterUsingFeature) {
  std::array<Shape *, 5> shapes = {r28, e21, r22, r34, t345};
  quickSort(shapes.begin(), shapes.end(), DescendingCompare("perimeter"));
  EXPECT_EQ(20, shapes[0]->perimeter());
  EXPECT_EQ(14, shapes[1]->perimeter());
  EXPECT_EQ(12, shapes[2]->perimeter());
  EXPECT_EQ(10.283, shapes[3]->perimeter());
  EXPECT_EQ(8, shapes[4]->perimeter());
}

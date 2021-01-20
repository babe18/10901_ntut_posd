#include "../src/shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include <array>

class ShapeSort : public ::testing::Test {
protected:
  void SetUp() override {
     r34 = new Rectangle(3, 4);
     r22 = new Rectangle(2, 2);
     t345 = new Triangle(3, 4, 5);
  }

  void TearDown() override {
      delete r34;
      delete r22;
      delete t345;
  }

  Shape * r34;
  Shape * r22;
  Shape * t345;
};

TEST_F(ShapeSort, SubtypePolymorphism){
  Shape * shapes[3] = {t345, r34, r22};
  ASSERT_EQ(6, shapes[0]->area());
  ASSERT_EQ(12, shapes[1]->area());
  ASSERT_EQ(4, shapes[2]->area());
}


TEST_F(ShapeSort, AscendingByArea) {
  Shape * shapes[3] = {t345, r34, r22};
  AreaSmaller as;
  std::sort(shapes, shapes+3, as);
  EXPECT_EQ(4, shapes[0]->area());
  EXPECT_EQ(6, shapes[1]->area());
  EXPECT_EQ(12, shapes[2]->area());
}

TEST_F(ShapeSort, DecendingByArea) {
  Shape * shapes[3] = {t345, r34, r22};
  std::sort(shapes, shapes+3, [](Shape * a, Shape * b) { return a->area() > b->area(); });
  EXPECT_EQ(12, shapes[0]->area());
  EXPECT_EQ(6, shapes[1]->area());
  EXPECT_EQ(4, shapes[2]->area());
}

TEST_F(ShapeSort, DecendingByAreaOnArray) {
  std::array<Shape *, 3> shapes = {t345, r34, r22};
  std::sort(shapes.begin(), shapes.end(), [](Shape * a, Shape * b) { return a->area() > b->area(); });
  EXPECT_EQ(12, shapes[0]->area());
  EXPECT_EQ(6, shapes[1]->area());
  EXPECT_EQ(4, shapes[2]->area());
}

#include "../src/triangle.h"

TEST(Shapes, CreateTriangle) {
  Triangle triangle(1, 1, 1);
  ASSERT_EQ(sqrt(3) / 4, triangle.area());
}

#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"

TEST(Triangle, TestTriangle) {
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);

  Triangle triangle(triangleVector);
  ASSERT_EQ(6.0, triangle.area());
  ASSERT_EQ(12.0, triangle.perimeter());
  ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle.info());
}
TEST(Triangle, TestTrianglefail) {
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(5, 0);
    //TwoDimensionalCoordinate t3(100, 0);
        vector<TwoDimensionalCoordinate*> vec;
    try{
            vec.push_back(&t1);
            vec.push_back(&t2);
            //vec.push_back(&t3);
            Triangle triangle4(vec);
             FAIL(); // you want fail but success means this test fail.
          }catch(std::string e){
            EXPECT_EQ(std::string("This is not a triangle!"), e);
          }
    }
TEST(Triangle, Test) {

}

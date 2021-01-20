#include "../src/shape.h"
#include "../src/compound_shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape_iterator.h"
#include "../src/iterator.h"
#include "../src/null_iterator.h"
#include <vector>
#include <list>
//rectangle
TEST(IteratorTestSuite, exception_for_rectangle_iterate_first) {
  try {
          Shape * r34 = new Rectangle("1",3, 4);
          Iterator * it = r34->createIterator();
          it->first();
          FAIL();
      }catch(string e) {
          ASSERT_EQ("No child member!", e);
     }
}
TEST(IteratorTestSuite, exception_for_rectangle_iterate_current_item) {
  try {
          Shape * r34 = new Rectangle("1",3, 4);
          Iterator * it = r34->createIterator();
          ASSERT_EQ(48, it->currentItem()->area());
          FAIL();
      }catch(string e) {
          ASSERT_EQ("No child member!", e);
     }
}
TEST(IteratorTestSuite, exception_for_rectangle_iterate_next) {
  try {
          Shape * r34 = new Rectangle("1",3, 4);
          Iterator * it = r34->createIterator();
          it->next();
          FAIL();
      }catch(string e) {
          ASSERT_EQ("No child member!", e);
     }
}
TEST(IteratorTestSuite, rectangle_iterate_is_done) {
  Shape * r34 = new Rectangle("1",3, 4);
  Iterator * it = r34->createIterator();
  ASSERT_TRUE(it->isDone());
}
//ellipse
TEST(IteratorTestSuite, exception_for_ellipse_iterate_first) {
  try {
          Shape * e43 = new Ellipse("1",4, 3);
          Iterator * it = e43->createIterator();
          it->first();
          FAIL();
      }catch(string e) {
          ASSERT_EQ("No child member!", e);
     }
}
TEST(IteratorTestSuite, exception_for_ellipse_iterate_current_item) {
  try {
          Shape * e43 = new Ellipse("1",4, 3);
          Iterator * it = e43->createIterator();
          ASSERT_EQ(48, it->currentItem()->area());
          FAIL();
      }catch(string e) {
          ASSERT_EQ("No child member!", e);
     }
}
TEST(IteratorTestSuite, exception_for_ellipse_iterate_next) {
  try {
          Shape * e43 = new Ellipse("1",4, 3);
          Iterator * it = e43->createIterator();
          it->next();
          FAIL();
      }catch(string e) {
          ASSERT_EQ("No child member!", e);
     }
}
TEST(IteratorTestSuite, ellipse_iterate_is_done) {
  Shape * e43 = new Ellipse("1",4, 3);
  Iterator * it = e43->createIterator();
  ASSERT_TRUE(it->isDone());
}
//triangle
TEST(IteratorTestSuite, exception_for_triangle_iterate_first) {
  try {
          TwoDimensionalCoordinate t1(0, 0);
          TwoDimensionalCoordinate t2(3, 0);
          TwoDimensionalCoordinate t3(0, 4);
          std::vector<TwoDimensionalCoordinate*> triangleVector;
          triangleVector.push_back(&t1);
          triangleVector.push_back(&t2);
          triangleVector.push_back(&t3);
          Shape * t123 = new Triangle("3",triangleVector);
          Iterator * it = t123->createIterator();
          it->first();
          FAIL();
      }catch(string e) {
          ASSERT_EQ("No child member!", e);
     }
}
TEST(IteratorTestSuite, exception_for_triangle_iterate_current_item) {
  try {
          TwoDimensionalCoordinate t1(0, 0);
          TwoDimensionalCoordinate t2(3, 0);
          TwoDimensionalCoordinate t3(0, 4);
          std::vector<TwoDimensionalCoordinate*> triangleVector;
          triangleVector.push_back(&t1);
          triangleVector.push_back(&t2);
          triangleVector.push_back(&t3);
          Shape * t123 = new Triangle("3",triangleVector);
          Iterator * it = t123->createIterator();
          ASSERT_EQ(48, it->currentItem()->area());
          FAIL();
      }catch(string e) {
          ASSERT_EQ("No child member!", e);
     }
}
TEST(IteratorTestSuite, exception_for_triangle_iterate_next) {
  try {
          TwoDimensionalCoordinate t1(0, 0);
          TwoDimensionalCoordinate t2(3, 0);
          TwoDimensionalCoordinate t3(0, 4);
          std::vector<TwoDimensionalCoordinate*> triangleVector;
          triangleVector.push_back(&t1);
          triangleVector.push_back(&t2);
          triangleVector.push_back(&t3);
          Shape * t123 = new Triangle("3",triangleVector);
          Iterator * it = t123->createIterator();
          it->next();
          FAIL();
      }catch(string e) {
          ASSERT_EQ("No child member!", e);
     }
}
TEST(IteratorTestSuite, triangle_iterate_is_done) {
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape * t123 = new Triangle("3",triangleVector);
  Iterator * it = t123->createIterator();
  ASSERT_TRUE(it->isDone());
}
//compound_shape
TEST(IteratorTest, compound_shape_iterate_first) {
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Rectangle("1",12,4) ,new Rectangle("2",5,4),new Triangle("3",triangleVector)};
  std::list<Shape*> shapeVec;
  shapeVec.clear();
  for(int i=0;i<3;i++)
     shapeVec.push_back(shape_array[i]);
  Shape* compoundShape = new CompoundShape("7", shapeVec);
  Iterator * it = compoundShape->createIterator();
  ASSERT_EQ(48, it->currentItem()->area());
  it->next();
  ASSERT_EQ(20, it->currentItem()->area());
  it->next();
  ASSERT_EQ(6, it->currentItem()->area());
  it->first();
  ASSERT_EQ(48, it->currentItem()->area());
}
TEST(IteratorTest, compound_shape_iterate_current_item) {
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Rectangle("1",12,4) ,new Rectangle("2",5,4),new Triangle("3",triangleVector)};
  std::list<Shape*> shapeVec;
  shapeVec.clear();
  for(int i=0;i<3;i++)
     shapeVec.push_back(shape_array[i]);
  Shape* compoundShape = new CompoundShape("7", shapeVec);
  Iterator * it = compoundShape->createIterator();
  ASSERT_EQ(48, it->currentItem()->area());
  it->next();
  ASSERT_EQ(20, it->currentItem()->area());
  it->next();
  ASSERT_EQ(6, it->currentItem()->area());
  it->next();
  ASSERT_TRUE(it->isDone());
}
TEST(IteratorTest, compound_shape_iterate_current_next) {
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Rectangle("1",12,4) ,new Rectangle("2",5,4),new Triangle("3",triangleVector)};
  std::list<Shape*> shapeVec;
  shapeVec.clear();
  for(int i=0;i<3;i++)
     shapeVec.push_back(shape_array[i]);
  Shape* compoundShape = new CompoundShape("7", shapeVec);
  Iterator * it = compoundShape->createIterator();
  ASSERT_EQ(48, it->currentItem()->area());
  it->next();
  ASSERT_EQ(20, it->currentItem()->area());
  it->next();
  ASSERT_EQ(6, it->currentItem()->area());
  it->next();
  ASSERT_TRUE(it->isDone());
}
TEST(IteratorTestSuite, exception_for_compound_shape_iterate_next_out_of_range){
  try {
          TwoDimensionalCoordinate t1(0, 0);
          TwoDimensionalCoordinate t2(3, 0);
          TwoDimensionalCoordinate t3(0, 4);
          std::vector<TwoDimensionalCoordinate*> triangleVector;
          triangleVector.push_back(&t1);
          triangleVector.push_back(&t2);
          triangleVector.push_back(&t3);
          Shape* shape_array[] = {new Rectangle("1",12,4) ,new Rectangle("2",5,4),new Triangle("3",triangleVector)};
          std::list<Shape*> shapeVec;
          shapeVec.clear();
          for(int i=0;i<3;i++)
             shapeVec.push_back(shape_array[i]);
          Shape* compoundShape = new CompoundShape("7", shapeVec);
          Iterator * it = compoundShape->createIterator();
          ASSERT_EQ(48, it->currentItem()->area());
          it->next();
          ASSERT_EQ(20, it->currentItem()->area());
          it->next();
          ASSERT_EQ(6, it->currentItem()->area());
          it->next();
          it->next();
          FAIL();
      }catch(string e) {
          ASSERT_EQ("Moving past the end!", e);
     }
}
TEST(IteratorTest, compound_shape_iterate_is_done) {
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Rectangle("1",12,4) ,new Rectangle("2",5,4),new Triangle("3",triangleVector)};
  std::list<Shape*> shapeVec;
  shapeVec.clear();
  for(int i=0;i<3;i++)
     shapeVec.push_back(shape_array[i]);
  Shape* compoundShape = new CompoundShape("7", shapeVec);
  Iterator * it = compoundShape->createIterator();
  ASSERT_EQ(48, it->currentItem()->area());
  it->next();
  ASSERT_EQ(20, it->currentItem()->area());
  it->next();
  ASSERT_EQ(6, it->currentItem()->area());
  it->next();
  ASSERT_TRUE(it->isDone());
}
// TEST(IteratorTest, VectorIterator) {
//   std::vector<int> v = {0, 1, 2};
//   std::vector<int>::iterator it = v.begin();
//   ASSERT_EQ(0, *it++);
//   ASSERT_EQ(1, *it++);
//   ASSERT_EQ(2, *it++);
//   ASSERT_EQ(v.end(), it);
// }

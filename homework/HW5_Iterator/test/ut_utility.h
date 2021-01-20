#include "../src/utility.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"
#include "../src/two_dimensional_coordinate.h"
#include "../src/ellipse.h"
#include "../src/shape_iterator.h"
#include "../src/iterator.h"
#include "../src/null_iterator.h"
#include <gtest/gtest.h>
#include <stdexcept>
TEST(UtlilityTestSuite, exception_for_rectangle_filter_shape)
{
  try {
    Shape * rectangle = new Rectangle("9",3,2);
    filterShape(rectangle, AreaFilter(100, 1));
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can filter shape!", e);
  }
}
TEST(UtlilityTestSuite, exception_for_rectangle_get_shape_by_id)
{
  try {
    Shape * rectangle = new Rectangle("9",3,2);
    getShapeById(rectangle, "1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can get shape!", e);
  }
}
TEST(UtlilityTestSuite, exception_for_ellipse_filter_shape)
{
  try {
    Shape * ellipse = new Ellipse("9",3,2);
    filterShape(ellipse, AreaFilter(100, 1));
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can filter shape!", e);
  }
}
TEST(UtlilityTestSuite, exception_for_ellipse_get_shape_by_id)
{
  try {
    Shape * ellipse = new Ellipse("9",3,2);
    getShapeById(ellipse, "1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can get shape!", e);
  }
}
TEST(UtlilityTestSuite, exception_for_triangle_filter_shape)
{
  try {
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(3, 0);
    TwoDimensionalCoordinate t3(0, 4);
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(&t1);
    triangleVector.push_back(&t2);
    triangleVector.push_back(&t3);
    Shape * triangle = new Triangle("3",triangleVector);
    filterShape(triangle, AreaFilter(100, 1));
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can filter shape!", e);
  }
}
TEST(UtlilityTestSuite, exception_for_triangle_get_shape_by_id)
{
  try {
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(3, 0);
    TwoDimensionalCoordinate t3(0, 4);
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(&t1);
    triangleVector.push_back(&t2);
    triangleVector.push_back(&t3);
    Shape * triangle = new Triangle("3",triangleVector);
    getShapeById(triangle, "1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can get shape!", e);
  }
}
TEST(UtlilityTestSuite, compound_shape_get_shape_by_id)
{
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(3, 0);
    TwoDimensionalCoordinate t3(0, 4);
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(&t1);
    triangleVector.push_back(&t2);
    triangleVector.push_back(&t3);
    Shape* shape_array[] = {new Rectangle("2",5,4,"red"),new Triangle("3",triangleVector)};
    std::list<Shape*> shapeVec;
    shapeVec.clear();
    for(int i=0;i<2;i++)
       shapeVec.push_back(shape_array[i]);
    Shape* compoundShape = new CompoundShape("7", shapeVec);
    Shape* shapeVec1 = getShapeById(compoundShape, "2");
    ASSERT_EQ(20, shapeVec1->area());
    ASSERT_EQ("red", shapeVec1->color());
}
TEST(UtlilityTestSuite, exception_for_compound_shape_get_shape_by_id)
{
  try {
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(3, 0);
    TwoDimensionalCoordinate t3(0, 4);
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(&t1);
    triangleVector.push_back(&t2);
    triangleVector.push_back(&t3);
    Shape* shape_array[] = {new Rectangle("2",5,4),new Triangle("3",triangleVector)};
    std::list<Shape*> shapeVec;
    shapeVec.clear();
    for(int i=0;i<2;i++)
       shapeVec.push_back(shape_array[i]);
    Shape* compoundShape = new CompoundShape("7", shapeVec);
    getShapeById(compoundShape, "2");
  }catch(std::string e) {
      ASSERT_EQ("Expected get shape but shape not found", e);
  }
}

//retrun shapes that area in range of 10 >= && 5 <=, but don't include compoundShape_0 itself.
TEST(UtlilityTestSuite, compound_shape_filter_shape_by_area)
{
    Shape* shape_array[] = {new Rectangle("2",3,3),new Rectangle("3",2,2)};
    std::list<Shape*> shapeVec;
    shapeVec.clear();
    for(int i=0;i<2;i++)
       shapeVec.push_back(shape_array[i]);
    Shape* compoundShape = new CompoundShape("7", shapeVec);
    std::deque<Shape*> i = filterShape(compoundShape, AreaFilter(10,0));
    std::deque<Shape*>::iterator it;
    it = i.begin();
    ASSERT_EQ(9, (*it)->area());
    ASSERT_EQ(12, (*it)->perimeter());
}

// retrun shapes that perimeter in range 10 >= && 5 <=, but don't include compoundShape_0 itself.
TEST(UtlilityTestSuite, compound_shape_filter_shape_by_perimeter)
{
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(3, 0);
    TwoDimensionalCoordinate t3(0, 4);
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(&t1);
    triangleVector.push_back(&t2);
    triangleVector.push_back(&t3);
    Shape* shape_array[] = {new Ellipse("1",6,4) ,new Rectangle("2",5,4),new Triangle("3",triangleVector)};
    Shape* shape_array1[] = {new Ellipse("5",5,4) ,new Rectangle("4",6,4)};
    std::list<Shape*> shapeVec;
    shapeVec.clear();
    for(int i=0;i<3;i++)
       shapeVec.push_back(shape_array[i]);

    std::list<Shape*> shapeVec1;
    shapeVec1.clear();
    for(int i=0;i<2;i++)
    shapeVec1.push_back(shape_array1[i]);

    Shape* compoundShape = new CompoundShape("7", shapeVec);
    Shape * Ellipse1 = new Ellipse("4",12,4);
    Shape* compoundShape1 = new CompoundShape("8", shapeVec1);
    compoundShape1->addShape(compoundShape);
    // ASSERT_EQ("40", compoundShape1-> info());
    // filterShape(compoundShape, PerimeterFilter(10, 5));
    std::deque<Shape*> i = filterShape(compoundShape1,AreaFilter(100,0));
    std::deque<Shape*>::iterator it;
    it = i.begin();
    // ASSERT_EQ(6, (*it)-> area());
    // it++;
    ASSERT_NEAR(62.8319, (*it)-> area(),0.001);
    it++;
    ASSERT_EQ(24, (*it)-> area());
    it++;
    ASSERT_NEAR(75.3982, (*it)-> area(),0.001);
    it++;
    ASSERT_EQ(20, (*it)-> area());
    it++;
    ASSERT_EQ(6, (*it)-> area());
    // it++;
    // ASSERT_EQ(48, (*it)-> area());
}
// retrun shapes that type match "Compound Shape", but don't include compoundShape_0 itself.
TEST(UtlilityTestSuite, compound_shape_filter_shape_by_type)
{
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(3, 0);
    TwoDimensionalCoordinate t3(0, 4);
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(&t1);
    triangleVector.push_back(&t2);
    triangleVector.push_back(&t3);
    Shape* shape_array[] = {new Ellipse("1",12,4) ,new Rectangle("2",5,4),new Triangle("3",triangleVector)};
    std::list<Shape*> shapeVec;
    shapeVec.clear();
    for(int i=0;i<3;i++)
       shapeVec.push_back(shape_array[i]);
    Shape* compoundShape = new CompoundShape("7", shapeVec);
    filterShape(compoundShape, TypeFilter("Compound Shape"));
    //ASSERT_EQ("", result.info());

}
// retrun shapes that color match "white", but don't include compoundShape_0 itself.
TEST(UtlilityTestSuite, compound_shape_filter_shape_by_color)
{
    try {
    TwoDimensionalCoordinate t1(0, 0);
    TwoDimensionalCoordinate t2(3, 0);
    TwoDimensionalCoordinate t3(0, 4);
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(&t1);
    triangleVector.push_back(&t2);
    triangleVector.push_back(&t3);
    Shape* shape_array[] = {new Ellipse("1",12,4) ,new Rectangle("2",5,4),new Triangle("3",triangleVector)};
    std::list<Shape*> shapeVec;
    shapeVec.clear();
    for(int i=0;i<3;i++)
       shapeVec.push_back(shape_array[i]);
    Shape* compoundShape = new CompoundShape("7", shapeVec);
    filterShape(compoundShape, ColorFilter("white"));
  }catch(std::string e) {
        ASSERT_EQ("Expected get shape but shape not found", e);
    }
}

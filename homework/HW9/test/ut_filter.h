#include <gtest/gtest.h>
#include "../src/shape_filter.h"
#include "../src/shape_setter.h"

TEST(FilterTest, shape_filter_by_area) {
  std::list<Shape*> data = {};
  Shape* r1 = new Rectangle("1", 2, 5);
  Shape* r2 = new Rectangle("2", 10, 4);
  Shape* r3 = new Rectangle("3", 3, 6);
  data.push_back(r1);
  data.push_back(r2);
  data.push_back(r3);
  Filter* areaFilter = new ShapeFilter([](Shape* shape) {return shape->area() <= 30;});
  std::list<Shape*> results = areaFilter->push(data);
  std::list<Shape*>::const_iterator ite;
  ite = results.begin();
  ASSERT_EQ("1", (*ite)->id());
  ASSERT_NEAR(10, (*ite)->area(), 0.001);
  ASSERT_NEAR(14, (*ite)->perimeter(), 0.001);
  ASSERT_EQ("white", (*ite)->color());
  ite++;
  ASSERT_EQ("3", (*ite)->id());
  ASSERT_NEAR(18, (*ite)->area(), 0.001);
  ASSERT_NEAR(18, (*ite)->perimeter(), 0.001);
  ASSERT_EQ("white", (*ite)->color());
  ASSERT_EQ(2, results.size());
}

TEST(FilterTest, shape_filter_by_perimeter) {
  std::list<Shape*> data = {};
  Shape* r1 = new Rectangle("1", 2, 5);
  Shape* r2 = new Rectangle("2", 7, 7);
  Shape* r3 = new Rectangle("3", 3, 6);
  data.push_back(r1);
  data.push_back(r2);
  data.push_back(r3);
  Filter* perimeterFilter = new ShapeFilter([](Shape* shape) {return shape->perimeter() >= 20;});
  std::list<Shape*> results = perimeterFilter->push(data);
  std::list<Shape*>::const_iterator ite;
  ite = results.begin();
  ASSERT_EQ("2", (*ite)->id());
  ASSERT_NEAR(49, (*ite)->area(), 0.001);
  ASSERT_NEAR(28, (*ite)->perimeter(), 0.001);
  ASSERT_EQ("white", (*ite)->color());
  ASSERT_EQ(1, results.size());
}

TEST(FilterTest, shapefilter_by_color_no_result) {
  std::list<Shape*> data = {};
  Shape* r1 = new Rectangle("1", 2, 5);
  Shape* r2 = new Rectangle("2", 3, 6);
  data.push_back(r1);
  data.push_back(r2);
  Filter* colorFilter = new ShapeFilter([](Shape* shape) {return shape->color() == "red";});
  std::list<Shape*> results = colorFilter->push(data);
  std::list<Shape*>::const_iterator ite;
  ite = results.begin();
  ASSERT_EQ(nullptr, (*ite));
}

TEST(FilterTest, shape_setter) {
  std::list<Shape*> data;
  std::list<Shape*>::const_iterator ite;
  Shape* r1 = new Rectangle("1", 2, 5);
  Shape* r2 = new Rectangle("2", 3, 6);
  data.push_back(r1);
  data.push_back(r2);
  Filter* colorFilter = new ShapeSetter( [](Shape* shape) {return shape->setColor("black");} );
  ite = data.begin();
  ASSERT_EQ("white", (*ite)->color());
  std::list<Shape*> results = colorFilter->push(data);
  ite = results.begin();
  ASSERT_EQ("black", (*ite)->color());
}


TEST(FilterTest, shape_filter_by_area_perimeter_color_and_setter) {
  std::list<Shape*> data = {};
  Shape* r1 = new Rectangle("1", 2, 5);
  Shape* r2 = new Rectangle("2", 1, 2);
  Shape* r3 = new Rectangle("3", 8, 7);
  Shape* r4 = new Rectangle("4", 3, 6);
  data.push_back(r1);
  data.push_back(r2);
  data.push_back(r3);
  data.push_back(r4);
  Filter* areaFilter = new ShapeFilter([](Shape* shape) {return shape->area() <= 30;});
  Filter* perimeterFilter = new ShapeFilter([](Shape* shape) {return shape->perimeter() >= 10;});
  Filter* colorSetter = new ShapeSetter([](Shape* shape) {shape->setColor("black");});
  Filter* colorFilter = new ShapeFilter([](Shape* shape) {return shape->color() == "black";});
  areaFilter->setNext(perimeterFilter)->setNext(colorSetter)->setNext(colorFilter);
  std::list<Shape*> results = areaFilter->push(data);
  std::list<Shape*>::const_iterator ite;
  ite = results.begin();
  ASSERT_EQ("1", (*ite)->id());
  ASSERT_NEAR(10, (*ite)->area(), 0.001);
  ASSERT_NEAR(14, (*ite)->perimeter(), 0.001);
  ASSERT_EQ("black", (*ite)->color());
  ite++;
  ASSERT_EQ("4", (*ite)->id());
  ASSERT_NEAR(18, (*ite)->area(), 0.001);
  ASSERT_NEAR(18, (*ite)->perimeter(), 0.001);
  ASSERT_EQ("black", (*ite)->color());
  ASSERT_EQ(2, results.size());
}

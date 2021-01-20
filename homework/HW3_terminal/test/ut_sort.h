#include <gtest/gtest.h>
#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"
#include "../src/rectangle.h"
#include "../src/ellipse.h"
#include "../src/sort.h"
#include "../src/terminal.h"
#include <stdexcept>
#include <algorithm>

TEST(QuickSort,AreaAscendingByFunction)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Triangle(triangleVector),new Ellipse(10,5),new Rectangle(5,3),new Ellipse(12,4),new Ellipse(5,3)};
  std::vector<Shape*> shapes;
  shapes.clear();
  for(int i=0;i<5;i++)
    shapes.push_back(shape_array[i]);
  quickSort(shapes.begin(), shapes.end(), areaAscendingCompare);
  std::vector<Shape*>::iterator it;
  it=shapes.begin();
  ASSERT_NEAR(6,(**it++).area(),0.001);
  ASSERT_NEAR(15,(**it++).area(),0.001);
  ASSERT_NEAR(47.1239,(**it++).area(),0.001);
  ASSERT_NEAR(150.796,(**it++).area(),0.001);
  ASSERT_NEAR(157.08,(**it).area(),0.001);
}

TEST(QuickSort,AreaAscendingByObject)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Triangle(triangleVector),new Ellipse(10,5),new Rectangle(5,3),new Ellipse(12,4),new Ellipse(5,3)};
  std::vector<Shape*> shapes;
  shapes.clear();
  for(int i=0;i<5;i++)
    shapes.push_back(shape_array[i]);
  quickSort(shapes.begin(), shapes.end(), AscendingCompare("area"));
  std::vector<Shape*>::iterator it;
  it=shapes.begin();
  ASSERT_NEAR(6,(**it++).area(),0.001);
  ASSERT_NEAR(15,(**it++).area(),0.001);
  ASSERT_NEAR(47.1239,(**it++).area(),0.001);
  ASSERT_NEAR(150.796,(**it++).area(),0.001);
  ASSERT_NEAR(157.08,(**it).area(),0.001);
}

TEST(QuickSort,AreaAscendingByLambda)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Triangle(triangleVector),new Ellipse(12,4),new Rectangle(5,3),new Ellipse(10,5),new Ellipse(5,3)};
  std::vector<Shape*> shapes;
  shapes.clear();
  for(int i=0;i<5;i++)
    shapes.push_back(shape_array[i]);
  quickSort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b){
     return a->area() < b->area();
   });
  std::vector<Shape*>::iterator it;
  it=shapes.begin();
  ASSERT_NEAR(6,(**it++).area(),0.001);
  ASSERT_NEAR(15,(**it++).area(),0.001);
  ASSERT_NEAR(47.1239,(**it++).area(),0.001);
  ASSERT_NEAR(150.796,(**it++).area(),0.001);
  ASSERT_NEAR(157.08,(**it).area(),0.001);
}

TEST(QuickSort,AreaDescendingByFunction)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Triangle(triangleVector),new Ellipse(10,5),new Rectangle(5,3),new Ellipse(12,4),new Ellipse(5,3)};
  std::vector<Shape*> shapes;
  shapes.clear();
  for(int i=0;i<5;i++)
    shapes.push_back(shape_array[i]);
  quickSort(shapes.begin(), shapes.end(), areaDescendingCompare);
  std::vector<Shape*>::iterator it;
  it=shapes.begin();
  ASSERT_NEAR(157.08,(**it++).area(),0.001);
  ASSERT_NEAR(150.796,(**it++).area(),0.001);
  ASSERT_NEAR(47.1239,(**it++).area(),0.001);
  ASSERT_NEAR(15,(**it++).area(),0.001);
  ASSERT_NEAR(6,(**it).area(),0.001);
}

TEST(QuickSort,AreaDescendingByObject)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Triangle(triangleVector),new Ellipse(10,5),new Rectangle(5,3),new Ellipse(12,4),new Ellipse(5,3)};
  std::vector<Shape*> shapes;
  shapes.clear();
  for(int i=0;i<5;i++)
    shapes.push_back(shape_array[i]);
  quickSort(shapes.begin(), shapes.end(), DescendingCompare("area"));
  std::vector<Shape*>::iterator it;
  it=shapes.begin();
  ASSERT_NEAR(157.08,(**it++).area(),0.001);
  ASSERT_NEAR(150.796,(**it++).area(),0.001);
  ASSERT_NEAR(47.1239,(**it++).area(),0.001);
  ASSERT_NEAR(15,(**it++).area(),0.001);
  ASSERT_NEAR(6,(**it).area(),0.001);
}

TEST(QuickSort,AreaDescendingByLambda)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Triangle(triangleVector),new Ellipse(12,4),new Rectangle(5,3),new Ellipse(10,5),new Ellipse(5,3)};
  std::vector<Shape*> shapes;
  shapes.clear();
  for(int i=0;i<5;i++)
    shapes.push_back(shape_array[i]);
  quickSort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b){
     return a->area() > b->area();
   });
  std::vector<Shape*>::iterator it;
  it=shapes.begin();
  ASSERT_NEAR(157.08,(**it++).area(),0.001);
  ASSERT_NEAR(150.796,(**it++).area(),0.001);
  ASSERT_NEAR(47.1239,(**it++).area(),0.001);
  ASSERT_NEAR(15,(**it++).area(),0.001);
  ASSERT_NEAR(6,(**it).area(),0.001);
}

//Perimeter
TEST(QuickSort,PerimeterAscendingByFunction)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Triangle(triangleVector),new Ellipse(10,5),new Rectangle(5,3),new Ellipse(12,4),new Ellipse(5,3)};
  std::vector<Shape*> shapes;
  shapes.clear();
  for(int i=0;i<5;i++)
    shapes.push_back(shape_array[i]);
  quickSort(shapes.begin(), shapes.end(), perimeterAscendingCompare);
  std::vector<Shape*>::iterator it;
  it=shapes.begin();
  ASSERT_NEAR(12,(**it++).perimeter(),0.001);
  ASSERT_NEAR(16,(**it++).perimeter(),0.001);
  ASSERT_NEAR(26.8496,(**it++).perimeter(),0.001);
  ASSERT_NEAR(51.4159,(**it++).perimeter(),0.001);
  ASSERT_NEAR(57.1327,(**it).perimeter(),0.001);
}

TEST(QuickSort,PerimeterAscendingByObject)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Triangle(triangleVector),new Ellipse(10,5),new Rectangle(5,3),new Ellipse(12,4),new Ellipse(5,3)};
  std::vector<Shape*> shapes;
  shapes.clear();
  for(int i=0;i<5;i++)
    shapes.push_back(shape_array[i]);
  quickSort(shapes.begin(), shapes.end(), AscendingCompare("perimeter"));
  std::vector<Shape*>::iterator it;
  it=shapes.begin();
  ASSERT_NEAR(12,(**it++).perimeter(),0.001);
  ASSERT_NEAR(16,(**it++).perimeter(),0.001);
  ASSERT_NEAR(26.8496,(**it++).perimeter(),0.001);
  ASSERT_NEAR(51.4159,(**it++).perimeter(),0.001);
  ASSERT_NEAR(57.1327,(**it).perimeter(),0.001);
}

TEST(QuickSort,PerimeterAscendingByLambda)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Triangle(triangleVector),new Ellipse(12,4),new Rectangle(5,3),new Ellipse(10,5),new Ellipse(5,3)};
  std::vector<Shape*> shapes;
  shapes.clear();
  for(int i=0;i<5;i++)
    shapes.push_back(shape_array[i]);
  quickSort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b){
     return a->perimeter() < b->perimeter();
   });
  std::vector<Shape*>::iterator it;
  it=shapes.begin();
  ASSERT_NEAR(12,(**it++).perimeter(),0.001);
  ASSERT_NEAR(16,(**it++).perimeter(),0.001);
  ASSERT_NEAR(26.8496,(**it++).perimeter(),0.001);
  ASSERT_NEAR(51.4159,(**it++).perimeter(),0.001);
  ASSERT_NEAR(57.1327,(**it).perimeter(),0.001);
}

TEST(QuickSort,PerimeterDescendingByFunction)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Triangle(triangleVector),new Ellipse(10,5),new Rectangle(5,3),new Ellipse(12,4),new Ellipse(5,3)};
  std::vector<Shape*> shapes;
  shapes.clear();
  for(int i=0;i<5;i++)
    shapes.push_back(shape_array[i]);
  quickSort(shapes.begin(), shapes.end(), perimeterDescendingCompare);
  std::vector<Shape*>::iterator it;
  it=shapes.begin();
  ASSERT_NEAR(57.1327,(**it++).perimeter(),0.001);
  ASSERT_NEAR(51.4159,(**it++).perimeter(),0.001);
  ASSERT_NEAR(26.8496,(**it++).perimeter(),0.001);
  ASSERT_NEAR(16,(**it++).perimeter(),0.001);
  ASSERT_NEAR(12,(**it).perimeter(),0.001);
}

TEST(QuickSort,PerimeterDescendingByObject)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Triangle(triangleVector),new Ellipse(10,5),new Rectangle(5,3),new Ellipse(12,4),new Ellipse(5,3)};
  std::vector<Shape*> shapes;
  shapes.clear();
  for(int i=0;i<5;i++)
    shapes.push_back(shape_array[i]);
  quickSort(shapes.begin(), shapes.end(), DescendingCompare("perimeter"));
  std::vector<Shape*>::iterator it;
  it=shapes.begin();
  ASSERT_NEAR(57.1327,(**it++).perimeter(),0.001);
  ASSERT_NEAR(51.4159,(**it++).perimeter(),0.001);
  ASSERT_NEAR(26.8496,(**it++).perimeter(),0.001);
  ASSERT_NEAR(16,(**it++).perimeter(),0.001);
  ASSERT_NEAR(12,(**it).perimeter(),0.001);
}

TEST(QuickSort,PerimeterDescendingByLambda)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Triangle(triangleVector),new Ellipse(12,4),new Rectangle(5,3),new Ellipse(10,5),new Ellipse(5,3)};
  std::vector<Shape*> shapes;
  shapes.clear();
  for(int i=0;i<5;i++)
    shapes.push_back(shape_array[i]);
  quickSort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b){
     return a->perimeter() > b->perimeter();
   });
  std::vector<Shape*>::iterator it;
  it=shapes.begin();
  ASSERT_NEAR(57.1327,(**it++).perimeter(),0.001);
  ASSERT_NEAR(51.4159,(**it++).perimeter(),0.001);
  ASSERT_NEAR(26.8496,(**it++).perimeter(),0.001);
  ASSERT_NEAR(16,(**it++).perimeter(),0.001);
  ASSERT_NEAR(12,(**it).perimeter(),0.001);
}

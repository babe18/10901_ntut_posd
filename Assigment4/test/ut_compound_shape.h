#include "../src/compound_shape.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"
#include "../src/two_dimensional_coordinate.h"
#include "../src/ellipse.h"
#include <gtest/gtest.h>
#include <stdexcept>
TEST(compound_shape, Area)
{
  Shape* shape_array[] = {new Ellipse("1",12,4) ,new Rectangle("2",5,4),new Rectangle("3",6,4)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
     shapeVec->push_back(shape_array[i]);
   Shape * compoundShape = new CompoundShape("7", shapeVec);
   ASSERT_NEAR(194.796, compoundShape->area(), 0.001);
}
TEST(compound_shape, Perimeter)
{
  Shape* shape_array[] = {new Ellipse("1",12,4) ,new Rectangle("2",5,4),new Rectangle("3",6,4)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
     shapeVec->push_back(shape_array[i]);
   Shape* compoundShape = new CompoundShape("7", shapeVec);
   ASSERT_NEAR(95.132, compoundShape->perimeter(), 0.001);
}
TEST(compound_shape, Info)
{

  Shape* shape_array[] = {new Ellipse("1",12,4) ,new Rectangle("2",5,4)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<2;i++)
     shapeVec->push_back(shape_array[i]);
   Shape* compoundShape = new CompoundShape("7", shapeVec);
   ASSERT_EQ("Compound Shape {Ellipse (12.000, 4.000), Rectangle (5.000, 4.000)}", compoundShape->info());
}
TEST(compound_shape, Color)
{

  Shape* shape_array[] = {new Ellipse("1",12,4) ,new Rectangle("2",5,4)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<2;i++)
     shapeVec->push_back(shape_array[i]);
   Shape* compoundShape = new CompoundShape("7", shapeVec);
   ASSERT_EQ("transparent", compoundShape->color());
}

TEST(compound_shape, AddShape)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Ellipse("1",12,4) ,new Rectangle("2",5,4),new Triangle("3",triangleVector)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
     shapeVec->push_back(shape_array[i]);
  Shape* compoundShape = new CompoundShape("7", shapeVec);
  Shape * Ellipse1 = new Ellipse("4",12,4);
  Shape * rectangle2 = new Rectangle("5",5,4);
  compoundShape->addShape(rectangle2);
  ASSERT_EQ("Compound Shape {Ellipse (12.000, 4.000), Rectangle (5.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (5.000, 4.000)}", compoundShape->info());
  compoundShape->addShape(Ellipse1);
  ASSERT_EQ("Compound Shape {Ellipse (12.000, 4.000), Rectangle (5.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (5.000, 4.000), Ellipse (12.000, 4.000)}", compoundShape->info());
}
TEST(compound_shape, DeleteShapeById)
{
  TwoDimensionalCoordinate t1(0, 0);
  TwoDimensionalCoordinate t2(3, 0);
  TwoDimensionalCoordinate t3(0, 4);
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(&t1);
  triangleVector.push_back(&t2);
  triangleVector.push_back(&t3);
  Shape* shape_array[] = {new Ellipse("1",12,4) ,new Rectangle("2",5,4),new Triangle("3",triangleVector)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
     shapeVec->push_back(shape_array[i]);
  Shape* compoundShape = new CompoundShape("7", shapeVec);
  compoundShape->deleteShapeById("3");
  ASSERT_EQ("Compound Shape {Ellipse (12.000, 4.000), Rectangle (5.000, 4.000)}", compoundShape->info());
  compoundShape->deleteShapeById("1");
  ASSERT_EQ("Compound Shape {Rectangle (5.000, 4.000)}", compoundShape->info());
}

TEST(compound_shape, ExceptionForDeleteShapeById)
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
            std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
            shapeVec->clear();
            for(int i=0;i<3;i++)
               shapeVec->push_back(shape_array[i]);
            Shape* compoundShape = new CompoundShape("7", shapeVec);
            compoundShape->deleteShapeById("4");
            FAIL();
        }catch(string e) {
            ASSERT_EQ("Expected delete shape but shape not found", e);
       }
}

TEST(compound_shape, ExceptionForGetShapeById)
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
          std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
          shapeVec->clear();
          for(int i=0;i<3;i++)
             shapeVec->push_back(shape_array[i]);
          Shape* compoundShape = new CompoundShape("7", shapeVec);
          compoundShape->getShapeById("4");
          FAIL();
      }catch(string e) {
          ASSERT_EQ("Expected get shape but shape not found", e);
     }
}

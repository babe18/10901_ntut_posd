#include "../src/visitor.h"
#include "../src/area_visitor.h"
#include "../src/info_visitor.h"
#include "../src/compound_shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/ellipse.h"
#include "../src/shape.h"
#include "../src/two_dimensional_coordinate.h"
#include <vector>
#include <list>

class VisitorTesting : public :: testing :: Test {
protected:
  void SetUp() override {
    triangleVector.push_back(new TwoDimensionalCoordinate(0,0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3,0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0,4));
    shapes.push_back(new Rectangle("0",3,4));
    shapes.push_back(new Triangle("1",triangleVector));
    shapes.push_back(new Ellipse("2",4,3.712));
    compoundShape = new CompoundShape("3",shapes);
    shapes1.push_back(new Rectangle("3",3,4));
    shapes1.push_back(new Ellipse("4",4,3.712));
    compoundShape1 = new CompoundShape("5", shapes1);
    shapes2.push_back(new Rectangle("5",3,4));
    shapes2.push_back(new Rectangle("6",4,6));
    compoundShape2 = new CompoundShape("5", shapes2);
    compoundShape1->addShape(compoundShape2);
    compoundShape->addShape(compoundShape1);
  }

  void TearDown() override {
    if(compoundShape != nullptr){
      delete compoundShape;
      compoundShape = nullptr;
    }
  }

  std::vector<TwoDimensionalCoordinate*> triangleVector;
  std::list<Shape*> shapes,shapes1,shapes2;
  CompoundShape * compoundShape;
  CompoundShape * compoundShape1;
  CompoundShape * compoundShape2;

};

TEST_F(VisitorTesting, ellipse_area){
  Ellipse ellipse("2",4,3.712);
  AreaVisitor * areavisitor = new AreaVisitor();
  ellipse.accept(areavisitor);
  ASSERT_NEAR(46.646,areavisitor->area(),0.001);
}
TEST_F(VisitorTesting, rectangle_area){
  Rectangle rectangle("0",3,4);
  AreaVisitor * areavisitor = new AreaVisitor();
  rectangle.accept(areavisitor);
  ASSERT_EQ(12,areavisitor->area());
}

TEST_F(VisitorTesting, triangle_area){
  Triangle triangle("1",triangleVector);
  AreaVisitor * areavisitor = new AreaVisitor();
  triangle.accept(areavisitor);
  ASSERT_EQ(6,areavisitor->area());
}

TEST_F(VisitorTesting, compound_shape_area){
  AreaVisitor * areavisitor = new AreaVisitor();
  compoundShape2->accept(areavisitor);
  ASSERT_NEAR(36,areavisitor->area(),0.001);
}
TEST_F(VisitorTesting, compound_shape_area_level_3_tree_structure){
  AreaVisitor * areavisitor = new AreaVisitor();
  compoundShape->accept(areavisitor);
  ASSERT_NEAR(159.292,areavisitor->area(),0.001);
  //ASSERT_NEAR(123.292,areavisitor->area(),0.001);
}
TEST_F(VisitorTesting, ellipse_info){

  Ellipse ellipse("2",4,3.712);
  InfoVisitor * infovisitor = new InfoVisitor();
  ellipse.accept(infovisitor);
  ASSERT_EQ("Ellipse (4.000, 3.712)",infovisitor->info());
}
TEST_F(VisitorTesting, rectangle_info){
  Rectangle rectangle("2",3,4);
  InfoVisitor * infovisitor = new InfoVisitor();
  rectangle.accept(infovisitor);
  ASSERT_EQ("Rectangle (3.000, 4.000)",infovisitor->info());
}
TEST_F(VisitorTesting, triangle_info){
  Triangle triangle("1",triangleVector);
  InfoVisitor * infovisitor = new InfoVisitor();
  triangle.accept(infovisitor);
  ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])",infovisitor->info());
}
TEST_F(VisitorTesting, compound_shape_info){
  InfoVisitor * infovisitor = new InfoVisitor();
  compoundShape2->accept(infovisitor);
  std::string answer = "Compound Shape {Rectangle (3.000, 4.000), Rectangle (4.000, 6.000)}";
  ASSERT_EQ(answer,infovisitor->info());
}
TEST_F(VisitorTesting, compound_shape_info_level_3_tree_structure){
  InfoVisitor * infovisitor = new InfoVisitor();
  compoundShape->accept(infovisitor);
  std::string answer = "Compound Shape {Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Ellipse (4.000, 3.712), Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.712), Compound Shape {Rectangle (3.000, 4.000), Rectangle (4.000, 6.000)}}}";
                       //"Compound Shape {Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Ellipse (4.000, 3.712), Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.712), Compound Shape {Rectangle (3.000, 4.000), Rectangle (4.000, 6.000)}}"
  ;ASSERT_EQ(answer,infovisitor->info());
}

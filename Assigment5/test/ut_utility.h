#include "../src/shape.h"
#include "../src/compound_shape.h"
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"
#include "../src/utility.h"
#include "../src/iterator.h"
#include "../src/shape_iterator.h"
#include <deque>
#include <vector>

class UtilityTesting : public :: testing :: Test{
protected:
  void SetUp() override{
    shapes = std::list<Shape*>();
    triangleVector.push_back(new TwoDimensionalCoordinate(0,0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3,0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0,4));

    shapes.push_back(new Rectangle("0",3,4,"red"));
    shapes.push_back(new Triangle("1",triangleVector,"red"));
    shapes.push_back(new Rectangle("2",2,2,"yellow"));
    compoundShape = new CompoundShape("4",shapes);
  }

  void TearDown() override{
    if(compoundShape != nullptr){
      delete compoundShape;
      compoundShape = nullptr;
    }
  }

  std::list<Shape*> shapes;
  CompoundShape * compoundShape;
  std::vector<TwoDimensionalCoordinate*> triangleVector;
};

TEST_F(UtilityTesting, getShapeById){
  ASSERT_EQ("Rectangle",getShapeById(compoundShape,"2")->type());

  try{
    getShapeById(compoundShape,"5");
    FAIL();
  }catch(std::string e){
    ASSERT_EQ("Expected get shape but shape not found",e);
  }
  try{
    getShapeById(new Rectangle("2",4,5,"blue"),"3");
    FAIL();
  }catch(std::string e){
    ASSERT_EQ("Only compound shape can get shape!",e);
  }
}

TEST_F(UtilityTesting, AreaFilter){
  std::deque<Shape*> fs = filterShape(compoundShape, AreaFilter(15, 6));
  std::deque<Shape*>::iterator it = fs.begin();
  ASSERT_EQ(12,(*it)->area());
  it++;
  ASSERT_EQ(6,(*it)->area());

}

TEST_F(UtilityTesting, PerimeterFilter){
  std::deque<Shape*> fs = filterShape(compoundShape, PerimeterFilter(10, 5));
  std::deque<Shape*>::iterator it = fs.begin();
  ASSERT_EQ(8,(*it)->perimeter());
}

TEST_F(UtilityTesting, ColorFilter){
  std::deque<Shape*> fs = filterShape(compoundShape, ColorFilter("yellow"));
  std::deque<Shape*>::iterator it = fs.begin();
  ASSERT_EQ("yellow",(*it)->color());
}

TEST_F(UtilityTesting, TypeFilter){
  std::deque<Shape*> fs = filterShape(compoundShape, TypeFilter("Rectangle"));
  std::deque<Shape*>::iterator it = fs.begin();
  ASSERT_EQ("Rectangle",(*it)->type());
  // return shapes that type match "Compound Shape", but don't include compoundShape_0 itself.
}

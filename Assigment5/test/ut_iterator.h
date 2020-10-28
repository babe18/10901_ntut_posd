#include "../src/iterator.h"
#include "../src/shape_iterator.h"
#include "../src/null_iterator.h"
#include "../src/shape.h"
#include "../src/compound_shape.h"
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"
#include <vector>

class IteratorTesting : public :: testing :: Test{

protected:
  void SetUp() override{
    shapes = std::list<Shape*>();
    triangleVector.push_back(new TwoDimensionalCoordinate(0,0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3,0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0,4));

    shapes.push_back(new Rectangle("0",3,4,"red"));
    shapes.push_back(new Triangle("1", triangleVector, "blue"));
    shapes.push_back(new Rectangle("2",2,2,"yellow"));
    compoundShape = new CompoundShape("4",shapes);

  }

  void TearDown() override{
    if(compoundShape != nullptr){
      delete compoundShape;
      compoundShape = nullptr;
    }

  }

  CompoundShape * compoundShape;
  std::list<Shape*> shapes;
  std::vector<TwoDimensionalCoordinate*> triangleVector;
};

TEST_F(IteratorTesting, first){
  Iterator * si = compoundShape->createIterator();
  si->next();
  si->next();
  si->first();
  ASSERT_EQ("Rectangle",si->currentItem()->type());
}

TEST_F(IteratorTesting, next){
  Iterator * si = compoundShape->createIterator();

  ASSERT_EQ("Rectangle",si->currentItem()->type());
  si->next();
  ASSERT_EQ("Triangle",si->currentItem()->type());
  si->next();
  ASSERT_EQ("Rectangle",si->currentItem()->type());

  try{

    si->next();
    si->next();
    FAIL();

  }catch(std::string e){

    ASSERT_EQ("Moving past the end!",e);

  }
}

TEST_F(IteratorTesting, isDone){
  Iterator * si = compoundShape->createIterator();

  ASSERT_EQ(false,si->isDone());
  si->next();
  si->next();
  si->next();
  ASSERT_TRUE(si->isDone());
}

TEST_F(IteratorTesting, currentItem){
  Iterator * si = compoundShape->createIterator();

  si->next();
  si->next();
  ASSERT_EQ("Rectangle",si->currentItem()->type());
}

TEST_F(IteratorTesting, NullsieratorTest){

  Rectangle rectangle("5",3,4,"blue");
  Iterator * reit = rectangle.createIterator();

  try{

    reit->first();
    FAIL();

  }catch(std::string e){

    ASSERT_EQ("No child member!",e);

  }
  try{

    reit->next();
    FAIL();

  }catch(std::string e){

    ASSERT_EQ("No child member!",e);

  }

    ASSERT_TRUE(reit->isDone());

  try{

    reit->currentItem();
    FAIL();

  }catch(std::string e){

    ASSERT_EQ("No child member!",e);

  }
}

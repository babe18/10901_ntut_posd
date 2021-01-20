#include "../src/ellipse.h"

TEST (Ellipse, ConstructorNoException)
{
  Ellipse e("1",4,3.712);
  ASSERT_NEAR(46.646, e.area(), 0.001);
  ASSERT_NEAR(24.475, e.perimeter(), 0.001);
  ASSERT_EQ("Ellipse (4.000, 3.712)", e.info());
}
TEST (Ellipse, ExceptionForSemiMajorAxesIsZero)
{
    try {
    Ellipse("1",0,3.712);
    }catch(std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}
TEST (Ellipse, ExceptionForSemiMinorAxesIsZero)
{
    try {
    Ellipse("1",4,0);
    }catch(std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}
TEST (Ellipse, ExceptionForSemiMajorAxesLessThanZero)
{
    try {
    Ellipse("1",-4,1);
    }catch(std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}
TEST (Ellipse, AreaInt)
{
  Ellipse e("1",4,3);
  ASSERT_NEAR(37.699, e.area(), 0.001);
}
TEST (Ellipse, AreaDouble)
{
  Ellipse e("1",4.5,3.5);
  ASSERT_NEAR(49.480, e.area(), 0.001);
}
TEST (Ellipse, PerimeterInt)
{
  Ellipse e("1",4,3);
  ASSERT_NEAR(22.849, e.perimeter(), 0.001);
}
TEST (Ellipse, PerimeterDouble)
{
  Ellipse e("1",4.5,3.5);
  ASSERT_NEAR(25.991, e.perimeter(), 0.001);;
}
TEST (Ellipse, Info)
{
  Ellipse e("1",4,3.712);
  ASSERT_EQ("Ellipse (4.000, 3.712)", e.info());
}
TEST (Ellipse, RedColor)
{
  Ellipse e("1",4,3.712,"red");
  ASSERT_EQ("red", e.color());
}
TEST (Ellipse, DefaultColor)
{
  Ellipse e("1",4,3.712);
  ASSERT_EQ("white", e.color());
}
TEST (Ellipse, ExceptionForAddShape)
{
  try {
    Ellipse e("1",4,3.712);
    Shape * Ellipse1 = new Ellipse("4",12,4);
    e.addShape(Ellipse1);
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can add shape!", e);
  }
}
TEST (Ellipse, ExceptionForDeleteShape)
{
  try {
    Ellipse e("1",4,3.712);
    e.deleteShapeById("1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can delete shape!", e);
  }
}
TEST (Ellipse, ExceptionForGetShapeById)
{
  try {
    Ellipse e("1",4,3.712);
    e.getShapeById("1");
  }catch(std::string e) {
      ASSERT_EQ("Only compound shape can get shape!", e);
  }
}

#include "../src/ellipse.h"

TEST (Ellipse, TestEllipse)
{
  Ellipse e(4,3.712);
  ASSERT_NEAR(46.646, e.area(), 0.001);
  ASSERT_NEAR(24.475, e.perimeter(), 0.001);
  ASSERT_EQ("Ellipse (4.000, 3.712)", e.info());
}
TEST (Ellipse, TestEllipsefail)
{

 try {
    Ellipse(0, 1);
  }catch(std::string e) {
      ASSERT_EQ("This is not an ellipse!", e);
  }
      ASSERT_NO_THROW(Ellipse(1, 1));
}

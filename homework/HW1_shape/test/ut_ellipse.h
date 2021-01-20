#include "../src/ellipse.h"

TEST (Ellipse, TestEllipse)
{
  Ellipse e(3.712,4);
  ASSERT_NEAR(46.646, e.area(), 0.001);
  ASSERT_NEAR(23.980, e.perimeter(), 0.001);
  ASSERT_EQ("Ellipse (3.712, 4.000)", e.info());
}

TEST (Ellipse, TestEllipsefail)
{

 try {
    Ellipse(0, 1);
  }catch(std::string e) {
      ASSERT_EQ("This is not a ellipse!", e);
  }
      ASSERT_NO_THROW(Ellipse(1, 1));
}

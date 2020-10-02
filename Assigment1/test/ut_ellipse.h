#include "../src/ellipse.h"

TEST(ELLIPSE, CreateEllipse){
  Ellipse ell(9.9876, 6.6789);
  ASSERT_EQ(209.563, ell.area());
  ASSERT_EQ(55.199, ell.perimeter());
  ASSERT_EQ("Ellipse (9.987, 6.678)", ell.info());
}

TEST(ELLIPSE, CreateEllipseFail){
  try{
    Ellipse ell(3,0);
    FAIL();
  }
  catch(std::string msg){
    ASSERT_EQ("This is not a ellipse!", msg);
  }

  try{
    Ellipse ell(3,4);
    FAIL();
  }
  catch(std::string msg){
    ASSERT_EQ("This is not a ellipse!", msg);
  }
}

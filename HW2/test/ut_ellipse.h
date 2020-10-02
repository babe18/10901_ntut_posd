#include "../src/ellipse.h"

TEST(ELLIPSE, CreateEllipse){
  Ellipse el(4.5678,3.7121);
  ASSERT_EQ(53.269, el.area());
  ASSERT_EQ(26.746, el.perimeter());
  ASSERT_EQ("Ellipse (4.567, 3.712)", el.info());
}

TEST(ELLIPSE, CreateEllipseFail){
  try{
    Ellipse el(3,0);
    FAIL();
  }
  catch(std::string msg){
    ASSERT_EQ("This is not an ellipse!", msg);
  }

  try{
    Ellipse el(3,4);
    FAIL();
  }
  catch(std::string msg){
    ASSERT_EQ("This is not an ellipse!", msg);
  }
}

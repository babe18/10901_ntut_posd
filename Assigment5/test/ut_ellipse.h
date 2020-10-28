#include "../src/ellipse.h"

TEST(Shapes, CreateEllipse){
  Ellipse ellipse("2",4.000,3.712);
  ASSERT_NEAR(46.646, ellipse.area(),0.001);
  ASSERT_NEAR(24.475, ellipse.perimeter(),0.001);
  ASSERT_EQ("Ellipse (4.000, 3.712)",ellipse.info());
  try {
        Ellipse ellipse("2",0, 1.000);
      FAIL();
  }catch(std::string e) {
      ASSERT_EQ("This is not an ellipse!", e);
  }
  try {
        Ellipse ellipse("2",-1.234, 0);
      FAIL();
  }catch(std::string e) {
      ASSERT_EQ("This is not an ellipse!", e);
  }
  try {
        Ellipse ellipse("2",3.712,4.000);
      FAIL();
  }catch(std::string e) {
      ASSERT_EQ("This is not an ellipse!", e);
  }

  ASSERT_NO_THROW(Ellipse ellipse("2",4.000,3.712));


}

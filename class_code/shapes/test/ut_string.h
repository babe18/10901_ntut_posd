#include <vector>

#include "../src/shape.h"
#include "../src/mixed_shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"


class StringTest : public ::testing::Test {
protected:
  void SetUp() override {
     r34 = new Rectangle(3, 4);
     r22 = new Rectangle(2, 2);
     t345 = new Triangle(3, 4, 5);
     mbox = new MixedShape();
     mbox2 = new MixedShape();
     mbox2->add(r22);
     mbox2->add(t345);
     mbox->add(r34);
     mbox->add(mbox2);
  }

  void TearDown() override {
      delete mbox;
      delete mbox2;
      delete r34;
      delete r22;
      delete t345;
  }

  Shape * r34;
  Shape * r22;
  Shape * t345;
  Shape * mbox;
  Shape * mbox2;
};


TEST_F(StringTest, RectangleToString){
    ASSERT_EQ("rect 3 4\n",r34->toString(""));
}

TEST_F(StringTest, Mbox2ToString){
  ASSERT_EQ("mixed {\n  rect 2 2\n  tri 3 4 5\n}\n", mbox2->toString(""));
}

TEST_F(StringTest, MboxToString) {
  std::cout << mbox->toString() << std::endl;
  ASSERT_EQ("mixed {\n  rect 3 4\n  mixed {\n    rect 2 2\n    tri 3 4 5\n  }\n}\n", mbox->toString(""));
}

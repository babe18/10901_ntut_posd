#include <vector>

#include "../src/shape.h"
#include "../src/mixed_shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape_iterator.h"
#include "../src/iterator.h"
#include "../src/find_first_visitor.h"
#include "../src/shape_visitor.h"
#include "../src/tostring_visitor.h"


class VisitorTest : public ::testing::Test {
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

TEST_F(VisitorTest, FindFirstVisitor){
  ShapeVisitor *sv = new FindFirstVisitor([](Shape* a){return a->area() == 4;});
  r22->accept(*sv);
  Shape * s = (dynamic_cast<FindFirstVisitor*>(sv))->getResult();
  ASSERT_EQ(r22, s);
}

TEST_F(VisitorTest, FindFirstByAreaOnNestedMixedShape) {
  ShapeVisitor *sv = new FindFirstVisitor([](Shape *a) {return a->area() == 4;});
  mbox->accept(*sv);
  Shape *s = (dynamic_cast<FindFirstVisitor*>(sv))->getResult();
  ASSERT_EQ(r22, s);
}

TEST_F(VisitorTest, ToStringVisitor) {
  ToStringVisitor * tsv = new ToStringVisitor();
  r22->accept(*tsv);
  std::string result = tsv->getResult();
  ASSERT_EQ("rect 2 2\n", result);
}

TEST_F(VisitorTest, MboxToStringVisitor) {
  ToStringVisitor * tsv = new ToStringVisitor();
  mbox->accept(*tsv);
  std::string result = tsv->getResult();
  ASSERT_EQ("mixed {\n  rect 3 4\n  mixed {\n    rect 2 2\n    tri 3 4 5\n  }\n}\n", result);
}
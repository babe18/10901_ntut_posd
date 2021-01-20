#include "../src/shape.h"
#include "../src/mixed_shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

class MixedShapeTest : public ::testing::Test {
protected:
  void SetUp() override {
     r34 = new Rectangle(3, 4);
     r22 = new Rectangle(2, 2);
     t345 = new Triangle(3, 4, 5);
  }

  void TearDown() override {
      delete r34;
      delete r22;
      delete t345;
  }

  Shape * r34;
  Shape * r22;
  Shape * t345;
};

TEST_F(MixedShapeTest, CreateMixedShape){
  MixedShape mbox;
  ASSERT_EQ(0, mbox.getNumberOfComponents());
}

TEST_F(MixedShapeTest, CreateMixedShapeAsAShape){
  Shape * mbox = new MixedShape();
  ASSERT_EQ(0, ((MixedShape *)mbox)->getNumberOfComponents());//debt
}

TEST_F(MixedShapeTest, AddShapeToMixedShape){
  MixedShape mbox;
  mbox.add(r34);
  ASSERT_EQ(1, mbox.getNumberOfComponents());
}

TEST_F(MixedShapeTest, MixedShapeArea){
  Shape * mbox = new MixedShape();
  mbox->add(r34);
  ASSERT_EQ(12, mbox->area());
}

TEST_F(MixedShapeTest, NestMixedShape){
  Shape * mbox = new MixedShape();
  Shape * mbox2 = new MixedShape();
  mbox2->add(r22);
  mbox2->add(t345);
  mbox->add(r34);
  mbox->add(mbox2);
  ASSERT_EQ(2, ((MixedShape *)mbox)->getNumberOfComponents());
  ASSERT_EQ(2, ((MixedShape *)mbox2)->getNumberOfComponents());
  ASSERT_EQ(22, mbox->area());
  ASSERT_EQ(10, mbox2->area());
}

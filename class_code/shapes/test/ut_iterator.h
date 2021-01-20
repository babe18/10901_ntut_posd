#include <vector>

#include "../src/shape.h"
#include "../src/mixed_shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape_iterator.h"
#include "../src/iterator.h"

class IteratorTest : public ::testing::Test {
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

TEST_F(IteratorTest, VectorIterator) {
  std::vector<int> v = {0, 1, 2};
  std::vector<int>::iterator it = v.begin();
  ASSERT_EQ(0, *it++);
  ASSERT_EQ(1, *it++);
  ASSERT_EQ(2, *it++);
  ASSERT_EQ(v.end(), it);
}

TEST_F(IteratorTest, FindFirstByArea) {
  ASSERT_EQ(r22, findFirst(((MixedShape *)mbox2)->createIterator(), [](Shape * a){
    return a->area() == 4;
  }));
}

TEST_F(IteratorTest, MixedShapeIteratorNew) {

  Iterator * it = mbox->createIterator();

  ASSERT_EQ(12, it->currentItem()->area());
  it->next();
  ASSERT_EQ(10, it->currentItem()->area());
  it->next();
  ASSERT_TRUE(it->isDone());
}

TEST_F(IteratorTest, NullIterator) {
  Iterator * it = r34->createIterator();
  ASSERT_TRUE(it->isDone());
}

TEST_F(IteratorTest, FindFirstByAreaOnNestMixedShape) {
  ASSERT_EQ(r22, findFirst(mbox->createIterator(), [](Shape * a){
    return a->area() == 4;
  }));
}

// TEST_F(IteratorTest, FindFirstAsMemberFunction) {
//   ASSERT_EQ(r22, r22->findFirst([](Shape * a){
//     return a->area() == 4;
//   }));
// }



// TEST_F(IteratorTest, FindFirstByAreaFindingMbox2) {
//   ASSERT_EQ(mbox2, findFirst(mbox2->createIterator(), [](Shape * a){
//     return a->area() == 10;
//   }));
// }

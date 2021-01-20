#include "../src/filter.h"
TEST(FilterTest, AreaFilter)
{
    AreaFilter * af1 = new AreaFilter([](Shape* shape){ return shape->area()<20; });
    AreaFilter * af2 = new AreaFilter([](Shape* shape){ return shape->area()>2; });

    af1->setNext(af2);

    Rectangle * r22 = new Rectangle(2, 2);
    Shape * result = af1->push(r22);

    ASSERT_NEAR(4, result->area(), 0.001);
}

TEST(FilterTest, AreaFilter2)
{
    AreaFilter * af1 = new AreaFilter([](Shape* shape){ return shape->area()<20; });
    AreaFilter * af2 = new AreaFilter([](Shape* shape){ return shape->area()>2; });

    af1->setNext(af2);

    Rectangle * r56 = new Rectangle(5, 6);
    Shape * result = af1->push(r56);

     ASSERT_EQ(nullptr, result);
}
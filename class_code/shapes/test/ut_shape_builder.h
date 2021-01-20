#include "../src/shape_builder.h"
#include <cmath>

TEST(ShapeBuilderTest, BuildRect){
    ShapeBuilder *sb = ShapeBuilder::instance();
    sb->buildRect(5, 5);
    std::vector<Shape *> result = sb->getResult();
    ASSERT_EQ(25,result[0]->area());
}

TEST(ShapeBuilderTest, BuildMixed){
    ShapeBuilder * sb = ShapeBuilder::instance();
    sb->buildMixedBegin();
    sb->buildRect(2, 2);
    sb->buildTri(3, 4, 5);
    sb->buildMixedEnd();
    std::vector<Shape *> result = sb->getResult();
    ASSERT_EQ(1,result.size());
    ASSERT_EQ(10,result[0]->area());
}
TEST(ShapeBuilderTest, BuildForest){
    ShapeBuilder * sb = ShapeBuilder::instance();
    sb->buildRect(5, 5);
    sb->buildMixedBegin();
    sb->buildRect(3, 4);
    sb->buildMixedBegin();
    sb->buildRect(2, 2);
    sb->buildTri(3, 4, 5);
    sb->buildMixedEnd();
    sb->buildMixedEnd();
    sb->buildTri(1, 1, sqrt(2));
    std::vector<Shape *> result = sb->getResult();
    ASSERT_EQ(3,result.size());
    ASSERT_EQ(25,result[0]->area());
    ASSERT_EQ(22,result[1]->area());
    ASSERT_NEAR(0.5,result[2]->area(), 0.001);
}
#include "../src/shape_builder.h"
#include <cmath>
#include <sstream>      

TEST(ShapeBuilderTest, build_rectangle){
    ShapeBuilder sb ;
    sb.buildRectangle(5, 5);
    std::deque<Shape *> results = sb.getResult();
    ASSERT_EQ(25,results[0]->area());
    ASSERT_EQ("Rectangle (5.000, 5.000)", results[0]->info());
}
TEST(ShapeBuilderTest, build_triangle) {
    ShapeBuilder sb;
    sb.buildTriangle(0,0,0,-3,-4,0);
    std::deque<Shape*> results = sb.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_EQ(6,results[0]->area());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[0]->info());
}
TEST(ShapeBuilderTest, build_ellipse) {
    ShapeBuilder sb;
    sb.buildEllipse(4,3);
    std::deque<Shape*> results = sb.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_NEAR(37.699, results[0]->area(), 0.001);
    ASSERT_EQ("Ellipse (4.000, 3.000)", results[0]->info());
}

TEST(ShapeBuilderTest, BuildCompound){
    ShapeBuilder sb ;
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(2, 2);
    sb.buildTriangle(0,0,3,0,0,4);
    sb.buildCompoundShapeEnd();
    std::deque<Shape *> result = sb.getResult();
    ASSERT_EQ(1,result.size());
    ASSERT_EQ(10,result[0]->area());
}

TEST(ShapeBuilderTest, build_multi_simple_shapes){
    ShapeBuilder sb ;
    sb.buildRectangle(2, 2);
    sb.buildTriangle(0,0,3,0,0,4);
    sb.buildEllipse(4,3);
    std::deque<Shape *> result = sb.getResult();
    ASSERT_EQ(3,result.size());
    ASSERT_EQ(4,result[0]->area());
    ASSERT_EQ(6,result[1]->area());
    ASSERT_NEAR(37.699, result[2]->area(), 0.001);
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_a_empty_compoundShape){
    ShapeBuilder sb ;
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();
    std::deque<Shape *> result = sb.getResult();
    ASSERT_EQ("Compound Shape {Compound Shape {}}",result[0]->info());
    ASSERT_EQ(0,result[0]->area());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_multi_simple_shapes_and_a_empty_compoundShape){
    ShapeBuilder sb ;
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(2, 2);
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();
    std::deque<Shape *> result = sb.getResult();
    ASSERT_EQ("Compound Shape {Rectangle (2.000, 2.000), Compound Shape {}}",result[0]->info());
    ASSERT_EQ(4,result[0]->area());
}


TEST(ShapeBuilderTest, Build_empty_Compound){
    ShapeBuilder sb ;
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    std::deque<Shape *> result = sb.getResult();
    ASSERT_EQ(1,result.size());
    ASSERT_EQ("Compound Shape {}",result[0]->info());
}

TEST(ShapeBuilderTest, build_level_3_compoundShape_and_multi_shapes_at_same_time){
    ShapeBuilder sb ;
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();
    std::deque<Shape *> result = sb.getResult();
    ASSERT_EQ(1,result.size());
    ASSERT_EQ("Compound Shape {Compound Shape {Compound Shape {}}}",result[0]->info());
}
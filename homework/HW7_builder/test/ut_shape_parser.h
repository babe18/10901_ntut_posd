#include "../src/shape_parser.h"
TEST(ShapeParserTest, parser_rectangle) {
    ShapeParser sp("Rectangle (3.000, 4.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Rectangle (3.000, 4.000)", results[0]->info());
    ASSERT_EQ(12, results[0]->area());
}

TEST(ShapeParserTest, parser_ellipse) {
    ShapeParser sp("Ellipse (4.000, 3.712)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Ellipse (4.000, 3.712)", results[0]->info());
    ASSERT_NEAR(46.646,results[0]->area(),0.001);
}

TEST(ShapeParserTest, parser_triangle) {
    ShapeParser sp("Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[0]->info());
    ASSERT_EQ(6,results[0]->area());
}

TEST(ShapeParserTest, parser_compoundshape) {
    ShapeParser sp("CompoundShape {Rectangle (2.000, 2.000), Rectangle (3.000, 4.000), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ(22,results[0]->area());
}

TEST(ShapeParserTest, parser_multi_simple_shapes_with_one_shape_contain_invalid_argument_that_should_be_ignored) {

    ShapeParser sp("Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Ellipse (4.200, 3.700, 12.502), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(3, results.size());

    EXPECT_EQ("Rectangle (3.000, 4.000)", results[0]->info());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results[1]->info());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[2]->info());
}

TEST(ShapeParserTest, parser_compoundShape_that_contains_rectangle) {
    ShapeParser sp("CompoundShape {Rectangle (4.000, 3.000)}");
    sp.parser();
    std::deque<Shape*> results = sp.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Rectangle (4.000, 3.000)}", results[0]->info());
    ASSERT_EQ(12, results[0]->area());
}
TEST(ShapeParserTest, parser_compoundShape_that_contains_ellipse) {
    ShapeParser sp("CompoundShape {Ellipse (4.000, 3.000)}");
    sp.parser();
    std::deque<Shape*> results = sp.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000)}", results[0]->info());
    ASSERT_NEAR(37.699, results[0]->area(), 0.001);
}
TEST(ShapeParserTest, parser_compoundShape_that_contains_trinalge) {
    ShapeParser sp("CompoundShape {Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)}");
    sp.parser();
    std::deque<Shape*> results = sp.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}", results[0]->info());
    ASSERT_EQ(6, results[0]->area());
}

TEST(ShapeParserTest, parser_compoundShape_that_contains_multi_simple_shapes) {
    ShapeParser sp("CompoundShape {Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}");
    sp.parser();
    std::deque<Shape*> results = sp.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}", results[0]->info());
    ASSERT_NEAR(66.8203, results[0]->area(), 0.001);
}


TEST(ShapeParserTest, parser_empty_compoundShape) {
    ShapeParser sp("CompoundShape {}");
    sp.parser();
    std::deque<Shape*> results = sp.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {}", results[0]->info());
}

TEST(ShapeParserTest, parser_compoundShape_that_contains_a_empty_compoundShape) {
    ShapeParser sp("CompoundShape {CompoundShape {}}");
    sp.parser();
    std::deque<Shape*> results = sp.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Compound Shape {}}", results[0]->info());
}

TEST(ShapeParserTest, parser_compoundShape_that_contains_multi_simple_shapes_and_a_empty_compoundShape) {
    ShapeParser sp("CompoundShape {CompoundShape {},Rectangle (3.000, 4.000)}");
    sp.parser();
    std::deque<Shape*> results = sp.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Compound Shape {}, Rectangle (3.000, 4.000)}", results[0]->info());
}
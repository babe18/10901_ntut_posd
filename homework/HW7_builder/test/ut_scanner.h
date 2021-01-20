#include "../src/scanner.h"
TEST(Scanner, ellipse) {
    Scanner scanner("Ellipse (4.000, 3.000)");
    ASSERT_EQ("Ellipse", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
    try {
        scanner.nextToken();
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("next char doesn't exist.", e);
    }
}

TEST(Scanner, rectangle) {
    Scanner scanner("Rectangle (4.000, 3.000)");
    ASSERT_EQ("Rectangle", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
}

TEST(Scanner, triangle) {
    Scanner scanner("Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    ASSERT_EQ("Triangle", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("0.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("0.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("0.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("-3.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("-4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("0.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
}

TEST(Scanner, next_token_exception) {
    Scanner scanner("Ellipse (4.000, 3.000)");
    ASSERT_EQ("Ellipse", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
    try {
        scanner.nextToken();
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("next char doesn't exist.", e);
    }
}

TEST(Scanner, compound_shape_contains_ellipse) {
    Scanner scanner("CompoundShape {Ellipse (4.000, 3.000)}");
    ASSERT_EQ("CompoundShape", scanner.nextToken());
    ASSERT_EQ("{", scanner.nextToken());
    ASSERT_EQ("Ellipse", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
    ASSERT_EQ("}", scanner.nextToken());
}
TEST(Scanner, compound_shape_contains_rectangle) {
    Scanner scanner("CompoundShape {Rectangle (4.000, 3.000)}");
    ASSERT_EQ("CompoundShape", scanner.nextToken());
    ASSERT_EQ("{", scanner.nextToken());
    ASSERT_EQ("Rectangle", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
    ASSERT_EQ("}", scanner.nextToken());
}
TEST(Scanner, compound_shape_contains_triangle) {
    Scanner scanner("CompoundShape {Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)}");
    ASSERT_EQ("CompoundShape", scanner.nextToken());
    ASSERT_EQ("{", scanner.nextToken());
    ASSERT_EQ("Triangle", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("0.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("0.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("0.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("-3.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("-4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("0.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
    ASSERT_EQ("}", scanner.nextToken());
}

TEST(Scanner, compound_shape_contains_compound_shape) {
    Scanner scanner("CompoundShape {CompoundShape {Ellipse (5.000, 3.000),Rectangle (4.000, 3.000)},Rectangle (5.000, 3.000)}");
    ASSERT_EQ("CompoundShape", scanner.nextToken());
    ASSERT_EQ("{", scanner.nextToken());
    ASSERT_EQ("CompoundShape", scanner.nextToken());
    ASSERT_EQ("{", scanner.nextToken());
    ASSERT_EQ("Ellipse", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("5.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("Rectangle", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
    ASSERT_EQ("}", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("Rectangle", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("5.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
    ASSERT_EQ("}", scanner.nextToken());
}


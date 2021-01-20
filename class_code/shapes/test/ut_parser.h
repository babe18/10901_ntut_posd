#include "../src/parser.h"

TEST(ParserTest, ParseShape){
    std::string input = "mixed {\n  rect 3 4\n  mixed {\n    rect 2 2\n    tri 3 4 5\n  }\n}\n";
    Parser * ps = new Parser(input);
    ps->parse();
    std::vector<Shape*> result = ps->getResult();

    ASSERT_EQ(1, result.size());
}

TEST(ParserTest, ParseRectangle){
    std::string input = "rect 3 4\n";
    Parser * ps = new Parser(input);
    ps->parse();
    std::vector<Shape*> result = ps->getResult();

    ASSERT_EQ(1, result.size());
    ASSERT_NEAR(12, result[0]->area(), 0.001);
}

TEST(ParserTest, ParseTriangle){
    std::string input = "tri 3 4 5\n";
    Parser * ps = new Parser(input);
    ps->parse();
    std::vector<Shape*> result = ps->getResult();

    ASSERT_EQ(1, result.size());
    ASSERT_NEAR(6, result[0]->area(), 0.001);
}
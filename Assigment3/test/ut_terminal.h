#include <gtest/gtest.h>
#include "../src/terminal.h"

class TerminnalTesting : public ::testing::Test {
protected:
void SetUp() override {
    terminal = new Terminal("Rectangle (3.7, 4.2) Ellipse (5, 4) Triangle ([0,0], [3,0], [0,4]) area inc");
}

void TearDown() override {
    delete terminal;
}

Terminal * terminal;
};

TEST_F(TerminnalTesting, createInalidTerminal) {
    try
    {
        Terminal terminal("");
        FAIL();
    }
    catch(const std::string e)
    {
        ASSERT_EQ("invalid input", e);
    }

    try
    {
        Terminal terminal("Rectangle (3.7, 4.2) Ellipse (3, 4) area");
        FAIL();
    }
    catch(const std::string e)
    {
        ASSERT_EQ("invalid input", e);
    }
    
    try
    {
        Terminal terminal("Rectangle (3.7, 4.2) Ellipse (3, 4) inc");
        FAIL();
    }
    catch(const std::string e)
    {
        ASSERT_EQ("invalid input", e);
    }
    
    try
    {
        Terminal terminal("area inc");
        FAIL();
    }
    catch(const std::string e)
    {
        ASSERT_EQ("invalid input", e);
    }

    try {
      Terminal("Rectangle (0, 0) Ellipse (-1, -1) area inc");
      FAIL();
    }
    catch(std::string e) {
      ASSERT_EQ("invalid input", e);
    }
}

TEST_F(TerminnalTesting, createValidTerminal) {
    ASSERT_NO_THROW(Terminal("Rectangle (3.7, 4.2) Ellipse (3, 4) Triangle ([0,-3], [-3,0], [0,-4]) area inc"));
    ASSERT_NO_THROW(Terminal("Rectangle     (3, 4) Rectangle (3,4) Ellipse (3, 4) Rectangle (  3,4  ) Triangle ([0,-3], [-3,0], [0,-4]) Triangle ([0,-3], [-3,0], [0,-4]) area inc"));
}

TEST_F(TerminnalTesting, showResult) {
    ASSERT_EQ("6.000\n15.540\n62.832", terminal->showResult());
}

TEST_F(TerminnalTesting, sortTarget) {
    ASSERT_EQ("area", terminal->getSortTarget());
}

TEST_F(TerminnalTesting, sortWay) {
    ASSERT_EQ("inc", terminal->getSortWay());
}

TEST_F(TerminnalTesting, sortAreaByInc) {
    ASSERT_EQ("6.000\n15.540\n62.832", Terminal("Rectangle (3.7, 4.2) Ellipse (5, 4) Triangle ([0,0], [3,0], [0,4]) area inc").showResult());
}

TEST_F(TerminnalTesting, sortAreaByDec) {
    ASSERT_EQ("62.832\n15.540\n6.000", Terminal("Rectangle (3.7, 4.2) Ellipse (5, 4) Triangle ([0,0], [3,0], [0,4]) area dec").showResult());
}

TEST_F(TerminnalTesting, sortPerimeterByInc) {
    ASSERT_EQ("12.000\n15.800\n29.133", Terminal("Rectangle (3.7, 4.2) Ellipse (5, 4) Triangle ([0,0], [3,0], [0,4]) perimeter inc").showResult());
}

TEST_F(TerminnalTesting, sortPerimeterByDec) {
    ASSERT_EQ("29.133\n15.800\n12.000", Terminal("Rectangle (3.7, 4.2) Ellipse (5, 4) Triangle ([0,0], [3,0], [0,4]) perimeter dec").showResult());
}

TEST_F(TerminnalTesting, sortPerimeterByDecWithOneErrorShape) {
    ASSERT_EQ("29.133\n15.800", Terminal("Rectangle (3.7, 4.2) Ellipse (5, 4) Triangle ([3,0], [0,4]) perimeter dec").showResult());
}

TEST_F(TerminnalTesting, sortPerimeterByIncSpec) {
    ASSERT_EQ("12.000\n15.800\n22.850", Terminal("Rectangle (3.7, 4.2) Ellipse (4, 3) Triangle ([0,0], [3,0], [0,4]) perimeter inc").showResult());
}

TEST_F(TerminnalTesting, sortAreaByIncWithOneShapeErrorArgumentIgnore) {
    ASSERT_EQ("22.850", Terminal("Rectangle (-3.7, 4.2) Ellipse (4, 3) Triangle (, [3,0], [0,4]) perimeter inc").showResult());
}
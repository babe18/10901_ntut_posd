#include <gtest/gtest.h>

#include "../src/ellipse.h"

#define ABS_ERROR 0.001

class EllipseTesting : public ::testing::Test {
protected :

    void SetUp() override {
        ellipse = new Ellipse(7.0, 6.0);
    }

    void TearDown() override {
        delete ellipse;
    }

    Ellipse * ellipse;
};

TEST_F(EllipseTesting, getInfo){
    delete ellipse;
    ellipse = new Ellipse(5.0, 1.0);
    ASSERT_EQ("Ellipse (5.000, 1.000)", ellipse->info());
    delete ellipse;
    ellipse = new Ellipse(5.3215, 4.123);
    ASSERT_EQ("Ellipse (5.321, 4.123)", ellipse->info());
}

TEST_F(EllipseTesting, testCreateEllipse){
    try
    {
        Ellipse ellipse(0, 1.0);
        FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("This is not an ellipse!", e);
    }

    try
    {
        Ellipse ellipse(-1.54, 1.0);
        FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("This is not an ellipse!", e);
    }

    try
    {
        Ellipse ellipse(5.0, 7.0);
        FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("This is not an ellipse!", e);
    }

    ASSERT_NO_THROW(Ellipse(90.50, 40.9));
}

TEST_F(EllipseTesting, testGetArea) {
    delete ellipse;
    ellipse = new Ellipse(5.0, 4.0);
    ASSERT_NEAR(62.831, ellipse->area(), ABS_ERROR);
    delete ellipse;
    ellipse = new Ellipse(5.123, 4.789);
    ASSERT_NEAR(77.075, ellipse->area(), ABS_ERROR);
    delete ellipse;
    ellipse = new Ellipse(888, 111);
    ASSERT_NEAR(309660.504, ellipse->area(), ABS_ERROR);
}

TEST_F(EllipseTesting, testGetPerimeter) {
    delete ellipse;
    ellipse = new Ellipse(5.0, 4.0);
    ASSERT_NEAR(29.132, ellipse->perimeter(), ABS_ERROR);
    delete ellipse;
    ellipse = new Ellipse(5.123, 4.789);
    ASSERT_NEAR(31.426, ellipse->perimeter(), ABS_ERROR);
    delete ellipse;
    ellipse = new Ellipse(888, 111);
    ASSERT_NEAR(3805.433, ellipse->perimeter(), ABS_ERROR);
    delete ellipse;
    ellipse = new Ellipse(4, 3);
    ASSERT_NEAR(22.849, ellipse->perimeter(), ABS_ERROR);
}
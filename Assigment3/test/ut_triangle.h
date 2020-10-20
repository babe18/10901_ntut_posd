#include <gtest/gtest.h>

#include "../src/two_dimensional_coordinate.h"
#include "../src/triangle.h"

#define ABS_ERROR 0.001

class TriangleTesting : public ::testing::Test {
protected:
    void SetUp() override {
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        triangle = new Triangle(triangleVector);
    }

    void TearDown() override {
        delete triangle;
    }

    Triangle * triangle;
    std::vector<TwoDimensionalCoordinate*> triangleVector;
};

TEST_F(TriangleTesting, getInfo){
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle->info());
}

TEST_F(TriangleTesting, testCreateTriangle) {
    std::vector<TwoDimensionalCoordinate*> triangleVector = std::vector<TwoDimensionalCoordinate*>();
    try
    {
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        Triangle triangle = Triangle(triangleVector);
        FAIL();
    }
    catch(std::string e)
    {
        for (auto p: triangleVector)
            delete p;
        triangleVector.clear();
        ASSERT_EQ("This is not a triangle!", e);
    }

    try
    {
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 1));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 2));
        Triangle triangle = Triangle(triangleVector);
        FAIL();
    }
    catch(std::string e)
    {
        for (auto p: triangleVector)
            delete p;
        triangleVector.clear();        
        ASSERT_EQ("This is not a triangle!", e);
    }

    try
    {
        triangleVector.clear();
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(2, 2));
        triangleVector.push_back(new TwoDimensionalCoordinate(2, 2));
        Triangle triangle = Triangle(triangleVector);
        FAIL();
    }
    catch(std::string e)
    {
        for (auto p: triangleVector)
            delete p;
        ASSERT_EQ("This is not a triangle!", e);
    }
    triangleVector.clear();
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 3));
    triangleVector.push_back(new TwoDimensionalCoordinate(4, 0));
    ASSERT_NO_THROW(Triangle triangle(triangleVector));
}

TEST_F(TriangleTesting, testGetArea) {
    ASSERT_NEAR(6.000, triangle->area(), ABS_ERROR);
}

TEST_F(TriangleTesting, testGetPerimeter) {
    ASSERT_NEAR(12.000, triangle->perimeter(), ABS_ERROR);
}

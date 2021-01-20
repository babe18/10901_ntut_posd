#include <gtest/gtest.h>
#include "../src/app.h"

using namespace std;

class AppTestSuite: public testing::Test {
protected:
    virtual void SetUp() {
        googleMap = new App("1", "googleMap", 112.357);
        gmail = new App("2", "gmail", 35.7);
    }

    virtual void TearDown() {}

    Node* googleMap;
    Node* gmail;
};

TEST(AppTest, constructor_no_throw) {
    ASSERT_NO_THROW(App("0", "firstApp", 654.321));
}

TEST(AppTest, id) {
    Node* firstApp = new App("0", "firstApp", 654.321);
    ASSERT_EQ("0", firstApp->id());
}

TEST(AppTest, name) {
    Node* firstApp = new App("0", "firstApp", 654.321);
    ASSERT_EQ("firstApp", firstApp->name());
}

TEST(AppTest, size) {
    Node* firstApp = new App("0", "firstApp", 654.321);
    ASSERT_DOUBLE_EQ(654.321, firstApp->size());
}

TEST(AppTest, route) {
    Node* firstApp = new App("0", "firstApp", 654.321);
    ASSERT_EQ("/firstApp", firstApp->route());
}

TEST(AppTest, update_path) {
    Node* firstApp = new App("0", "firstApp", 654.321);
    ASSERT_EQ("/firstApp", firstApp->route());

    firstApp->updatePath("/RootFolder");
    EXPECT_EQ("/RootFolder/firstApp", firstApp->route());

    firstApp->updatePath("/favortie");
    EXPECT_EQ("/favortie/firstApp", firstApp->route());
}

TEST_F(AppTestSuite, add_node_should_throw_exception) {
    try {
        googleMap->addNode(gmail);
    }catch(string e) {
        ASSERT_EQ("only folder can add node.", e);
    }
}

TEST_F(AppTestSuite, delete_node_should_throw_exception) {
    try {
        googleMap->deleteNodeById("2");
    }catch(string e) {
        ASSERT_EQ("only folder can delete node.", e);
    }
}

TEST_F(AppTestSuite, get_node_should_throw_exception) {
    try {
        googleMap->getNodeById("2");
    }catch(string e) {
        ASSERT_EQ("only folder can get node.", e);
    }
}
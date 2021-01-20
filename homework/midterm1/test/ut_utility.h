#include "../src/folder.h"
#include "../src/app.h"
#include "../src/utility.h"

using namespace std;

class UtlilityTestSuite: public testing::Test {
protected:
    virtual void SetUp() {
        chrome = new App("1", "chrome", 50.15);
        facebook = new App("2", "facebook", 30.32);
        instagram = new App("3", "instagram", 20.21);
        youtube = new App("4", "youtube", 70.07);
        ubereat = new App("5", "ubereat", 40.34);
        line = new App("6", "line", 60.66);

        favorite = new Folder("7", "favorite");
        common = new Folder("8", "common");
        community = new Folder("9", "community");
        trash = new Folder("10", "trash");

        favorite->addNode(chrome);
        favorite->addNode(facebook);
        favorite->addNode(common);
        common->addNode(instagram);
        common->addNode(community);
        common->addNode(youtube);
        community->addNode(ubereat);
        community->addNode(line);
        community->addNode(trash);
    }

    virtual void TearDown() {}

    Node* chrome;
    Node* facebook;
    Node* instagram;
    Node* youtube;
    Node* ubereat;
    Node* line;

    Node* favorite;
    Node* common;
    Node* community;
    Node* trash;
};

TEST_F(UtlilityTestSuite, exception_for_app_filter_by_size) {
    try {
        filterNode(chrome, SizeFilter(100, 1));
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only folder can filter node!", e);
    }
}

TEST_F(UtlilityTestSuite, folder_filter_by_size_between_80_and_50) {
    deque<Node *> nodes = filterNode(favorite, SizeFilter(80, 50));

    ASSERT_EQ(3, nodes.size());

    EXPECT_EQ("1", nodes[0]->id());
    EXPECT_DOUBLE_EQ(50.15, nodes[0]->size());

    EXPECT_EQ("6", nodes[1]->id()); //4
    EXPECT_DOUBLE_EQ(60.66, nodes[1]->size());

    EXPECT_EQ("4", nodes[2]->id()); //6
    EXPECT_DOUBLE_EQ(70.07, nodes[2]->size());
}

TEST_F(UtlilityTestSuite, folder_filter_by_size_between_999_and_0) {
    deque<Node *> nodes = filterNode(favorite, SizeFilter(999, 0));

    ASSERT_EQ(9, nodes.size());

    EXPECT_EQ("1", nodes[0]->id());
    EXPECT_DOUBLE_EQ(50.15, nodes[0]->size());

    EXPECT_EQ("2", nodes[1]->id());
    EXPECT_DOUBLE_EQ(30.32, nodes[1]->size());

    EXPECT_EQ("8", nodes[2]->id());//3
    EXPECT_DOUBLE_EQ(191.28, nodes[2]->size());

    EXPECT_EQ("3", nodes[3]->id());//5
    EXPECT_DOUBLE_EQ(20.21, nodes[3]->size());

    EXPECT_EQ("9", nodes[4]->id());//6
    EXPECT_DOUBLE_EQ(101, nodes[4]->size());

    EXPECT_EQ("5", nodes[5]->id()); //10
    EXPECT_DOUBLE_EQ(40.34, nodes[5]->size());

    EXPECT_EQ("6", nodes[6]->id()); //9
    EXPECT_DOUBLE_EQ(60.66, nodes[6]->size());

    EXPECT_EQ("10", nodes[7]->id()); //4
    EXPECT_DOUBLE_EQ(0, nodes[7]->size());

    EXPECT_EQ("4", nodes[8]->id()); //8
    EXPECT_DOUBLE_EQ(70.07, nodes[8]->size());
}


TEST_F(UtlilityTestSuite, folder_filter_by_size_equal_to_zero) {
    deque<Node *> nodes = filterNode(favorite, SizeFilter(0, 0));
    ASSERT_EQ(1, nodes.size());

    EXPECT_EQ("10", nodes[0]->id());
    EXPECT_EQ(0, nodes[0]->size());
}

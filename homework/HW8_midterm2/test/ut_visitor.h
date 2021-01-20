#include <gtest/gtest.h>
#include "../src/folder.h"
#include "../src/app.h"
#include "../src/find_visitor.h"

using namespace std;
//30%
class VisitorTestSuite: public testing::Test {
protected:
    virtual void SetUp() {
        favorite = new Folder("1", "favorite");
        community = new Folder("2", "community");
        common = new Folder("3", "common");
        trash = new Folder("4", "trash");
        others_in_community = new Folder("5", "others");
        favorite_in_common = new Folder("6", "favorite");
        favorite->addNodes({
            new App("7", "instagram", 20.21),
            community,
            new App("8", "youtube", 70.07),
            common
        });

        community->addNodes({
            new App("9", "facebook", 30.32),
            new App("10", "instagram", 20.21),
            new Folder("11", "favorite"),
            others_in_community
        });

        common->addNodes({
            new App("12", "instagram", 20.21),
            new App("13", "line", 60.66),
            favorite_in_common,
            new App("14", "twitter", 40.05)
        });

        others_in_community->addNodes({
            new App("15", "twitter", 40.05)
        });

        favorite_in_common->addNodes({
            new Folder("16", "others")
        });
    }

    Node* favorite;
    Node* community;
    Node* common;
    Node* trash;

    Node* favorite_in_common;
    Node* others_in_community;
};

//2%
TEST(VisitorTest, find_app) {
    Node *ubereat = new App("1", "ubereat", 40.34);
    FindVisitor* fv = new FindVisitor("ubereat");
    ubereat->accept(fv);

    ASSERT_EQ("/ubereat", fv->getResult());
}

//2%
TEST(VisitorTest, find_folder) {
    Node *game = new Folder("1", "game");

    FindVisitor* fv = new FindVisitor("game");
    game->accept(fv);

    ASSERT_EQ("/game", fv->getResult());
}

//3%
TEST_F(VisitorTestSuite, find_app_in_folder) {
    FindVisitor* fv = new FindVisitor("youtube");
    favorite->accept(fv);

    ASSERT_EQ("/favorite/youtube", fv->getResult());
}

//3%
TEST_F(VisitorTestSuite, find_folder_in_folder) {
    FindVisitor* fv = new FindVisitor("community");
    favorite->accept(fv);

    ASSERT_EQ("/favorite/community", fv->getResult());
}

//5%
TEST_F(VisitorTestSuite, find_node_in_tree_structure_1) {
    FindVisitor* fv = new FindVisitor("instagram");
    favorite->accept(fv);

    ASSERT_EQ("/favorite/instagram\n/favorite/community/instagram\n/favorite/common/instagram", fv->getResult());
}

//5%
TEST_F(VisitorTestSuite, find_node_in_tree_structure_2) {
    FindVisitor* fv = new FindVisitor("twitter");
    favorite->accept(fv);

    ASSERT_EQ("/favorite/community/others/twitter\n/favorite/common/twitter", fv->getResult());
}

//5%
TEST_F(VisitorTestSuite, find_node_in_tree_structure_3) {
    FindVisitor* fv = new FindVisitor("others");
    favorite->accept(fv);

    ASSERT_EQ("/favorite/community/others\n/favorite/common/favorite/others", fv->getResult());
}

//5%
TEST_F(VisitorTestSuite, find_node_in_tree_structure_4) {
    FindVisitor* fv = new FindVisitor("favorite");
    favorite->accept(fv);

    ASSERT_EQ("/favorite\n/favorite/community/favorite\n/favorite/common/favorite", fv->getResult());
}
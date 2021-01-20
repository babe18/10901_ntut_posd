#include "../src/folder.h"
#include "../src/app.h"

using namespace std;

class IteratorTestSuite: public testing::Test {
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

        common->addNode(instagram);
        common->addNode(community);
        common->addNode(youtube);


        community->addNode(ubereat);
        community->addNode(line);
        community->addNode(trash);
        
        favorite->addNode(chrome);
        favorite->addNode(facebook);
        favorite->addNode(common);
    }

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

// TEST_F(IteratorTestSuite, exception_for_app_iterate_first){
//     Iterator* it = chrome->createIterator();
//     try {
//         it->first();
//         FAIL();
//     }catch(string e) {
//         ASSERT_EQ("No child member!", e);
//     }
// }

// TEST_F(IteratorTestSuite, exception_for_app_iterate_current_item){
//     Iterator* it = chrome->createIterator();
//     try {
//         it->currentItem();
//         FAIL();
//     }catch(string e) {
//         ASSERT_EQ("No child member!", e);
//     }
// }

// TEST_F(IteratorTestSuite, exception_for_app_iterate_next){
//     Iterator* it = chrome->createIterator();
//     try {
//         it->next();
//         FAIL();
//     }catch(string e) {
//         ASSERT_EQ("No child member!", e);
//     }
// }

// TEST_F(IteratorTestSuite, app_iterate_is_done){
//     Iterator* it = chrome->createIterator();
//     ASSERT_TRUE(it->isDone());
// }

// TEST_F(IteratorTestSuite, folder_iterate_first) {
//     Iterator* it = favorite->createIterator();
//     ASSERT_NO_THROW(it->first());
// }

// TEST_F(IteratorTestSuite, folder_iterate_current_item) {
//     Iterator* it = favorite->createIterator();

//     Node* node = it->currentItem();

//     EXPECT_EQ("1", node->id());
//     EXPECT_EQ("chrome", node->name());
//     EXPECT_DOUBLE_EQ(50.15, node->size());
//     EXPECT_EQ("/favorite/chrome", node->route());
// }

// TEST_F(IteratorTestSuite, folder_iterate_current_next) {
//     Iterator* it = favorite->createIterator();

//     ASSERT_NO_THROW(it->next());

//     Node *node = it->currentItem();

//     EXPECT_EQ("2", node->id());
//     EXPECT_EQ("facebook", node->name());
//     EXPECT_DOUBLE_EQ(30.32, node->size());
//     EXPECT_EQ("/favorite/facebook", node->route());

//     ASSERT_NO_THROW(it->next());


//     node = it->currentItem();

//     EXPECT_EQ("8", node->id());
//     EXPECT_EQ("common", node->name());
//     EXPECT_DOUBLE_EQ(191.28, node->size());
//     EXPECT_EQ("/favorite/common", node->route());
// }

// TEST_F(IteratorTestSuite, exception_for_folder_iterate_next_out_of_range) {
//     Iterator* it = favorite->createIterator();
//     ASSERT_NO_THROW(it->next());
//     ASSERT_NO_THROW(it->next());
//     ASSERT_NO_THROW(it->next());

//     try {
//         it->next();
//         FAIL();
//     }catch(string e) {
//         EXPECT_EQ("Moving past the end!", e);
//     }
// }

// TEST_F(IteratorTestSuite, folder_iterate_is_done) {
//     Iterator* it = favorite->createIterator();
//     ASSERT_NO_THROW(it->next());
//     ASSERT_NO_THROW(it->next());
//     ASSERT_NO_THROW(it->next());
//     EXPECT_TRUE(it->isDone());
// }
#include <gtest/gtest.h>
#include "../src/node_builder.h"

class Node;

std::vector<Node*> getChildren(Node* folder) {
    Iterator* it = folder->createIterator();
    std::vector<Node*> childern = {};
    for(it->first(); !it->isDone(); it->next()) {
        childern.push_back(it->currentItem());
    }
    return childern;
}

//32%

//2%
TEST(NodeBuilderTest, build_app) {
    NodeBuilder nb;

    nb.buildApp("googleMap", 112.357);

    std::deque<Node*> results = nb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_DOUBLE_EQ(112.357, results[0]->size());
    EXPECT_EQ("/googleMap", results[0]->route());
}

//2%
TEST(NodeBuilderTest, build_multi_app) {
    NodeBuilder nb;

    nb.buildApp("googleMap", 112.357);
    nb.buildApp("gmail", 35.7);

    std::deque<Node*> results = nb.getResult();

    ASSERT_EQ(2, results.size());

    EXPECT_NE(results[0]->id(), results[1]->id());

    EXPECT_DOUBLE_EQ(112.357, results[0]->size());
    EXPECT_EQ("/googleMap", results[0]->route());

    EXPECT_DOUBLE_EQ(35.7, results[1]->size());
    EXPECT_EQ("/gmail", results[1]->route());

}

//2%
TEST(NodeBuilderTest, build_empty_folder) {
    NodeBuilder nb;

    nb.buildFolderBegin("trash");
    nb.buildFolderEnd();

    std::deque<Node*> results = nb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_DOUBLE_EQ(0.0, results[0]->size());
    EXPECT_EQ("/trash", results[0]->route());
}

//3%
TEST(NodeBuilderTest, build_folder_contains_one_app) {
    NodeBuilder nb;

    nb.buildFolderBegin("community");
        nb.buildApp("ubereat", 40.34);
    nb.buildFolderEnd();

    std::deque<Node*> results = nb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_DOUBLE_EQ(40.34, results[0]->size());
    EXPECT_EQ("/community", results[0]->route());

    std::vector<Node*> community_childern = getChildren(results[0]);

    ASSERT_EQ(1, community_childern.size());

    EXPECT_DOUBLE_EQ(40.34, community_childern[0]->size());
    EXPECT_EQ("/community/ubereat", community_childern[0]->route());
}

//3%
TEST(NodeBuilderTest, build_folder_contains_a_empty_folder) {
    NodeBuilder nb;

    nb.buildFolderBegin("community");
        nb.buildFolderBegin("trash");
        nb.buildFolderEnd();
    nb.buildFolderEnd();

    std::deque<Node*> results = nb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_DOUBLE_EQ(0.0, results[0]->size());
    EXPECT_EQ("/community", results[0]->route());

    std::vector<Node*> community_childern = getChildren(results[0]);

    ASSERT_EQ(1, community_childern.size());

    EXPECT_DOUBLE_EQ(0.0, community_childern[0]->size());
    EXPECT_EQ("/community/trash", community_childern[0]->route());
}

//5%
TEST(NodeBuilderTest, build_folder_contains_multi_app_and_empty_folder) {
    NodeBuilder nb;

    nb.buildFolderBegin("community");
        nb.buildApp("ubereat", 40.34);
        nb.buildApp("line", 60.66);
        nb.buildFolderBegin("trash");
        nb.buildFolderEnd();
    nb.buildFolderEnd();

    std::deque<Node*> results = nb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_DOUBLE_EQ(101.0, results[0]->size());
    EXPECT_EQ("/community", results[0]->route());

    std::vector<Node*> community_childern = getChildren(results[0]);

    ASSERT_EQ(3, community_childern.size());

    EXPECT_DOUBLE_EQ(40.34, community_childern[0]->size());
    EXPECT_EQ("/community/ubereat", community_childern[0]->route());

    EXPECT_DOUBLE_EQ(60.66, community_childern[1]->size());
    EXPECT_EQ("/community/line", community_childern[1]->route());

    EXPECT_DOUBLE_EQ(0.0, community_childern[2]->size());
    EXPECT_EQ("/community/trash", community_childern[2]->route());
}

//5%
TEST(NodeBuilderTest, build_multi_nodes_and_folder_contains_multi_app_and_empty_folder) {
    NodeBuilder nb;

    nb.buildApp("googleMap", 112.357);

    nb.buildFolderBegin("community");
        nb.buildApp("ubereat", 40.34);
        nb.buildApp("line", 60.66);
        nb.buildFolderBegin("trash");
        nb.buildFolderEnd();
    nb.buildFolderEnd();

    nb.buildApp("gmail", 35.7);

    nb.buildFolderBegin("trash");
    nb.buildFolderEnd();
    nb.buildFolderBegin("trash");
    nb.buildFolderEnd();

    std::deque<Node*> results = nb.getResult();

    ASSERT_EQ(5, results.size());

    EXPECT_NE(results[0]->id(), results[1]->id());
    EXPECT_NE(results[1]->id(), results[2]->id());
    EXPECT_NE(results[2]->id(), results[3]->id());
    EXPECT_NE(results[3]->id(), results[4]->id());
    EXPECT_NE(results[4]->id(), results[0]->id());

    EXPECT_DOUBLE_EQ(112.357, results[0]->size());
    EXPECT_EQ("/googleMap", results[0]->route());

    EXPECT_DOUBLE_EQ(101.0, results[1]->size());
    EXPECT_EQ("/community", results[1]->route());

    std::vector<Node*> community_childern = getChildren(results[1]);

    ASSERT_EQ(3, community_childern.size());

    EXPECT_DOUBLE_EQ(40.34, community_childern[0]->size());
    EXPECT_EQ("/community/ubereat", community_childern[0]->route());

    EXPECT_DOUBLE_EQ(60.66, community_childern[1]->size());
    EXPECT_EQ("/community/line", community_childern[1]->route());

    EXPECT_DOUBLE_EQ(0.0, community_childern[2]->size());
    EXPECT_EQ("/community/trash", community_childern[2]->route());

    EXPECT_DOUBLE_EQ(35.7, results[2]->size());
    EXPECT_EQ("/gmail", results[2]->route());

    EXPECT_DOUBLE_EQ(0.0, results[3]->size());
    EXPECT_EQ("/trash", results[3]->route());

    EXPECT_DOUBLE_EQ(0.0, results[4]->size());
    EXPECT_EQ("/trash", results[4]->route());
}

//5%
TEST(NodeBuilderTest, build_multi_nodes_and_level_3_folder_contains_multi_app_and_empty_folder) {
    NodeBuilder nb;

    nb.buildFolderBegin("common");
        nb.buildApp("instagram", 20.21);
        nb.buildApp("youtube", 70.07);
        nb.buildFolderBegin("community");
            nb.buildApp("ubereat", 40.34);
            nb.buildApp("line", 60.66);
            nb.buildFolderBegin("trash");
            nb.buildFolderEnd();
        nb.buildFolderEnd();
    nb.buildFolderEnd();

    nb.buildFolderBegin("trash");
    nb.buildFolderEnd();

    nb.buildApp("googleMap", 112.357);
    nb.buildApp("googleMap", 112.357);

    std::deque<Node*> results = nb.getResult();

    ASSERT_EQ(4, results.size());

    EXPECT_NE(results[0]->id(), results[1]->id());
    EXPECT_NE(results[1]->id(), results[2]->id());
    EXPECT_NE(results[2]->id(), results[3]->id());
    EXPECT_NE(results[3]->id(), results[0]->id());

    EXPECT_DOUBLE_EQ(191.28, results[0]->size());
    EXPECT_EQ("/common", results[0]->route());

    std::vector<Node*> common_childern = getChildren(results[0]);

    ASSERT_EQ(3, common_childern.size());

    EXPECT_DOUBLE_EQ(20.21, common_childern[0]->size());
    EXPECT_EQ("/common/instagram", common_childern[0]->route());

    EXPECT_DOUBLE_EQ(70.07, common_childern[1]->size());
    EXPECT_EQ("/common/youtube", common_childern[1]->route());

    EXPECT_DOUBLE_EQ(101.0, common_childern[2]->size());
    EXPECT_EQ("/common/community", common_childern[2]->route());

    std::vector<Node*> community_childern = getChildren(common_childern[2]);

    ASSERT_EQ(3, community_childern.size());

    EXPECT_DOUBLE_EQ(40.34, community_childern[0]->size());
    EXPECT_EQ("/common/community/ubereat", community_childern[0]->route());

    EXPECT_DOUBLE_EQ(60.66, community_childern[1]->size());
    EXPECT_EQ("/common/community/line", community_childern[1]->route());

    EXPECT_DOUBLE_EQ(0.0, community_childern[2]->size());
    EXPECT_EQ("/common/community/trash", community_childern[2]->route());

    EXPECT_DOUBLE_EQ(0.0, results[1]->size());
    EXPECT_EQ("/trash", results[1]->route());

    EXPECT_DOUBLE_EQ(112.357, results[2]->size());
    EXPECT_EQ("/googleMap", results[2]->route());

    EXPECT_DOUBLE_EQ(112.357, results[3]->size());
    EXPECT_EQ("/googleMap", results[3]->route());
}

//5%
TEST(NodeBuilderTest, build_multi_nodes_and_level_4_folder_contains_multi_app_and_empty_folder) {
    NodeBuilder nb;

    nb.buildFolderBegin("trash");
    nb.buildFolderEnd();

    nb.buildApp("gmail", 35.7);
    nb.buildApp("gmail", 35.7);

    nb.buildFolderBegin("favorite");
        nb.buildApp("chrome", 50.15);
        nb.buildApp("facebook", 30.32);
        nb.buildFolderBegin("common");
            nb.buildApp("instagram", 20.21);
            nb.buildFolderBegin("community");
                nb.buildApp("ubereat", 40.34);
                nb.buildApp("line", 60.66);
                nb.buildFolderBegin("trash");
                nb.buildFolderEnd();
            nb.buildFolderEnd();
            nb.buildApp("youtube", 70.07);
        nb.buildFolderEnd();
    nb.buildFolderEnd();

    nb.buildFolderBegin("trash");
    nb.buildFolderEnd();

    std::deque<Node*> results = nb.getResult();

    ASSERT_EQ(5, results.size());

    EXPECT_NE(results[0]->id(), results[1]->id());
    EXPECT_NE(results[1]->id(), results[2]->id());
    EXPECT_NE(results[2]->id(), results[3]->id());
    EXPECT_NE(results[3]->id(), results[4]->id());
    EXPECT_NE(results[4]->id(), results[0]->id());

    EXPECT_DOUBLE_EQ(0.0, results[0]->size());
    EXPECT_EQ("/trash", results[0]->route());

    EXPECT_DOUBLE_EQ(35.7, results[1]->size());
    EXPECT_EQ("/gmail", results[1]->route());

    EXPECT_DOUBLE_EQ(35.7, results[2]->size());
    EXPECT_EQ("/gmail", results[2]->route());

    EXPECT_DOUBLE_EQ(271.75, results[3]->size());
    EXPECT_EQ("/favorite", results[3]->route());

    std::vector<Node*> favorite_childern = getChildren(results[3]);

    ASSERT_EQ(3, favorite_childern.size());

    EXPECT_DOUBLE_EQ(50.15, favorite_childern[0]->size());
    EXPECT_EQ("/favorite/chrome", favorite_childern[0]->route());

    EXPECT_DOUBLE_EQ(30.32, favorite_childern[1]->size());
    EXPECT_EQ("/favorite/facebook", favorite_childern[1]->route());

    EXPECT_DOUBLE_EQ(191.28, favorite_childern[2]->size());
    EXPECT_EQ("/favorite/common", favorite_childern[2]->route());

    std::vector<Node*> common_childern = getChildren(favorite_childern[2]);

    ASSERT_EQ(3, common_childern.size());

    EXPECT_DOUBLE_EQ(20.21, common_childern[0]->size());
    EXPECT_EQ("/favorite/common/instagram", common_childern[0]->route());

    EXPECT_DOUBLE_EQ(101.0, common_childern[1]->size());
    EXPECT_EQ("/favorite/common/community", common_childern[1]->route());

    EXPECT_DOUBLE_EQ(70.07, common_childern[2]->size());
    EXPECT_EQ("/favorite/common/youtube", common_childern[2]->route());

    std::vector<Node*> community_childern = getChildren(common_childern[1]);

    ASSERT_EQ(3, community_childern.size());

    EXPECT_DOUBLE_EQ(40.34, community_childern[0]->size());
    EXPECT_EQ("/favorite/common/community/ubereat", community_childern[0]->route());

    EXPECT_DOUBLE_EQ(60.66, community_childern[1]->size());
    EXPECT_EQ("/favorite/common/community/line", community_childern[1]->route());

    EXPECT_DOUBLE_EQ(0, community_childern[2]->size());
    EXPECT_EQ("/favorite/common/community/trash", community_childern[2]->route());

    EXPECT_DOUBLE_EQ(0.0, results[4]->size());
    EXPECT_EQ("/trash", results[4]->route());
}

// TEST(NodeBuilderTest, test1) {
//     NodeBuilder nb;

//     nb.buildFolderBegin("trash");
//     nb.buildApp("gmail", 35.7);
//     nb.buildApp("facebook", 30.32);
//     nb.buildApp("line", 60.66);
//     nb.buildFolderEnd();
//     std::deque<Node*> results = nb.getResult();
//     EXPECT_EQ(1, results.size());
// }
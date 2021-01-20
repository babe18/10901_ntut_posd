#include <gtest/gtest.h>
#include "../src/node_parser.h"

std::vector<Node*> getChildren(Node* folder);
// implementation in ut_node_builder.h

//22%

//3%
TEST(Parser, parser_single_app) {
    std::string input = "facebook (30.32)";
    NodeParser* np = new NodeParser(input);

    np->parser();

    std::deque<Node*> results = np->getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("facebook", results[0]->name());
    EXPECT_DOUBLE_EQ(30.32, results[0]->size());
} 

//3%
TEST(Parser, parser_single_folder) {
    std::string input = "favorite {}";
    NodeParser* np = new NodeParser(input);

    np->parser();

    std::deque<Node*> results = np->getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("favorite", results[0]->name());
    EXPECT_DOUBLE_EQ(0.0, results[0]->size());
} 

//4%
TEST(Parser, parser_folder_contain_apps) {
    std::string input = "favorite {chrome (50.15), facebook (30.32), instagram (20.21)}";
    NodeParser* np = new NodeParser(input);

    np->parser();

    std::deque<Node*> results = np->getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("favorite", results[0]->name());
    EXPECT_DOUBLE_EQ(100.68, results[0]->size());

    std::vector<Node*> favorite_children = getChildren(results[0]);

    EXPECT_EQ("chrome", favorite_children[0]->name());
    EXPECT_DOUBLE_EQ(50.15, favorite_children[0]->size());

    EXPECT_EQ("facebook", favorite_children[1]->name());
    EXPECT_DOUBLE_EQ(30.32, favorite_children[1]->size());

    EXPECT_EQ("instagram", favorite_children[2]->name());
    EXPECT_DOUBLE_EQ(20.21, favorite_children[2]->size());
} 

//4%
TEST(Parser, parser_folder_contain_folders) {
    std::string input = "favorite {community {trash {}}, common {}}";
    NodeParser *np = new NodeParser(input);

    np->parser();

    std::deque<Node*> results = np->getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("favorite", results[0]->name());
    EXPECT_DOUBLE_EQ(0.0, results[0]->size());


    std::vector<Node *> favorite_children = getChildren(results[0]);

    EXPECT_EQ("community", favorite_children[0]->name());
    EXPECT_DOUBLE_EQ(0.0, favorite_children[0]->size());

    EXPECT_EQ("common", favorite_children[1]->name());
    EXPECT_DOUBLE_EQ(0.0, favorite_children[1]->size());

    std::vector<Node*> community_children = getChildren(favorite_children[0]);

    EXPECT_EQ("trash", community_children[0]->name());
    EXPECT_DOUBLE_EQ(0.0, community_children[0]->size());
} 

//4%
TEST(Parser, parser_tree_structure) {
    std::string input = "favorite {chrome (50.15), facebook (30.32), common {instagram (20.21), community {ubereat (40.34), line (60.66), trash {}}, youtube (70.07)}}";
    NodeParser *np = new NodeParser(input);

    np->parser();

    std::deque<Node*> results = np->getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("favorite", results[0]->name());
    EXPECT_DOUBLE_EQ(271.75, results[0]->size());

    std::vector<Node*> favorite_children = getChildren(results[0]);

    EXPECT_EQ("chrome", favorite_children[0]->name());
    EXPECT_DOUBLE_EQ(50.15, favorite_children[0]->size());
    
    EXPECT_EQ("facebook", favorite_children[1]->name());
    EXPECT_DOUBLE_EQ(30.32, favorite_children[1]->size());

    EXPECT_EQ("common", favorite_children[2]->name());
    EXPECT_DOUBLE_EQ(191.28, favorite_children[2]->size());

    std::vector<Node*> common_children = getChildren(favorite_children[2]);

    EXPECT_EQ("instagram", common_children[0]->name());
    EXPECT_DOUBLE_EQ(20.21, common_children[0]->size());
    
    EXPECT_EQ("community", common_children[1]->name());
    EXPECT_DOUBLE_EQ(101, common_children[1]->size());

    EXPECT_EQ("youtube", common_children[2]->name());
    EXPECT_DOUBLE_EQ(70.07, common_children[2]->size());

    std::vector<Node*> community_children = getChildren(common_children[1]);

    EXPECT_EQ("ubereat", community_children[0]->name());
    EXPECT_DOUBLE_EQ(40.34, community_children[0]->size());
    
    EXPECT_EQ("line", community_children[1]->name());
    EXPECT_DOUBLE_EQ(60.66, community_children[1]->size());

    EXPECT_EQ("trash", community_children[2]->name());
    EXPECT_DOUBLE_EQ(0.0, community_children[2]->size());
} 

//4%
TEST(Parser, parser_tree_structure_with_invaild_node) {
    std::string input = "favorite {chrome (50.15, 51.05), facebook (), {instagram (20.21), community {ubereat (40.34), line ((60.66)), trash {}}, youtube (70.07)}}";
    NodeParser *np = new NodeParser(input);
    np->parser();

    std::deque<Node*> results = np->getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("favorite", results[0]->name());
    EXPECT_DOUBLE_EQ(130.62, results[0]->size());

    std::vector<Node*> favorite_children = getChildren(results[0]);

    ASSERT_EQ(3, favorite_children.size());

    EXPECT_EQ("instagram", favorite_children[0]->name());
    EXPECT_DOUBLE_EQ(20.21, favorite_children[0]->size());

    EXPECT_EQ("community", favorite_children[1]->name());
    EXPECT_DOUBLE_EQ(40.34, favorite_children[1]->size());

    std::vector<Node*> community_children = getChildren(favorite_children[1]);

    ASSERT_EQ(2, community_children.size());

    EXPECT_EQ("ubereat", community_children[0]->name());
    EXPECT_DOUBLE_EQ(40.34, community_children[0]->size());

    EXPECT_EQ("trash", community_children[1]->name());
    EXPECT_DOUBLE_EQ(0, community_children[1]->size());

    std::vector<Node*> trash_children = getChildren(community_children[1]);

    ASSERT_EQ(0, trash_children.size());

    EXPECT_EQ("youtube", favorite_children[2]->name());
    EXPECT_DOUBLE_EQ(70.07, favorite_children[2]->size());
} 
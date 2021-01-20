#include "../src/scanner.h"

TEST(ScannerTest, Next) {
    std::string input = "mixed {\n  rect 3 4\n  mixed {\n    rect 2 2\n    tri 3 4 5\n  }\n}\n";
    Scanner scanner(input);
    ASSERT_EQ("mixed", scanner.next());
    ASSERT_EQ("{", scanner.next());
    ASSERT_EQ("rect", scanner.next());
    ASSERT_EQ(3, scanner.nextDouble());
    ASSERT_EQ(4, scanner.nextDouble());
    ASSERT_EQ("mixed", scanner.next());
    ASSERT_EQ("{", scanner.next());
    ASSERT_EQ("rect", scanner.next());
    ASSERT_EQ(2, scanner.nextDouble());
    ASSERT_EQ(2, scanner.nextDouble());
    ASSERT_EQ("tri", scanner.next());
    ASSERT_EQ(3, scanner.nextDouble());
    ASSERT_EQ(4, scanner.nextDouble());
    ASSERT_EQ(5, scanner.nextDouble());
    ASSERT_EQ("}", scanner.next());
    ASSERT_EQ("}", scanner.next());

    ASSERT_TRUE(scanner.isDone());


}
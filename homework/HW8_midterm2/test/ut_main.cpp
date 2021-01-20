#include <gtest/gtest.h>
#include "ut_iterator.h"
#include "ut_app.h"
#include "ut_utility.h"
#include "ut_folder.h"
#include "ut_node_scanner.h"
#include "ut_node_builder.h"
#include "ut_node_parser.h"
#include "ut_visitor.h"
int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv) ;
  return RUN_ALL_TESTS() ;
}

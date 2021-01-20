#include <gtest/gtest.h>
#include "ut_rectangle.h"
#include "ut_triangle.h"
#include "ut_sort.h"
#include "ut_mixed_shape.h"
#include "ut_iterator.h"
#include "ut_visitor.h"
#include "ut_string.h"
#include "ut_scanner.h"
#include "ut_shape_builder.h"
#include "ut_parser.h"
#include "ut_filter.h"

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

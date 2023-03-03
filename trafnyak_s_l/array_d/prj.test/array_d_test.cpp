#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <array_d/array_d.hpp>

TEST_CASE("[array_d] - array_d ctor") {
  CHECK(array_d(10).size() == 10);
  
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <array_d/array_d.hpp>

TEST_CASE("[array_d] - array_d ctor") {
//    CHECK(0==0);
  CHECK(array_d(10).size() == 10);
  CHECK(array_d(0).size() == 0);

  array_d test(10);
  test.resize(15);
  CHECK(test.size() == 15);

  CHECK_THROWS(test[-1]);
  CHECK_THROWS(test[20]);
}

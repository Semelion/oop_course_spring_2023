#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <arrayt/arrayt.hpp>

using arrayd = ArrayT<double>;

TEST_CASE("[arrayd] - arrayd ctor") {
//    CHECK(0==0);
  CHECK(arrayd(10).size() == 10);
  CHECK(arrayd(0).size() == 0);

  arrayd test(10);
  test.resize(15);
  CHECK(test.size() == 15);

  CHECK_THROWS(test[-1]);
  CHECK_THROWS(test[20]);
}
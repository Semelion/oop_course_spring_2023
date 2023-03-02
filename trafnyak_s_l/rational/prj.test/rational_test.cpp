#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <rational/rational.hpp>

TEST_CASE("[rational] - rational ctor") {
  CHECK(rational() == rational(0, 1));
  CHECK(rational(3) == rational(3, 1));
  CHECK(rational(-3) == rational(-3, 1));
  CHECK(rational(10, 6) == rational(5, 3));
  CHECK(rational(-10, 6) == rational(-5, 3));
  CHECK(rational(10, -6) == rational(-5, 3));
  CHECK(rational(-10, -6) == rational(5, 3));
  CHECK_THROWS(rational(1, 0));
}
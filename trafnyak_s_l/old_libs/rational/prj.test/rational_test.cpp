#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <rational/rational.hpp>

TEST_CASE("[rational] - rational ctor") {
  CHECK(rational() == rational(0, 1));
  CHECK(rational(3) == rational(3, 1));
  CHECK(rational(1) == rational(3, 3));
  CHECK(rational(-3) == rational(3, -1));
  CHECK(rational(-3) == rational(-3, 1));
  CHECK(rational(10, 6) == rational(5, 3));
  CHECK(rational(-10, 6) == rational(-5, 3));
  CHECK(rational(10, -6) == rational(-5, 3));
  CHECK(rational(-10, -6) == rational(5, 3));
  
  CHECK(rational(34,35) == (rational(2,5) + rational(4,7)));
  CHECK(rational(17,63) == (rational(5,9) - rational(2,7)));
  CHECK(rational(10,63) == (rational(5,9) * rational(2,7)));
  CHECK(rational(35,18) == (rational(5,9) / rational(2,7)));
  
  CHECK_THROWS(rational(5, 2) / rational(2,0));
  CHECK_THROWS(rational(1, 0));
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <arrayt/arrayt.hpp>

#include <cmath>

using arrayd = ArrayT<double>;

TEST_CASE("[arrayd] - arrayd ctor") {
//    CHECK(0==0);
  CHECK(arrayd(10).ssize() == 10);
  CHECK(arrayd(0).ssize() == 0);

  arrayd test(10);
  test.resize(15);
  CHECK(test.ssize() == 15);
  test.insert(3,1.0);
  CHECK(test[3] == 1.0);
  CHECK(test.ssize() == 16);


  CHECK_THROWS(test[-1]);
  test.resize(10);
  CHECK_THROWS(test[20]);
}

TEST_CASE("[arrayd] - arrayd2") {
  arrayd mass1(10);

  for(int i = 0; i < mass1.ssize(); i++){
    mass1[i] = std::pow(2, i);
  }

  arrayd mass2 = mass1;

  for(int i = 0; i < mass2.ssize(); i++){
    CHECK(mass1[i] == mass2[i]);
  }
}
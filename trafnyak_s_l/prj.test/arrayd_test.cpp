#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <arrayd/arrayd.hpp>

TEST_CASE("[arrayd] - arrayd ctor") {
//    CHECK(0==0);
  CHECK(arrayd(10).size() == 10);
  CHECK(arrayd(0).size() == 0);

  arrayd test(10);
  test.resize(15);
  CHECK(test.size() == 15);
  test.insert(3,1.0);
  CHECK(test[3] == 1.0);
  CHECK(test.size() == 16);


  CHECK_THROWS(test[-1]);
  test.resize(10);
  CHECK_THROWS(test[20]);
}

TEST_CASE("[arrayd] - arrayd2") {
  arrayd mass1(10);

  for(int i = 0; i < mass1.size(); i++){
    mass1[i] = std::pow(2, i);
  }

  arrayd mass2 = mass1;

  for(int i = 0; i < mass2.size(); i++){
    CHECK(mass1[i] == mass2[i]);
  }
}
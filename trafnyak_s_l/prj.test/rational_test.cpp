#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <rational/rational.hpp>

#include <sstream>

TEST_CASE("[rational] - rational ctor") {
  CHECK(rational() == rational(0, 1));
  CHECK(rational(3) == rational(3, 1));
  CHECK(rational(-3) == rational(-3, 1));
  CHECK(rational(10, 6) == rational(5, 3));
  CHECK(rational(-10, 6) == rational(-5, 3));
  CHECK(rational(10, -6) == rational(-5, 3));
  CHECK(rational(-10, -6) == rational(5, 3));
  CHECK_THROWS(rational(1, 0));
  rational r(-13,12);
  CHECK(r.numerator() == -13);
  CHECK(r.denomerator() == 12);
}

TEST_CASE("[rational] - rational add") {
  CHECK(rational(3, 2) + rational(5, 7) == rational(31, 14));
  CHECK(rational(5, 7) + rational(3, 2) == rational(31, 14));
  CHECK(rational() + rational() == rational());
  CHECK(rational() + rational(29, 41) == rational(29, 41));
  CHECK(rational(5, 1) + rational(3, 2) == rational(13, 2));
}

TEST_CASE("[rational] - rational subtract") {
  CHECK(rational(31, 14) - rational(5, 7) == rational(3, 2));
  CHECK(rational(25, 7) - rational(2, 9) == rational(211, 63));
  CHECK(rational(2, 3) - rational(7, 4) == rational(-13, 12));
}

TEST_CASE("[rational] - rational division") {
  CHECK(rational(5, 2) / rational(5, 2) == rational(1, 1));
  CHECK(rational(3, 2) / rational(9, 8) == rational(4, 3));
  CHECK_THROWS(rational(3, 2) / rational(5, 0));
}

TEST_CASE("[rational] - rational minus") {
  CHECK(-rational() == rational());
  CHECK(rational(-5, 3) == -rational(5, 3));
  CHECK(rational(25, 7) == -(-(rational(25, 7))));
  CHECK(rational(29, 41) == -rational(-29, 41));
}

TEST_CASE("[rational] - I/O") {

  SUBCASE("Output") {

    std::stringstream sstrm;

    SUBCASE("Simple") {
      sstrm << rational(23, 7);
      CHECK(sstrm.str() == "23/7");
    }

    sstrm.clear();

    SUBCASE("Default constructor") {
      sstrm << rational();
      CHECK(sstrm.str() == "0/1");
    }

    sstrm.clear();


    SUBCASE("Negative") {
      sstrm << -rational(3, 8);
      CHECK(sstrm.str() == "-3/8");
    }

    sstrm.clear();

    SUBCASE("Negative with reduce") {
      sstrm << rational(-8, 2);
      CHECK(sstrm.str() == "-4/1");
    }

  }

  SUBCASE("Correct inputs") {

    rational r;
    std::stringstream sstrm;

    SUBCASE("Simple") {
      sstrm.str("2/3");
      sstrm >> r;
      CHECK(sstrm.rdstate() == std::ios_base::eofbit);
      CHECK(r == rational(2, 3));
    }

    sstrm.clear();

    SUBCASE("Input with reducing") {
      sstrm.str("36/48");
      sstrm >> r;
      CHECK(sstrm.rdstate() == std::ios_base::eofbit);
      CHECK(r == rational(3, 4));
    }

    sstrm.clear();

    SUBCASE("Negative input") {
      sstrm.str("-8/7");
      sstrm >> r;
      CHECK(sstrm.rdstate() == std::ios_base::eofbit);
      CHECK(r == rational(-8, 7));
    }
  }

  SUBCASE("Correct inputs with extra spaces on begin and trash on end") {

    rational r;
    std::stringstream sstrm;

    SUBCASE("Extra spaces on begin") {
      sstrm.str(" 1/3");
      sstrm >> r;
      CHECK(sstrm.rdstate() == std::ios_base::eofbit);
      CHECK(r == rational(1, 3));
    }

    sstrm.clear();

    SUBCASE("Extra extra spaces on begin") {
      sstrm.str("   -3/4");
      sstrm >> r;
      CHECK(sstrm.rdstate() == std::ios_base::eofbit);
      CHECK(r == rational(-3, 4));
    }

    sstrm.clear();

    SUBCASE("Extra spaces on both ends") {
      sstrm.str(" 5/9  ");
      sstrm >> r;
      CHECK(sstrm.rdstate() == std::ios_base::goodbit);
      CHECK(r == rational(5, 9));
    }

    sstrm.clear();

    SUBCASE("Extra spaces on both ends and negative number") {
      sstrm.str(" -3/9  ");
      sstrm >> r;
      CHECK(sstrm.rdstate() == std::ios_base::goodbit);
      CHECK(r == rational(-1, 3));
    }

    sstrm.clear();

    SUBCASE("Extra spaces on begin and trash on end") {
      sstrm.str(" 23/9abc");
      sstrm >> r;
      CHECK(sstrm.rdstate() == std::ios_base::goodbit);
      CHECK(r == rational(23, 9));
    }

    sstrm.clear();

    SUBCASE("Extra spaces on end") {
      sstrm.str("3/7 ");
      sstrm >> r;
      CHECK(sstrm.rdstate() == std::ios_base::goodbit);
      CHECK(r == rational(3, 7));
    }

    sstrm.clear();

    SUBCASE("Trash on end") {
      sstrm.str("9/2&");
      sstrm >> r;
      CHECK(sstrm.rdstate() == std::ios_base::goodbit);
      CHECK(r == rational(9, 2));
    }
  }

  SUBCASE("Uncorrect inputs") {
    rational r;
    std::stringstream sstrm;

    SUBCASE("Trash") {
      sstrm.str("kek");
      sstrm >> r;
      CHECK(sstrm.fail());
      CHECK(!sstrm.bad());
    }

    sstrm.clear();

    SUBCASE("Bad delimiter") {
      sstrm.str("5\\3");
      sstrm >> r;
      CHECK(sstrm.fail());
      CHECK(!sstrm.bad());
    }

    sstrm.clear();

    SUBCASE("Numerator is trash") {
      sstrm.str("a/3");
      sstrm >> r;
      CHECK(sstrm.fail());
      CHECK(!sstrm.bad());
    }

    sstrm.clear();

    SUBCASE("Denominator is trash") {
      sstrm.str("3/*");
      sstrm >> r;
      CHECK(sstrm.fail());
      CHECK(!sstrm.bad());
    }

    sstrm.clear();

    SUBCASE("Spaces between 1") {
      sstrm.str("3 /2");
      sstrm >> r;
      CHECK(sstrm.fail());
      CHECK(!sstrm.bad());
    }

    sstrm.clear();

    SUBCASE("Spaces between 2") {
      sstrm.str("3/ 2");
      sstrm >> r;
      CHECK(sstrm.fail());
      CHECK(!sstrm.bad());
    }

    sstrm.clear();

    SUBCASE("Spaces between 3") {
      sstrm.str("3 / 2");
      sstrm >> r;
      CHECK(sstrm.fail());
      CHECK(!sstrm.bad());
    }

    sstrm.clear();

    SUBCASE("Denominator is negative") {
      sstrm.str("3/-2");
      sstrm >> r;
      CHECK(sstrm.fail());
      CHECK(!sstrm.bad());
    }

  }
}


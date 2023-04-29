// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include <doctest/doctest.h>

// #include <rational/rational.hpp>

// #include <sstream>

// TEST_CASE("[Rational] - Rational ctor") {
//   CHECK(Rational() == Rational(0, 1));
//   CHECK(Rational(3) == Rational(3, 1));
//   CHECK(Rational(-3) == Rational(-3, 1));
//   CHECK(Rational(10, 6) == Rational(5, 3));
//   CHECK(Rational(-10, 6) == Rational(-5, 3));
//   CHECK(Rational(10, -6) == Rational(-5, 3));
//   CHECK(Rational(-10, -6) == Rational(5, 3));
//   CHECK_THROWS(Rational(1, 0));
//   Rational r(-13,12);
//   CHECK(r.numerator() == -13);
//   CHECK(r.denomerator() == 12);
// }

// TEST_CASE("[Rational] - Rational add") {
//   CHECK(Rational(3, 2) + Rational(5, 7) == Rational(31, 14));
//   CHECK(Rational(5, 7) + Rational(3, 2) == Rational(31, 14));
//   CHECK(Rational() + Rational() == Rational());
//   CHECK(Rational() + Rational(29, 41) == Rational(29, 41));
//   CHECK(Rational(5, 1) + Rational(3, 2) == Rational(13, 2));
// }

// TEST_CASE("[Rational] - Rational subtract") {
//   CHECK(Rational(31, 14) - Rational(5, 7) == Rational(3, 2));
//   CHECK(Rational(25, 7) - Rational(2, 9) == Rational(211, 63));
//   CHECK(Rational(2, 3) - Rational(7, 4) == Rational(-13, 12));
// }

// TEST_CASE("[Rational] - Rational division") {
//   CHECK(Rational(5, 2) / Rational(5, 2) == Rational(1, 1));
//   CHECK(Rational(3, 2) / Rational(9, 8) == Rational(4, 3));
//   CHECK_THROWS(Rational(3, 2) / Rational(5, 0));
// }

// TEST_CASE("[Rational] - Rational minus") {
//   CHECK(-Rational() == Rational());
//   CHECK(Rational(-5, 3) == -Rational(5, 3));
//   CHECK(Rational(25, 7) == -(-(Rational(25, 7))));
//   CHECK(Rational(29, 41) == -Rational(-29, 41));
// }

// TEST_CASE("[Rational] - Rational with ints") {
//   CHECK(Rational() + 5 == Rational(5));
//   CHECK(Rational() + 5 == Rational(5, 1));
//   CHECK(Rational(1, 2) + 2 == Rational(5, 2));
//   CHECK(3 + Rational(3, 5) == Rational(18, 5));
// }

// TEST_CASE("[Rational] - I/O") {

//   SUBCASE("Output") {

//     std::stringstream sstrm;

//     SUBCASE("Simple") {
//       sstrm << Rational(23, 7);
//       CHECK(sstrm.str() == "23/7");
//     }

//     sstrm.clear();

//     SUBCASE("Default constructor") {
//       sstrm << Rational();
//       CHECK(sstrm.str() == "0/1");
//     }

//     sstrm.clear();


//     SUBCASE("Negative") {
//       sstrm << -Rational(3, 8);
//       CHECK(sstrm.str() == "-3/8");
//     }

//     sstrm.clear();

//     SUBCASE("Negative with reduce") {
//       sstrm << Rational(-8, 2);
//       CHECK(sstrm.str() == "-4/1");
//     }

//   }

//   SUBCASE("Correct inputs") {

//     Rational r;
//     std::stringstream sstrm;

//     SUBCASE("Simple") {
//       sstrm.str("2/3");
//       sstrm >> r;
//       CHECK(sstrm.rdstate() == std::ios_base::eofbit);
//       CHECK(r == Rational(2, 3));
//     }

//     sstrm.clear();

//     SUBCASE("Input with reducing") {
//       sstrm.str("36/48");
//       sstrm >> r;
//       CHECK(sstrm.rdstate() == std::ios_base::eofbit);
//       CHECK(r == Rational(3, 4));
//     }

//     sstrm.clear();

//     SUBCASE("Negative input") {
//       sstrm.str("-8/7");
//       sstrm >> r;
//       CHECK(sstrm.rdstate() == std::ios_base::eofbit);
//       CHECK(r == Rational(-8, 7));
//     }
//   }

//   SUBCASE("Correct inputs with extra spaces on begin and trash on end") {

//     Rational r;
//     std::stringstream sstrm;

//     SUBCASE("Extra spaces on begin") {
//       sstrm.str(" 1/3");
//       sstrm >> r;
//       CHECK(sstrm.rdstate() == std::ios_base::eofbit);
//       CHECK(r == Rational(1, 3));
//     }

//     sstrm.clear();

//     SUBCASE("Extra extra spaces on begin") {
//       sstrm.str("   -3/4");
//       sstrm >> r;
//       CHECK(sstrm.rdstate() == std::ios_base::eofbit);
//       CHECK(r == Rational(-3, 4));
//     }

//     sstrm.clear();

//     SUBCASE("Extra spaces on both ends") {
//       sstrm.str(" 5/9  ");
//       sstrm >> r;
//       CHECK(sstrm.rdstate() == std::ios_base::goodbit);
//       CHECK(r == Rational(5, 9));
//     }

//     sstrm.clear();

//     SUBCASE("Extra spaces on both ends and negative number") {
//       sstrm.str(" -3/9  ");
//       sstrm >> r;
//       CHECK(sstrm.rdstate() == std::ios_base::goodbit);
//       CHECK(r == Rational(-1, 3));
//     }

//     sstrm.clear();

//     SUBCASE("Extra spaces on begin and trash on end") {
//       sstrm.str(" 23/9abc");
//       sstrm >> r;
//       CHECK(sstrm.rdstate() == std::ios_base::goodbit);
//       CHECK(r == Rational(23, 9));
//     }

//     sstrm.clear();

//     SUBCASE("Extra spaces on end") {
//       sstrm.str("3/7 ");
//       sstrm >> r;
//       CHECK(sstrm.rdstate() == std::ios_base::goodbit);
//       CHECK(r == Rational(3, 7));
//     }

//     sstrm.clear();

//     SUBCASE("Trash on end") {
//       sstrm.str("9/2&");
//       sstrm >> r;
//       CHECK(sstrm.rdstate() == std::ios_base::goodbit);
//       CHECK(r == Rational(9, 2));
//     }
//   }

//   SUBCASE("Uncorrect inputs") {
//     Rational r;
//     std::stringstream sstrm;

//     SUBCASE("Trash") {
//       sstrm.str("kek");
//       sstrm >> r;
//       CHECK(sstrm.fail());
//       CHECK(!sstrm.bad());
//     }

//     sstrm.clear();

//     SUBCASE("Bad delimiter") {
//       sstrm.str("5\\3");
//       sstrm >> r;
//       CHECK(sstrm.fail());
//       CHECK(!sstrm.bad());
//     }

//     sstrm.clear();

//     SUBCASE("Numerator is trash") {
//       sstrm.str("a/3");
//       sstrm >> r;
//       CHECK(sstrm.fail());
//       CHECK(!sstrm.bad());
//     }

//     sstrm.clear();

//     SUBCASE("Denominator is trash") {
//       sstrm.str("3/*");
//       sstrm >> r;
//       CHECK(sstrm.fail());
//       CHECK(!sstrm.bad());
//     }

//     sstrm.clear();

//     SUBCASE("Spaces between 1") {
//       sstrm.str("3 /2");
//       sstrm >> r;
//       CHECK(sstrm.fail());
//       CHECK(!sstrm.bad());
//     }

//     sstrm.clear();

//     SUBCASE("Spaces between 2") {
//       sstrm.str("3/ 2");
//       sstrm >> r;
//       CHECK(sstrm.fail());
//       CHECK(!sstrm.bad());
//     }

//     sstrm.clear();

//     SUBCASE("Spaces between 3") {
//       sstrm.str("3 / 2");
//       sstrm >> r;
//       CHECK(sstrm.fail());
//       CHECK(!sstrm.bad());
//     }

//     sstrm.clear();

//     SUBCASE("Denominator is negative") {
//       sstrm.str("3/-2");
//       sstrm >> r;
//       CHECK(sstrm.fail());
//       CHECK(!sstrm.bad());
//     }

//   }
// }



#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <rational/rational.hpp>
#include <sstream>

TEST_CASE("[Rational] - Rational ctor") {
  CHECK(Rational() == Rational(0, 1));
  CHECK(Rational(3) == Rational(3, 1));
  CHECK(Rational(-3) == Rational(-3, 1));
  CHECK(Rational(10, 6) == Rational(5, 3));
  CHECK(Rational(-10, 6) == Rational(-5, 3));
  CHECK(Rational(10, -6) == Rational(-5, 3));
  CHECK(Rational(-10, -6) == Rational(5, 3));
  CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("addsub"){
  CHECK((Rational(1, 2) + Rational(1, 2)) == Rational(1, 1));
  CHECK((Rational(11, 3) + Rational(1, 2)) == Rational(25, 6));
  CHECK((Rational(-8, 3) + Rational(1, 5)) == Rational(-37, 15));
  CHECK((Rational(13, 5) - Rational(1, 2)) == Rational(21, 10));
}

TEST_CASE("multdiv"){
  CHECK((Rational(14, 36) * Rational(81, 193)) == Rational(63, 386));
  CHECK((Rational(13, 36) * Rational(0, 193)) == Rational(0, 1));
  CHECK_THROWS(Rational(64, 95)/Rational(0,0));
}

TEST_CASE("outinput"){
  Rational output_obj = Rational(1,2);
  std::stringstream out;
  std::stringstream out1;
  out << output_obj;
  CHECK((out1 << output_obj).good());
  CHECK(out.str() == "1/2");
}

TEST_CASE("lessmore"){
  CHECK(Rational(1,2) > Rational(1, 4));
  CHECK(Rational(-1, 2) < Rational(1, 6));
}

TEST_CASE("[rational] - Rational add") {
    CHECK(Rational(3, 2) + Rational(5, 7) == Rational(31, 14));
    CHECK(Rational(5, 7) + Rational(3, 2) == Rational(31, 14));
    CHECK(Rational() + Rational() == Rational());
    CHECK((Rational(0, 1) + Rational(29, 41)) == Rational(29, 41));
    CHECK(Rational(5, 1) + Rational(3, 2) == Rational(13, 2));
}

TEST_CASE("[rational] - Rational subtract") {
    CHECK(Rational(31, 14) - Rational(5, 7) == Rational(3, 2));
    CHECK(Rational(25, 7) - Rational(2, 9) == Rational(211, 63));
    CHECK(Rational(2, 3) - Rational(7, 4) == Rational(-13, 12));
}

TEST_CASE("[rational] - Rational division") {
    CHECK(Rational(5, 2) / Rational(5, 2) == Rational(1, 1));
    CHECK(Rational(3, 2) / Rational(9, 8) == Rational(4, 3));
    CHECK_THROWS(Rational(3, 2) / Rational(5, 0));
}

TEST_CASE("[rational] - Rational minus") {
    CHECK(-Rational() == Rational());
    CHECK(Rational(-5, 3) == -Rational(5, 3));
    CHECK(Rational(25, 7) == -(-(Rational(25, 7))));
    CHECK(Rational(29, 41) == -Rational(-29, 41));
}

TEST_CASE("[rational] - I/O") {

    SUBCASE("Output") {

        std::stringstream sstrm;

        SUBCASE("Simple") {
            sstrm << Rational(23, 7);
            CHECK(sstrm.str() == "23/7");
        }

        sstrm.clear();

        SUBCASE("Default constructor") {
            sstrm << Rational();
            CHECK(sstrm.str() == "0/1");
        }

        sstrm.clear();


        SUBCASE("Negative") {
            sstrm << -Rational(3, 8);
            CHECK(sstrm.str() == "-3/8");
        }

        sstrm.clear();

        SUBCASE("Negative with reduce") {
            sstrm << Rational(-8, 2);
            CHECK(sstrm.str() == "-4/1");
        }

    }

    SUBCASE("Correct inputs") {

        Rational r;
        std::stringstream sstrm;

        SUBCASE("Simple") {
            sstrm.str("2/3");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(2, 3));
        }

        sstrm.clear();

        SUBCASE("Input with reducing") {
            sstrm.str("36/48");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(3, 4));
        }

        sstrm.clear();

        SUBCASE("Negative input") {
            sstrm.str("-8/7");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(-8, 7));
        }
    }

    SUBCASE("Correct inputs with extra spaces on begin and trash on end") {

        Rational r;
        std::stringstream sstrm;

        SUBCASE("Extra spaces on begin") {
            sstrm.str(" 1/3");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(1, 3));
        }

        sstrm.clear();

        SUBCASE("Extra extra spaces on begin") {
            sstrm.str("   -3/4");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(-3, 4));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on both ends") {
            sstrm.str(" 5/9  ");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(5, 9));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on both ends and negative number") {
            sstrm.str(" -3/9  ");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(-1, 3));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on begin and trash on end") {
            sstrm.str(" 23/9abc");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(23, 9));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on end") {
            sstrm.str("3/7 ");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(3, 7));
        }

        sstrm.clear();

        SUBCASE("Trash on end") {
            sstrm.str("9/2&");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(9, 2));
        }
    }

    SUBCASE("Uncorrect inputs") {
        Rational r;
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

TEST_CASE("[Rational] - operator bool()") {
    Rational r;
    CHECK(!r);
    r = {1,1};
    CHECK(r);
}
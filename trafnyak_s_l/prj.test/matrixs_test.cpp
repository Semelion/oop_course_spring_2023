#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <matrixs/matrixs.hpp>
#include <iostream>

TEST_CASE("MatrixS default constructor creates matrix of size 0x0") {
	MatrixS mat();
	//std::cout << mat.nRows() << "\n";
	// CHECK(mat.nRows() == 0);
	// CHECK(mat.nCols() == 0);
}

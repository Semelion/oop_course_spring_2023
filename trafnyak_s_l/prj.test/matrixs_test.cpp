#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <matrixs/matrixs.hpp>

TEST_CASE("MatrixS default constructor creates matrix of size 0x0") {
MatrixS mat;
CHECK(mat.nRows() == 0);
CHECK(mat.nCols() == 0);
}

TEST_CASE("MatrixS constructor with SizeType creates matrix of correct size") {
MatrixS::SizeType size{ 2, 3 };
MatrixS mat(size);
CHECK(mat.nRows() == 2);
CHECK(mat.nCols() == 3);
}

TEST_CASE("MatrixS constructor with m, n creates matrix of correct size") {
MatrixS mat(2, 3);
CHECK(mat.nRows() == 2);
CHECK(mat.nCols() == 3);
}

TEST_CASE("MatrixS copy constructor creates a new matrix with identical values") {
MatrixS mat1(2, 3);
mat1.at(0, 0) = 1;
MatrixS mat2(mat1);
CHECK(mat2.nRows() == 2);
CHECK(mat2.nCols() == 3);
CHECK(mat2.at(0, 0) == 1);
}

TEST_CASE("MatrixS copy assignment creates a new matrix with identical values") {
MatrixS mat1(2, 3);
mat1.at(0, 0) = 1;
MatrixS mat2 = mat1;
CHECK(mat2.nRows() == 2);
CHECK(mat2.nCols() == 3);
CHECK(mat2.at(0, 0) == 1);
}

TEST_CASE("MatrixS operator[] returns correct element by reference") {
MatrixS mat(2, 3);
mat.at(0, 1) = 2;
mat[std::make_tuple(0, 1)] = 3;
CHECK(mat.at(0, 1) == 3);
}

TEST_CASE("MatrixS operator[] const returns correct element by const reference") {
MatrixS mat(2, 3);
mat.at(0, 1) = 2;
const MatrixS& constMat = mat;
CHECK(constMat[std::make_tuple(0, 1)] == 2);
}

TEST_CASE("MatrixS operator+ adds matrices element-wise") {
MatrixS mat1(2, 3);
mat1.at(0, 0) = 1;
mat1.at(0, 1) = 2;
mat1.at(1, 0) = 3;
mat1.at(1, 1) = 4;

MatrixS mat2(2, 3);
mat2.at(0, 0) = 1;
mat2.at(0, 1) = 2;
mat2.at(1, 0) = 3;
mat2.at(1, 1) = 4;

MatrixS mat3 = mat1 + mat2;
CHECK(mat3.at(0, 0) == 2);
CHECK(mat3.at(0, 1) == 4);
CHECK(mat3.at(1, 0) == 6);
CHECK(mat3.at(1, 1) == 8);
}
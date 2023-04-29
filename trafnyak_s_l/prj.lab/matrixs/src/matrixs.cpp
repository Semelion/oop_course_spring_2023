#include <matrixs/matrixs.hpp>
#include <iostream>
#include <cmath>
#include <vector>

MatrixS::MatrixS(){
    rows_ = 0;
    cols_ = 0;
    data_ = nullptr;
    size_ = 0;
}

MatrixS::MatrixS(const SizeType& size) : rows_{ std::get<0>(size) }, cols_{ std::get<1>(size) }, data_(nullptr) {
    if (rows_ <= 0 || cols_ <= 0) {
        throw std::invalid_argument("Sizes must be positive");
    }
    size_ = rows_ + rows_ * cols_;
    data_ = new int[size_];
    for (std::ptrdiff_t i = 0; i < rows_; ++i) {
        data_[i] = rows_ + i * cols_;
    }
    for (std::ptrdiff_t i = rows_; i < size_; ++i) {
        data_[i] = 0;
    }
}

MatrixS::MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n) : rows_{ m }, cols_{ n }, data_(nullptr) {
    if (rows_ <= 0 || cols_ <= 0) {
        throw std::invalid_argument("Sizes must be positive");
    }
    data_ = new int[size_];
    for (std::ptrdiff_t i = 0; i < rows_; ++i) {
        data_[i] = rows_ + i * cols_;
    }
    for (std::ptrdiff_t i = rows_; i < size_; ++i) {
        data_[i] = 0;
    }
}

MatrixS::MatrixS(const MatrixS& other) : rows_{ other.rows_ }, cols_{ other.cols_ }, size_{other.size_}, data_(nullptr) {
    if (this == &other) {
        return;
    }
    data_ = new int[size_];
    std::copy(other.data_, other.data_ + rows_ * cols_, data_);
}

MatrixS::~MatrixS() {
    delete[] data_;
}

MatrixS& MatrixS::operator=(const MatrixS& other)
    {
        if (this == &other) {
            return *this;
        }
        rows_ = other.rows_;
        cols_ = other.cols_;
        size_ = other.size_;
        if (data_ != nullptr) {
            delete[] data_;
        }
        data_ = new int[size_];
        for (std::ptrdiff_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
        return *this;
    }


const int& MatrixS::at(const std::ptrdiff_t row, const std::ptrdiff_t col) const {
    if (row >= rows_ || data_[row] + col >= size_ || row < 0 || data_[row] + col < 0) {
        throw std::out_of_range("Wrong position");
    }
    return data_[data_[row] + col]; //это указатель на начало строки матрицы с индексом row
}

int& MatrixS::at(const std::ptrdiff_t row, const std::ptrdiff_t col) {
    if (row >= rows_ || data_[row] + col >= size_ || row < 0 || data_[row] + col < 0) {
        throw std::out_of_range("Wrong position");
    }
    return data_[data_[row] + col];
}

const int& MatrixS::at(const MatrixS::SizeType s) const{
    if (std::get<0>(s) >= rows_ || data_[std::get<0>(s)] + std::get<1>(s) >= size_ || std::get<0>(s) < 0 || data_[std::get<0>(s)] + std::get<1>(s) < 0) {
        throw std::out_of_range("Wrong position");
    }
    return data_[data_[std::get<0>(s)] + std::get<1>(s)];
}

int& MatrixS::at(const MatrixS::SizeType s) {
    if (std::get<0>(s) >= rows_ || data_[std::get<0>(s)] + std::get<1>(s) >= size_ || std::get<0>(s) < 0 || data_[std::get<0>(s)] + std::get<1>(s) < 0) {
        throw std::out_of_range("Wrong position");
    }
    return data_[data_[std::get<0>(s)] + std::get<1>(s)];
}



void MatrixS::resize(const std::ptrdiff_t row, const std::ptrdiff_t col)
{
    if (row <= 0 || col <= 0) {
        throw std::invalid_argument("Sizes must be positive");
    }
    MatrixS newMatrix(row, col);
    for (std::ptrdiff_t r = 0; r < row; ++r) {
        for (std::ptrdiff_t c = 0; c < col; ++c) {
            if (rows_ <= r || cols_ <= c) {
                newMatrix.at(SizeType(r, c)) = 0;
            }
            else {
                newMatrix.at(SizeType(r, c)) = at(SizeType(r, c));
            }
        }
    }
    *this = newMatrix;
}
void MatrixS::resize(const SizeType& s)
{
    if (std::get<0>(s) <= 0 || std::get<1>(s) <= 0) {
        throw std::invalid_argument("Sizes must be positive");
    }
    MatrixS newMatrix(std::get<0>(s), std::get<1>(s));
    for (std::ptrdiff_t r = 0; r < std::get<0>(s); ++r) {
        for (std::ptrdiff_t c = 0; c < std::get<1>(s); ++c) {
            if (rows_ <= r || cols_ <= c) {
                newMatrix.at(SizeType(r, c)) = 0;
            }
            else {
                newMatrix.at(SizeType(r, c)) = at(SizeType(r, c));
            }
        }
    }
    *this = newMatrix;
}

const MatrixS::SizeType &MatrixS::ssize() const noexcept{
    return SizeType(rows_, cols_);
}
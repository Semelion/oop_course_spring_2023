#ifndef LIB_MATRIXS_HPP
#define LIB_MATRIXS_HPP
#include <cstddef>
#include <tuple>
#include <utility>

class MatrixS {
public:
    using SizeType = std::tuple<std::ptrdiff_t, std::ptrdiff_t>;

public:
    ptrdiff_t rows_;
    ptrdiff_t cols_;
    int* data_;
    ptrdiff_t size_;

public:
    MatrixS();
    explicit MatrixS(const SizeType &size = {0, 0});
    MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n);
    ~MatrixS();

    MatrixS(const MatrixS &other);
    MatrixS& operator=(const MatrixS& other);

    void resize(const SizeType &new_size);
    void resize(const std::ptrdiff_t i, const std::ptrdiff_t j);

    [[nodiscard]] const int& at(const std::ptrdiff_t, const std::ptrdiff_t) const;
    [[nodiscard]] int& at(const std::ptrdiff_t, const std::ptrdiff_t);
    [[nodiscard]] const int& at(const SizeType) const;
    [[nodiscard]] int& at(const SizeType);

    [[nodiscard]] const SizeType& ssize() const noexcept;
    [[nodiscard]] std::ptrdiff_t nRows() const noexcept;
    [[nodiscard]] std::ptrdiff_t nCols() const noexcept;

};

#endif //LIB_MATRIXS_HPP
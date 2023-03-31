#ifndef ARRAY_D_LIBRARY_H
#define ARRAY_D_LIBRARY_H

#include <cstddef>
#include <iosfwd>
#include <array>


class array_d{
public:
    array_d() = default;
    explicit array_d(const std::ptrdiff_t size);
    array_d(const array_d& rhs);
    array_d& operator= (const array_d& rhs);
    ~array_d();

    double& operator[] (const std::ptrdiff_t i);
    const double& operator[] (const std::ptrdiff_t i) const;
    void resize (const std::ptrdiff_t size);
    [[nodiscard]] std::ptrdiff_t size() const { return size_; };
    [[nodiscard]] std::ptrdiff_t capacity() const { return capacity_; };
    void insert (const std::ptrdiff_t index, const double value);
    void remove (const std::ptrdiff_t index, const double value);

private:
    ptrdiff_t size_ = 0;
    ptrdiff_t capacity_ = 0;
    double* data_ = nullptr;
};

#endif //ARRAY_D_LIBRARY_H

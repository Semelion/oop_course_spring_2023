#ifndef ARRAYD_LIBRARY_H
#define ARRAYD_LIBRARY_H

#include <cstddef>
#include <iosfwd>
#include <array>


class arrayd{
public:
    arrayd() = default;
    explicit arrayd(const std::ptrdiff_t size);
    arrayd(const arrayd& rhs);
    arrayd& operator= (const arrayd& rhs);
    ~arrayd();

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

#endif //ARRAYD_LIBRARY_H

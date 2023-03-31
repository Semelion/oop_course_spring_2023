#ifndef ARRAY_T_LIBRARY_H
#define ARRAY_T_LIBRARY_H

#include <cstddef>
#include <iosfwd>
#include <array>

template <typename T>

class array_t{
    T* data_;
public:
    array_t() = default;
    explicit array_t(const std::ptrdiff_t size);
    array_t(const array_t& rhs);
    array_t& operator= (const array_t& rhs);
    ~array_t();

    T& operator[] (const std::ptrdiff_t i);
    const T& operator[] (const std::ptrdiff_t i) const;
    void resize (const std::ptrdiff_t size);
    [[nodiscard]] std::ptrdiff_t size() const { return size_; };
    [[nodiscard]] std::ptrdiff_t capacity() const { return capacity_; };
    void insert (const std::ptrdiff_t index, const T value);
    void remove (const std::ptrdiff_t index, const T value);

private:
    ptrdiff_t size_ = 0;
    ptrdiff_t capacity_ = 0;
    T* data_ = nullptr;
};

#endif //ARRAY_D_LIBRARY_H

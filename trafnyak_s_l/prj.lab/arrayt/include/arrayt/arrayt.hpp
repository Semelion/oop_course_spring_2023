#ifndef ARRAYT_LIBRARY_H
#define ARRAYT_LIBRARY_H

#include <cstddef>
#include <iosfwd>
#include <array>
#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayT{
public:
    ArrayT() = default;
    explicit ArrayT(const std::ptrdiff_t size);
    ArrayT(const ArrayT& rhs);
    ArrayT& operator= (const ArrayT& rhs);
    ~ArrayT();

    T& operator[] (const std::ptrdiff_t i);
    const T& operator[] (const std::ptrdiff_t i) const;
    void resize (const std::ptrdiff_t size);
    [[nodiscard]] std::ptrdiff_t ssize() const { return size_; };
    [[nodiscard]] std::ptrdiff_t capacity() const { return capacity_; };
    void insert (const std::ptrdiff_t index, const T value);
    void remove (const std::ptrdiff_t index, const T value);

 private:
    ptrdiff_t size_ = 0;
    ptrdiff_t capacity_ = 0;
    T* data_ = nullptr;
};

///////////////////////

template<typename T>
ArrayT<T>::ArrayT(const ArrayT& rhs){
    size_ = rhs.ssize();
    capacity_ = rhs.capacity();
    data_ = new T [capacity_];
    for (size_t i = 0; i < ssize(); i++)
        *(data_ + i) = *(rhs.data_ + i);
}

template<typename T>
ArrayT<T>::~ArrayT(){
    delete[] data_;
}

template <typename T>
ArrayT<T>& ArrayT<T>::operator= (const ArrayT<T>& rhs){
    if(this == &rhs){
        return *this;
    }
    if (capacity_ >= rhs.ssize())
        size_ = rhs.size_;
    else
    {
        capacity_ = 2 * rhs.ssize() + 1;
        size_ = rhs.ssize();
        data_ = new T [capacity_];
    }
    for (std::ptrdiff_t i = 0; i < size_; i++)
    {
        *(data_ + i) = *(rhs.data_ + i);
    }
    return *this;
}

template <typename T>
ArrayT<T>::ArrayT(const std::ptrdiff_t size){
    if (size < 0)
        throw std::logic_error ("size is negative");
    capacity_ = 2 * size + 1;
    size_ = size;
    data_ = new T [capacity_];
    for (std::ptrdiff_t i = 0; i < size_; i++)
        *(data_ + i) = 0.0f;
}

template<typename T>
T& ArrayT<T>::operator[] (const std::ptrdiff_t i){
    if (i < 0 || i >= ssize())
        throw std::out_of_range("Wrong Index");
    return *(data_ + i);
}

template<typename T>
const T& ArrayT<T>::operator[] (const std::ptrdiff_t i) const{
    if (i < 0 || i >= ssize())
        throw std::out_of_range("Wrong Index");
    return *(data_ + i);
}

template<typename T>
void ArrayT<T>::resize(const std::ptrdiff_t size){
    if (size <= 0)
        throw std::logic_error("size isn't normal");
    if (size > capacity_){
        capacity_ = 2 * size + 1;
        T* temp = new T[capacity_];
        for (std::ptrdiff_t i = 0; i < size_; i++)
            *(temp + i) = *(data_+ i);
        data_ = temp;
    }
//    std::fill
    for (std::ptrdiff_t i = size_; i < size; i++)
        *(data_ + i) = 0;
    size_ = size;
}

template<typename T>
void ArrayT<T>::insert(const std::ptrdiff_t index, const T value) {
    if (index < 0 || index >= size_)
        throw std::out_of_range("Wrong Index");
    this ->resize(size_ + 1);
    for(std::ptrdiff_t i = size_ - 1; i > index; i--){
        *(data_ + i) = *(data_ + i - 1);
    }
    *(data_ + index) = value;
}

template<typename T>
void ArrayT<T>::remove(const std::ptrdiff_t index, const T value) {
    if (index < 0 || index >= size_)
        throw std::out_of_range("Wrong Index");
    for(std::ptrdiff_t i = index; i < size_ - 1; i++){
        *(data_ + i) = *(data_ + i + 1);
    }
    *(data_ + index) = value;
    this ->resize(size_ - 1);
}

//////////////////////////
#endif //ARRAY_D_LIBRARY_H



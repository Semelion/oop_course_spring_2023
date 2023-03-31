#include "../include/array_t/array_t.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>

//int main(){
//    array_t test(15);
//    test.resize(10);
//    for(int i = 0; i < 10; i++){
//        test[i] = i;
//    }
//    test.insert(2,32);
//    for(int i = 0; i < test.size(); i++){
//        std::cout << test[i] << " ";
//    }
//}

array_t::array_t(const array_t& rhs){
    size_ = rhs.size();
    capacity_ = rhs.capacity();
    data_ = new T [capacity_];
    for (size_t i = 0; i < size(); i++)
        *(data_ + i) = *(rhs.data_ + i);
}
array_t::~array_t(){
    delete[] data_;
}
array_t& array_t::operator= (const array_t& rhs){
    if(this == &rhs){
        return *this;
    }
    if (capacity_ >= rhs.size())
        size_ = rhs.size_;
    else
    {
        capacity_ = 2 * rhs.size() + 1;
        size_ = rhs.size();
        data_ = new T [capacity_];
    }
    for (std::ptrdiff_t i = 0; i < size_; i++)
    {
        *(data_ + i) = *(rhs.data_ + i);
    }
    return *this;
}
array_t::array_t(const std::ptrdiff_t size){
    if (size < 0)
        throw std::logic_error ("size is negative");
    capacity_ = 2 * size + 1;
    size_ = size;
    data_ = new T [capacity_];
    for (std::ptrdiff_t i = 0; i < size_; i++)
        *(data_ + i) = 0.0f;
}
void array_t::resize(const std::ptrdiff_t size){
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
        *(data_ + i) = 0.0f;
    size_ = size;
}
T& array_t::operator[] (const std::ptrdiff_t i){
    if (i < 0 || i >= size())
        throw std::out_of_range("Wrong Index");
    return *(data_ + i);
}
const T& array_t::operator[] (const std::ptrdiff_t i) const{
    if (i < 0 || i >= size())
        throw std::out_of_range("Wrong Index");
    return *(data_ + i);

}

void array_t::insert(const std::ptrdiff_t index, const T value) {
    if (index < 0 || index >= size_)
        throw std::out_of_range("Wrong Index");
    this ->resize(size_ + 1);
    for(std::ptrdiff_t i = size_ - 1; i > index; i--){
        *(data_ + i) = *(data_ + i - 1);
    }
    *(data_ + index) = value;
}

void array_t::remove(const std::ptrdiff_t index, const T value) {
    if (index < 0 || index >= size_)
        throw std::out_of_range("Wrong Index");
    for(std::ptrdiff_t i = index; i < size_ - 1; i++){
        *(data_ + i) = *(data_ + i + 1);
    }
    *(data_ + index) = value;
    this ->resize(size_ - 1);
}


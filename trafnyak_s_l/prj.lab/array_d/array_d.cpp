#include "include/array_d/array_d.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>

//int main(){
//    array_d test(15);
//    test.resize(10);
//    for(int i = 0; i < 10; i++){
//        test[i] = i;
//    }
//    test.insert(2,32);
//    for(int i = 0; i < test.size(); i++){
//        std::cout << test[i] << " ";
//    }
//}

array_d::array_d(const array_d& rhs){
    size_ = rhs.size();
    capacity_ = rhs.capacity();
    data_ = new double [capacity_];
    for (size_t i = 0; i < size(); i++)
        *(data_ + i) = *(rhs.data_ + i);
}
array_d::~array_d(){
    delete[] data_;
}
array_d& array_d::operator= (const array_d& rhs){
    if(this == &rhs){
        return *this;
    }
    if (capacity_ >= rhs.size())
        size_ = rhs.size_;
    else
    {
        capacity_ = 2 * rhs.size() + 1;
        size_ = rhs.size();
        data_ = new double [capacity_];
    }
    for (std::ptrdiff_t i = 0; i < size_; i++)
    {
        *(data_ + i) = *(rhs.data_ + i);
    }
    return *this;
}
array_d::array_d(const std::ptrdiff_t size){
    if (size < 0)
        throw std::logic_error ("size is negative");
    capacity_ = 2 * size + 1;
    size_ = size;
    data_ = new double [capacity_];
    for (std::ptrdiff_t i = 0; i < size_; i++)
        *(data_ + i) = 0.0f;
}
void array_d::resize(const std::ptrdiff_t size)
{
    if (size <= 0)
        throw std::logic_error("size isn't normal");
    if (size > capacity_){
        capacity_ = 2 * size + 1;
        double* temp = new double[capacity_];
        for (std::ptrdiff_t i = 0; i < size_; i++)
            *(temp + i) = *(data_+ i);
        data_ = temp;
    }
//    std::fill
    for (std::ptrdiff_t i = size_; i < size; i++)
        *(data_ + i) = 0.0f;
    size_ = size;
}
double& array_d::operator[] (const std::ptrdiff_t i)
{
    if (i < 0 || i >= size())
        throw std::out_of_range("Wrong Index");
    return *(data_ + i);
}
const double& array_d::operator[] (const std::ptrdiff_t i) const
{
    if (i < 0 || i >= size())
        throw std::out_of_range("Wrong Index");
    return *(data_ + i);

}

void array_d::insert(const std::ptrdiff_t index, const double value) {
    if (index < 0 || index >= size_)
        throw std::out_of_range("Wrong Index");
    this ->resize(size_ + 1);
    for(std::ptrdiff_t i = size_ - 1; i > index; i--){
        *(data_ + i) = *(data_ + i - 1);
    }
    *(data_ + index) = value;
}

void array_d::remove(const std::ptrdiff_t index, const double value) {
    if (index < 0 || index >= size_)
        throw std::out_of_range("Wrong Index");
    for(std::ptrdiff_t i = index; i < size_ - 1; i++){
        *(data_ + i) = *(data_ + i + 1);
    }
    *(data_ + index) = value;
    this ->resize(size() - 1);
}


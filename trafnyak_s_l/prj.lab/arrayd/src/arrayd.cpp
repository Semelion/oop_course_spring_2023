#include <../include/arrayd/arrayd.hpp>
#include <algorithm>
#include <iostream>
#include <stdexcept>

//int main(){
//    ArrayD test(15);
//    test.resize(10);
//    for(int i = 0; i < 10; i++){
//        test[i] = i;
//    }
//    test.insert(2,32);
//    for(int i = 0; i < test.size(); i++){
//        std::cout << test[i] << " ";
//    }
//}

ArrayD::ArrayD(const ArrayD& rhs){
    size_ = rhs.ssize();
    capacity_ = rhs.capacity();
    data_ = new double [capacity_];
    for (size_t i = 0; i < ssize(); i++)
        *(data_ + i) = *(rhs.data_ + i);
}
ArrayD::~ArrayD(){
    delete[] data_;
}
ArrayD& ArrayD::operator= (const ArrayD& rhs){
    if(this == &rhs){
        return *this;
    }
    if (capacity_ >= rhs.ssize())
        size_ = rhs.size_;
    else
    {
        capacity_ = 2 * rhs.ssize() + 1;
        size_ = rhs.ssize();
        data_ = new double [capacity_];
    }
    for (std::ptrdiff_t i = 0; i < size_; i++)
    {
        *(data_ + i) = *(rhs.data_ + i);
    }
    return *this;
}
ArrayD::ArrayD(const std::ptrdiff_t size){
    if (size < 0)
        throw std::logic_error ("size is negative");
    capacity_ = 2 * size + 1;
    size_ = size;
    data_ = new double [capacity_];
    for (std::ptrdiff_t i = 0; i < size_; i++)
        *(data_ + i) = 0.0f;
}
void ArrayD::resize(const std::ptrdiff_t size)
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
double& ArrayD::operator[] (const std::ptrdiff_t i)
{
    if (i < 0 || i >= ssize())
        throw std::out_of_range("Wrong Index");
    return *(data_ + i);
}
const double& ArrayD::operator[] (const std::ptrdiff_t i) const
{
    if (i < 0 || i >= ssize())
        throw std::out_of_range("Wrong Index");
    return *(data_ + i);

}

void ArrayD::insert(const std::ptrdiff_t index, const double value) {
    if (index < 0 || index >= size_)
        throw std::out_of_range("Wrong Index");
    this ->resize(size_ + 1);
    for(std::ptrdiff_t i = size_ - 1; i > index; i--){
        *(data_ + i) = *(data_ + i - 1);
    }
    *(data_ + index) = value;
}

void ArrayD::remove(const std::ptrdiff_t index, const double value) {
    if (index < 0 || index >= size_)
        throw std::out_of_range("Wrong Index");
    for(std::ptrdiff_t i = index; i < size_ - 1; i++){
        *(data_ + i) = *(data_ + i + 1);
    }
    *(data_ + index) = value;
    this ->resize(ssize() - 1);
}


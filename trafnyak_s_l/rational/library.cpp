#include "library.h"
#include <string>
#include <stdexcept>

int main() {
    rational in;
    std::cin >> in;
    rational num = {1, 4};
    in += num;
    num = rational(1, 2) + rational(3, 8);
    std::cout << in << "_____" << num << "\n";
    return 0;
}

int32_t rational::NOD(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == b || a == 0) {
        return b;
    }
    if (a > b) {
        return NOD(a - b, b);
    }
    return NOD(a, b - a);
}

std::ostream &operator<<(std::ostream &ostrm, const rational &rhs) noexcept {
    return rhs.write_to(ostrm);
}

std::ostream &rational::write_to(std::ostream &ostrm) const noexcept {
    ostrm << numerator_ << "/" << denominator_;
    return ostrm;
}


std::istream &operator>>(std::istream &istrm, rational &rhs) noexcept {
    return rhs.read_from(istrm);
}

std::istream& rational::read_from(std::istream& istrm) noexcept
{
    int32_t num1 = 0;
    char slash = 0;
    int32_t denum1 = 1;
    istrm >> num1;
    istrm.get(slash);
    int32_t trash = istrm.peek();
    istrm >> denum1;
    if (!istrm || trash > '9' || trash < '0') {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }
    if (istrm.good() || istrm.eof()) {
        if ('/' == slash && denum1 > 0) {
            *this = rational(num1, denum1);
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}


bool rational::operator==(const rational &rhs) const noexcept {
    return (numerator_ == rhs.numerator()) && (denominator_ == rhs.denomerator());
}

bool rational::operator!=(const rational &rhs) const noexcept {
    return (numerator_ != rhs.numerator()) || (denominator_ != rhs.denomerator());
}

bool rational::operator>(const rational &rhs) const noexcept {
    int32_t num_1 = numerator_ * rhs.denomerator();
    int32_t num_2 = rhs.numerator() * denominator_;
    return num_1 > num_2;
}

bool rational::operator<(const rational &rhs) const noexcept {
    int32_t num_1 = numerator_ * rhs.denomerator();
    int32_t num_2 = rhs.numerator() * denominator_;
    return num_1 < num_2;
}

bool rational::operator>=(const rational &rhs) const noexcept {
    int32_t num_1 = numerator_ * rhs.denomerator();
    int32_t num_2 = rhs.numerator() * denominator_;
    return num_1 >= num_2;
}

bool rational::operator<=(const rational &rhs) const noexcept {
    int32_t num_1 = numerator_ * rhs.denomerator();
    int32_t num_2 = rhs.numerator() * denominator_;
    return num_1 <= num_2;
}

rational rational::operator-(const rational &rhs) const noexcept {
    int32_t num = (numerator_ * rhs.denomerator()) - (rhs.numerator() * denominator_);
    int32_t den = denominator_ * rhs.denomerator();
    return rational(num, den);
}

rational &rational::operator+=(const rational &rhs) {
    int nod = NOD(numerator_, rhs.denomerator());
    numerator_ = (numerator_ * rhs.denomerator()) / nod + rhs.numerator_ * denominator_ / nod;
    denominator_ = (denominator_ * rhs.denomerator()) / nod;
    this->normalize(numerator_, denominator_);
    return *this;
}

rational &rational::operator*=(const rational &rhs) noexcept {
    numerator_ *= rhs.numerator_;
    denominator_ *= rhs.denomerator();
    this->normalize(numerator_, denominator_);
    return *this;
}

rational& rational::operator-=(const rational& rhs) noexcept{
    int32_t nod = NOD(numerator_,rhs.denominator_);
    numerator_ = (numerator_*rhs.denomerator())/nod - rhs.numerator_*denominator_/nod;
    denominator_ = (denominator_*rhs.denominator_)/nod;
    this->normalize(numerator_, denominator_);
    return *this;
}

rational& rational::operator/= (const rational& rhs){
    denominator_ *= rhs.numerator_;
    if (denominator_ == 0 || rhs.denomerator() == 0){
        throw std::invalid_argument("division by zero");
    }
    numerator_ *= rhs.denomerator();
    this->normalize(numerator_, denominator_);
    return *this;
}
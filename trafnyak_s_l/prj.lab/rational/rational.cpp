#include <rational/rational.hpp>
#include <string>
#include <stdexcept>

//int main() {
//    Rational in;
//    std::cin >> in;
//    Rational num = {1, 4};
//    in += num;
//    num = Rational(1, 2) + Rational(3, 8);
//    std::cout << in << "_____" << num << "\n";
//    return 0;
//}

int32_t Rational::NOD(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    if (a == b || a == 0) {
        return b;
    }
    if (a > b) {
        return NOD(a - b, b);
    }
    return NOD(a, b - a);
}

std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs) noexcept {
    return rhs.write_to(ostrm);
}

std::ostream &Rational::write_to(std::ostream &ostrm) const noexcept {
    ostrm << numerator_ << "/" << denominator_;
    return ostrm;
}


std::istream &operator>>(std::istream &istrm, Rational &rhs) noexcept {
    return rhs.read_from(istrm);
}

std::istream& Rational::read_from(std::istream& istrm) noexcept
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
            *this = Rational(num1, denum1);
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}


bool Rational::operator==(const Rational &rhs) const noexcept {
    return (numerator_ == rhs.numerator()) && (denominator_ == rhs.denomerator());
}

bool Rational::operator!=(const Rational &rhs) const noexcept {
    return (numerator_ != rhs.numerator()) || (denominator_ != rhs.denomerator());
}

bool Rational::operator>(const Rational &rhs) const noexcept {
    int32_t num_1 = numerator_ * rhs.denomerator();
    int32_t num_2 = rhs.numerator() * denominator_;
    return num_1 > num_2;
}

bool Rational::operator<(const Rational &rhs) const noexcept {
    int32_t num_1 = numerator_ * rhs.denomerator();
    int32_t num_2 = rhs.numerator() * denominator_;
    return num_1 < num_2;
}

bool Rational::operator>=(const Rational &rhs) const noexcept {
    int32_t num_1 = numerator_ * rhs.denomerator();
    int32_t num_2 = rhs.numerator() * denominator_;
    return num_1 >= num_2;
}

bool Rational::operator<=(const Rational &rhs) const noexcept {
    int32_t num_1 = numerator_ * rhs.denomerator();
    int32_t num_2 = rhs.numerator() * denominator_;
    return num_1 <= num_2;
}

Rational Rational::operator-(const Rational &rhs) const noexcept {
    int32_t num = (numerator_ * rhs.denomerator()) - (rhs.numerator() * denominator_);
    int32_t den = denominator_ * rhs.denomerator();
    return Rational(num, den);
}

Rational Rational::operator-() const noexcept {
    return Rational(-numerator_, denominator_);
}

Rational &Rational::operator+=(const Rational &rhs) {
    int nod = NOD(denominator_, rhs.denomerator());
    numerator_ = (numerator_ * rhs.denomerator()) / nod + rhs.numerator_ * denominator_ / nod;
    denominator_ = (denominator_ * rhs.denomerator()) / nod;
    this->normalize(numerator_, denominator_);
    return *this;
}

Rational &Rational::operator*=(const Rational &rhs) noexcept {
    numerator_ *= rhs.numerator_;
    denominator_ *= rhs.denomerator();
    this->normalize(numerator_, denominator_);
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) noexcept{
    //int32_t nod = NOD(numerator_,rhs.denominator_);
    numerator_ = (numerator_*rhs.denomerator()) - rhs.numerator()*denominator_;
    denominator_ = (denominator_*rhs.denominator_);
    this->normalize(numerator_, denominator_);
    return *this;
}

Rational& Rational::operator/= (const Rational& rhs){
    denominator_ *= rhs.numerator_;
    if (denominator_ == 0 || rhs.denomerator() == 0){
        throw std::invalid_argument("division by zero");
    }
    numerator_ *= rhs.denomerator();
    this->normalize(numerator_, denominator_);
    return *this;
}

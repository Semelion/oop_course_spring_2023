#ifndef UNTITLED_RATIONAL_H
#define UNTITLED_RATIONAL_H

#include <cstdint>
#include <sstream>
#include <algorithm>
#include <iostream>

class Rational {
public:
    Rational() = default;

    Rational(const Rational &) = default;

    Rational(Rational &&) = default;

    Rational(const int32_t numerator) noexcept {
        numerator_ = numerator;
        denominator_ = 1;
    }

    Rational(const int32_t numerator, const int32_t denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Error: divizon into 0");
        }
        normalize(numerator, denominator);
    }

    ~Rational() = default;

    Rational &operator=(const Rational &) = default;

    Rational &operator=(Rational &&) = default;

    [[nodiscard]] int32_t numerator() const noexcept { return numerator_; }

    [[nodiscard]] int32_t denomerator() const noexcept { return denominator_; }

    bool operator==(const Rational &rhs) const noexcept;

    bool operator!=(const Rational &rhs) const noexcept;

    bool operator>(const Rational &rhs) const noexcept;

    bool operator<(const Rational &rhs) const noexcept;

    bool operator>=(const Rational &rhs) const noexcept;

    bool operator<=(const Rational &rhs) const noexcept;

    Rational operator-(const Rational &rhs) const noexcept;
    Rational operator-() const noexcept;

    explicit operator bool() const noexcept;

    Rational &operator*=(const Rational &rhs) noexcept;

    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const int rhs){
        return operator+= (Rational(rhs));
    }

    Rational &operator-=(const Rational &rhs) noexcept;

    Rational &operator/=(const Rational &rhs);

    std::istream &read_from(std::istream &istrm) noexcept;

    std::ostream &write_to(std::ostream &ostrm) const noexcept;

private:
    int numerator_ = 0;
    int32_t denominator_ = 1;
private:
    int32_t NOD(int32_t a, int32_t b);
    void normalize(int32_t num, int32_t den) noexcept {
        int32_t max_del = 1;
        int32_t t = std::min(std::abs(num), std::abs(den));
        for (int32_t i = 2; i <= t; i++) {
            if (num % i == 0 && den % i == 0) {
                max_del = i;
            }
        }

        if ((num < 0 && den < 0) || (num > 0 && den > 0)) {
            numerator_ = std::abs(num / max_del);
            denominator_ = std::abs(den / max_del);
        } else {
            numerator_ = -1 * std::abs(num / max_del);
            denominator_ = std::abs(den / max_del);
        }
    }
};

std::istream &operator>>(std::istream &istrm, Rational &rhs) noexcept;

std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs) noexcept;

inline Rational operator-(const Rational &lhs, const Rational &rhs) noexcept {
    return Rational(lhs) -= rhs;
}

inline Rational operator+ (const Rational& lhs, const Rational& rhs){
    return Rational(lhs) += rhs;
}
inline Rational operator+ (const Rational& lhs, const int rhs){
    return Rational(lhs) + Rational(rhs);
}
inline Rational operator+ (const int lhs, const Rational& rhs){
    return Rational(lhs) + Rational(rhs);
}

inline Rational operator/(const Rational &lhs, const Rational &rhs) {
    return Rational(lhs) /= rhs;
}

inline Rational operator*(const Rational &lhs, const Rational &rhs) noexcept {
    return Rational(lhs) *= rhs;
}

#endif

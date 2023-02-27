#ifndef rATIONAL_LIBRARY_H
#define rATIONAL_LIBRARY_H


#include <cstdint>
#include <sstream>
#include <algorithm>
#include <iostream>

class rational {
public:
    rational() = default;

    rational(const rational &) = default;

    rational(rational &&) = default;

    rational(const int32_t numerator) noexcept {
        numerator_ = numerator;
        denominator_ = 1;
    }

    rational(const int32_t numerator, const int32_t denominator) {
        normalize(numerator, denominator);
    }

    ~rational() = default;

    rational &operator=(const rational &) = default;

    rational &operator=(rational &&) = default;

    [[nodiscard]] int32_t numerator() const noexcept { return numerator_; }

    [[nodiscard]] int32_t denomerator() const noexcept { return denominator_; }

    bool operator==(const rational &rhs) const noexcept;

    bool operator!=(const rational &rhs) const noexcept;

    bool operator>(const rational &rhs) const noexcept;

    bool operator<(const rational &rhs) const noexcept;

    bool operator>=(const rational &rhs) const noexcept;

    bool operator<=(const rational &rhs) const noexcept;

    rational operator-(const rational &rhs) const noexcept;

    explicit operator bool() const noexcept;

    rational &operator*=(const rational &rhs) noexcept;

    rational& operator+=(const rational& rhs);
    rational& operator+=(const int rhs){
        return operator+= (rational(rhs));
    }

    rational &operator-=(const rational &rhs) noexcept;

    rational &operator/=(const rational &rhs);

    std::istream &read_from(std::istream &istrm) noexcept;

    std::ostream &write_to(std::ostream &ostrm) const noexcept;

private:
    int numerator_ = 0;
    int32_t denominator_ = 1;
private:
    int32_t NOD(int32_t a, int32_t b);
    void normalize(int32_t num, int32_t den) noexcept {
        if (den == 0) {
            throw std::invalid_argument("Error: divizon into 0");
        }
        int32_t max_del = 1;
        int t = std::min(std::abs(num), std::abs(den));
        for (int i = 2; i <= t; i++) {
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

std::istream &operator>>(std::istream &istrm, rational &rhs) noexcept;

std::ostream &operator<<(std::ostream &ostrm, const rational &rhs) noexcept;

inline rational operator-(const rational &lhs, const rational &rhs) noexcept {
    return rational(lhs) -= rhs;
}

inline rational operator+ (const rational& lhs, const rational& rhs){
    return rational(lhs) += rhs;
}
inline rational operator+ (const rational& lhs, const int rhs){
    return rational(lhs) + rational(rhs);
}
inline rational operator+ (const int lhs, const rational& rhs){
    return rational(lhs) + rational(rhs);
}

inline rational operator/(const rational &lhs, const rational &rhs) {
    return rational(lhs) /= rhs;
}

inline rational operator*(const rational &lhs, const rational &rhs) noexcept {
    return rational(lhs) *= rhs;
}

#endif

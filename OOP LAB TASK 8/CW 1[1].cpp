#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Fraction {
private:
    int numerator, denominator;

    void reduce() {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

public:
    Fraction(int n = 0, int d = 1) {
        numerator = n;
        denominator = d == 0 ? 1 : d;
        reduce();
    }

    Fraction operator+(const Fraction& f) const {
        return Fraction(numerator * f.denominator + f.numerator * denominator,
                        denominator * f.denominator);
    }

    Fraction operator-(const Fraction& f) const {
        return Fraction(numerator * f.denominator - f.numerator * denominator,
                        denominator * f.denominator);
    }

    Fraction operator*(const Fraction& f) const {
        return Fraction(numerator * f.numerator, denominator * f.denominator);
    }

    Fraction operator/(const Fraction& f) const {
        return Fraction(numerator * f.denominator, denominator * f.numerator);
    }

    bool operator==(const Fraction& f) const {
        return numerator == f.numerator && denominator == f.denominator;
    }

    bool operator!=(const Fraction& f) const {
        return !(*this == f);
    }

    bool operator<(const Fraction& f) const {
        return numerator * f.denominator < f.numerator * denominator;
    }

    bool operator>(const Fraction& f) const {
        return f < *this;
    }

    bool operator<=(const Fraction& f) const {
        return !(*this > f);
    }

    bool operator>=(const Fraction& f) const {
        return !(*this < f);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.denominator == 1)
            os << f.numerator;
        else
            os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        is >> f.numerator >> f.denominator;
        f.reduce();
        return is;
    }
};

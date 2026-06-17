#include <iostream>
using namespace std;

class Polynomial;  // Forward declaration

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x);
    static Polynomial derivative(const Polynomial& p);
};

class Polynomial {
private:
    int coeffs[10];
    int degree;

    void trim() {
        while (degree > 0 && coeffs[degree] == 0)
            degree--;
    }

public:
    Polynomial() {
        degree = 0;
        for (int i = 0; i < 10; ++i)
            coeffs[i] = 0;
    }

    Polynomial(int deg, int c[]) {
        degree = deg;
        for (int i = 0; i < 10; ++i)
            coeffs[i] = c[i];
        trim();
    }

    friend class PolynomialUtils;

    Polynomial operator+(const Polynomial& p) const {
        Polynomial result;
        result.degree = max(degree, p.degree);
        for (int i = 0; i <= result.degree; ++i)
            result.coeffs[i] = coeffs[i] + p.coeffs[i];
        result.trim();
        return result;
    }

    Polynomial operator-(const Polynomial& p) const {
        Polynomial result;
        result.degree = max(degree, p.degree);
        for (int i = 0; i <= result.degree; ++i)
            result.coeffs[i] = coeffs[i] - p.coeffs[i];
        result.trim();
        return result;
    }

    Polynomial operator*(const Polynomial& p) const {
        Polynomial result;
        for (int i = 0; i <= degree; ++i)
            for (int j = 0; j <= p.degree; ++j)
                result.coeffs[i + j] += coeffs[i] * p.coeffs[j];
        result.degree = degree + p.degree;
        result.trim();
        return result;
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        for (int i = p.degree; i >= 0; --i) {
            if (p.coeffs[i] != 0) {
                if (i != p.degree && p.coeffs[i] > 0)
                    os << " + ";
                else if (p.coeffs[i] < 0)
                    os << " - ";

                if (abs(p.coeffs[i]) != 1 || i == 0)
                    os << abs(p.coeffs[i]);

                if (i > 0)
                    os << "x";
                if (i > 1)
                    os << "^" << i;
            }
        }
        return os;
    }
};

int PolynomialUtils::evaluate(const Polynomial& p, int x) {
    int result = 0;
    int power = 1;
    for (int i = 0; i <= p.degree; ++i) {
        result += p.coeffs[i] * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial& p) {
    Polynomial d;
    for (int i = 1; i <= p.degree; ++i)
        d.coeffs[i - 1] = p.coeffs[i] * i;
    d.degree = p.degree - 1;
    d.trim();
    return d;
}

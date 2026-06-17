#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {
    double* co;  
    int degree;  

public:
    Polynomial() {
        degree = 0;
        co = new double[1];  
        co[0] = 0;
    }

    Polynomial(int degree, const double* coefficient) {
        this->degree = degree;
        co = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            co[i] = coefficient[i];
        }
    }

    Polynomial(const Polynomial& p1) {
        degree = p1.degree;
        co = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            co[i] = p1.co[i];
        }
    }

    Polynomial(Polynomial&& p1) noexcept {
        degree = p1.degree;
        co = p1.co;
        p1.co = nullptr;
    }

    ~Polynomial() {
        delete[] co;
        cout << "DELETE DATA " << endl;
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0;
        for (int i = 0; i <= degree; ++i) {
            result += co[i] * pow(x, i);
        }
        return result;
    }

    Polynomial add(const Polynomial& p1) const {
        int maxDegree = max(degree, p1.degree);
        double* resultCo = new double[maxDegree + 1]{0};

        for (int i = 0; i <= degree; ++i) {
            resultCo[i] += co[i];
        }

        for (int i = 0; i <= p1.degree; ++i) {
            resultCo[i] += p1.co[i];
        }

        Polynomial result(maxDegree, resultCo);
        delete[] resultCo;
        return result;
    }

    Polynomial multiply(const Polynomial& p1) const {
        int resultDegree = degree + p1.degree;
        double* resultCo = new double[resultDegree + 1]{0};

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= p1.degree; ++j) {
                resultCo[i + j] += co[i] * p1.co[j];
            }
        }

        Polynomial result(resultDegree, resultCo);
        delete[] resultCo;
        return result;
    }

    void print() const {
        for (int i = 0; i <= degree; ++i) {
            if (i == 0) {
                cout << co[i];
            } else if (i == 1) {
                cout << " + " << co[i] << "x";
            } else {
                cout << " + " << co[i] << "x^" << i;
            }
        }
        cout << endl;
    }
};

int main() {
    double coeffs1[] = {1, 2, 3};  
    double coeffs2[] = {4, 5, 6};  

    Polynomial p1(2, coeffs1);
    Polynomial p2(2, coeffs2);

    Polynomial sum = p1.add(p2);  
    Polynomial product = p1.multiply(p2);  

    cout << "p1: ";
    p1.print();
    cout << "p2: ";
    p2.print();
    cout << "Sum: ";
    sum.print();
    cout << "Product: ";
    product.print();

    cout << "p1 evaluated at x = 3: " << p1.evaluate(3) << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "DimensionMismatchException: Matrix dimensions do not match.";
    }
};

template<typename T>
class Matrix {
    vector<vector<T>> data;
    size_t rows, cols;
public:
    Matrix(size_t r, size_t c) : rows(r), cols(c), data(r, vector<T>(c)) {}

    T& at(size_t r, size_t c) {
        if (r >= rows || c >= cols)
            throw out_of_range("Matrix index out of range");
        return data[r][c];
    }

    const T& at(size_t r, size_t c) const {
        if (r >= rows || c >= cols)
            throw out_of_range("Matrix index out of range");
        return data[r][c];
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException();
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw DimensionMismatchException();
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < other.cols; ++j)
                for (size_t k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    size_t rowCount() const { return rows; }
    size_t colCount() const { return cols; }
};

int main() {
    Matrix<int> A(2, 2), B(2, 2);
    A.at(0, 0) = 1; A.at(0, 1) = 2;
    A.at(1, 0) = 3; A.at(1, 1) = 4;

    B.at(0, 0) = 5; B.at(0, 1) = 6;
    B.at(1, 0) = 7; B.at(1, 1) = 8;

    try {
        Matrix<int> C = A + B;
        Matrix<int> D = A * B;

        for (size_t i = 0; i < C.rowCount(); ++i) {
            for (size_t j = 0; j < C.colCount(); ++j)
                cout << C.at(i, j) << " ";
            cout << endl;
        }

        for (size_t i = 0; i < D.rowCount(); ++i) {
            for (size_t j = 0; j < D.colCount(); ++j)
                cout << D.at(i, j) << " ";
            cout << endl;
        }

    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}


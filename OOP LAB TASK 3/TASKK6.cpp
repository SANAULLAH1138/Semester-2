#include <iostream>
#include <cstdlib>  
using namespace std;

class Matrix {
private:
    int rows, columns;
    int** matrix;

public:
  
    Matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[columns]{0}; 
        }
    }
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    int getRows() const { return rows; }
    int getColumns() const { return columns; }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < columns) {
            matrix[i][j] = value;
        } else {
            cout << "Invalid position (" << i << ", " << j << "). Element not set." << endl;
        }
    }
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    //  add two matrices
    Matrix add(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            cout << "Matrices cannot be added. Dimensions do not match." << endl;
            return Matrix(0, 0); // empty matrix
        }

        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    //  Multiply two matrices
    Matrix multiply(const Matrix& other) const {
        if (columns != other.rows) {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0); // empty matrix
        }

        Matrix result(rows, other.columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.columns; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < columns; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    int rows1, cols1, rows2, cols2;

    if (argc > 1) {  
        
        if (argc < 7) {  
            cout << "ERROR" << endl;
            return 1;
        }

        rows1 = stoi(argv[1]);
        cols1 = stoi(argv[2]);
        rows2 = stoi(argv[3]);
        cols2 = stoi(argv[4]);

        if (rows1 <= 0 || cols1 <= 0 || rows2 <= 0 || cols2 <= 0) {
            cout << "INVALID MATRIX!" << endl;
            return 1;
        }

        Matrix mat1(rows1, cols1);
        Matrix mat2(rows2, cols2);

        int index = 5;
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                mat1.setElement(i, j, stoi(argv[index++]));
            }
        }
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < cols2; j++) {
                mat2.setElement(i, j, stoi(argv[index++]));
            }
        }

        cout << "\nMatrix 1:" << endl;
        mat1.display();
        cout << "\nMatrix 2:" << endl;
        mat2.display();

        if (rows1 == rows2 && cols1 == cols2) {
            Matrix sum = mat1.add(mat2);
            cout << "\nSUM OF MATRIX:" << endl;
            sum.display();
        } else {
            cout << "MATRIX ADDITION NOT POSSIBLE DUE TO DIFFERENT ORDER " << endl;
        }

        if (cols1 == rows2) {
            Matrix product = mat1.multiply(mat2);
            cout << "\nProduct of matrices:" << endl;
            product.display();
        } else {
            cout << "MATRIX MULTIPLICATION NOT POSSIBLE" << endl;
        }
    } 
    else {  
        cout << "Enter rows and columns for Matrix 1: ";
        cin >> rows1 >> cols1;
        cout << "Enter rows and columns for Matrix 2: ";
        cin >> rows2 >> cols2;

        Matrix mat1(rows1, cols1);
        Matrix mat2(rows2, cols2);

        cout << "\nEnter elements for Matrix 1 (" << rows1 << "x" << cols1 << "):" << endl;
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                int value;
                cout << "Enter element at (" << i << ", " << j << "): ";
                cin >> value;
                mat1.setElement(i, j, value);
            }
        }

        cout << "\nEnter elements for Matrix 2 (" << rows2 << "x" << cols2 << "):" << endl;
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < cols2; j++) {
                int value;
                cout << "Enter element at (" << i << ", " << j << "): ";
                cin >> value;
                mat2.setElement(i, j, value);
            }
        }

        cout << "\nMatrix 1:" << endl;
        mat1.display();
        cout << "\nMatrix 2:" << endl;
        mat2.display();

        if (rows1 == rows2 && cols1 == cols2) {
            Matrix sum = mat1.add(mat2);
            cout << "\nSum of matrices:" << endl;
            sum.display();
        } else {
            cout << "ADDITION NOT POSSIBLE DUE TO DIFFERENT ORDER " << endl;
        }

        if (cols1 == rows2) {
            Matrix product = mat1.multiply(mat2);
            cout << "\nProduct of matrices:" << endl;
            product.display();
        } else {
            cout << "MATRIX MULTIPLICATION NOT POSSIBLE " << endl;
        }
    }
}


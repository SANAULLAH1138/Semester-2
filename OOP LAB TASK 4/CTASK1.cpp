#include<iostream>
#include<string>
using namespace std;

class Matrix {
    int row, column;
    int** Mat;

public:
    int getrow() {
        return row;
    }

    int getcolumn() {
        return column;
    }

    Matrix() {
        row = 0;
        column = 0;
        Mat = nullptr;
    }

    Matrix(int row, int column) {
        this->row = row;
        this->column = column;
        Mat = new int*[row];
        for (int i = 0; i < row; i++) {
            Mat[i] = new int[column];
        }
    }

    Matrix(const Matrix& m1) {
        row = m1.row;
        column = m1.column;
        Mat = new int*[row];
        for (int i = 0; i < row; i++) {
            Mat[i] = new int[column];
            for (int j = 0; j < column; j++) {
                cout << "ENTER [" << i << "][" << j << "] value at index : ";
                cin >> Mat[i][j];
            }
        }
    }

    Matrix(Matrix&& m1) {
        row = m1.row;
        column = m1.column;
        Mat = m1.Mat;
        m1.Mat = nullptr;
        m1.row = 0;
        m1.column = 0;
    }

    ~Matrix() {
        if (Mat != nullptr) {
            for (int i = 0; i < row; i++) {
                delete[] Mat[i];
            }
            delete[] Mat;
        }
        cout << "PROGRAM ENDED" << endl;
    }

    void transpose() {
        int** temp = new int*[column];
        for (int i = 0; i < column; i++) {
            temp[i] = new int[row];
            for (int j = 0; j < row; j++) {
                temp[i][j] = Mat[j][i];
            }
        }

        cout << "Transpose matrix:" << endl;
        for (int i = 0; i < column; i++) {
            for (int j = 0; j < row; j++) {
                cout << temp[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < column; i++) {
            delete[] temp[i];
        }
        delete[] temp;
    }

    void inputElements() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << "Enter the element [" << i+1 << "][" << j+1 << "] : ";
                cin >> Mat[i][j];
            }
        }
    }

    void display() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << Mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int row = 3;
    int column = 3;

    Matrix m1(row, column);

    m1.inputElements();
    cout << "Original Matrix:" << endl;
    m1.display();

    m1.transpose();

    return 0;
}


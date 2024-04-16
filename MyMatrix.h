#pragma once

#include <iostream>

using namespace std;

class MyMatrix {
private:
    double **_matrix;
    int _n;
    int _m;
public:
    // default constructor
    MyMatrix();

    // constructor`
    MyMatrix(int n, int m);

    // copy constructor
    MyMatrix(const MyMatrix &other);

    // MyMatrix destructor
    ~MyMatrix();

    int getRows() const { return this->_n; }

    int getCols() const { return this->_m; }

    void setRows(int rows);

    void setCols(int cols);

    void setMatrix(int rows, int cols);

    // Matrices addition
    MyMatrix operator+(const MyMatrix &other);

    // Matrices subtraction
    MyMatrix operator-(const MyMatrix &other);

    // Matrix multiplication
    MyMatrix operator*(const MyMatrix &other);

    // Matrix * scalar multiplication
    MyMatrix operator*(double scalar);

    // Scalar * matrix multiplication
    friend MyMatrix operator*(double scalar, const MyMatrix &matrix);

    // MyMatrix1 = MyMatrix2
    MyMatrix &operator=(const MyMatrix &other);

    // compares MyMatrix's and returns ture/false accordingly
    bool operator==(const MyMatrix &other) const;

    // print matrix
    friend ostream &operator<<(ostream &out, const MyMatrix &matrix);

    // input value to matrix
    friend istream &operator>>(istream &input, MyMatrix &matrix);

    // Overloading [] operator to access rows of the matrix
    double *operator[](int index) const;

    // Casting operator to return the sum of all matrix elements as a double
    operator double() const;
};

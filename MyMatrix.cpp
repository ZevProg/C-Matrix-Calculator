#include "MyMatrix.h"

MyMatrix::MyMatrix() {
    setMatrix(3, 3);
}

MyMatrix::MyMatrix(int n, int m) {
    setMatrix(n, m);
}

MyMatrix::MyMatrix(const MyMatrix &other) {
    this->setMatrix(other.getRows(), other.getCols());
    *this = other;
}

MyMatrix::~MyMatrix() {
    if (_matrix != nullptr) {
        for (int i = 0; i < getRows(); i++) {
            delete[] _matrix[i];
        }
        delete[] _matrix;
    }
}

void MyMatrix::setRows(int rows) {
    try {
        if (rows <= 0) {
            throw invalid_argument("Number of rows must be positive. Number of rows will now be 3");
        }
        this->_n = rows;
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
        this->_n = 3;
    }
}

void MyMatrix::setCols(int cols) {
    try {
        if (cols <= 0) {
            throw invalid_argument("Number of columns must be positive. Number of columns will now be 3");
        }
        this->_m = cols;
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
        this->_m = 3;
    }
}

void MyMatrix::setMatrix(int rows, int cols) {

    setRows(rows);
    setCols(cols);

    // Allocate memory for the new matrix
    _matrix = new double *[getRows()];
    for (int i = 0; i < getRows(); i++) {
        _matrix[i] = new double[getCols()];
    }

    // Initialize matrix elements to 0
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getCols(); j++) {
            _matrix[i][j] = 0.0;
        }
    }
}

MyMatrix MyMatrix::operator+(const MyMatrix &other) {
    try {
        if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
            throw invalid_argument("Matrices have incompatible dimensions for addition. Matrix was reset");
        }

        MyMatrix result(this->getRows(), getCols());

        for (int i = 0; i < this->getRows(); i++) {
            for (int j = 0; j < this->getCols(); j++) {
                result._matrix[i][j] = this->_matrix[i][j] + other._matrix[i][j];
            }
        }
        return result;
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
        return MyMatrix();
    }
}

MyMatrix MyMatrix::operator-(const MyMatrix &other) {
    try {
        if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
            throw invalid_argument("Matrices have incompatible dimensions for subtraction. Matrix was reset");
        }

        MyMatrix result(this->getRows(), this->getCols());

        for (int i = 0; i < this->getRows(); i++) {
            for (int j = 0; j < this->getCols(); j++) {
                result._matrix[i][j] = this->_matrix[i][j] - other._matrix[i][j];
            }
        }
        return result;
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
        return MyMatrix();
    }
}

// Matrix * Matrix
MyMatrix MyMatrix::operator*(const MyMatrix &other) {
    try {
        if (this->getCols() != other.getRows()) {
            throw invalid_argument("Matrices have incompatible dimensions for multiplication. Matrix was reset");
        }

        MyMatrix result(this->getRows(), other.getCols());

        for (int i = 0; i < this->getRows(); i++) {
            for (int j = 0; j < other.getCols(); j++) {
                double sum = 0.0;
                for (int k = 0; k < this->getCols(); k++) {
                    sum += this->_matrix[i][k] * other._matrix[k][j];
                }
                result._matrix[i][j] = sum;
            }
        }

        return result;
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
        return MyMatrix();
    }
}

// Matrix * Scalar
MyMatrix MyMatrix::operator*(double scalar) {
    MyMatrix result(*this);

    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            result._matrix[i][j] *= scalar;
        }
    }
    return result;
}

// Scalar * Matrix
MyMatrix operator*(double scalar, const MyMatrix &other) {
    MyMatrix result(other);
    return result * scalar;
}

MyMatrix &MyMatrix::operator=(const MyMatrix &other) {
    // Clear matrix before setting it to new size
    if (this->_matrix != nullptr)
        for (int i = 0; i < this->getRows(); i++)
            delete[] this->_matrix[i];
    delete[] this->_matrix;

    this->setMatrix(other.getRows(), other.getCols());

    // Copy the elements from the other matrix
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            this->_matrix[i][j] = other._matrix[i][j];
        }
    }

    return *this;
}


bool MyMatrix::operator==(const MyMatrix &other) const {
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
        return false;
    }
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            if (this->_matrix[i][j] != other._matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

ostream &operator<<(ostream &out, const MyMatrix &matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            out << matrix._matrix[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

istream &operator>>(istream &input, MyMatrix &matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            input >> matrix._matrix[i][j];
        }
    }
    return input;
}


double *MyMatrix::operator[](int index) const {
    return _matrix[index];
}

MyMatrix::operator double() const {
    double sum = 0.0;
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getCols(); j++) {
            sum += _matrix[i][j];
        }
    }
    return sum;
}





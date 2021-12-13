
#ifndef UNTITLED24_LIBRARY_H
#define UNTITLED24_LIBRARY_H

typedef enum{
    ZEROS,
    IDENTITY,
    TEMPORARY,
    ONES,
    RANDOM,
} Matrix_Type;

class Matrix {
private:
    int rows;
    int cols;
    int *data;
public:
    Matrix();
    Matrix(int rows, int cols, int *arr, unsigned int size);
    Matrix(int rows, int cols, Matrix_Type type, int value);
    ~Matrix();
    Matrix(const Matrix &source);
    Matrix(Matrix &&source) noexcept;
    Matrix& operator= (const Matrix &source);
    Matrix& operator= (Matrix &&source) noexcept;
    Matrix operator+ (const Matrix &other);
    Matrix operator- (const Matrix &other);
    Matrix operator* (const Matrix &other);
    int tr();
    void print();
    int det();
    void set_zeros( int value );
    void set_identity(int value);
    void set_temporary(int rows, int cols);
    void set_random(int value);
};

#endif //UNTITLED24_LIBRARY_H

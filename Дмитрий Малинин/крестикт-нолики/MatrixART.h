#ifndef INC_1_MatrixART_H
#define INC_1_MatrixART_H


class Mat {
public:
    unsigned int rows;
    unsigned int cols;
    double* data;

public:

    double trace(const Mat A);// ���� �������

    Mat sum(const Mat A, const Mat B);// ����� ������

    Mat mult(const Mat A, const Mat B);// ��������� ������

    Mat mult_const(const double scalar, const Mat A); // ��������� ������� �� ������

    Mat transp(const Mat A); // ���������������� �������

    Mat minor(int row, int col, const Mat A);// ������

    Mat dop(const Mat A);//������� ����������

    double det(const Mat A); // ������������ �������

    Mat one(const unsigned int size);  // ��������� �������

    Mat power(const Mat A, const unsigned int power); // ���������� ������� � �������

    Mat exp(const Mat A);

    void print(const Mat A);// ������� ������� �� �����
};


#endif //INC_1_MatrixART_H
#pragma once
#include <string.h>
using namespace std;


class Matrix
{
private:
	int rows;
	int cols;
	int** arr;
	string name;

public:
	Matrix(int rows, int cols, string name); //����������� ��� �������� �������
	Matrix(const Matrix& other_matrix) ;	//����������� ����������� (�=�)
	void Inicialization(const Matrix A); //����������� ������������� �������
	Matrix operator +(const Matrix& B); //���������� ��������� +
	Matrix operator *(const Matrix& B); //���������� ��������� *
	Matrix& operator =(const Matrix& other_matrix); //���������� ��������� =
	void Print(); //����� ������� �� �����
	int Trace(); //���������� ����� �������
	Matrix Minor(int row, int col, const Matrix a); //���������� ������ �������
	double Det(const Matrix a); //���������� ������������ �������
	~Matrix(); //���������� ������� ��� ������� 
};
	
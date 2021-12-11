#include <iostream> //���������� ������� ��� ����� � ���������
#include <string.h>
#include<math.h>
#include "Matrix.Libryary.h"
using namespace std;


Matrix::Matrix(int rows, int cols, string name)
{
	this->rows = rows;
	this->cols = cols;
	this->name = name;
	//�������� ������������� ���������� �������
	this->arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		this->arr[i] = new int[cols];
	}
}

Matrix::Matrix(const Matrix& other_matrix)	//����������� �����������
{
	this->rows = other_matrix.rows;
	this->cols = other_matrix.cols;

	//�������� ������������� ���������� �������
	this->arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		this->arr[i] = new int[cols];
	}

	//������������� ������������� ���������� �������
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->arr[i][j] = other_matrix.arr[i][j];
		}
	}
}

void Matrix::Inicialization(const Matrix A) //������������� ������������� ���������� �������
{
	setlocale(LC_ALL, "ru");
	cout << "���������������, ������� �� ������� ��������, ������� �������� ������� " << name << ", �������� " << rows << " x " << cols << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> arr[i][j];
		}
	}
}

Matrix Matrix::operator +(const Matrix& B) //���������� ��������� +
{
	if ((this->rows != B.rows) || (this->cols != B.cols))
	{
		std::cout << "������� ������ ��������. ��� � �������� �� �����? :(\n";
	}

	Matrix result(this->rows, this->cols, "result");

	//������������� ������������� ���������� �������
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result.arr[i][j] = this->arr[i][j] + B.arr[i][j];

		}
	}
	return result;
}

Matrix Matrix::operator *(const Matrix& B) //���������� ��������� *
{
	if (this->cols != B.rows)
	{
		std::cout << "����� �������� ������ ������� �� ����� ����� ����� ������ �������. ��� � ������� ���������? :(\n";
	}
	Matrix result(this->rows, B.cols, "result");
	//������������� ������������� ���������� �������
	for (int row = 0; row < this->rows; row++) {
		for (int col = 0; col < B.cols; col++) {
			result.arr[row][col] = 0;
			for (int i = 0; i < B.rows; i++) {
				result.arr[row][col] += this->arr[row][i] * B.arr[i][col];
			}
		}
	}
	return result;
}

Matrix& Matrix::operator =(const Matrix& other_matrix) //���������� ��������� =
{
	this->rows = other_matrix.rows;
	this->cols = other_matrix.cols;

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	//�������� ������������� ���������� �������
	this->arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		this->arr[i] = new int[cols];
	}

	//������������� ������������� ���������� �������
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->arr[i][j] = other_matrix.arr[i][j];
		}
	}
	return *this;
}


void Matrix::Print()
{
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
}

int Matrix::Trace()
{
	setlocale(LC_ALL, "ru");
	int trace = 0;
	if (rows != cols)
	{
		cout << "���� ������� �� ����������. ��� � ��� ����� ������� ���������:( ?";
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			trace += arr[i][i];
		}
	}
	return trace;
}


Matrix Matrix::Minor(int row, int col, const Matrix a)
{
	Matrix result(a.rows - 1, a.cols - 1, "result");

	int offsetRow = 0; //�������� ������� ������ � �������
	int offsetCol = 0; //�������� ������� ������� � �������

	for (int i = 0; i < result.rows; i++)
	{
		//���������� row-�� ������
		if (i == row)
		{
			offsetRow = 1; //��� ������ ��������� ������, ������� ���� ����������, ������ �������� ��� �������� �������
		}

		offsetCol = 0; //�������� �������� �������
		for (int j = 0; j < result.cols; j++)
		{
			//���������� col-�� �������
			if (j == col)
			{
				offsetCol = 1; //��������� ������ �������, ��������� ��� ���������
			}

			result.arr[i][j] = a.arr[i + offsetRow][j + offsetCol];
		}
	}
	return result;
}

double Matrix::Det(const Matrix a)
{
	setlocale(LC_ALL, "ru");
	double det = 0;
	if (a.rows != a.cols)
	{
		cout << "���� ������� �� ����������. ��� � ��� ����� �� ������������:( ?";
	}

	switch (a.rows)
	{
	case 1:
		return a.arr[0][0];
	case 2:
		return a.arr[0][0] * a.arr[1][1] - a.arr[1][0] * a.arr[0][1];
	default:
		for (int j = 0; j < a.cols; j++)
		{
			det += pow(-1, j) * a.arr[0][j] * Det(Minor(0, j, a));
		}
		return det;
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
}
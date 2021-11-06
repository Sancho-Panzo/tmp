#include <stdio.h> //�������� ������ � ����� � ������������� �������� ����
#include <stdlib.h>
#include <string.h>
//#include "Global_peremennie.h"
//#include "bot_move.h"

int size = 0;
int field[100] = { 0 };
int field_size();

void iniciallization_field(int massiv[]);
void output(int massiv[]);

void x_move(void);
void win_check(void);
void who_win(int igrok);

void o_move(void);

int main(void)
{
	size = field_size();
	iniciallization_field(field); //������������� ����
	output(field); //����� ����
	for (int g = 0; g <= (size * size - 1) / 2; g++)
	{
		x_move(); //����� ������
		output(field); //����� ����
		win_check(); //�������� �� �������

		if (g == (size * size - 1) / 2)
			printf("pobedila druzhba!");

		o_move();
		output(field); //����� ����
		win_check(); //�������� �� �������
	}
	return 0;
}

int field_size() {
	int word;
	printf("Pole NxN. Vvedite N.\n");
	word = scanf_s("%d", &size);
	while ((word != 1) || size > 10 || size < 3)
	{
		printf("Necorectniy vvod!\n");
		printf("Povtorite popitky: ");
		word = scanf_s("%d", &size);
	}
	return size;
}

void iniciallization_field(int massiv[])
{
	for (int i = 0; i < size * size; i++)
	{
		{
			massiv[i] = i + 1;
			//printf("%d ", massiv[i]);
		}
	}
	printf("\n");
}

void output(int massiv[])
{
	int k = 0;
	int i = 0;
	printf("Play field\n\n");
	for (k = 0; k <= size * size - size; k += size)
	{
		for (i = k; i < k + size; i = i++)
			printf("%2d ", massiv[i]);
		printf("\n");
	}
}

void x_move(void) //����� �������
{
	char position = 0;
	int position_chislo = 0;
	int k = 0;
	int i = 0;
	int j = 0;
	char mass1[4] = { 0 };

	printf("\nKrestiki move. VVedite chislo. ");

	position = getchar();

	while (position == ' ' || position == '\t') //���� position - ������ ��������� ������� ����� ������
	{
		position = getchar();
	}

	if (!isdigit(position)) //���� position �� �����
	{
		printf("\nVvedite chislo: ");
		position = getchar();
	}

	while (isdigit(position)) //������ � ������ op �����
	{
		mass1[k] = position;
		k++;
		position = getchar();
	}
	mass1[k] = '\0';
	position_chislo = atoi(mass1);

	if ((field[position_chislo - 1] == 'X') || (field[position_chislo - 1] == 'O'))
	{
		printf("Cell is busy!\n");
		x_move();
	}
	else
	{
		field[position_chislo - 1] = 'X';
	}
}

void win_check(void) //���������� �������� ����������
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 1; i < size; i++) //�������� 1 ���������
	{
		if (field[0] == field[0 + i * (size + 1)])
			j++;
		if (j + 1 == size)
			who_win(field[0]);
	}

	j = 0;

	for (i = 1; i < size; i++) //�������� 2 ���������
	{
		if (field[size - 1] == field[(size - 1) + i * (size - 1)])
			j++;
		if (j + 1 == size)
			who_win(field[size - 1]);
	}

	j = 0;

	for (k = 0; k <= size * size - size; k += size) //�������� ���� �����
	{
		for (i = k; i < k + size - 1; i++)
			if (field[i] == field[i + 1])
				j++;
		if (j + 1 == size)
			who_win(field[i]);
		j = 0;
	}

	j = 0;

	for (k = 0; k <= size - 1; k++) //�������� ���� ��������
	{
		for (i = k; i < k + size * size - size; i += size)
			if (field[i] == field[i + size])
				j++;
		if (j + 1 == size)
			who_win(field[i]);
		j = 0;
	}
}

void who_win(int igrok) //��� �������
{
	if (igrok == 'O')
		printf("\nPobeda noliki :)\n");
	else
		printf("\nPobeda krestiki :)\n");
	exit(1);
}

void o_move(void)
{
	char position = 0;
	int position_chislo = 0;
	int k = 0;
	int i = 0;
	int j = 0;
	char mass1[4] = { 0 };

	printf("\nNoliki move. VVedite chislo. ");

	position = getchar();

	while (position == ' ' || position == '\t') //���� position - ������ ��������� ������� ����� ������
	{
		position = getchar();
	}

	if (!isdigit(position)) //���� position �� �����
	{
		printf("\nVvedite chislo: ");
		position = getchar();
	}

	while (isdigit(position)) //������ � ������ op �����
	{
		mass1[k] = position;
		k++;
		position = getchar();
	}
	mass1[k] = '\0';
	position_chislo = atoi(mass1);

	if ((field[position_chislo - 1] == 'X') || (field[position_chislo - 1] == 'O'))
	{
		printf("Cell is busy!\n");
		x_move();
	}
	else
	{
		field[position_chislo - 1] = 'O';
	}
}


#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;


const short int WIDTH = 3, HEIGHT = 3;																//������ ���� (��� ��������� ���������������� �� ��������:))


enum PlayerTurn {																					//������������ �������
	X = 1,
	O = 2
};


int turn;																							//����� ����
char input;																							//���� ����������
const char *gameStatus;																				//������ ����
char field[WIDTH][HEIGHT];																			//����																						
bool correctInput;																					//���������� ����������, �������� ���������� � ������������ �����
PlayerTurn playerTurn;																				//������� ����������� ����

bool checkWin() {																					
	bool flag;
	int intDgFlag1 = 0, intDgFlag2 = 0, intVrFlag = 0, intGrFlag = 0;
	if (field[1][1] != '*') {
		for (int i = 0; i < WIDTH - 1; i++) {														//�������� ������ ���������
			if (field[i + 1][i + 1] == field[i][i]) intDgFlag1++;
		}

		for (int i = 0; i < WIDTH - 1; i++) {														//�������� ������ ���������
			if (field[WIDTH-1-i][i] == field[WIDTH-1-(i+1)][i + 1]) intDgFlag2++;
		}
	}
	
	for (int i = 0; i < WIDTH; i++) {																//�������� ����������
		for (int j = 0; j < HEIGHT - 1; j++) {
			if (field[(WIDTH - 1) / 2][i] != '*')
				if (field[j + 1][i] == field[j][i]) intVrFlag++;
		}
		if (intVrFlag != 2) intVrFlag = 0;
		if (intVrFlag == 2) break;
	}

	for (int i = 0; i < HEIGHT; i++) {																//�������� ������������
		for (int j = 0; j < HEIGHT - 1; j++) {
			if (field[i][(HEIGHT - 1) / 2] != '*')
				if (field[i][j + 1] == field[i][j]) intGrFlag++;
		}
		if (intGrFlag != 2) intGrFlag = 0;
		if (intGrFlag == 2) break;
	}



	if (intDgFlag1 == 2||intDgFlag2==2||intVrFlag==2||intGrFlag==2) flag = true;
	else flag = false;
	return flag;
}

bool checkDraw() {
	bool flag;
	int intFlag=0;

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (field[i][j] != '*') intFlag++;
		}
	}
	if (intFlag == 9) flag = true;
	else flag = false;
	return flag;
}

void Setup() {																						//��������� �������� �� ���������
	setlocale(LC_ALL, "Russian");
	
	playerTurn = X;
	turn = 0;																					
	gameStatus = "���� �� ��������";

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			 field[i][j] = '*';
		}
	}	
}

void Instruction() {																				//������� ��� ������ ���������� 
	cout << "����� �1 - 'X', � ����� �2 - '0'" << endl;
	cout << "��� ��������� ������ ����� � ��������������� ������ �������:" << endl;
	cout << "'q' - ������ a11; 'w' - ������ a12; 'e' - ������ a13;" << endl;
	cout << "'a' - ������ a21; 's' - ������ a22; 'd' - ������ a23;" << endl;
	cout << "'z' - ������ a31; 'x' - ������ a32; 'c' - ������ a33;" << endl;
	cout << "��� ������ �� ���� �������: 'o'." << endl;
}


void Draw(){																						//������� ��� ��������� ����
	cout << endl << endl << endl;
	cout << "\t   ��������-������!" << endl << endl;
	cout << "\t     ��� ������ �" << playerTurn << endl << endl;
	
		for (int i = 0; i < HEIGHT; i++) {
			cout << "\t\t";
			for (int j = 0; j < WIDTH; j++) {
				cout << field[i][j]<<' ';
			}
			cout << endl << endl;
		}
	Instruction();
	cout << gameStatus<<endl;
	}


void Input() {
	cout << "����: ";
	cin >> setw(1) >> input;
	switch (input) { 
	default:
		correctInput = false;
		break;

	case ('o'):
		correctInput = true;
		exit(0);
		break;

	case ('q'):
		if (field[0][0] == '*') {
			(playerTurn == X) ? (field[0][0] = 'X') : (field[0][0] = '0');
			correctInput = true;
		}
		else correctInput = false;
		break;

	case ('w'):
		if (field[0][1] == '*') {
			(playerTurn == X) ? (field[0][1] = 'X') : (field[0][1] = '0');
			correctInput = true;
		}
		else correctInput = false;
		break;

	case ('e'):
		if (field[0][2] == '*') {
			(playerTurn == X) ? (field[0][2] = 'X') : (field[0][2] = '0');
			correctInput = true;
		}
		else correctInput = false;
		break;

	case ('a'):
		if (field[1][0] == '*') {
			(playerTurn == X) ? (field[1][0] = 'X') : (field[1][0] = '0');
			correctInput = true;
		}
		else correctInput = false;
		break;

	case ('s'):
		if (field[1][1] == '*') {
			(playerTurn == X) ? (field[1][1] = 'X') : (field[1][1] = '0');
			correctInput = true;
		}
		else correctInput = false;
		break;

	case ('d'):
		if (field[1][2] == '*') {
			(playerTurn == X) ? (field[1][2] = 'X') : (field[1][2] = '0');
			correctInput = true;
		}
		else correctInput = false;
		break;

	case ('z'):
		if (field[2][0] == '*') {
			(playerTurn == X) ? (field[2][0] = 'X') : (field[2][0] = '0');
			correctInput = true;
		}
		else correctInput = false;
		break;

	case ('x'):
		if (field[2][1] == '*') {
			(playerTurn == X) ? (field[2][1] = 'X') : (field[2][1] = '0');
			correctInput = true;
		}
		else correctInput = false;
		break;

	case ('c'):
		if (field[2][2] == '*') {
			(playerTurn == X) ? (field[2][2] = 'X') : (field[2][2] = '0');
			correctInput = true;
		}
		else correctInput = false;
		break;
	}
}

void Logic() {
	if (correctInput) turn++;
	(turn % 2 == 0) ? (playerTurn = X) : (playerTurn = O);

	if (checkWin()) {
		turn--;
		(turn % 2 == 0) ? (playerTurn = X) : (playerTurn = O);
		gameStatus = "���� ��������!";
		Draw();
		cout << "������� ����� " << playerTurn << endl << endl;
		exit(0);
	}
	
	if (checkDraw()) {
		gameStatus = "���� ��������!";
		Draw();
		cout << "�����!" << endl << endl;
		exit(0);
	}
}

int main() {
	
	Setup();

	while (1) {
		Draw();
		Input();
		Logic();
	}
	return 0;
}
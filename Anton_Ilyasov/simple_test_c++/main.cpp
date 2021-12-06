#include <iostream>
#include <string.h>

#define COUNTQUESTION 4
using namespace std;

class User
{
public:
	string name;
	string answer;
	int correct_answer;
	int incorrect_answer;
	User();
};

User::User() {
	name = "";
	answer = "";
	correct_answer = 0;
	incorrect_answer = 0;
}

class Test
{
public:
	string question;
	string correct_answer;
	Test();
	void fill_question(int number);
	void print_question();
};

Test::Test() {
	question = "";
	correct_answer = "";
}

void Test::fill_question(int number) {
	switch (number)
	{
	case 1:
	{
		question = "�� ����������� ���� ����� ����, ������� ����� ������ ������. \n"
			"��� ��������� ������ ���� �� �����. � ����� ����������� ����� ����? ";
		correct_answer = "������";
		break;
	}
	case 2:
	{
		question = "������� ��������� �����: 41, 34, 28, 23, 19...";
		correct_answer = "16";
		break;
	}
	case 3:
	{
		question = "������� ��� ��� ����� � 3 ������� � 4 �����?";
		correct_answer = "11";
		break;
	}
	case 4:
	{
		question = "���� 1+1=10, �� ���� ����� 1+10?";
		correct_answer = "11";
		break;
	}
	}
}

void Test::print_question() {
	cout << endl << question << endl << endl;
}

User User1;
void greeting() {
	cout << "������� ���� ���" << endl;
	cin >> User1.name;
	cout << "�������!" << endl;
	cout << "����������, ������� ����� � ���������� � ��������� ����� :)" << endl;
}

void test() {
	Test Test1;
	for (int i = 1; i <= COUNTQUESTION; i++)
	{
		Test1.fill_question(i);
		Test1.print_question();
		cin >> User1.answer;
		if (User1.answer == Test1.correct_answer)
		{
			User1.correct_answer++;
		}
		else
		{
			User1.incorrect_answer++;
		}
	}
}

void get_results() {
	if (User1.correct_answer >= 3)
	{
		cout << "\n�� �������!" << endl;
	}
	else
	{
		cout << "\n�� ��� �, ��������� ��� �����!" << endl;
	}
	cout << "���������� ������� = " << User1.correct_answer << endl;
	cout << "������������ ������� = " << User1.incorrect_answer << endl;
}

int main(void)
{
	setlocale(LC_ALL, "ru");
	greeting();
	test();
	get_results();
}
#include<iostream>
#include<Windows.h>
#include<cstring>
using namespace std;

int stringLength(const char str[]);
void to_upper(char str[], const int SIZE);
void to_lower(char str[], const int SIZE);



void main()
{
	setlocale(LC_ALL, "Russian");
	const int SIZE = 256;
	SetConsoleCP(1251);
	char str[SIZE]{};
	cout << "������� �����: (�� ������ 256 ��������) ";
	cin.getline(str, SIZE);
	stringLength(str);
	cout << endl;
	cout << "������� ����� ��� �������� �� ������� �������� � �������: (�� ������ 256 ��������) ";
	cin.getline(str, SIZE);
	to_upper(str,SIZE);
	cout << "������� ����� ��� �������� �� �������� �������� � ������: (�� ������ 256 ��������) ";
	cin.getline(str, SIZE);
	to_lower(str, SIZE);
	SetConsoleCP(866);

}
int stringLength(const char str[])
{
	int symbol = 0;
	while (str[symbol] != '\0')
	{
		symbol++;
	}
	cout << "��������� ������ ������� �� " << symbol << " �������� ";
	return symbol;
	cout << endl;
}
void to_upper(char str[], const int SIZE)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		if (str[i] > 'A' && str[i] < 'Z')
			str[i] += 'z' - 'Z';
		if (str[i] > 'a' && str[i] < 'z')
		 str[i] -= 'a' - 'A';
		if (str[i] > '�' && str[i] < '�')
			str[i] += '�' - '�';
		if (str[i] > '�' && str[i] < '�')
			str[i] -= '�' - '�';
	}
	cout << str;
	cout << endl;
}
void to_lower(char str[], const int SIZE)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		if (str[i] > 'a' && str[i] < 'z')
			str[i] += 'Z' - 'z';
		if (str[i] > 'A' && str[i] < 'Z')
			str[i] -= 'A' - 'a';
		if (str[i] > '�' && str[i] < '�')
			str[i] += '�' - '�';
		if (str[i] > '�' && str[i] < '�')
			str[i] -= '�' - '�';
	}
	cout << str;
}
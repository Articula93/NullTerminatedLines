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
	cout << "Введите текст: (не больше 256 символов) ";
	cin.getline(str, SIZE);
	stringLength(str);
	cout << endl;
	cout << "Введите текст для перевода из нижнего регистра в верхний: (не больше 256 символов) ";
	cin.getline(str, SIZE);
	to_upper(str,SIZE);
	cout << "Введите текст для перевода из верхнего регистра в нижний: (не больше 256 символов) ";
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
	cout << "Введенная строка состоит из " << symbol << " символов ";
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
		if (str[i] > 'А' && str[i] < 'Я')
			str[i] += 'я' - 'Я';
		if (str[i] > 'а' && str[i] < 'я')
			str[i] -= 'а' - 'А';
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
		if (str[i] > 'а' && str[i] < 'я')
			str[i] += 'Я' - 'я';
		if (str[i] > 'А' && str[i] < 'Я')
			str[i] -= 'А' - 'а';
	}
	cout << str;
}
#include<iostream>
#include<Windows.h>
#include<cstring>
using namespace std;

int stringLength(const char str[]);
void to_upper(char str[], const int SIZE);
void to_lower(char str[], const int SIZE);
char* shrink(char str[]);
bool is_palindrome(const char str[]);
bool is_int_number(const char str[]);
bool is_bin_number(const char str[]);
bool is_hex_number(const char str[]);


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
	cout << "Строка без лишних пробелов: " << endl;
	cout << shrink(str);
	if (is_palindrome(str))
		cout << "строка палиндром " << endl;
	else
		cout << "строка не палиндром" << endl;

	if(is_int_number(str))	
		cout << "строка " << str << " является десятичным числом. " << endl;
	else
		cout << "строка " << str << " не является десятичным числом. " << endl;
	if(is_bin_number(str))
		cout << "строка " << str << " является двоичным числом. " << endl;
	else
		cout << "строка " << str << " не является двоичным числом. " << endl;
	if(is_hex_number(str))
		cout << "строка " << str << " является шестнадцатиричным числом. " << endl;
	else 
		cout << "строка " << str << " не является шестнадцатиричным числом числом. " << endl;
	cout << endl;
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
	cout << endl;
}
char* shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++) str[j] = str[j + 1];
		}
	}
	return str;
}
bool is_palindrome(const char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[n - i - 1])
		{
			return false;

		}
	}
	return true;
	cout << endl;
}
bool is_int_number(const char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			return true;	
		}
		else
		{
			return false;
		}
	}
}
bool is_bin_number(const char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '0' || str[i] == '1')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
bool is_hex_number(const char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if ((str[i] >= '0' || str[i] <= '9') &&
			(str[i] >= 'A' || str[i] <= 'F') &&
			(str[i] >= 'a' || str[i] <= 'f'))
			return true;
	}
	return false;
}

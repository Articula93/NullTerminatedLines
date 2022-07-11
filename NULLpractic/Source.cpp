#include<iostream>
#include<Windows.h>
#include<cstring>

using namespace std;

int stringLength(const char str[]);
bool is_palindrome(const char str[]);

void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	const int SIZE = 256;
	char str[SIZE]{};
	cout << "Введите предложение: " << endl;
	cin.getline(str, SIZE);
	cout << str << endl;
	stringLength(str);
	if (is_palindrome(str))
		cout << " строка палиндром " << endl;
	else
		cout << " строка не палиндром" << endl;
	SetConsoleCP(866);
}
int stringLength(const char str[])
{
	int symbol = 0;
	while (str[symbol] != '\0')
	{
		symbol++;
	}
	cout << "Введенная строка состоит из " << symbol << " символов " << endl;
	return symbol;
	cout << endl;
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
	
}

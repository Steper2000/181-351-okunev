// lab5.cpp: операторы переходов и циклов.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void shifr_cez(char *arr)
{
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] < 120 && arr[i] != 32) { arr[i] = arr[i] + 3; } //шифрование
		else { if (arr[i] >= 120) { arr[i] = arr[i] - 23; } }
	}
}
/*void *input_array(int *arr)
{
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		std::cin >> arr[i];
	}
	//return arr;
}

int *print_array()
{
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i];
	}
	return arr;
}
*/

int main()
{
	/*if (условие)
	{
	код
	}
	else 
	{
	код
	}
	пример:
	if (a>b){...;
	*/
	
	//применение шифра цезаря для строчных латинских букв со сдвигом вправо на 3 
	char string[6]; // вводимая строка из 5 букв
	cin >> string;
	shifr_cez(string);
	cout << string;
}
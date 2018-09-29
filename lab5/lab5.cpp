// lab5.cpp: операторы переходов и циклов.
//

#include "stdafx.h"
#include <iostream>

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
int func(int num1, int num2);

int main()
{
	/*if (условие)
	{
	код
	}
	else (условие)
	{
	код
	}
	пример:
	if (a>b){...;
	*/

   
	/*int iter = 0;
	while (true)
	{
		std::cout << iter;
		iter++;
		if (iter = 10);
	}*/

	
	//input_array;
	//print_array;
	
	int num1 = 1, num2 = 2, res = 0;
	res = func(num1, num2);
	std::cout << res << " " << num1 << " " << num2;
	return 0;
}

int func(int num1, int num2)
{
	num1 += 10;
	return num1 + num2;
}
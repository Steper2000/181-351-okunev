// lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/*ЛАБОРАТОРНАЯ РАБОТА
МАССИВЫ*/

//ф-ция для обмена значений ячеек
void swapEl(int *arr, int i)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}

//ф-ция "шейкер"-сортировки
void myShakerSort(int *arr, int size)
{
	int leftMark = 1;
	int rightMark = size - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		rightMark--;
	}
}

int main()
{
	/*МАССИВ - блок из нескольких однотипных данных
	задавать массивом удобно:
	1) вектора и матрицы
	2) множество точек 2D И 3D
	3)просто какой-либо числовой ряд, таблица и т.д.
	4)строка - массив символов
	5)видеобуфер (двумерный массив, соответствующий пикселам экрана)*/

	// тип_данных имя_массива[размер] ={значение}
	// тип_данных имя_массива[размер1][размер2] ={значение}
	// int a [3][3]=
	// {{10, 5, 7}
	// {6, 4, 98}
	// {34, 65, 45}}

	//Перемножение матриц а и b
	int a[3][3] =
	{ {1, 2, 3},
	{4, 5, 6},
	{7, 8, 9} };

	int b[3][3] =
	{ { 3, 4, 5 },
	{ 6, 7, 8 },
	{ 1, 2, 4 } };

	int c[3][3] = { {0} };
	c[0][0] = a[0][0] * b[0][0] + b[1][0] * a[0][1] + a[0][2] * b[2][0];
	c[0][1] = a[0][0] * b[0][1] + b[1][1] * a[0][1] + a[0][2] * b[2][1];
	c[0][2] = a[0][0] * b[0][2] + b[1][2] * a[0][1] + a[0][2] * b[2][2];
	std::cout << c[0][0] << " " << c[0][1] << " " << c[0][2] << "\n" << std::endl;

	c[1][0] = a[1][0] * b[0][0] + b[1][0] * a[1][1] + a[1][2] * b[2][0];
	c[1][1] = a[1][0] * b[0][1] + b[1][1] * a[1][1] + a[1][2] * b[2][1];
	c[1][2] = a[1][0] * b[0][2] + b[1][2] * a[1][1] + a[1][2] * b[2][2];
	std::cout << c[1][0] << " " << c[1][1] << " " << c[1][2] << "\n" << std::endl;

	c[2][0] = a[2][0] * b[0][0] + b[1][0] * a[2][1] + a[2][2] * b[2][0];
	c[2][1] = a[2][0] * b[0][1] + b[1][1] * a[2][1] + a[2][2] * b[2][1];
	c[2][2] = a[2][0] * b[0][2] + b[1][2] * a[2][1] + a[2][2] * b[2][2];
	std::cout << c[2][0] << " " << c[2][1] << " " << c[2][2] << "\n" << std::endl;

	//Сортировка массива d пузырьком
	int d[5]{ 2, 3, 1, 5, 4 };
	for (int i = 0; i < 5; i++) {
		std::cout << d[i] << " ";
	}
	std::cout << "\n";
	int t;
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j < 5; j++) 
		{ 
		   if (d[j-1] > d[j]) 
		   {
		     swapEl(d, j);
           }
		}
	}
	for (int i = 0; i < 5; i++) {
		std::cout << d[i] << " ";
	}
	std::cout << "\n";
	std::cout << "\n";

	// шейкерская кодировка массива
	int size = 5;
	int *A = new int[size];
	for (int k = 0; k < size; k++)
	{
		A[k] = rand() % 10;
		std::cout << A[k] << " ";
	}

	myShakerSort(A, size); // сортировка

	std::cout << "\n";
	for (int k = 0; k < size; k++)
	{
		std::cout << A[k] << " ";
	}
	std::cout << "\n\n";

	
	//применение шифра цезаря для строчных латинских букв со сдвигом вправо на 3 
	char string[6]; // вводимая строка из 5 букв
	gets_s(string);
  for (int i = 0; i < 5; i++)
  {
	if (string[i] < 120 && string[i]!=32) string[i] = string[i] + 3;  //шифрование
	else {if (string[i] >= 120) string[i] = string[i] - 23;}
  }
	std::cout << string;
}


// lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;
//работа с динамической памятью происходит через указатели
//Преимущества
//1) доступно гораздо больше памяти, нежели в стеке
//2) размеры массиво
//Особенность :
//Можно очищать
//Чтобы очистить память delete название_указателя

//указатель_на_тип_переменной имя_переменной = new тип;
//или тип * имя_переменной = new тип;
// пример: int * ptr_int=new int; для удаления delete имя_указателя

//В динамической памяти могут выделяться только одномерные массивы:
// тип * имя_указателя = new тип[длина]; для удаления delete[] имя_указателя

/*Для выделения двумерного массива сначала создаётся одномерный массив
содержащий указатели на другие массивы(строки)
int ** dynamic2Darray = new int[l1]
затем выделяется блок памяти под каждую строку и указатель на неё
возвращается в созданный массив указателей
for (int i = 0; i < l1; i++) {
	dynamic2darray[i] = new int[l2];
	for (int j = 0; j < l2; j++) {
		dynamic2Darray[i][j] = j;
	}
}
Чтобы удалить двумерный массив
for (int i = 0; i < l1; i++) {
	delete[] dynemic2Darray[i];
}
delete[] dynamic2Darray; */


class matrix
{
private:
	int * matr = new int[rows*columns];
	int rows, columns;
	int *res = new int[rows*columns];
public:
	matrix();
	~matrix();

	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);

	int getElem(int row, int col);
	int getRows() { return rows; }
	int getColumns() { return columns; }

	bool input();
	void transp();

	void printM()
	{
		for (int i = 0; i <rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matr[i*columns + j] << "\t";
			}
			cout << endl;
		}
	};

};




int main()
{
	matrix matrA, matrB;
	matrA.input();
	matrB.input();
	//matrA.printM();
	//matrA.transp();
	//matrA.summMatrix(matrB);
	matrA.multMatrix(matrB);
	return 0;
}

matrix::matrix() {}
matrix::~matrix() { /*delete [] matr;*/ }

bool matrix::summMatrix(matrix matr2)
{
	if (rows == matr2.getRows() && columns == matr2.getColumns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i*columns+j] += matr2.getElem(i, j);
			}
		}
		printM();
		return true;
	}
	else 
	{ 
		cout << "columns and rows are not equal"; 
		return false;
	}
}

void matrix::transp()
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << matr[j * columns + i] <<" ";
		}
		cout << endl;
	}
	
}

bool matrix::multMatrix(matrix matr2)
{
	if (columns == matr2.getRows())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				int sum = 0;
				for (int k = 0; k < columns; k++) {
					sum += matr[i*columns+k] * matr2.getElem(k, j);
				}
				res[i*matr2.getColumns()+j] = sum;
			}
		}
		
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				cout << res[i*matr2.getColumns() + j] << "\t";
			}
			cout << endl;
		}
		return true;
	}
	else 
	{
		cout << "col1 != row2";
		return false;
	}
}

int matrix::getElem(int row, int col)
{
	if (row<rows && col<columns && row>-1 && col>-1)
	{
		return matr[row*columns+col];
	}
	else
	{
		cout << "error";
		return -1;
	}
}

bool matrix::input()
{
	cout << "rows=";
	cin >> rows;
	cout << "columns=";
	cin >> columns;
    for (int i = 0; i <rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matr[i*columns+j];
		}
		cout << endl;
	}
	return true;
}

// lab9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//перегрузка - объявление нескольких функций
//с одинаковыми именами,но разными именами
//
#include "pch.h"
#include <iostream>
#include<sstream>
using namespace std;

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
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matr[i*columns + j] << "\t";
			}
			cout << endl;
		}
	};
	friend ostream & operator<< (ostream & os, matrix & matr);
	friend matrix & operator + (matrix & matr, matrix & matr2);
	friend matrix & operator - (matrix & matr, matrix & matr2);
	friend matrix & operator *(matrix & matr, matrix & matr2);
};




int main()
{
	matrix matrA, matrB, res;
	matrA.input();
	matrB.input();
	//matrA.printM();
	//matrA.transp();
	//matrA.summMatrix(matrB);
	//matrA.multMatrix(matrB);
	//cout << (matrA+matrB);
	res = matrA * matrB;
	cout << res;
	return 0;
}

matrix::matrix() {}
matrix::~matrix() { /*delete[] matr; */}



bool matrix::summMatrix(matrix matr2)
{
	if (rows == matr2.getRows() && columns == matr2.getColumns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i*columns + j] += matr2.getElem(i, j);
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
			cout << matr[j * columns + i] << " ";
		}
		cout << endl;
	}

}

ostream & operator<<(ostream & os, matrix & matr)
{
	for (int i = 0; i < matr.getRows(); i++)
	{
		for (int j = 0; j < matr.getColumns(); j++)
		{
			os << matr.getElem(i,j) << "\t";
		}
		os << endl;
	}
	return os;
}

matrix & operator+(matrix & matr, matrix & matr2)
{
	matrix res;
	//res.columns = matr.columns;
//res.rows = matr.rows;
	//res.matr = new int[res.rows*res.columns];
	if (matr.getRows() == matr2.getRows() && matr.getColumns() == matr2.getColumns())
	{
		for (int i = 0; i < matr.getRows(); i++)
		{
			for (int j = 0; j < matr.getColumns(); j++)
			{
				matr.matr[i*matr.columns + j] = matr.getElem(i, j) + matr2.getElem(i, j);
			}
		}
		return matr;
	}
	else { cout << "error!"; return matr; }
}

matrix & operator-(matrix & matr, matrix & matr2)
{
	if (matr.getRows() == matr2.getRows() && matr.getColumns() == matr2.getColumns())
	{
		for (int i = 0; i < matr.getRows(); i++)
		{
			for (int j = 0; j < matr.getColumns(); j++)
			{
				matr.matr[i*matr.columns + j] = matr.getElem(i, j) - matr2.getElem(i, j);
			}
		}
		return matr;
	}
	else { cout << "error!"; return matr; }
}

matrix & operator*(matrix & matr, matrix & matr2)
{
	matrix res;
	res.columns = matr2.columns;
res.rows = matr.rows;
	res.matr = new int[res.rows*res.columns];
	if (matr.getColumns() == matr2.getRows())
	{
		for (int i = 0; i < matr.getRows(); i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				int sum = 0;
				for (int k = 0; k < matr.getColumns(); k++) {
					sum += matr.getElem(i, k)* matr2.getElem(k, j);
				}
				res.matr[i*matr2.getColumns() + j] = sum;
			}
		}
	   /* delete[] matr.matr;
		matr.matr = nullptr;
		matr.matr = new int[res.rows*res.columns];
		for (int i = 0; i < res.rows*res.columns; i++) 
		{
			matr.matr[i] = res.matr[i];
		}
		delete[]  res.matr;*/
		return res;
	}
	else { cout << "error!"; return matr; }

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
					sum += matr[i*columns + k] * matr2.getElem(k, j);
				}
				res[i*matr2.getColumns() + j] = sum;
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
		return matr[row*columns + col];
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
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matr[i*columns + j];
		}
		cout << endl;
	}
	return true;
}


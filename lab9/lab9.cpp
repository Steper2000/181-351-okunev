// lab9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//перегрузка - объявление нескольких функций
//с одинаковыми именами,но разными именами
//
#include "pch.h"
#include <iostream>
#include<sstream>
using std::cout;

class matrix
{
protected:
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
			cout << std::endl;
		}
	};
	friend std::ostream & operator<< (std::ostream & os, matrix & matr);
	friend matrix & operator + (matrix & matr, matrix & matr2);
	friend matrix & operator - (matrix & matr, matrix & matr2);
	friend matrix & operator *(matrix & matr, matrix & matr2);

};

class  vector :public matrix
{
public:
	vector();
	~vector();
	bool multvec(matrix vec2);
	/*
	friend vector & operator *(vector vec, vector vec2);
	friend vector & operator *(vector vec, int k);
	friend std::ostream & operator <<(std::ostream vc, vector vec);
	friend vector & operator+(vector vec, vector vec2);
	friend vector & operator-(vector vec, vector vec2);
	*/
};

vector::vector() {}
vector::~vector() {}



int main()
{
	matrix matrA, matrB, res;
	vector vec, vec2;
	vec.input();
	vec2.input();
	cout << (vec+vec2);
	//matrA.input();
	//matrB.input();
	//cout << (matrA+matrB);
	//res = matrA * matrB;
	//cout << res;
	
	//cout << vec;
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
		cout << std::endl;
	}

}

std::ostream & operator<<(std::ostream & os, matrix & matr)
{
	for (int i = 0; i < matr.getRows(); i++)
	{
		for (int j = 0; j < matr.getColumns(); j++)
		{
			os << matr.getElem(i,j) << "\t";
		}
		os << std::endl;
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

// ДЛЯ ВЕКТОРОВ
/*
vector & operator*(vector vec, vector vec2)
{
	int scal = 0;
	if (vec.getColumns() == vec2.getColumns())
	{

		for (int i = 0; i < vec2.getColumns(); i++)
		{
			scal += vec.getElem(0, i) * vec2.getElem(0, i);
		}
		cout << scal;
		//delete[]vec;
		return vec;
	}
	else { return vec; }
}

vector & operator*(vector vec, int k)
{
	for (int i = 0; i < vec.getColumns(); i++)
	{
		vec.matr[i] *= k;
	}
	return vec;
}

std::ostream & operator<<(std::ostream vc, vector vec)
{
	for (int i = 0; i < vec.getColumns(); i++) 
	{ 
		vc << vec.getElem(0, i)<<" ";
	}
	return vc;
}

vector & operator +(vector vec, vector vec2)
{
	if (vec.getColumns() == vec2.getColumns())
	{
		for (int i = 0; i < vec2.getColumns(); i++)
		{
			vec.matr[i] = vec.getElem(0, i) + vec2.getElem(0, i);
		}
		return vec;
	}
	else { cout << "error!"; return vec; }

}

vector & operator -(vector vec, vector vec2)
{
	if (vec.getColumns() == vec2.getColumns())
	{
		for (int i = 0; i < vec2.getColumns(); i++)
		{
			vec.matr[i] = vec.getElem(0, i) - vec2.getElem(0, i);
		}
		return vec;
	}
	else { cout << "error!"; return vec; }
}
*/
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
			cout << std::endl;
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
	std::cin >> rows;
	cout << "columns=";
	std::cin >> columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i*columns + j];
		}
		cout << std::endl;
	}
	return true;
}

bool vector::multvec(matrix vec2)
{
	int scal = 0;
	if (columns == vec2.getColumns())
	{
		for (int i = 0; i < columns; i++)
		{
			scal += matr[i] * vec2.getElem(0, i);
		}
		cout << scal;
		//delete[]vec;
		return true;
	}
	else { return false; }
}


#pragma once
#include <iostream>
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

	void printM();
	friend std::ostream & operator<< (std::ostream & os, matrix & matr);
	friend matrix & operator + (matrix & matr, matrix & matr2);
	friend matrix & operator - (matrix & matr, matrix & matr2);
	friend matrix & operator *(matrix & matr, matrix & matr2);
};
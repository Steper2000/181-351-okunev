// lab6 Настледование
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
/*синтаксис имя_произ_класса:[тип_наследования] имя_род_класса
где тпи наследования publik private protectedy, 
но указывать не обязательно
 
                указано в наследовании
 класс        public      private     protected
 private         n o t  i n h e r t e d
 protected    protected   private     protected
 public       public      private     protected

 Чтобы при запуске нового дочернего метода выполнялся также родительский
 необходимо это указать
 в род классе void weapon::reload(){};
 в доч классе void rifle::reload():weapon::reload(),...{};

 void fnc(const тип1 параметр1, тип2 параметр2)
 {
 параметр1=10; // будет ошибка из-за const
 }
  
  объявление конст метода запрещает менять св-ва любого объекта
 void fnc2 (тип1 параметр1, тип2 параметр2) const
 {
 параметр1=10; // будет ошибка из-за const
 }
 */

class matrix
{
private: 
	int matr[10][10];
	int rows, columns;
	int res[10][10];
public:
	matrix();
	~matrix();
	
	bool summMatrix(matrix matr2);
    bool multMatrix(matrix matr2);
	
	int getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		cout << "error";
		return -1;
	}

	int getRows(){ return rows; }
	int getColumns(){ return columns; }
	
	bool input();
	void transp();
	
	void printM()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matr[i][j] <<"\t";
			}
			cout << endl;
		}
	};

	void printR()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << res[i][j] <<"\t";
			}
			cout << endl;
		}
	};

};


int main()
{
	matrix matrA, matrB;
	matrA.input();
	matrA.printM();
	
	
	/*int a = -15;
	double d = 1000.5e+03;//=1000.5 *10^3 = 1000.5 * pow(10,3) = 1000500
	float res1;
	long long res2;
	res1 = a + d;
	res2 = a / d;
	
	const char *ch1 = "123"; //=('1', '2', '3', '\0')=('1', '2', '3', 0)
    const char *ch2 = "456";
	cout << "1st:";
	cin >> ch1;
	cout << "2nd:";
	cin>>ch2;
	
	
	a=atoi(ch1); // для int или long
	d=atof(ch2);// перевод для doudle
	//ch1 + ch2;*/

return 0;
}
matrix::matrix(){}
matrix::~matrix(){}

bool matrix::summMatrix(matrix matr2)
{
	if (rows == matr2.getRows() && columns == matr2.getColumns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i][j] += matr2.getElem(i, j);
			}
		}
		return true;
		printM();
	}
	else { return false; }
}

void matrix::transp()
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			 
			cout << matr[j][i] <<"  ";
		}
		cout << endl;
	}
}

bool matrix::multMatrix(matrix matr2)
{
	if (columns == matr2.getRows())
	{
		for (int i = 0; i < matr2.getRows(); i++)
		{
			for (int j = 0; j < columns; j++)
			{
				int sum = 0;
				for (int k = 0; k < rows; k++) {
					sum += matr[i][k] * matr2.getElem(k, j);
				}
				res[i][j] = sum;
			}
		}
		printR();
		return true;
	}
    else { return false; }
}



bool matrix::input()
{
	cout << "rows=";
	cin >> rows;
	if (rows < 1 || rows>10) { return false; }
	cout << "columns=";
	cin >> columns;
	if (columns < 1 || columns>10) { return false; }
	for(int i=0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
			cout << "matr["<<i<<"]["<<j<<"]=";
			cin >> matr[i][j];
		}
		cout << endl;
	}
	return true;
}

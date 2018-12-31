// lab6 Настледование, матрицы и векторы.
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
protected: 
	int matr[10][10];
	int rows, columns;
	int res[10][10];
public:
	matrix();
	~matrix();
	
	bool summMatrix(matrix matr2);
    bool multMatrix(matrix matr2);
	
	int getElem(int row, int col);
	int getRows(){ return rows; }
	int getColumns(){ return columns; }
	
	bool input();
	void transp();
	void Kmult(int k);
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


};
class vector : public matrix
{
private:
	//int vec[10];
	//int n;
public: 
	//int getN() { return n; }
	//int getEl(int n);
	//bool enter();
	/*void kvec(int k)
	{
	 for (int i=0; i<n; i++)
	 {
		 vec[i] *= k;
		 cout << vec[i]<<' ';
	 }
	};*/
	bool multvec(matrix vec2);
};

int main()
{
	matrix matrA, matrB;
	vector vecA, vecB;
	//matrA.input();
	//matrB.input();
	//matrA.Kmult(3);
	//matrA.transp(); 
	//matrA.multMatrix(matrB);
	
	
	//int k;
 //cout << "k=";
	//cin >> k;
	vecA.input();
	vecB.input();
	//vecA.Kmult(k);
	vecA.multvec(vecB);
	//vecA.summMatrix(vecB);
	//vecA.kvec(k);
	//vecA.enter();
	//vecB.enter();
	//vecA.multvec(vecB);
	//vecA.kvec(5);
	
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
		printM();
		return true;
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

void matrix::Kmult(int k)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matr[i][j] *= k;
		}
	}
	printM();
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
					sum += matr[i][k] * matr2.getElem(k, j);
				}
				res[i][j] = sum;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				cout << res[i][j]<<" ";
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
		return matr[row][col];
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
/*
int vector::getEl(int n)
{
	if (n < 10 && n>-1) { return vec[n]; }
	else
	{
		cout << "error";
		return -1;
	}
}
*/
/*bool vector::enter()
{
	cout << "n=";
	cin >> n;
	if (n < 1 || n>10) { return false; }
	for (int j = 0; j < n; j++)
	{
		cout << "vec[" << j << "]=";
		cin >> vec[j];
	}
	return true;
}*/

bool vector::multvec(matrix vec2)
{
	int scal=0;
	if (columns = vec2.getColumns()) {
		for (int i = 0; i < columns; i++)
		{
			scal += matr[0][i] * vec2.getElem(0, i);
		}
		cout << scal;
	}
	else { return false; }
}
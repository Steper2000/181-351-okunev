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
 класс         public  private  protected
 private
 protected
 public



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
	int rows = 10;
	int columns = 10;
public:

	
	void summMatrix(int *matr2)
	{
		for (int i = 0; i <rows; i++) 
		{
		 for (int j = 0; j < columns; j++)
		 {
			 matr2[i][j] = matr[i][j] + matr2[i][j];
		 }
		}
	}

	void multMatrix(int *matr2)
	{
		for (int i = 0; i <rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr2[i][j] = matr[i][j] + matr2[i][j];
			}
		}
	}

	
	
	int getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		cout << "error";
		return -1;
	}

	bool transp();

	bool input();
	void print()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matr[i][j] << "\t";
			}
			cout << endl;
		}
	};
};


int main()
{
	int m1;
	
	
	
	
	
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

bool matrix::transp()
{
	int t;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			t = matr[i][j];
			matr[i][j] = matr[j][i];
			matr[j][i] = t;
		}

    }
}

bool matrix::input()
{
	cin >> rows;
	if(rows<1 && rows>10){return false}
	cin >> columns;
	if (columns<1 && columns>10) { return false }
	for(int i=0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
		 cin>>matr[i][j]
		}
	}
	return true;
}

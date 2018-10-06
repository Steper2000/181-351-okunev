// lab5.cpp: шифр цезаря и классы.
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

class wehicle
{
private:
public:
	double speed;
	char regnumber[6]{ 0 };
	unsigned char capacity;
	bool check_regnumber()
	{
		const char *true_number = "K370AO";
		bool result = true;
	}
};

class user_data
{
private:
	char first_name[255];
	char second_name[255];
	char str_passpot[10];
	char str_birthday[10];
	public:
		/*bool set_first_name(char p_first_name[255])
		{
			for(int i=0; i<255; i++)
			{
				if (first_name[i] < 128 || first_name[i] <176 || first_name[i] > 241 )
				{
					return false;
				}
			}

			
		*/
		
		bool set_birthday(char p_birthday[10])
	{
			for (int j = 0; j<10; j++)
			{
				if (str_birthday[j]>45 && str_birthday[j] != 47 && str_birthday[j]<58) 
				return true;
				else return false;
			}
			
	}
	
		bool set_birthday(char p_passport[10])
	{
		return false;
	};
};
	
	
	int main()
{
	wehicle car;
	car.speed = 123;



	//применение шифра цезаря для строчных латинских букв со сдвигом вправо на 3 
	char string[6]; // вводимая строка из 5 букв
	cin >> string;
	shifr_cez(string);
	cout << string;
/*Классы




свойство(property)-пременная в сотаве класса
метод(method)-функ в составе класса
инкапсуляция-фактически, об
Наследие
полиморфизм


*/


}



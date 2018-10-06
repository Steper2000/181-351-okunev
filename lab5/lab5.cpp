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
	char str_passport[10];
	char str_birthday[10];
	public:
		user_data( char p_passport[10] ,char set_birthday[10]);//конструктор
		~user_data();//деструктор
		
		user_data();
		/*bool set_first_name(char p_first_name[255])
		{
			for(int i=0; i<255; i++)
			{
				if (first_name[i]  128 || first_name[i] <176 || first_name[i] > 241 )
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
	
		bool set_passport(char p_passport[10])
	{
			int s = 0;
				while ( false || s<11)

			{
				if (str_passport[s] > 47 && str_passport[s] < 58)
				{
					return true;
					s++;
				}
				else return false ;
			}
	};

};

user_data::user_data(char p_first_name[255], char p_birthday[10])
{
	if (set_birthday = p_birthday && set_passport = p_passport)cout << "1\n";
	else cout<<"0\n"
}
	
int main()
{
	
		
		user_data  user1(a, b);
		{
			if 
		}
	 




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



// lab5.cpp: шифр цезаря и классы.
 

/*1. СИНТАКСИС ОБЪЯВЛЕНИЯ КЛАССА
 class Имя_Класса
 {
	int hp; число ХП
	double speed; скорость персонажа
	void heal(); восстановление ХП
	void move(); проигрывание анимации
 }
*/
/* Определение класса и объекта
СВОЙСТВО (PROPERTY) - переменная в составе класса
МЕТОД (method) - функция в составе класса
ИНКАПСУЛЯЦИЯ - фактически, объединение данных и методов, объединённых
единым смыслом, в одну конструкцию языка
НАСЛЕДОВАНИЕ - создание производных классов от родительского и заимствование
его свойств и методов
ПОЛИМОРФИЗМ простыми словами: экземпляры одного класса ведут себя по-разному
инкапсуляция, наследование и полиморфизм - три основные идеи ООП
*/
//2. СИНТАКСИС ОБЪЯВЛЕНИЯ ОБЪЕКТА И ОБРАЩЕНИЯ К СВОЙСТВАМ И МЕТОДАМ
//Имя_Класса объект1;
//vehicle car;
//car.speed = 123;
//обЪект1.свойство1 = 1;
//обЪект1.метод3();

/*3. СПЕЦИФИКАТОРЫ ДОСТУПА
К полям (свойсвтвам и методам), объявленным в разделе public:
можно обращаться везде (и из методов класса, и снаружи, где виден объект)
К полям private и protected можно обращаться только из методов
самого класса. Различие между privat и protected объясняется в следующей теме
про наследование классов.
4. КОНСТРУКТОР И ДЕСТРУКТОР КЛАССА
В случае, если при создании объекта нужно выполнять сложные
действия по
инициализации, установлению сетевого соединения, действия с файлами,
выделения ОП и т.д. эти действия прописываются в специальном
методе - конструкторе
Конструктор вызывается автоматически при создании объекта
В случае если при исчезновении объекта нужно общие системные
ресурсы освобождать:
закрывать порты, освобождать ОП, сохранять файлы и т.д. - эти действия
прописываются в методе - деструкторе (вызывается автоматически
при исчезновении объекта)
5. СТРУКТУРЫ
Несмотря на то, что в литературе структура как правило хранит
только даные, на самом деле это то же самое, что и класс.
Единсвтенное отличие - поля по умолчанию public
struct
*/

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

void shifr_cez(char *arr)
{
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] < 120 && arr[i] != 32) { arr[i] = arr[i] + 3; } //шифрование
		else { if (arr[i] >= 120) { arr[i] = arr[i] - 23; } }
	}
}

void array_equalization(char * first_array, char * second_array) // приравнивание массивов
{
	int lenght = strlen(first_array);
	for (int i = 0; i < lenght; i++)
	{
		second_array[i] = first_array[i];
	}
}

void print_array_chr(char * arr) // вывод массива
{
	int lenght = strlen(arr);
	for (int i = 0; i < lenght; i++) 
	{
		cout << arr[i];
	}
}


class user_data
{
private:
	char first_name[255];
	char second_name[255];
	char str_passport[10];
	char str_birthday[10];
	public:
		user_data();// конструктор
		user_data(char * p_first_name, char * p_second_name, char * p_str_passport, char * p_str_birthdate); //конструктор
		~user_data();//деструктор
		
		bool set_first_name(char *p_firstname)
		{
			int lenght = strlen(p_firstname);
			for (int i = 0; i < lenght; i++) {
				if ((p_firstname[i] < 'A') || (p_firstname[i] > 'Z' &&
					p_firstname[i] < 'a') || (p_firstname[i] > 'z')) {
					if (p_firstname[i] == '-') {
						continue;
					}
					return false;
				}

			}
			array_equalization(p_firstname, first_name);
			return true;
		}
		
		bool set_last_name(char *p_lastname)
		{
			int lenght = strlen(p_lastname);
			for (int i = 0; i < lenght; i++) {
				if ((p_lastname[i] < 'A') || (p_lastname[i] > 'Z' &&
					p_lastname[i] < 'a') || (p_lastname[i] > 'z')) {
					if (p_lastname[i] == '-') {
						continue;
					}
					return false;
				}

			}
			array_equalization(p_lastname, second_name);
			return true;
		}

		bool set_birthday(char *p_birthday)
		{
			for (int i = 0; i < 10; i++) 
			{
				if (i == 2 || i == 5) 
				{
					if (p_birthday[i] != '.') 
					{
						return false;
					}
				}
				else if (p_birthday[i] < '0' || p_birthday[i] > '9') 
				{
					return false;
				}
			}
			
			array_equalization(p_birthday, str_birthday);
			return true;
		};
	
		bool set_passport(char *p_passport)
		{
			for (int i = 0; i < 10; i++) 
			{
				if (p_passport[i] < '0' || p_passport[i] > '9') 
				{
					return false;
				}
			}
			array_equalization(p_passport, str_passport);
			return true;
		};

		void print_user_data() 
		{
			print_array_chr(first_name);
			print_array_chr(second_name);
			print_array_chr(str_passport);
			print_array_chr(str_birthday);
		}
};



user_data::user_data(char * p_first_name, char * p_second_name, char * p_str_passport, char * p_str_birthdate) {
	
	if (set_first_name(p_first_name)) 
	{
		cout << "First name Okey.\n";
	}
	if (set_last_name(p_second_name)) 
	{
		cout << "Second name Okey.\n";
	}
	if (set_passport(p_str_passport))
	{
		cout << "Passport Okey.\n";
	}
	if (set_birthday(p_str_birthdate)) 
	{
		cout << "Birthdate Okey.\n";
	}
};
	user_data::~user_data() {}; 
	user_data::user_data() {};
	
	int main()
	{
	/*

	user_data birthday;
    char birthdate_array[11] = "25.09.2000";
	char firstname_array[255] = "Ivanov";
	char secondname_array[255] = "Ivan";
	char passport_array[11] = "1234567890";
		if (birthday.set_first_name(firstname_array))
		{
		  cout << "Ok";
		}
		else 
		{
		 cout << "Error";
		}


		cout << "\nEnter your message"<<endl;
*/
//применение шифра цезаря для строчных латинских букв со сдвигом вправо на 3 
	char string[6]; // вводимая строка из 5 букв
	cin >> string;
	shifr_cez(string);
	cout << string; 

}



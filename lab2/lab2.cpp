// lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
   //создать целочисленные переменные а=300
	// b= 600
	// вывести на экран a*a*b*b
	// b/a
	//символ А+а
	int a = 5;
	int b = 3;
	std::cout << "a+b=" << a << std::endl;
	std::cout << a*a*b*b << std::endl;
	std::cout << b / a << std::endl;
std::cout << sizeof(int) << std::endl;
int max_int = 0b01111111111111111111111111111111;
std::cout << "max_int=" << max_int << std::endl;
	
/*вывести таблицу
тип данных - занимаемый размер - мин значение- макс значение
bool 
char 
int 
short 
long
long long
double
*/
std::cout << "\n";
std::cout << "tipe\t"<< "size\t" << "min\t"<<  "max\t\n" << std::endl;
std::cout << "bool\t" << sizeof(bool)<<"\t" << "0\t" << "1\n" << std::endl;
std::cout << "int\t" << sizeof(int) <<"\t" << INT_MIN  << "\t" << INT_MAX<< "\t\n" <<std::endl;
std::cout << "short\t" << sizeof(short) << "\t" << SHRT_MIN << "\t" << SHRT_MAX << "\t\n" << std::endl;
std::cout << "long\t" << sizeof(long) << "\t" << LONG_MIN << "\t" << LONG_MAX << "\t\n" << std::endl;
std::cout << "double\t" << sizeof(double) << "\t" << "2,2250738585072014e–308" << "\t" << "1,7976931348623158e+308" << "\t\n" << std::endl;

return 0;
}


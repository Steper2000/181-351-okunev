// lab4.cpp: операторы цикла,.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{// указатель - переменная хранящая адресс каких либо данных, переменых в оперативной памяти
 // фактически указатель - unsignet int 
	int a = 3;
	int *ptr_a;
	ptr_a = &a;// оператор получения адресса

	double b;
	double *ptr_b = &b;

	char c;
	char *ptr_c = &c;

	long d;
	long *ptr_d = &d;

	bool e;
	bool *ptr_e = &e;
	std::cout << "int pointer size=" << sizeof(ptr_a) << std::endl;
	std::cout << "double pointer size=" << sizeof(ptr_b) << std::endl;
	std::cout << "char  pointer size=" << sizeof(ptr_c) << std::endl;
	std::cout << "long pointer size=" << sizeof(ptr_d) << std::endl;
	std::cout << "bool pointer size=" << sizeof(ptr_e) << std::endl;
	// содержимое указателей
	std::cout << "\nptr_a=" << ptr_a << std::endl;

	int arr[4]{ 1, 2, 3, 4 };
	std::cout << "\narr=" << arr << std::endl;
	std::cout << "*arr=arr[0]=" << *arr << std::endl;
	std::cout << "(arr+3)=arr[3]" << *(arr + 3) << std::endl;
	return 0;
}


#include <iostream>
#include <string>
#include <cstring>
#include "lab15.h"
using std::cout;
using std::endl;
int main()
{
	
	cl a;
	std::cout << a <<std::endl;
	char * arra = new char[4];
		arra[0] = '1';
		arra[1] = '2';
		arra[2] = '3';
		arra[3] = '\0';
	cl b(arra);
	cout << b << std::endl;
	std::string st = "qwerty";
	cl c(st);
	std::cout << c << std::endl;
	cl d(c);
	std::cout << d << std::endl;
	b.add(st); //добавляем st
	cout <<"b+st = " << b << std::endl;
	b.add(arra); // добавляем arra
	cout << "b+st+arra = " << b << std::endl;
	b.clear(); //очищаем b
	cout << "b after clean = " << b << std::endl;
	a.add(arra);// добавляем arra
	cout << "a+arra = " << a << std::endl;
	c.insert(st, 2);//вставляет st после 2-го символа
	cout << c << endl;
	c.insert(arra, 4);
	cout << c << endl;
	c.cut(2, 12); //удаляет 12 эелементов после 2-го
	cout << c << endl;
	
	/*
	std::string strr;
	std::string strr1 = "def is fuu";
	std::string strr2 = "rasa ";
	strr1.insert(4, strr2);
	//strr.append(strr1, 0, 4);
	//strr.append(strr2.begin(), strr2.end());
	//strr.append(strr1.begin()+4, strr1.end());
	cout << strr1<< endl;*/
		
	/*
	char * arra = new char[6];
	arra[0] = '1';
	arra[1] = '2';
	arra[2] = '3';
	arra[3] = '4';
	arra[4] = '5';
	arra[5] = '\0';
	std::string copy(arra, 1);
	std::string copy2(arra, 1+2 , strlen(arra));
	cout << copy+copy2;

	std::string strr(arra, 2, 2);
	cout << strr;
	std::string strr = "def";
	cl b(arra);
	b.add(strr);
	cout << b << std::endl;
	b.add(arra);
	cout << b;
	*/
	
	
	/*
	//arr2[strlen(arra) + 1] = '\0';
	std::cout << arr2<<std::endl;
	delete[] arra;
	arra = new char[strlen(arr2) + strlen(arr2) + 1];
	for (int i = 0; i < strlen(arra); i++)
		arr2[i] = arra[i];
	for (int i = strlen(arra); i < 2*strlen(arra)+1; i++)
		arr2[i] = arra[i- strlen(arra)];
	cout << arra;*/
	/*
	char a[] = "asdf";
	strncat(a, a, strlen(a));
	cout << a;*/
	std::cin.get();
}
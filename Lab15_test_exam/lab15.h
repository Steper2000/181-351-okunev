#pragma once
#include <iostream>
#include <string>
#include <cstring>
/*class aaaa
{
private: int ab;
public: aaaa() {
	ab = 100;
	std::cout << ab;
};
};*/

class cl
{
private: char * arr; //= new char[len];
		 //int len;
public:
	cl() //создание пустой строки
	{
		arr = new char[0];
		arr[0] = '\0';
		std::cout << "a created!" << std::endl;
	};
	cl(char * copy) // копирование из *char
	{
		arr = new char[strlen(copy) + 1];
		for (int i = 0; i < strlen(copy) + 1; i++)
			arr[i] = copy[i];
		//strcpy_s(arr, strlen(copy), copy);
		std::cout << "b created!" << std::endl;
	}
	cl(cl& str1) //копирование из класса
	{
		int len = strlen(str1.arr);
		if (len)
		{
			arr = new char[len + 1];
			for (int i = 0; i < len + 1; i++)
				arr[i] = str1.arr[i];
		}
		else arr = new char[0];
		std::cout << "d created!" << std::endl;
	}
	cl(std::string str2) //копирование из std::string
	{
		int len = str2.size();
		if (len)
		{
			arr = new char[len + 1];
			for (int i = 0; i < len+1; i++)
				arr[i] = str2[i];
			arr[len + 1] = '\0';
		}
		else arr = new char[0];
		std::cout << "c created!" << std::endl;
	};
	~cl() { std::cout << "deleted" << std::endl; };
	
	void clear();
	void add(char* str);
	void add(std::string str);
	void insert(std::string str, int n);
	void insert(char * str, int n);
	void cut(int n, int m);
	int getlen() { return strlen(arr); }
	friend std::ostream & operator<< (std::ostream & os,cl & arr);
	};
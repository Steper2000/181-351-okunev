#include <iostream>
#include <cstring>
#include <string>
#include "lab15.h"

void cl::clear()
{
	//delete[] arr;
	arr = new char[0];
	arr[0] = '\0';
}

void cl::add(char * str)
{
	std::string copy(arr);
	std::string copy2(str);
	copy += copy2;
	//delete[]arr;
	int len = copy.size() + 1;
	arr = new char[len];
	for (int i = 0; i < len; i++)
		arr[i] = copy[i];
	arr[len ] = '\0';
}

void cl::add(std::string str)
{
	std::string copy(arr);
	copy += str;
	int len = copy.size() + 1;
	//delete[] arr;
	arr = new char[len];
	for (int i = 0; i < len; i++)
		arr[i] = copy[i];
	arr[len] = '\0';
}

void cl::insert(std::string str, int n)
{
	std::string copy(arr);
	copy.insert(n, str);
	int len = copy.size() + 1;
	//delete[] arr;
	arr = new char[len];
	for (int i = 0; i < len; i++)
		arr[i] = copy[i];
	arr[len] = '\0';
}

void cl::insert(char * str, int n)
{
	std::string copy(arr);
	std::string copy2(str);
	copy.insert(n, copy2);
	int len = copy.size() + 1;
	//delete[] arr;
	arr = new char[len];
	for (int i = 0; i < len; i++)
		arr[i] = copy[i];
	arr[len] = '\0';
}

void cl::cut(int n,int m) //n-позиция; m-кол-во
{
	std::string copy(arr, n);
	std::string copy2(arr, n+m, strlen(arr));
	copy += copy2;
	int len = copy.size() + 1;
	//delete[] arr;
	arr = new char[len];
	for (int i = 0; i < len; i++)
		arr[i] = copy[i];
	arr[len] = '\0';
}

std::ostream & operator<<(std::ostream & os, cl & ar)
{
	for (int i = 0; i < ar.getlen(); i++)
		os << ar.arr[i];
	return os;
}
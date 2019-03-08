#pragma once
#include <string>
#include <vector>
#include < QFile>
#include <QTextStream> // Подключаем класс QTextStream
//#include < QIODevice>


struct datas {
	std::string pred;
	std::string otr;
	std::string date;
	std::string nal;
	std::string sum;
};

bool checkPred(std::string pred);//Используемые символы - только буквы; Если регистр не тот, меняем на правильный.
bool checkOtr(std::string otr);
bool checkDate(std::string date);//тип данных Date
bool checkNal(std::string nal);
bool checkSum(std::string sum);

class DataBase {

public:
	DataBase() {};//конструктор
	//DataBase(std::string* tempDB); //конструктор по строке: т.е. по строке, в которой записана БД, формируем БД
	~DataBase() {};//деструктор
	bool add_data(datas tempData);// добавить строку данных в БД
	bool download(std::string & res);//загружаем данные из файла в строку
	//bool close();// закрытие файла
    //bool open(std::string filename);//открываем файл
	//data parsing(std::string line);
	
	void transformStr2BD(std::string sdb);// преобразует строку в БД
	

	/*
	bool download()//загружаем данные из файла в строку
	{
		std::string strFromFile;
		open(FileName);
		download(strFromFile);
		close();
		transformStr2BD(strFromFile);
	}*/

	//bool del_data(std::string id);//удалить запись с заданным id

//	template<typename T>
//	std::vector<data> find(int criterior, T data2find);//найти запись с заданным id

//	bool change(std::string id, data tempData)
//	{
//		//db[id] = tempData;
//	}

	bool write2file();

private:
	std::string sdb;
	std::vector<datas> db; //* тут было
	//QFile fin("database.txt");

};
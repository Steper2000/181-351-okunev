#include <iostream>
#include "Lab1logandpas.h"
#include <QMessageBox>
#include "menu.h"
#include <string>
#include "classdb.h"
#include "showDB.h"
//#include <fstream>

Lab1logandpas::Lab1logandpas(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}


int autorise(QString login, QString password)
{
	if (login == "" || password == "") {
		return 0;
	}
	FILE *base;
	base = fopen("log&pass.txt", "r");
	//std::ifstream base;
	//base.open("database.txt");
	QString sl;
	QString sp;
	char i = fgetc(base);
	while (true)
	{
		//base.getline(sl, 20, ' ');
		//base.getline(sp, 20, '\n');
		while (i != ' ') 
		{
			sl = sl + i;
			if (i == '\n')
				sl.clear();
			i = fgetc(base);
			if (i == -1) 
			{ 
				return 0;
				//break;
			}
		}
		
	
		
		i = fgetc(base);
		
		while (i != '\n')
		{
	     sp = sp + i;
	     i = fgetc(base);
		}
		
		
	
        if (login == sl && password == sp)
		{
			return 2;
			//break;
		}
		/*
		if (sl=="\n") 
		{
			return 0;
			break;
		}*/
		sl.clear();
		sp.clear();
	}
	//base.close();
	fclose(base);
}

void Lab1logandpas::on_pushButton_autorise_clicked()
{
	QString login = ui.line_login->text();
	QString password = ui.line_password->text();
	QMessageBox msgBox;
	
	if (autorise(login, password) == 2)
	{

		if (login == "admin")
		{
			msgBox.setText("Hello "+login);
			msgBox.exec();
		}
		else 
		{
			std::string sl = login.toStdString(); //копирует логин
			std::string sll; // первые 7 символов логина
			sll.insert(0, sl, 0, 7);
			if (sll == "manager")
		    {
				menu m;
			m.setModal(true);
			m.exec();
			  //msgBox.setText("Hello manager!");
			 // msgBox.exec();
		    }
		   else
		   {
			 //msgBox.setText("Hello "+login+"!");
			 //msgBox.exec();
				showDB m;
				m.setModal(true);
			 m.exec();
		   }
		}
	}
	else
	{
	
		msgBox.setText("Wrong login or password");
		msgBox.setInformativeText("Again?");
		msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
		msgBox.setDefaultButton(QMessageBox::Save);
		msgBox.exec();
	}
	/*int res = msgBox.exec();
	if (res == QMessageBox::Close)
	{
		close();
	}*/
	
}

void Lab1logandpas::on_Ftest_clicked()
{	
	datas da;
	da.pred = "alax";
	da.date = "1.06.2001";
	da.nal = "dan";
	da.otr = "rap";
	da.sum = "1000";
	datas das;
	das.pred = "hesus";
	das.date = "7.01.2000";
	das.nal = "indulg";
	das.otr = "god";
	das.sum = "2000";
	DataBase s;
	s.download();
	s.add_data(da);
	s.add_data(das);
	s.find("indulg");
	s.del_data(1);
	s.write2file();
}
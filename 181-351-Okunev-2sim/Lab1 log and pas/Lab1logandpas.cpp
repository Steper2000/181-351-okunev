#include <iostream>
#include "Lab1logandpas.h"
#include <QMessageBox>
#include <string>
#include <fstream>

Lab1logandpas::Lab1logandpas(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}


int autorise(QString login, QString password)
{
	FILE *base;
	base = fopen("database.txt", "r");
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
			if (i == '\n')sl.clear();
			i = fgetc(base);
			if (i == '\n') 
			{ 
				sl = i;
				break;
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
			break;
		}
		if (sl=="\n") 
		{
			return 0;
			break;
		}
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
			msgBox.setText("hello admin");
			msgBox.exec();
		}
		else 
		{
			std::string sl = login.toStdString();
			std::string sll;
			sll.insert(0, sl, 0, 7);
			if (sll == "manager")
		    {
			  msgBox.setText("hello manager");
			  msgBox.exec();
		    }
		   else
		   {
			 msgBox.setText("hello user");
			 int res = msgBox.exec();
		   }
		}
	}
	else
	{
	
		msgBox.setText("nonono");
		msgBox.setInformativeText("Again?");
		msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
		msgBox.setDefaultButton(QMessageBox::Save);
	
	}
	int res = msgBox.exec();
	if (res == QMessageBox::Close)
	{
		close();
	}
	
}

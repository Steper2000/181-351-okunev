#include <iostream>
#include <QMessageBox>
#include "menu.h"
#include "change.h"
#include <string>
#include <fstream>
#include "add.h"
#include "showDB.h"

menu::menu(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

menu::~menu()
{
}

void menu::on_pushButton_change_clicked()
{
	//QMessageBox b;
	//b.setText("lol");
	//b.exec();
	change c;
	c.setModal(true);
	c.exec();
}

void menu:: on_pushButton_nolog_clicked()
{
	showDB d;
	d.setModal(true);
	d.exec();
	//QMessageBox b;
	//b.setText("now it's not ready :(");
	//b.exec();
}

void menu::on_pushButton_add_clicked()
{
	add c;
	c.setModal(true);
	c.exec();

}

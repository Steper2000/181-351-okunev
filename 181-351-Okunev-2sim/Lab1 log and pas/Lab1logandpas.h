#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab1logandpas.h"

class Lab1logandpas : public QMainWindow
{
	Q_OBJECT

public:
	Lab1logandpas(QWidget *parent = Q_NULLPTR);

private:
	Ui::Lab1logandpasClass ui;
private slots:
	void on_pushButton_autorise_clicked();
	void on_Ftest_clicked();
};

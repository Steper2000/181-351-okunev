#pragma once

#include <QDialog>
#include "ui_menu.h"

class menu : public QDialog, public Ui::menu
{
	Q_OBJECT

public:
	menu(QWidget *parent = Q_NULLPTR);
	~menu();
private slots:
	void on_pushButton_change_clicked();
	void on_pushButton_nolog_clicked();
};

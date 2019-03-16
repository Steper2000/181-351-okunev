#pragma once

#include <QDialog>
#include "ui_add.h"

class add : public QDialog, public Ui::add
{
	Q_OBJECT

public:
	add(QWidget *parent = Q_NULLPTR);
	~add();
private: Ui::add ui;
private slots:
	void on_pushButton_add_clicked();
	void on_pushButton_del_clicked();
};

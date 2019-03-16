#pragma once
//#include "qstandarditemmodel.h"
#include "QStandardItemModel"
#include <QDialog>
#include "ui_showDB.h"
#include "classdb.h"

class showDB : public QDialog, public Ui::showDB//, public classdb
{
	Q_OBJECT

public:
	showDB(QWidget *parent = Q_NULLPTR);
	~showDB();
private: Ui::showDB ui;
		 QStandardItemModel *model;
};

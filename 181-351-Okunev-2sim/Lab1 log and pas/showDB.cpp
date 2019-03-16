#include "showDB.h"
#include "classdb.h"
showDB::showDB(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	model = new QStandardItemModel;
	QStandardItem *item;

	//Заголовки столбцов
	QStringList horizontalHeader;
	horizontalHeader.append("Company");
	horizontalHeader.append("Industry");
	horizontalHeader.append("Date");
	horizontalHeader.append("Tax");
	horizontalHeader.append("Sum");

	//Заголовки строк
	//QStringList verticalHeader;
	//verticalHeader.append("Ряд 1");
	//verticalHeader.append("Ряд 2");

	model->setHorizontalHeaderLabels(horizontalHeader);
	//model->setVerticalHeaderLabels(verticalHeader);

	DataBase eshkere;
	eshkere.download();
	
	for (int i = 1; i < eshkere.db.size(); i++)
	{
		//for(int j=0; j<5; j++){}
		item = new QStandardItem(QString::fromStdString(eshkere.db[i].pred));
		model->setItem(i-1, 0, item);

		item = new QStandardItem(QString::fromStdString(eshkere.db[i].otr));
		model->setItem(i-1, 1, item);

		item = new QStandardItem(QString::fromStdString(eshkere.db[i].date));
		model->setItem(i-1, 2, item);

		item = new QStandardItem(QString::fromStdString(eshkere.db[i].nal));
		model->setItem(i-1, 3, item);

		item = new QStandardItem(QString::fromStdString(eshkere.db[i].sum));
		model->setItem(i - 1, 4, item);
	}
	
	
	/*
	//Первый ряд
	item = new QStandardItem(QString("0"));
	model->setItem(0, 0, item);

	item = new QStandardItem(QString("1"));
	model->setItem(0, 1, item);

	item = new QStandardItem(QString("2"));
	model->setItem(0, 2, item);

	item = new QStandardItem(QString("3"));
	model->setItem(0, 3, item);
	
	
	//Второй ряд
	item = new QStandardItem(QString("4"));
	model->setItem(1, 0, item);

	item = new QStandardItem(QString("5"));
	model->setItem(1, 1, item);

	item = new QStandardItem(QString("6"));
	model->setItem(1, 2, item);

	item = new QStandardItem(QString("7"));
	model->setItem(1, 3, item);
	*/
	ui.tableView->setModel(model);

	ui.tableView->resizeRowsToContents();
	ui.tableView->resizeColumnsToContents();
}

showDB::~showDB()
{
}


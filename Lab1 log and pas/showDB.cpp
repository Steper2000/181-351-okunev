#include "showDB.h"
#include <cstdlib>  // для функции atoi
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

void chil(DataBase &eshkere, std::string sso)
{
	int cif;
	//int j=0;
	if (sso[0] == '<')
	{
		if (sso[1] == '=')
		{
			sso.erase(sso.begin());
			sso.erase(sso.begin());
			cif = std::stoi(sso);
			int id;
			for (int i = 0; i < eshkere.db.size(); i++)
			{
				id = std::stoi(eshkere.db[i].sum);

				if (id > cif)
				{
					eshkere.del_data(i);
					i--;
				}
			}
		}
		else 
		{
			//std::string::size_type sz;
			sso.erase(sso.begin());
			cif = std::stoi(sso);
			int id;
			for (int i = 0; i < eshkere.db.size(); i++)
			{
				id = std::stoi(eshkere.db[i].sum);

				if (id >= cif)
				{
					eshkere.del_data(i);
					i--;
				}
			}
		}
	}
	else
	{
		if (sso[0] == '>')
		{
			
			if (sso[1] == '=')
			{
				sso.erase(sso.begin());
				sso.erase(sso.begin());
				cif = std::stoi(sso);
				int id;
				for (int i = 0; i < eshkere.db.size(); i++)
				{
					id = std::stoi(eshkere.db[i].sum);

					if (id < cif)
					{
						eshkere.del_data(i);
						i--;
					}
				}
			}
			else
			{
				sso.erase(sso.begin());
				cif = std::stoi(sso);

				int id;
				for (int i = 0; i < eshkere.db.size(); i++)
				{
					id = std::stoi(eshkere.db[i].sum);

					if (id <= cif)
					{
						eshkere.del_data(i);
						i--;
					}
				}
			}
		}
		else
		{

			//sso.erase(sso.begin());
			cif = std::stoi(sso);

			int id;
			for (int i = 0; i < eshkere.db.size(); i++)
			{
				id = std::stoi(eshkere.db[i].sum);

				if (id != cif)
				{
					eshkere.del_data(i);
					i--;
				}
			}
		}
	}
}


void showDB::on_delsor_clicked()
{
	//showDB();
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
		model->setItem(i - 1, 0, item);

		item = new QStandardItem(QString::fromStdString(eshkere.db[i].otr));
		model->setItem(i - 1, 1, item);

		item = new QStandardItem(QString::fromStdString(eshkere.db[i].date));
		model->setItem(i - 1, 2, item);

		item = new QStandardItem(QString::fromStdString(eshkere.db[i].nal));
		model->setItem(i - 1, 3, item);

		item = new QStandardItem(QString::fromStdString(eshkere.db[i].sum));
		model->setItem(i - 1, 4, item);
	}

	ui.tableView->setModel(model);

	ui.tableView->resizeRowsToContents();
	ui.tableView->resizeColumnsToContents();
}

void showDB::on_sort_clicked()
{
	model = new QStandardItemModel;
	QStandardItem *item;
	QStringList horizontalHeader;
	horizontalHeader.append("Company");
	horizontalHeader.append("Industry");
	horizontalHeader.append("Date");
	horizontalHeader.append("Tax");
	horizontalHeader.append("Sum");
	model->setHorizontalHeaderLabels(horizontalHeader);
	DataBase eshkere, tab;
	eshkere.download();
	QString sor= ui.lineEdit->text();
	std::string so = sor.toStdString();
	int id;
	
	//на компанию сортирует
	if (so != "")
	{
		id = eshkere.find(so);
		//int i = 0;
		if (id == -1)
		{
			QMessageBox m;
			m.setText("Not in database");
			m.exec();
		}
		while (id!=-1)
		{
			tab.add_data(eshkere.db[id]);
			id = eshkere.find(so, id);
		}
	}
	
	//на отрасль сортирует
	QString ssor = ui.lineEdit_2->text();
	std::string sso = ssor.toStdString();
	if (sso != "")
	{
		
		id = eshkere.find(sso, -1);
		//int i = 0;
		if (id == -1)
		{
			QMessageBox m;
			m.setText("Not in database");
			m.exec();
		}
		else 
		{
			//for(int i=0; i<tab.db.size();)
			if (so != "")
			{
				int r;
					for (int i = 0; i < tab.db.size(); i++)
					{
					
						if (i != tab.find(sso, i - 1))
						{
							tab.del_data(i);
							i--;
						}
					}
				
			}
			else 
			{
				while (id != -1)
				{
					tab.add_data(eshkere.db[id]);
					id = eshkere.find(sso, id);
				}
			}
		}
	}
	
	//на дату сортирует
	QString sssor = ui.lineEdit_3->text();
	std::string ssso = sssor.toStdString();
	if (ssso != "")
	{

		id = eshkere.find(ssso, -1);
		//int i = 0;
		if (id == -1)
		{
			QMessageBox m;
			m.setText("Not in database");
			m.exec();
		}
		else
		{
			//for(int i=0; i<tab.db.size();)
			if (so != "")
			{
				int r;
				for (int i = 0; i < tab.db.size(); i++)
				{
					r = tab.find(ssso, i - 1);
					if (i != r)
					{
						tab.del_data(i); 
						i--;
					}
				}

			}
			else
			{
				if (sso != "")
				{
					int r;
					for (int i = 0; i < tab.db.size(); i++)
					{
						r = tab.find(ssso, i - 1);
						if (i != r)
						{
							tab.del_data(i); 
							i--;
						}
					}
			    }
				else 
				{
					while (id != -1)
					{
						tab.add_data(eshkere.db[id]);
						id = eshkere.find(ssso, id);
					}
				}
			}
		}
	}
	
	//на налог сортирует
	QString ssssor = ui.lineEdit_4->text();
	std::string sssso = ssssor.toStdString();
	if (sssso != "")
	{

		id = eshkere.find(sssso, -1);
		//int i = 0;
		if (id == -1)
		{
			QMessageBox m;
			m.setText("Not in database");
			m.exec();
		}
		else
		{
			//for(int i=0; i<tab.db.size();)
			if (so != "")
			{
				int r;
				for (int i = 0; i < tab.db.size(); i++)
				{
					r = tab.find(sssso, i - 1);
					if (i != r)
					{
						tab.del_data(i);
						i--;
					}
				}

			}
			else
			{
				if (sso != "")
				{
					int r;
					for (int i = 0; i < tab.db.size(); i++)
					{
						r = tab.find(sssso, i - 1);
						if (i != r)
						{
							tab.del_data(i);
							i--;
						}
					}
				}
				else
				{
					if (ssso != "")
					{
						int r;
						for (int i = 0; i < tab.db.size(); i++)
						{
							r = tab.find(sssso, i - 1);
							if (i != r)
							{
								tab.del_data(i);
								i--;
							}
						}
					}

					else 
					{
						while (id != -1)
						{
							tab.add_data(eshkere.db[id]);
							id = eshkere.find(sssso, id);
						}
					}
				}
			}
		}
	}
	
	//на сумму сортирует
	QString vor = ui.lineEdit_5->text();
	std::string vo = vor.toStdString();
	if (vor != "")
	{
		if (so != "")
		{
			chil(tab, vo);
		}
		else
		{
			if (sso != "")
			{
				chil(tab, vo);
			}
			else
			{
				if (ssso != "")
				{
					chil(tab, vo);
				}
				else
				{
					if (sssso != "")
					{
						chil(tab, vo);
					}
					else
					{
						for (int i = 1; i < eshkere.db.size()-1; i++)
						{
							tab.add_data(eshkere.db[i]);
						}
						chil(tab, vo);
					}
				}
			}
		}
		
	}
	/*while (id != 0)
		{

			item = new QStandardItem(QString::fromStdString(eshkere.db[id].pred));
			model->setItem(j, 0, item);

			item = new QStandardItem(QString::fromStdString(eshkere.db[id].otr));
			model->setItem(j, 1, item);

			item = new QStandardItem(QString::fromStdString(eshkere.db[id].date));
			model->setItem(j, 2, item);

			item = new QStandardItem(QString::fromStdString(eshkere.db[id].nal));
			model->setItem(j, 3, item);

			item = new QStandardItem(QString::fromStdString(eshkere.db[id].sum));
			model->setItem(j, 4, item);
			id = eshkere.find(so, id);
			j++;
		}
		
	}
	else
	{
		item = new QStandardItem(QString::fromStdString("Why are you press me!?"));
		model->setItem(j, 0, item);
	}
	
	
	
	//на сумму сортирует
	if (ui.lineEdit_5->text()!= "")
	{
		sor = ui.lineEdit_5->text();
		std::string sso = sor.toStdString();
		int cif;
		//int j=0;
		if (sso[0]=='<')
		{
			//std::string::size_type sz;
			sso.erase(sso.begin());
			cif = std::stoi(sso);
			
			for (int i = 1; i < eshkere.db.size(); i++)
			{
				id = std::stoi(eshkere.db[i].sum);
				
				if(id < cif)
				{
					item = new QStandardItem(QString::fromStdString(eshkere.db[i].pred));
					model->setItem(j, 0, item);

					item = new QStandardItem(QString::fromStdString(eshkere.db[i].otr));
					model->setItem(j, 1, item);

					item = new QStandardItem(QString::fromStdString(eshkere.db[i].date));
					model->setItem(j, 2, item);

					item = new QStandardItem(QString::fromStdString(eshkere.db[i].nal));
					model->setItem(j, 3, item);

					item = new QStandardItem(QString::fromStdString(eshkere.db[i].sum));
					model->setItem(j, 4, item);
					j++;
				}
		    }
		}
		else
		{
			if (sso[0] == '>')
			{
				sso.erase(sso.begin());
				cif = std::stoi(sso);
				
				for (int i = 1; i < eshkere.db.size(); i++)
				{
					id = std::stoi(eshkere.db[i].sum);

					if (id > cif)
					{
						item = new QStandardItem(QString::fromStdString(eshkere.db[i].pred));
						model->setItem(j, 0, item);

						item = new QStandardItem(QString::fromStdString(eshkere.db[i].otr));
						model->setItem(j, 1, item);

						item = new QStandardItem(QString::fromStdString(eshkere.db[i].date));
						model->setItem(j, 2, item);

						item = new QStandardItem(QString::fromStdString(eshkere.db[i].nal));
						model->setItem(j, 3, item);

						item = new QStandardItem(QString::fromStdString(eshkere.db[i].sum));
						model->setItem(j, 4, item);
						j++;
					}
				}
			}
			else
			{
				//sso.erase(sso.begin());
				cif = std::stoi(sso);
				
				for (int i = 1; i < eshkere.db.size(); i++)
				{
					id = std::stoi(eshkere.db[i].sum);

					if (id == cif)
					{
						item = new QStandardItem(QString::fromStdString(eshkere.db[i].pred));
						model->setItem(j, 0, item);

						item = new QStandardItem(QString::fromStdString(eshkere.db[i].otr));
						model->setItem(j, 1, item);

						item = new QStandardItem(QString::fromStdString(eshkere.db[i].date));
						model->setItem(j, 2, item);

						item = new QStandardItem(QString::fromStdString(eshkere.db[i].nal));
						model->setItem(j, 3, item);

						item = new QStandardItem(QString::fromStdString(eshkere.db[i].sum));
						model->setItem(j, 4, item);
						j++;
					}
				}
			}
		}
	}*/
	
for (int i = 0; i < tab.db.size(); i++)
{
	item = new QStandardItem(QString::fromStdString(tab.db[i].pred));
	model->setItem(i , 0, item);

	item = new QStandardItem(QString::fromStdString(tab.db[i].otr));
	model->setItem(i, 1, item);

	item = new QStandardItem(QString::fromStdString(tab.db[i].date));
	model->setItem(i , 2, item);

	item = new QStandardItem(QString::fromStdString(tab.db[i].nal));
	model->setItem(i , 3, item);

	item = new QStandardItem(QString::fromStdString(tab.db[i].sum));
	model->setItem(i , 4, item);
}

    ui.tableView->setModel(model);
	ui.tableView->resizeRowsToContents();
	ui.tableView->resizeColumnsToContents();
}


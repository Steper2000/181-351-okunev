#include "add.h"
#include "classdb.h"
#include <QMessageBox>
add::add(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

add::~add()
{
}

void add::on_pushButton_del_clicked()//сомнительное, но чётко работающее удаление
{
	datas da;
	DataBase db;
	QString a = ui.ld1->text();
	if (a!="")
	{
		if (a == "0") 
		{
			QMessageBox m;
			m.setText("Nothing wasn't added for delete");
			m.exec();
		}
		else 
		{
			int id = a.toInt();
			db.download();
			db.del_data(id);
			db.write2file();
			QMessageBox m;
			m.setText("Data deleted");
			m.exec();
		}
	}
	else
	{
		a = ui.ld2->text();
		if (a != "") {
			db.download();
			db.del_data(db.find(a.toStdString()));
			db.write2file();
				QMessageBox m;
				m.setText("Data deleted");
				m.exec();
			
		}
		else{
			QMessageBox m;
			m.setText("Nothing wasn't added for delete");
			m.exec();
		}
	}
}

void add::on_pushButton_add_clicked() //добавляет чётко
{
	datas da;
	QString a= ui.lc->text();
	da.pred = a.toStdString();
	QString b = ui.li->text();
	da.otr = b.toStdString();
	QString c = ui.ld->text();
	da.date = c.toStdString();
	QString d = ui.ln->text();
	da.nal = d.toStdString();
	QString e = ui.ls->text();
	da.sum = e.toStdString();
	DataBase db;
	db.download();
	//db.add_data(da);
	if (db.add_data(da)) 
	{
		db.write2file();
		QMessageBox m;
		m.setText("Data added");
		m.exec();
	}
	else{ QMessageBox m;
		m.setText("Data don't add! Wrong Industry!");
		m.exec(); }
}

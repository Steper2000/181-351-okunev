#include "change.h"
//#include "Lab1logandpas.h"
change::change(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

change::~change()
{
}

void change::on_pushButton_change_close()
{
	FILE *b;
	b=fopen("database.txt", "r");
	QString blog = ui.line_blogin->text();
	QString nlog = ui.line_Nlogin->text();
	QString npass = ui.line_Npassword->text();
	// QString aaa

}
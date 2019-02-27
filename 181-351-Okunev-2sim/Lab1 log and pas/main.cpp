#include "Lab1logandpas.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	//setlocale(LC_ALL, "Russian");
	QApplication a(argc, argv);
	Lab1logandpas w;
	w.show();
	return a.exec();
}

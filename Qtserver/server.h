#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

/*
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
*/
class server : public QObject
{
	Q_OBJECT

public:
	server(QObject *parent=nullptr);
	~server();
public slots:
	void slotNewConnection();//вход
	void slotClientDis();//выход
	//void slotServerRead();// чтение
	void slotReadClient();

private:
	QTcpServer * mtser;
	//QTcpSocket * mtsoc;
	int server_status;
	QMap<int,QTcpSocket *> SClient;
};

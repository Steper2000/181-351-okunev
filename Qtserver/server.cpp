#include "server.h"
#include <QDateTime>
//Qtsp server конспект
server::server(QObject *parent)
	: QObject(parent)
{
	mtser = new QTcpServer(this);
	connect(mtser, &QTcpServer::newConnection, this, &server::slotNewConnection);
	if(!mtser->listen(QHostAddress::Any, 33333)&&server_status==0)
	{
		qDebug() << "server is not started";
	}
	else {
		server_status = 1;
		qDebug() << "server is started";
	}
}

server::~server()
{
	server_status = 0;
}


void server::slotNewConnection()
{
	if (server_status == 1)
	{
		/*
		mtsoc = mtser->nextPendingConnection();
		mtsoc->write("hello world");
			connect(mtsoc, &QTcpSocket::readyRead, this, &server::slotReadClient);
			connect(mtsoc, &QTcpSocket::disconnected, this, &server::slotClientDis);*/
		qDebug() << QString::fromUtf8("new conection");
		QTcpSocket* clientSocket =mtser->nextPendingConnection();
		int id = clientSocket->socketDescriptor();
		SClient[id] = clientSocket;
		connect(SClient[id],  SIGNAL(readyRead()), this, SLOT(slotReadClient()));
		connect(SClient[id], &QTcpSocket::disconnected, this, &server::slotClientDis); 
	}
}


void server::slotClientDis()
{	if (server_status == 1)
	{
		//mtsoc->close();
	
		foreach(int i, SClient.keys()) {
			QTextStream os(SClient[i]);
			os.setAutoDetectUnicode(true);
			os << QDateTime::currentDateTime().toString() << "\n";
			SClient[i]->close();
			SClient.remove(i);
		}
		mtser->close();
		qDebug() << QString::fromUtf8("server stoped");
			server_status = 0;
	}
}

void server::slotReadClient()
{
	QObject * object = QObject::sender(); 
	QTcpSocket * socket = static_cast<QTcpSocket *>(object);
	QTextStream os(socket);
	os.setAutoDetectUnicode(true);
	os << "\hello! you conected ";
}


/*
void server::slotServerRead()
{
	 /*array;
	while (mtsoc->bytesAvailable() > 0)
	{
		QByteArray array = mtsoc->readAll();
		char str = *array.data();
		str+=1;
		mtsoc->write(' '+ QByteArray::fromStdString((std::string)&str));
	}
	QTextStream os(mtsoc);
	os.setAutoDetectUnicode(true);
	os << "\nfffffffffffffff";
} */

#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

#include<QTimer>
#include<QTcpSocket>
#include<QThread>
#include<QString>
#include"table.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QSqlError>

class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = nullptr);

    ~client();

    QTcpSocket *tcpSocket;

    QString userName;

    QSqlQuery oper;

    QTimer* readTimer;

    QTimer* upOnline;

    int linkflag;

    bool ban;

    bool remove;






signals:

    void discon(void);


public slots:
    void cliThread(void);



};



#endif // CLIENT_H

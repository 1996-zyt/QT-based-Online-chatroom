#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include<QMap>
#include <QThread>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QMessageBox>
#include<QKeyEvent>
#include<QProcess>
#include"client.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    int numUser;

    QProcess process;

    QStringList blackList;

    QTcpServer *tcpServer;

    QMap <client*,QThread*> user;

    QSqlDatabase* mydb;

    QSqlQuery* oper;

    QMap <client*,QThread*>::iterator Select(void);

    bool eventFilter(QObject *target, QEvent *event) override;



signals:


private slots:
    void on_send_clicked();

    void on_remove_clicked();

    void on_showIp_clicked();

    void on_ban_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;





};

#endif // WIDGET_H

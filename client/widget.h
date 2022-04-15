#ifndef WIDGET_H
#define WIDGET_H

#include<QWidget>
#include<QMessageBox>
#include<QTcpSocket>
#include<QKeyEvent>
#include<QTimer>

#if _MSC_VER >=1600    // MSVC2015>1899,对于MSVC2010以上版本都可以使用
#pragma execution_character_set("utf-8")
#endif

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int linkflag;

private slots:
    void on_link_clicked();

    void on_send_clicked();

    void on_leave_clicked();

    void on_out_clicked();


    void on_name_returnPressed();

    void on_pow_returnPressed();


private:
    Ui::Widget *ui;

    QString userName;

    QTcpSocket *tcpSocket;

    QTimer *linkTimer;

    bool eventFilter(QObject *target, QEvent *event) override;




};

#endif // WIDGET_H

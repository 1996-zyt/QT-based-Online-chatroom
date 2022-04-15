#include "widget.h"
#include "ui_widget.h"


#if _MSC_VER >=1600    // MSVC2015>1899,����MSVC2010���ϰ汾������ʹ��
#pragma execution_character_set("utf-8")
#endif

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    linkflag=0;
    userName="(��)";
    tcpSocket=new QTcpSocket(this);
    linkTimer=new QTimer(this);


    ui->pow->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9]+$"),ui->pow));
    ui->name->setFocus();
    ui->textEdit->setPlaceholderText("�����롭�� ");
    ui->textEdit->installEventFilter(this);// �����¼�������

    connect(tcpSocket,&QTcpSocket::connected,this,[=](){
        linkflag=1;
    });

    connect(linkTimer,&QTimer::timeout,this,[=](){
        if(linkflag==0)
        {
            tcpSocket->disconnectFromHost();
            tcpSocket->close();
            linkTimer->stop();
            QMessageBox::warning(this,"��½��ʾ","δ�����ӵ������");

        }
        if(linkflag==1)
        {
            QString str=ui->name->text()+"zyt"+ui->pow->text();
            tcpSocket->write(str.toUtf8().data());
            tcpSocket->flush();
        }
        if(linkflag==2)
        {
            linkTimer->stop();
            QMessageBox::information(this,"��½�ɹ�","�ѽ��������� ");
        }
        ui->link->setDisabled(false);
    });
    connect(tcpSocket,&QTcpSocket::readyRead,this,[=](){
        QString str=QString(tcpSocket->readAll());
        if(linkflag==1)
        {
            linkflag=2;
            ui->listWidget->clear();
            ui->textBrowser->clear();
            ui->textEdit->clear();
            setWindowTitle("�����ҿͻ��ˡ��� "+ui->name->text());
            ui->textEdit->setFocus();
            ui->stackedWidget->setCurrentIndex(1);
        }
        if(str.left(3)=="245")
        {
            QStringList slist=str.split("245");
            slist.removeFirst();
            ui->listWidget->clear();
            ui->listWidget->addItems(slist);

        }
        else  ui->textBrowser->append(str);
    });

    connect(tcpSocket,&QTcpSocket::disconnected,this,[=](){
        if(linkflag==1)
        {
            linkTimer->stop();
            QMessageBox::warning(this,"��½ʧ�� ","����ԭ��\n   1.�˺��������\n   2.���˺��ѵ�½��\n   3.���˺ű������������ ");
        }
        if(linkflag==2)
        {

            setWindowTitle("�����ҿͻ��˵�½ ");
            ui->stackedWidget->setCurrentIndex(0);
            ui->name->setFocus();
            QMessageBox::warning(this,"�ǳ���ʾ","��������Ͽ����� ");
        }
        if(linkflag==3)
        {


            setWindowTitle("�����ҿͻ��˵�½ ");
            ui->stackedWidget->setCurrentIndex(0);
            QMessageBox::information(this,"�ǳ���ʾ","���˳������� ");
        }
        ui->pow->clear();
        ui->name->setFocus();
        tcpSocket->close();
        linkflag=0;
    });

    connect(this,&Widget::destroyed,[=](){
        linkflag=0;
    });



}

Widget::~Widget()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    delete ui;
    delete tcpSocket;
    delete linkTimer;
}

void Widget::on_link_clicked()
{
    if(ui->name->text().isEmpty()||ui->pow->text().isEmpty())
    {
        QMessageBox::warning(this,"��½ʧ��","������������Ϣ ");
        return;
    }
    ui->link->setDisabled(true);
    tcpSocket->connectToHost("127.0.0.1",6966);
    linkTimer->start(500);
}

void Widget::on_send_clicked()
{
    QString str=ui->textEdit->toPlainText();
    tcpSocket->write(str.toUtf8().data());
    tcpSocket->flush();
    ui->textEdit->clear();
}

void Widget::on_leave_clicked()
{
    linkflag=3;
    tcpSocket->disconnectFromHost();
}



void Widget::on_out_clicked()
{
    close();
}

bool Widget::eventFilter(QObject *target, QEvent *event)
{

    if (target == ui->textEdit)
    {

        QKeyEvent *k = static_cast<QKeyEvent *>(event);
        if(k->key() == Qt::Key_Return)
        {
            on_send_clicked();
            return true;
        }

    }
    return QWidget::eventFilter(target,event);
}

void Widget::on_name_returnPressed()
{
    ui->pow->setFocus();
}

void Widget::on_pow_returnPressed()
{
    on_link_clicked();
}


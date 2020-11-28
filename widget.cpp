
#include "widget.h"
#include "ui_widget.h"
#include"table.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*---------------------打开数据库--------------------------*/
    mydb=new QSqlDatabase;
    *mydb=QSqlDatabase::addDatabase("QMYSQL");
    mydb->setHostName("localhost");
    mydb->setDatabaseName("mysql");
    mydb->setPort(3306);
    mydb->setUserName("root");
    mydb->setPassword("123456");
    if(!mydb->open())
    {
        QMessageBox::warning(this,"数据库打开失败",mydb->lastError().text());
        close();
    }
            oper=new QSqlQuery;
            oper->exec("USE mydb;");
    /*--------------------------------------------------------*/


    ui->textEdit->installEventFilter(this);//设置事件过滤器
    ui->textEdit->setPlaceholderText("请输入……");
    ui->textEdit->setFocus();

    numUser=0;
    tcpServer=new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,9999);
    QTimer* linkTimer=new QTimer(this);

    onLine<<"在线人数：0";
    message.enqueue(tr("245%1").arg(onLine[0]).toUtf8().data());
    readNum=0;

    blackList<<"黑名单：";
    oper->exec("select userName from userinfor where flag1=1;");
            while(oper->next())
            {
                blackList<<oper->value(0).toString();
            }
    ui->bList->addItems(blackList);


    linkTimer->start(50);


    connect(tcpServer,&QTcpServer::newConnection,this,[=](){
        qDebug()<<"123";
        client* user0=new client;
        QThread* thread0=new QThread(this);
        QMap <client*,QThread*>::iterator iter= user.insert(user0,thread0);
        iter.key()->tcpSocket=tcpServer->nextPendingConnection();
        iter.key()->moveToThread(iter.value());
        iter.value()->start();
        connect(iter.value(),&QThread::started,iter.key(),&client::cliThread);
        connect(iter.key(),&client::discon,this,[=](){
            disconnect(iter.value(),0,0,0);
            disconnect(iter.key(),0,0,0);
            iter.value()->quit();
            iter.value()->wait();
            delete iter.key();
            delete iter.value();
            user.erase(iter);
        });
    });


    connect(linkTimer,&QTimer::timeout,this,[=](){


        if(readNum==0)
        {
            QString str=QString(message.dequeue());
            if(str.left(3)=="245")
            {
                QStringList slist=str.split("245");
                slist.removeFirst();
                ui->userlist->clear();
                ui->userlist->addItems(slist);

            }
            else
                {
                ui->textBrowser->append(str);
                }
            if(!message.empty())
            {
                readNum=onLine.count()-1;
            }
            readNum--;
        }
        else if(readNum==-1&&!message.empty())
        {
            readNum=onLine.count()-1;
        }
   });
}


QMap <client*,QThread*>::iterator Widget::Select(void)
{
    QString str=ui->userlist->currentItem()->text();
    for (QMap <client*,QThread*>::iterator iter= user.begin(); iter != user.end(); iter++)
        if(iter.key()->userName==str)
        {
            return iter;
        }
    return NULL;
}


Widget::~Widget()
{
    mydb->close();
    delete ui;
    delete oper;
    delete mydb;

    for (QMap <client*,QThread*>::iterator iter= user.begin(); iter != user.end(); iter++)
    {

        iter.value()->quit();
        iter.value()->wait();
        delete iter.key();
        delete iter.value();
    }

}





void Widget::on_send_clicked()
{
    if(!ui->textEdit->document()->isEmpty())
    {
        QString str=ui->textEdit->toPlainText();
        oper->exec("INSERT INTO record VALUES((select now()) ,'管理员','"+str+"');");
        str="管理员："+str;
        message.enqueue(str.toUtf8().data());
        ui->textEdit->clear();
    }

}

void Widget::on_remove_clicked()
{
    if(ui->userlist->currentRow()>0)
    {
        QMap <client*,QThread*>::iterator iter=Select();
        oper->exec("UPDATE userinfor SET flag1=1 WHERE userName='"+iter.key()->userName+"';");
        blackList<<iter.key()->userName;
        iter.key()->remove=1;
        iter.key()->tcpSocket->disconnected();
        ui->bList->clear();
        ui->bList->addItems(blackList);
        }


}

void Widget::on_showIp_clicked()
{
    if(ui->userlist->currentRow()>0)
    {
        QMap <client*,QThread*>::iterator iter=Select();
        ui->textBrowser->append(iter.key()->userName+"的IP地址为"+iter.key()->tcpSocket->peerAddress().toString().remove("::ffff"));
    }
}

void Widget::on_ban_clicked()
{
    if(ui->userlist->currentRow()>0)
    {
        QMap <client*,QThread*>::iterator iter=Select();
        QString str=iter.key()->userName;
        if(iter.key()->ban==true)
        {
            iter.key()->ban=false;
            str+="已被解除禁言。";
            oper->exec("UPDATE userinfor SET flag0=0 WHERE userName='"+iter.key()->userName+"';");
            }
        else
        {
            iter.key()->ban=true;
            str+="已被禁言。";
            oper->exec("UPDATE userinfor SET flag0=1 WHERE userName='"+iter.key()->userName+"';");
         }
         oper->exec("INSERT INTO record VALUES((select now()) ,'系统','"+str+"');");
        message.enqueue(str.toUtf8().data());
    }
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

void Widget::on_pushButton_clicked()//移出黑名单
{
    if(ui->bList->currentRow()>0)
    {
        QString str=ui->bList->currentItem()->text();
        oper->exec("UPDATE userinfor SET flag1=0 WHERE userName='"+str+"';");
        blackList.removeOne(str);
        str+="已被移出黑名单";
        message.enqueue(str.toUtf8().data());
        ui->bList->clear();
        ui->bList->addItems(blackList);
    }
}

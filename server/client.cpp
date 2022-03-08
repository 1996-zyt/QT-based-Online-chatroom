#include "client.h"
#include"table.h"


client::client(QObject *parent) : QObject(parent)
{
    tcpSocket=NULL;
    ban=0;
    remove=0;


}


void client::cliThread()
{
    readTimer=new QTimer(this);
    upOnline=new QTimer(this);
    linkflag=0;
    QTimer* longin=new QTimer;
    longin->start(500);
    connect(longin,&QTimer::timeout,this,[=](){
        longin->stop();
        delete longin;
        emit discon();
    });


    connect(tcpSocket,&QTcpSocket::readyRead,this,[=](){
        if(linkflag==0)
        {
            longin->stop();
            delete longin;
            QString str=QString(tcpSocket->readAll());
            QStringList list=str.split("zyt");
            oper.exec("select flag0 from userinfor where userName='"+list[0]+"'and userPow='"+list[1]+"'and flag1=0;");

            if(!oper.next()||onLine.contains(list[0]))
            {
                emit discon();
            }
            else
            {
                linkflag=1;
                userName=list[0];
                readTimer->start(100);
                ban=oper.value(0).toBool();
                onLine<<userName;
                onLine.first()="在线人数："+QString::number(onLine.count()-1);
                tcpSocket->write("欢迎使用聊天室！");
                tcpSocket->flush();
                upOnline->start(200);
            }


        }
        else {
            QString str0=QString(tcpSocket->readAll());
            if(ban)
            {
                tcpSocket->write("您已被禁言！");
                tcpSocket->flush();
                return;
            }
            oper.exec("INSERT INTO record VALUES((select now()) ,'"+userName+"','"+str0+"');");
            QString str=userName+"："+str0;
            message.enqueue(str.toUtf8().data());

        }
    });

    connect(tcpSocket,&QTcpSocket::disconnected,this,[=](){
        readTimer->stop();
        onLine.removeOne(userName);
        onLine.first()="在线人数："+QString::number(onLine.count()-1);
        QString str;
        if(remove)
            str=userName+"被移出聊天室。";
        else str=userName+"退出聊天室。";
        oper.exec("INSERT INTO record VALUES((select now()) ,'系统','"+str+"');");
        message.enqueue(str.toUtf8().data());
        linkflag=3;
        upOnline->start(200);


    });


    connect(readTimer,&QTimer::timeout,this,[=](){

        if(readNum>0)
        {
            readNum--;
            tcpSocket->write(message.head());
            tcpSocket->flush();
        }
    });
    connect(upOnline,&QTimer::timeout,this,[=](){

        if(linkflag==1)
        {
            QString str0=QString(userName+"进入聊天室。");
            message.enqueue(str0.toUtf8().data());
            oper.exec("INSERT INTO record VALUES((select now()) ,'系统','"+str0+"');");

            linkflag=2;
        }
        else if(linkflag==2)
        {
            QString str;
            for(int i = 0; i< onLine.size();++i)
                str+="245"+onLine[i];
            message.enqueue(str.toUtf8().data());
            upOnline->stop();
        }
        else if(linkflag==3)
        {
            QString str;
            for(int i = 0; i< onLine.size();++i)
                str+="245"+onLine[i];
            message.enqueue(str.toUtf8().data());
            upOnline->stop();
            emit discon();
        }
    });
}





client::~client()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    delete tcpSocket;
}

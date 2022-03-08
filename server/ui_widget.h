/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textEdit;
    QListWidget *userlist;
    QListWidget *bList;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *showIp;
    QPushButton *ban;
    QPushButton *remove;
    QPushButton *pushButton;
    QPushButton *send;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(600, 400);
        Widget->setMinimumSize(QSize(600, 400));
        Widget->setMaximumSize(QSize(600, 400));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(10);
        Widget->setFont(font);
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(11, 299, 471, 91));
        textEdit->setMaximumSize(QSize(16777215, 100));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        textEdit->setFont(font1);
        textEdit->setReadOnly(false);
        userlist = new QListWidget(Widget);
        userlist->setObjectName(QStringLiteral("userlist"));
        userlist->setGeometry(QRect(370, 10, 111, 281));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        userlist->setFont(font2);
        bList = new QListWidget(Widget);
        bList->setObjectName(QStringLiteral("bList"));
        bList->setGeometry(QRect(489, 10, 101, 201));
        bList->setMinimumSize(QSize(0, 0));
        bList->setMaximumSize(QSize(16777215, 99999));
        bList->setFont(font2);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(490, 220, 101, 170));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        showIp = new QPushButton(widget);
        showIp->setObjectName(QStringLiteral("showIp"));
        QFont font3;
        font3.setPointSize(10);
        showIp->setFont(font3);

        verticalLayout->addWidget(showIp);

        ban = new QPushButton(widget);
        ban->setObjectName(QStringLiteral("ban"));
        ban->setFont(font3);

        verticalLayout->addWidget(ban);

        remove = new QPushButton(widget);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setFont(font3);

        verticalLayout->addWidget(remove);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        send = new QPushButton(widget);
        send->setObjectName(QStringLiteral("send"));
        send->setFont(font3);

        verticalLayout->addWidget(send);

        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(11, 11, 351, 281));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        textBrowser->setFont(font4);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\350\201\212\345\244\251\345\256\244\346\234\215\345\212\241\345\231\250", nullptr));
        textEdit->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\351\273\221\344\275\223'; font-size:10pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        showIp->setText(QApplication::translate("Widget", "\346\237\245\347\234\213IP", nullptr));
        ban->setText(QApplication::translate("Widget", "\347\246\201\350\250\200/\350\247\243\347\246\201", nullptr));
        remove->setText(QApplication::translate("Widget", "\350\270\242\345\207\272\345\271\266\346\213\211\351\273\221", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\347\247\273\345\207\272\351\273\221\345\220\215\345\215\225", nullptr));
        send->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

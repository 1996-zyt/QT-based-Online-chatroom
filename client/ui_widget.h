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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *link;
    QPushButton *out;
    QLabel *title;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *name;
    QLabel *label_4;
    QLineEdit *pow;
    QWidget *page_2;
    QPushButton *leave;
    QListWidget *listWidget;
    QTextEdit *textEdit;
    QTextBrowser *textBrowser;
    QPushButton *send;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(600, 400);
        Widget->setMinimumSize(QSize(600, 400));
        Widget->setMaximumSize(QSize(600, 400));
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QFont font;
        font.setPointSize(9);
        stackedWidget->setFont(font);
        stackedWidget->setLineWidth(0);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        link = new QPushButton(page);
        link->setObjectName(QStringLiteral("link"));
        link->setGeometry(QRect(70, 290, 141, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200"));
        font1.setPointSize(15);
        link->setFont(font1);
        link->setTabletTracking(false);
        link->setIconSize(QSize(20, 20));
        out = new QPushButton(page);
        out->setObjectName(QStringLiteral("out"));
        out->setGeometry(QRect(340, 290, 161, 41));
        out->setFont(font1);
        out->setIconSize(QSize(20, 20));
        title = new QLabel(page);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(60, 30, 461, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font2.setPointSize(40);
        font2.setBold(false);
        font2.setWeight(50);
        title->setFont(font2);
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 130, 387, 131));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200"));
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setWeight(50);
        label_5->setFont(font3);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        name = new QLineEdit(layoutWidget);
        name->setObjectName(QStringLiteral("name"));
        name->setFont(font1);

        gridLayout->addWidget(name, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font3);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        pow = new QLineEdit(layoutWidget);
        pow->setObjectName(QStringLiteral("pow"));
        pow->setFont(font1);
        pow->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(pow, 1, 1, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(13);
        font4.setBold(false);
        font4.setWeight(50);
        page_2->setFont(font4);
        leave = new QPushButton(page_2);
        leave->setObjectName(QStringLiteral("leave"));
        leave->setGeometry(QRect(450, 300, 141, 41));
        leave->setFont(font3);
        listWidget = new QListWidget(page_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(450, 10, 141, 281));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font5.setPointSize(13);
        listWidget->setFont(font5);
        textEdit = new QTextEdit(page_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 300, 431, 91));
        textBrowser = new QTextBrowser(page_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 431, 281));
        send = new QPushButton(page_2);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(450, 350, 141, 41));
        send->setFont(font3);
        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\350\201\212\345\244\251\345\256\244\345\256\242\346\210\267\347\253\257", nullptr));
        link->setText(QApplication::translate("Widget", "\350\277\233\345\205\245\350\201\212\345\244\251\345\256\244", nullptr));
        out->setText(QApplication::translate("Widget", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        title->setText(QApplication::translate("Widget", "\346\254\242\350\277\216\344\275\277\347\224\250\350\201\212\345\244\251\345\256\244", nullptr));
        label_5->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        name->setText(QString());
        label_4->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", nullptr));
        leave->setText(QApplication::translate("Widget", "\351\200\200\345\207\272\350\201\212\345\244\251", nullptr));
        send->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

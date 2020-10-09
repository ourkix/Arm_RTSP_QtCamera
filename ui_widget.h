/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <QString>
QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label,*fpslabel;
    QLineEdit *edit,*sizeedit;
    QPushButton *pushButton_start,*changeex,*changesize;
    
    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(650, 620);
        Widget->setMinimumSize(QSize(650, 720));
        Widget->setMaximumSize(QSize(1280, 720));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(5, 5, 640, 480));
        label->setMinimumSize(QSize(640, 480));
        label->setMaximumSize(QSize(1280, 720));
	fpslabel = new QLabel(Widget);
        fpslabel->setObjectName("fpslabel");
        fpslabel->setGeometry(QRect(140, 500, 101, 41));
        fpslabel->setMinimumSize(QSize(101, 41));
        fpslabel->setMaximumSize(QSize(101, 41));

	edit = new QLineEdit(Widget);
	edit->setObjectName("edit");
	edit->setPlaceholderText("Normal");
	edit->setEchoMode(QLineEdit::Normal);
	edit->setGeometry(QRect(20, 570, 400, 41));

        changeex = new QPushButton(Widget);
        changeex->setObjectName(QStringLiteral("changeex"));
        changeex->setGeometry(QRect(450, 570, 101, 41));

	sizeedit = new QLineEdit(Widget);
	sizeedit->setObjectName("sizeedit");
	sizeedit->setPlaceholderText("Normal");
	sizeedit->setEchoMode(QLineEdit::Normal);
	sizeedit->setGeometry(QRect(20, 640, 101, 41));

       changesize = new QPushButton(Widget);
        changesize->setObjectName(QStringLiteral("changesize"));
        changesize->setGeometry(QRect(140, 640, 101, 41));


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "opencvrtsp", 0));
        label->setText(QString());
	fpslabel->setText(QString());
      	changeex->setText(QApplication::translate("Widget", "change", 0));
	changesize->setText(QApplication::translate("Widget", "cgsize", 0));


    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

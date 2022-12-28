/********************************************************************************
** Form generated from reading UI file 'stackform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STACKFORM_H
#define UI_STACKFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StackForm
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *labelGrafico;
    QWidget *widget;
    QPushButton *btnPush;
    QTextEdit *txtInputDato;
    QPushButton *btnPop;
    QWidget *widget_2;
    QLabel *label;
    QLabel *labelCodeImg;
    QLabel *label_2;

    void setupUi(QDialog *StackForm)
    {
        if (StackForm->objectName().isEmpty())
            StackForm->setObjectName("StackForm");
        StackForm->resize(1300, 700);
        StackForm->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        horizontalLayout = new QHBoxLayout(StackForm);
        horizontalLayout->setObjectName("horizontalLayout");
        scrollArea = new QScrollArea(StackForm);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 874, 680));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        labelGrafico = new QLabel(scrollAreaWidgetContents);
        labelGrafico->setObjectName("labelGrafico");

        gridLayout->addWidget(labelGrafico, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        widget = new QWidget(StackForm);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(400, 0));
        widget->setStyleSheet(QString::fromUtf8("/*background: rgb(250,250,250);*/\n"
"background: #9DAABC;"));
        btnPush = new QPushButton(widget);
        btnPush->setObjectName("btnPush");
        btnPush->setGeometry(QRect(240, 130, 111, 41));
        btnPush->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        txtInputDato = new QTextEdit(widget);
        txtInputDato->setObjectName("txtInputDato");
        txtInputDato->setGeometry(QRect(70, 130, 111, 41));
        txtInputDato->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        btnPop = new QPushButton(widget);
        btnPop->setObjectName("btnPop");
        btnPop->setGeometry(QRect(140, 200, 141, 41));
        btnPop->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, -1, 401, 91));
        widget_2->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 20, 101, 51));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";\n"
"color: white;"));
        label->setTextFormat(Qt::AutoText);
        labelCodeImg = new QLabel(widget);
        labelCodeImg->setObjectName("labelCodeImg");
        labelCodeImg->setGeometry(QRect(60, 350, 311, 311));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 300, 201, 41));
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 14pt \"Cooper Black\";\n"
"color: black;"));
        label_2->setTextFormat(Qt::AutoText);

        horizontalLayout->addWidget(widget);

        horizontalLayout->setStretch(0, 3);

        retranslateUi(StackForm);

        QMetaObject::connectSlotsByName(StackForm);
    } // setupUi

    void retranslateUi(QDialog *StackForm)
    {
        StackForm->setWindowTitle(QCoreApplication::translate("StackForm", "Dialog", nullptr));
        labelGrafico->setText(QString());
        btnPush->setText(QCoreApplication::translate("StackForm", "Push", nullptr));
        btnPop->setText(QCoreApplication::translate("StackForm", "Pop", nullptr));
        label->setText(QCoreApplication::translate("StackForm", "Stack", nullptr));
        labelCodeImg->setText(QString());
        label_2->setText(QCoreApplication::translate("StackForm", "Estructura del Nodo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StackForm: public Ui_StackForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STACKFORM_H

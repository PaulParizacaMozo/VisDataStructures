/********************************************************************************
** Form generated from reading UI file 'avlform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVLFORM_H
#define UI_AVLFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_avlform
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QLabel *labelGrafico_2;
    QWidget *widget;
    QPushButton *btnInsertar;
    QTextEdit *inputT;
    QPushButton *btnBuscar;
    QLabel *label_2;
    QLabel *labelCodeImg;
    QWidget *widget_2;
    QLabel *label;
    QTextEdit *inputTFind;

    void setupUi(QDialog *avlform)
    {
        if (avlform->objectName().isEmpty())
            avlform->setObjectName("avlform");
        avlform->resize(1300, 700);
        avlform->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        scrollArea = new QScrollArea(avlform);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(7, 10, 901, 681));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 899, 679));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName("gridLayout_2");
        labelGrafico_2 = new QLabel(scrollAreaWidgetContents_2);
        labelGrafico_2->setObjectName("labelGrafico_2");

        gridLayout_2->addWidget(labelGrafico_2, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);
        widget = new QWidget(avlform);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(915, 10, 381, 681));
        widget->setStyleSheet(QString::fromUtf8("background: #9DAABC;\n"
""));
        btnInsertar = new QPushButton(widget);
        btnInsertar->setObjectName("btnInsertar");
        btnInsertar->setGeometry(QRect(220, 530, 101, 31));
        btnInsertar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        inputT = new QTextEdit(widget);
        inputT->setObjectName("inputT");
        inputT->setGeometry(QRect(90, 530, 111, 31));
        inputT->setStyleSheet(QString::fromUtf8("\n"
"QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        btnBuscar = new QPushButton(widget);
        btnBuscar->setObjectName("btnBuscar");
        btnBuscar->setGeometry(QRect(220, 580, 101, 31));
        btnBuscar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 100, 201, 41));
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 14pt \"Cooper Black\";\n"
"color: black;"));
        label_2->setTextFormat(Qt::AutoText);
        labelCodeImg = new QLabel(widget);
        labelCodeImg->setObjectName("labelCodeImg");
        labelCodeImg->setGeometry(QRect(10, 140, 361, 331));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 381, 91));
        widget_2->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 20, 171, 51));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";\n"
"color: white;"));
        label->setTextFormat(Qt::AutoText);
        inputTFind = new QTextEdit(widget);
        inputTFind->setObjectName("inputTFind");
        inputTFind->setGeometry(QRect(90, 580, 111, 31));
        inputTFind->setStyleSheet(QString::fromUtf8("\n"
"QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));

        retranslateUi(avlform);

        QMetaObject::connectSlotsByName(avlform);
    } // setupUi

    void retranslateUi(QDialog *avlform)
    {
        avlform->setWindowTitle(QCoreApplication::translate("avlform", "Dialog", nullptr));
        labelGrafico_2->setText(QString());
        btnInsertar->setText(QCoreApplication::translate("avlform", "Insertar", nullptr));
        btnBuscar->setText(QCoreApplication::translate("avlform", "Buscar", nullptr));
        label_2->setText(QCoreApplication::translate("avlform", "Estructura del Nodo", nullptr));
        labelCodeImg->setText(QString());
        label->setText(QCoreApplication::translate("avlform", "AVL Tree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class avlform: public Ui_avlform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVLFORM_H

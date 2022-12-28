/********************************************************************************
** Form generated from reading UI file 'binarysform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINARYSFORM_H
#define UI_BINARYSFORM_H

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

class Ui_binarysform
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QLabel *labelGrafico_2;
    QWidget *widget;
    QPushButton *btnInsertar;
    QTextEdit *inputT;
    QPushButton *btnDelete;
    QPushButton *btnBuscar;
    QLabel *label_2;
    QLabel *labelCodeImg;
    QWidget *widget_2;
    QLabel *label;
    QTextEdit *inputT_Find;
    QTextEdit *inputT_Eliminar;

    void setupUi(QDialog *binarysform)
    {
        if (binarysform->objectName().isEmpty())
            binarysform->setObjectName("binarysform");
        binarysform->resize(1300, 700);
        binarysform->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        scrollArea = new QScrollArea(binarysform);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(410, 10, 881, 681));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 879, 679));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName("gridLayout_2");
        labelGrafico_2 = new QLabel(scrollAreaWidgetContents_2);
        labelGrafico_2->setObjectName("labelGrafico_2");

        gridLayout_2->addWidget(labelGrafico_2, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);
        widget = new QWidget(binarysform);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 391, 681));
        widget->setStyleSheet(QString::fromUtf8("background: #9DAABC;"));
        btnInsertar = new QPushButton(widget);
        btnInsertar->setObjectName("btnInsertar");
        btnInsertar->setGeometry(QRect(60, 20, 111, 31));
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
        inputT->setGeometry(QRect(200, 20, 111, 31));
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
        btnDelete = new QPushButton(widget);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setGeometry(QRect(60, 120, 111, 31));
        btnDelete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        btnBuscar = new QPushButton(widget);
        btnBuscar->setObjectName("btnBuscar");
        btnBuscar->setGeometry(QRect(60, 70, 111, 31));
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
        label_2->setGeometry(QRect(100, 210, 201, 41));
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 14pt \"Cooper Black\";\n"
"color: black;"));
        label_2->setTextFormat(Qt::AutoText);
        labelCodeImg = new QLabel(widget);
        labelCodeImg->setObjectName("labelCodeImg");
        labelCodeImg->setGeometry(QRect(10, 250, 371, 331));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 590, 401, 91));
        widget_2->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 331, 51));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";\n"
"color: white;"));
        label->setTextFormat(Qt::AutoText);
        inputT_Find = new QTextEdit(widget);
        inputT_Find->setObjectName("inputT_Find");
        inputT_Find->setGeometry(QRect(200, 70, 111, 31));
        inputT_Find->setStyleSheet(QString::fromUtf8("\n"
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
        inputT_Eliminar = new QTextEdit(widget);
        inputT_Eliminar->setObjectName("inputT_Eliminar");
        inputT_Eliminar->setGeometry(QRect(200, 120, 111, 31));
        inputT_Eliminar->setStyleSheet(QString::fromUtf8("\n"
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

        retranslateUi(binarysform);

        QMetaObject::connectSlotsByName(binarysform);
    } // setupUi

    void retranslateUi(QDialog *binarysform)
    {
        binarysform->setWindowTitle(QCoreApplication::translate("binarysform", "Dialog", nullptr));
        labelGrafico_2->setText(QString());
        btnInsertar->setText(QCoreApplication::translate("binarysform", "Insertar", nullptr));
        btnDelete->setText(QCoreApplication::translate("binarysform", "Eliminar", nullptr));
        btnBuscar->setText(QCoreApplication::translate("binarysform", "Buscar", nullptr));
        label_2->setText(QCoreApplication::translate("binarysform", "Estructura del Nodo", nullptr));
        labelCodeImg->setText(QString());
        label->setText(QCoreApplication::translate("binarysform", "Binary Search Tree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class binarysform: public Ui_binarysform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINARYSFORM_H

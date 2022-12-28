/********************************************************************************
** Form generated from reading UI file 'hashform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HASHFORM_H
#define UI_HASHFORM_H

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

class Ui_hashform
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QLabel *labelGrafico_2;
    QWidget *widget;
    QPushButton *btnInsertar;
    QTextEdit *inputKey;
    QTextEdit *inputDato;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *labelCodeImg;

    void setupUi(QDialog *hashform)
    {
        if (hashform->objectName().isEmpty())
            hashform->setObjectName("hashform");
        hashform->resize(1300, 700);
        hashform->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        scrollArea = new QScrollArea(hashform);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(7, 10, 911, 681));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 909, 679));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName("gridLayout_2");
        labelGrafico_2 = new QLabel(scrollAreaWidgetContents_2);
        labelGrafico_2->setObjectName("labelGrafico_2");

        gridLayout_2->addWidget(labelGrafico_2, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);
        widget = new QWidget(hashform);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(930, 10, 361, 681));
        widget->setStyleSheet(QString::fromUtf8("background: #9DAABC;"));
        btnInsertar = new QPushButton(widget);
        btnInsertar->setObjectName("btnInsertar");
        btnInsertar->setGeometry(QRect(100, 140, 151, 31));
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
        inputKey = new QTextEdit(widget);
        inputKey->setObjectName("inputKey");
        inputKey->setGeometry(QRect(150, 30, 111, 31));
        inputKey->setStyleSheet(QString::fromUtf8("\n"
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
        inputDato = new QTextEdit(widget);
        inputDato->setObjectName("inputDato");
        inputDato->setGeometry(QRect(150, 70, 111, 31));
        inputDato->setStyleSheet(QString::fromUtf8("\n"
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
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 40, 71, 17));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 80, 54, 17));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(-10, 600, 401, 91));
        widget_2->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 20, 251, 51));
        label_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";\n"
"color: white;"));
        label_3->setTextFormat(Qt::AutoText);
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 210, 201, 41));
        label_4->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 14pt \"Cooper Black\";\n"
"color: black;"));
        label_4->setTextFormat(Qt::AutoText);
        labelCodeImg = new QLabel(widget);
        labelCodeImg->setObjectName("labelCodeImg");
        labelCodeImg->setGeometry(QRect(0, 260, 371, 331));

        retranslateUi(hashform);

        QMetaObject::connectSlotsByName(hashform);
    } // setupUi

    void retranslateUi(QDialog *hashform)
    {
        hashform->setWindowTitle(QCoreApplication::translate("hashform", "Dialog", nullptr));
        labelGrafico_2->setText(QString());
        btnInsertar->setText(QCoreApplication::translate("hashform", "Insertar", nullptr));
        label->setText(QCoreApplication::translate("hashform", "Key (String):", nullptr));
        label_2->setText(QCoreApplication::translate("hashform", "Dato (Int):", nullptr));
        label_3->setText(QCoreApplication::translate("hashform", "Tablas de Hash", nullptr));
        label_4->setText(QCoreApplication::translate("hashform", "Estructura del Nodo", nullptr));
        labelCodeImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class hashform: public Ui_hashform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HASHFORM_H

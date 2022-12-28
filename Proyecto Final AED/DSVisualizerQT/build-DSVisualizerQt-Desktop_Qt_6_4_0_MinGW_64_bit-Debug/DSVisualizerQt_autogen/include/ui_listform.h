/********************************************************************************
** Form generated from reading UI file 'listform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTFORM_H
#define UI_LISTFORM_H

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

class Ui_listform
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *labelGrafico;
    QWidget *widget;
    QPushButton *btnPushBack;
    QPushButton *btnPopBack;
    QTextEdit *txtInputDatoPushBack;
    QPushButton *btnPushFront;
    QTextEdit *txtInputDatoPushFront;
    QPushButton *btnPopFront;
    QPushButton *btnInsert;
    QPushButton *btnFind;
    QTextEdit *txtInputDatoFind;
    QTextEdit *txtInputDatoInsert;
    QTextEdit *txtInputDatoIndice;
    QLabel *labelCodeImg;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *widget_2;
    QLabel *label;

    void setupUi(QDialog *listform)
    {
        if (listform->objectName().isEmpty())
            listform->setObjectName("listform");
        listform->resize(1300, 700);
        listform->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        scrollArea = new QScrollArea(listform);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 10, 1281, 281));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1279, 279));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        labelGrafico = new QLabel(scrollAreaWidgetContents);
        labelGrafico->setObjectName("labelGrafico");

        gridLayout->addWidget(labelGrafico, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        widget = new QWidget(listform);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 310, 1051, 381));
        widget->setMinimumSize(QSize(0, 0));
        widget->setStyleSheet(QString::fromUtf8("background: #9DAABC;"));
        btnPushBack = new QPushButton(widget);
        btnPushBack->setObjectName("btnPushBack");
        btnPushBack->setGeometry(QRect(200, 80, 131, 41));
        btnPushBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 16px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        btnPopBack = new QPushButton(widget);
        btnPopBack->setObjectName("btnPopBack");
        btnPopBack->setGeometry(QRect(450, 50, 131, 41));
        btnPopBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 16px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        txtInputDatoPushBack = new QTextEdit(widget);
        txtInputDatoPushBack->setObjectName("txtInputDatoPushBack");
        txtInputDatoPushBack->setGeometry(QRect(20, 80, 161, 41));
        txtInputDatoPushBack->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        btnPushFront = new QPushButton(widget);
        btnPushFront->setObjectName("btnPushFront");
        btnPushFront->setGeometry(QRect(200, 140, 131, 41));
        btnPushFront->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 16px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        txtInputDatoPushFront = new QTextEdit(widget);
        txtInputDatoPushFront->setObjectName("txtInputDatoPushFront");
        txtInputDatoPushFront->setGeometry(QRect(20, 140, 161, 41));
        txtInputDatoPushFront->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        btnPopFront = new QPushButton(widget);
        btnPopFront->setObjectName("btnPopFront");
        btnPopFront->setGeometry(QRect(450, 120, 131, 41));
        btnPopFront->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 16px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        btnInsert = new QPushButton(widget);
        btnInsert->setObjectName("btnInsert");
        btnInsert->setGeometry(QRect(200, 270, 131, 41));
        btnInsert->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 16px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        btnFind = new QPushButton(widget);
        btnFind->setObjectName("btnFind");
        btnFind->setGeometry(QRect(450, 250, 131, 41));
        btnFind->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 16px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        txtInputDatoFind = new QTextEdit(widget);
        txtInputDatoFind->setObjectName("txtInputDatoFind");
        txtInputDatoFind->setGeometry(QRect(450, 200, 131, 41));
        txtInputDatoFind->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        txtInputDatoInsert = new QTextEdit(widget);
        txtInputDatoInsert->setObjectName("txtInputDatoInsert");
        txtInputDatoInsert->setGeometry(QRect(70, 240, 111, 41));
        txtInputDatoInsert->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        txtInputDatoIndice = new QTextEdit(widget);
        txtInputDatoIndice->setObjectName("txtInputDatoIndice");
        txtInputDatoIndice->setGeometry(QRect(70, 290, 111, 41));
        txtInputDatoIndice->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        labelCodeImg = new QLabel(widget);
        labelCodeImg->setObjectName("labelCodeImg");
        labelCodeImg->setGeometry(QRect(710, 60, 311, 311));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(760, 10, 201, 41));
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 14pt \"Cooper Black\";\n"
"color: black;"));
        label_2->setTextFormat(Qt::AutoText);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 300, 49, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 11pt;"));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 250, 49, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 11pt;"));
        widget_2 = new QWidget(listform);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(1080, 370, 200, 311));
        widget_2->setMinimumSize(QSize(180, 0));
        widget_2->setMaximumSize(QSize(400, 16777215));
        widget_2->setStyleSheet(QString::fromUtf8("background: transparent;"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 80, 181, 141));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";\n"
"color: white;"));
        label->setTextFormat(Qt::AutoText);

        retranslateUi(listform);

        QMetaObject::connectSlotsByName(listform);
    } // setupUi

    void retranslateUi(QDialog *listform)
    {
        listform->setWindowTitle(QCoreApplication::translate("listform", "Dialog", nullptr));
        labelGrafico->setText(QString());
        btnPushBack->setText(QCoreApplication::translate("listform", "PushBack", nullptr));
        btnPopBack->setText(QCoreApplication::translate("listform", "PopBack", nullptr));
        btnPushFront->setText(QCoreApplication::translate("listform", "PushFront", nullptr));
        btnPopFront->setText(QCoreApplication::translate("listform", "PopFront", nullptr));
        btnInsert->setText(QCoreApplication::translate("listform", "Insert By Index", nullptr));
        btnFind->setText(QCoreApplication::translate("listform", "Find", nullptr));
        labelCodeImg->setText(QString());
        label_2->setText(QCoreApplication::translate("listform", "Estructura del Nodo", nullptr));
        label_3->setText(QCoreApplication::translate("listform", "Indice:", nullptr));
        label_4->setText(QCoreApplication::translate("listform", "Dato:", nullptr));
        label->setText(QCoreApplication::translate("listform", "Linked\n"
"List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listform: public Ui_listform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTFORM_H

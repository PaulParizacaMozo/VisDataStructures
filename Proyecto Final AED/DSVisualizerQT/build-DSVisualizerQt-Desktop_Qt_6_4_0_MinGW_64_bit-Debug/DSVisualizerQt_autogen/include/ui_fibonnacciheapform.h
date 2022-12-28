/********************************************************************************
** Form generated from reading UI file 'fibonnacciheapform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIBONNACCIHEAPFORM_H
#define UI_FIBONNACCIHEAPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fibonnacciheapform
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *labelGrafico;
    QWidget *widget;
    QPushButton *btnPush;
    QPushButton *btnDeleteMin;
    QSpinBox *spinBox;
    QWidget *widget_2;
    QLabel *label_3;
    QLabel *labelCodeImg;
    QLabel *label_4;

    void setupUi(QDialog *fibonnacciheapform)
    {
        if (fibonnacciheapform->objectName().isEmpty())
            fibonnacciheapform->setObjectName("fibonnacciheapform");
        fibonnacciheapform->resize(1300, 700);
        fibonnacciheapform->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        scrollArea = new QScrollArea(fibonnacciheapform);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 10, 911, 681));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 909, 679));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        labelGrafico = new QLabel(scrollAreaWidgetContents);
        labelGrafico->setObjectName("labelGrafico");

        gridLayout->addWidget(labelGrafico, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        widget = new QWidget(fibonnacciheapform);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(925, 10, 371, 681));
        widget->setStyleSheet(QString::fromUtf8("background: #9DAABC;"));
        btnPush = new QPushButton(widget);
        btnPush->setObjectName("btnPush");
        btnPush->setGeometry(QRect(200, 40, 131, 41));
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
        btnDeleteMin = new QPushButton(widget);
        btnDeleteMin->setObjectName("btnDeleteMin");
        btnDeleteMin->setGeometry(QRect(200, 100, 131, 41));
        btnDeleteMin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(90, 40, 81, 41));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 590, 371, 91));
        widget_2->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 20, 261, 51));
        label_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";\n"
"color: white;"));
        label_3->setTextFormat(Qt::AutoText);
        labelCodeImg = new QLabel(widget);
        labelCodeImg->setObjectName("labelCodeImg");
        labelCodeImg->setGeometry(QRect(10, 230, 341, 331));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 160, 201, 41));
        label_4->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 14pt \"Cooper Black\";\n"
"color: black;"));
        label_4->setTextFormat(Qt::AutoText);

        retranslateUi(fibonnacciheapform);

        QMetaObject::connectSlotsByName(fibonnacciheapform);
    } // setupUi

    void retranslateUi(QDialog *fibonnacciheapform)
    {
        fibonnacciheapform->setWindowTitle(QCoreApplication::translate("fibonnacciheapform", "Dialog", nullptr));
        labelGrafico->setText(QString());
        btnPush->setText(QCoreApplication::translate("fibonnacciheapform", "Push", nullptr));
        btnDeleteMin->setText(QCoreApplication::translate("fibonnacciheapform", "Delete_Min", nullptr));
        label_3->setText(QCoreApplication::translate("fibonnacciheapform", "Fibonacci Heap", nullptr));
        labelCodeImg->setText(QString());
        label_4->setText(QCoreApplication::translate("fibonnacciheapform", "Estructura del Nodo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fibonnacciheapform: public Ui_fibonnacciheapform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIBONNACCIHEAPFORM_H

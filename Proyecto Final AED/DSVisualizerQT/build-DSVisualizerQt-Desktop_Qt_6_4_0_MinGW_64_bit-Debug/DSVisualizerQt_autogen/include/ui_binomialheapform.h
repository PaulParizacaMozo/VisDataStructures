/********************************************************************************
** Form generated from reading UI file 'binomialheapform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINOMIALHEAPFORM_H
#define UI_BINOMIALHEAPFORM_H

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

class Ui_binomialheapform
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QLabel *labelGrafico_2;
    QWidget *widget;
    QPushButton *btnPush_2;
    QPushButton *btnDeleteMax;
    QSpinBox *spinBox_2;
    QWidget *widget_2;
    QLabel *label_3;
    QLabel *labelCodeImg;
    QLabel *label_4;

    void setupUi(QDialog *binomialheapform)
    {
        if (binomialheapform->objectName().isEmpty())
            binomialheapform->setObjectName("binomialheapform");
        binomialheapform->resize(1300, 700);
        binomialheapform->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        scrollArea = new QScrollArea(binomialheapform);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 10, 891, 681));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 889, 679));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName("gridLayout_2");
        labelGrafico_2 = new QLabel(scrollAreaWidgetContents_2);
        labelGrafico_2->setObjectName("labelGrafico_2");

        gridLayout_2->addWidget(labelGrafico_2, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);
        widget = new QWidget(binomialheapform);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(910, 10, 381, 681));
        widget->setStyleSheet(QString::fromUtf8("background: #9DAABC;"));
        btnPush_2 = new QPushButton(widget);
        btnPush_2->setObjectName("btnPush_2");
        btnPush_2->setGeometry(QRect(200, 520, 101, 41));
        btnPush_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        btnDeleteMax = new QPushButton(widget);
        btnDeleteMax->setObjectName("btnDeleteMax");
        btnDeleteMax->setGeometry(QRect(120, 590, 151, 41));
        btnDeleteMax->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}"));
        spinBox_2 = new QSpinBox(widget);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(90, 520, 81, 41));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(-10, 0, 391, 91));
        widget_2->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 20, 251, 51));
        label_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";\n"
"color: white;"));
        label_3->setTextFormat(Qt::AutoText);
        labelCodeImg = new QLabel(widget);
        labelCodeImg->setObjectName("labelCodeImg");
        labelCodeImg->setGeometry(QRect(10, 150, 371, 331));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 100, 201, 41));
        label_4->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 14pt \"Cooper Black\";\n"
"color: black;"));
        label_4->setTextFormat(Qt::AutoText);

        retranslateUi(binomialheapform);

        QMetaObject::connectSlotsByName(binomialheapform);
    } // setupUi

    void retranslateUi(QDialog *binomialheapform)
    {
        binomialheapform->setWindowTitle(QCoreApplication::translate("binomialheapform", "Dialog", nullptr));
        labelGrafico_2->setText(QString());
        btnPush_2->setText(QCoreApplication::translate("binomialheapform", "Push", nullptr));
        btnDeleteMax->setText(QCoreApplication::translate("binomialheapform", "Extract_Max", nullptr));
        label_3->setText(QCoreApplication::translate("binomialheapform", "Binomial Heap", nullptr));
        labelCodeImg->setText(QString());
        label_4->setText(QCoreApplication::translate("binomialheapform", "Estructura del Nodo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class binomialheapform: public Ui_binomialheapform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINOMIALHEAPFORM_H

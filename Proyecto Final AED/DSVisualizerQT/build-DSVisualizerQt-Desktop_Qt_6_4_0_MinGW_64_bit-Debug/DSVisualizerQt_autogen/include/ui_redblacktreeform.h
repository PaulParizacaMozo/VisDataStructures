/********************************************************************************
** Form generated from reading UI file 'redblacktreeform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDBLACKTREEFORM_H
#define UI_REDBLACKTREEFORM_H

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

class Ui_redblacktreeform
{
public:
    QWidget *widget;
    QPushButton *btnPush;
    QSpinBox *spinBox;
    QLabel *labelCodeImg;
    QLabel *label_2;
    QWidget *widget_2;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *labelGrafico;

    void setupUi(QDialog *redblacktreeform)
    {
        if (redblacktreeform->objectName().isEmpty())
            redblacktreeform->setObjectName("redblacktreeform");
        redblacktreeform->resize(1300, 700);
        redblacktreeform->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        widget = new QWidget(redblacktreeform);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 371, 681));
        widget->setMinimumSize(QSize(300, 0));
        widget->setStyleSheet(QString::fromUtf8("background: #9DAABC;"));
        btnPush = new QPushButton(widget);
        btnPush->setObjectName("btnPush");
        btnPush->setGeometry(QRect(220, 140, 75, 31));
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(100, 130, 81, 41));
        labelCodeImg = new QLabel(widget);
        labelCodeImg->setObjectName("labelCodeImg");
        labelCodeImg->setGeometry(QRect(0, 340, 371, 341));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 290, 201, 41));
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 14pt \"Cooper Black\";\n"
"color: black;"));
        label_2->setTextFormat(Qt::AutoText);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 371, 91));
        widget_2->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 20, 261, 51));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";\n"
"color: white;"));
        label->setTextFormat(Qt::AutoText);
        scrollArea = new QScrollArea(redblacktreeform);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(390, 10, 901, 681));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 899, 679));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        labelGrafico = new QLabel(scrollAreaWidgetContents);
        labelGrafico->setObjectName("labelGrafico");

        gridLayout->addWidget(labelGrafico, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(redblacktreeform);

        QMetaObject::connectSlotsByName(redblacktreeform);
    } // setupUi

    void retranslateUi(QDialog *redblacktreeform)
    {
        redblacktreeform->setWindowTitle(QCoreApplication::translate("redblacktreeform", "Dialog", nullptr));
        btnPush->setText(QCoreApplication::translate("redblacktreeform", "Push", nullptr));
        labelCodeImg->setText(QString());
        label_2->setText(QCoreApplication::translate("redblacktreeform", "Estructura del Nodo", nullptr));
        label->setText(QCoreApplication::translate("redblacktreeform", "Red Black Tree", nullptr));
        labelGrafico->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class redblacktreeform: public Ui_redblacktreeform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDBLACKTREEFORM_H

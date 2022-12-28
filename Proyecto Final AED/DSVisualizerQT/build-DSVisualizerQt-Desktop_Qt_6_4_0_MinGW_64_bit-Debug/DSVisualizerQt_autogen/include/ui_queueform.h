/********************************************************************************
** Form generated from reading UI file 'queueform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEUEFORM_H
#define UI_QUEUEFORM_H

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

class Ui_QueueForm
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *labelGrafico;
    QWidget *widget;
    QPushButton *btnPush;
    QPushButton *btnPop;
    QTextEdit *txtInputDato;
    QLabel *labelCodeImg;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *QueueForm)
    {
        if (QueueForm->objectName().isEmpty())
            QueueForm->setObjectName("QueueForm");
        QueueForm->resize(1300, 700);
        QueueForm->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        scrollArea = new QScrollArea(QueueForm);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 10, 1281, 311));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1279, 309));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        labelGrafico = new QLabel(scrollAreaWidgetContents);
        labelGrafico->setObjectName("labelGrafico");

        gridLayout->addWidget(labelGrafico, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        widget = new QWidget(QueueForm);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(290, 330, 1001, 361));
        widget->setStyleSheet(QString::fromUtf8("background: #9DAABC;"));
        btnPush = new QPushButton(widget);
        btnPush->setObjectName("btnPush");
        btnPush->setGeometry(QRect(780, 50, 131, 41));
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
        btnPop = new QPushButton(widget);
        btnPop->setObjectName("btnPop");
        btnPop->setGeometry(QRect(660, 140, 131, 41));
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
        txtInputDato = new QTextEdit(widget);
        txtInputDato->setObjectName("txtInputDato");
        txtInputDato->setGeometry(QRect(540, 50, 161, 41));
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
        labelCodeImg = new QLabel(widget);
        labelCodeImg->setObjectName("labelCodeImg");
        labelCodeImg->setGeometry(QRect(100, 50, 311, 281));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 0, 201, 41));
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 14pt \"Cooper Black\";\n"
"color: black;"));
        label_2->setTextFormat(Qt::AutoText);
        label = new QLabel(QueueForm);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 440, 181, 141));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";\n"
"color: white;"));
        label->setTextFormat(Qt::AutoText);

        retranslateUi(QueueForm);

        QMetaObject::connectSlotsByName(QueueForm);
    } // setupUi

    void retranslateUi(QDialog *QueueForm)
    {
        QueueForm->setWindowTitle(QCoreApplication::translate("QueueForm", "Dialog", nullptr));
        labelGrafico->setText(QString());
        btnPush->setText(QCoreApplication::translate("QueueForm", "Push", nullptr));
        btnPop->setText(QCoreApplication::translate("QueueForm", "Pop", nullptr));
        labelCodeImg->setText(QString());
        label_2->setText(QCoreApplication::translate("QueueForm", "Estructura del Nodo", nullptr));
        label->setText(QCoreApplication::translate("QueueForm", "Queue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QueueForm: public Ui_QueueForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEUEFORM_H

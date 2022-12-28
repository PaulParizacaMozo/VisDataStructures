/********************************************************************************
** Form generated from reading UI file 'matrizesparzaform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATRIZESPARZAFORM_H
#define UI_MATRIZESPARZAFORM_H

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

class Ui_matrizesparzaform
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QLabel *labelGrafico_2;
    QWidget *widget;
    QPushButton *btnPush;
    QPushButton *btnDelete;
    QSpinBox *spinBox;
    QSpinBox *spinBoxFil;
    QSpinBox *spinBoxCol;
    QLabel *label_2;
    QLabel *labelCodeImg;
    QLabel *label;

    void setupUi(QDialog *matrizesparzaform)
    {
        if (matrizesparzaform->objectName().isEmpty())
            matrizesparzaform->setObjectName("matrizesparzaform");
        matrizesparzaform->resize(1300, 700);
        matrizesparzaform->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        scrollArea = new QScrollArea(matrizesparzaform);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 60, 641, 581));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 639, 579));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName("gridLayout_2");
        labelGrafico_2 = new QLabel(scrollAreaWidgetContents_2);
        labelGrafico_2->setObjectName("labelGrafico_2");

        gridLayout_2->addWidget(labelGrafico_2, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);
        widget = new QWidget(matrizesparzaform);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(670, 80, 621, 611));
        widget->setStyleSheet(QString::fromUtf8("background: #9DAABC;"));
        btnPush = new QPushButton(widget);
        btnPush->setObjectName("btnPush");
        btnPush->setGeometry(QRect(300, 460, 75, 31));
        btnDelete = new QPushButton(widget);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setGeometry(QRect(300, 560, 75, 31));
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(300, 410, 81, 41));
        spinBoxFil = new QSpinBox(widget);
        spinBoxFil->setObjectName("spinBoxFil");
        spinBoxFil->setGeometry(QRect(210, 500, 81, 41));
        spinBoxCol = new QSpinBox(widget);
        spinBoxCol->setObjectName("spinBoxCol");
        spinBoxCol->setGeometry(QRect(390, 500, 81, 41));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 10, 201, 41));
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 14pt \"Cooper Black\";\n"
"color: black;"));
        label_2->setTextFormat(Qt::AutoText);
        labelCodeImg = new QLabel(widget);
        labelCodeImg->setObjectName("labelCodeImg");
        labelCodeImg->setGeometry(QRect(130, 70, 351, 321));
        label = new QLabel(matrizesparzaform);
        label->setObjectName("label");
        label->setGeometry(QRect(860, 30, 241, 31));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";\n"
"color: white;"));
        label->setTextFormat(Qt::AutoText);

        retranslateUi(matrizesparzaform);

        QMetaObject::connectSlotsByName(matrizesparzaform);
    } // setupUi

    void retranslateUi(QDialog *matrizesparzaform)
    {
        matrizesparzaform->setWindowTitle(QCoreApplication::translate("matrizesparzaform", "Dialog", nullptr));
        labelGrafico_2->setText(QString());
        btnPush->setText(QCoreApplication::translate("matrizesparzaform", "Push", nullptr));
        btnDelete->setText(QCoreApplication::translate("matrizesparzaform", "Eliminar", nullptr));
        label_2->setText(QCoreApplication::translate("matrizesparzaform", "Estructura del Nodo", nullptr));
        labelCodeImg->setText(QString());
        label->setText(QCoreApplication::translate("matrizesparzaform", "Sparse Matrix", nullptr));
    } // retranslateUi

};

namespace Ui {
    class matrizesparzaform: public Ui_matrizesparzaform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATRIZESPARZAFORM_H

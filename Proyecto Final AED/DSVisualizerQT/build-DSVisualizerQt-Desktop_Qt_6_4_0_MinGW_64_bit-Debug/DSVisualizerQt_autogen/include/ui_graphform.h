/********************************************************************************
** Form generated from reading UI file 'graphform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHFORM_H
#define UI_GRAPHFORM_H

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

class Ui_Graphform
{
public:
    QLabel *label_4;
    QPushButton *btnPrim;
    QLabel *label_6;
    QTextEdit *inputVO;
    QLabel *label_3;
    QLabel *label_5;
    QTextEdit *inputPeso;
    QPushButton *InsArista;
    QPushButton *InsVertice;
    QLabel *label_2;
    QPushButton *btn_Draw;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *labelGrafico;
    QTextEdit *inputVD;
    QTextEdit *inputPrim;
    QTextEdit *inputVertice;
    QPushButton *btnKruskal;
    QLabel *label;
    QWidget *widget_2;
    QLabel *label_8;

    void setupUi(QDialog *Graphform)
    {
        if (Graphform->objectName().isEmpty())
            Graphform->setObjectName("Graphform");
        Graphform->resize(1300, 700);
        Graphform->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        label_4 = new QLabel(Graphform);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(740, 220, 111, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: white;"));
        btnPrim = new QPushButton(Graphform);
        btnPrim->setObjectName("btnPrim");
        btnPrim->setGeometry(QRect(1050, 370, 91, 31));
        btnPrim->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #33FF99;\n"
"    padding: 6px;\n"
"}"));
        label_6 = new QLabel(Graphform);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(740, 260, 111, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: white;"));
        inputVO = new QTextEdit(Graphform);
        inputVO->setObjectName("inputVO");
        inputVO->setGeometry(QRect(860, 180, 104, 31));
        inputVO->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        label_3 = new QLabel(Graphform);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(740, 180, 111, 31));
        label_3->setStyleSheet(QString::fromUtf8("color: white;"));
        label_5 = new QLabel(Graphform);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(1120, 140, 91, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: white;"));
        inputPeso = new QTextEdit(Graphform);
        inputPeso->setObjectName("inputPeso");
        inputPeso->setGeometry(QRect(860, 260, 104, 31));
        inputPeso->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        InsArista = new QPushButton(Graphform);
        InsArista->setObjectName("InsArista");
        InsArista->setGeometry(QRect(780, 310, 161, 31));
        InsArista->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #33FF99;\n"
"    padding: 6px;\n"
"}"));
        InsVertice = new QPushButton(Graphform);
        InsVertice->setObjectName("InsVertice");
        InsVertice->setGeometry(QRect(1110, 180, 81, 31));
        InsVertice->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #33FF99;\n"
"    padding: 6px;\n"
"}"));
        label_2 = new QLabel(Graphform);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(810, 130, 91, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: white;"));
        btn_Draw = new QPushButton(Graphform);
        btn_Draw->setObjectName("btn_Draw");
        btn_Draw->setGeometry(QRect(1050, 240, 191, 41));
        btn_Draw->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #33FF99;\n"
"    padding: 6px;\n"
"}"));
        scrollArea = new QScrollArea(Graphform);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 10, 631, 681));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 629, 679));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        labelGrafico = new QLabel(scrollAreaWidgetContents);
        labelGrafico->setObjectName("labelGrafico");

        gridLayout->addWidget(labelGrafico, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        inputVD = new QTextEdit(Graphform);
        inputVD->setObjectName("inputVD");
        inputVD->setGeometry(QRect(860, 220, 104, 31));
        inputVD->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        inputPrim = new QTextEdit(Graphform);
        inputPrim->setObjectName("inputPrim");
        inputPrim->setGeometry(QRect(1170, 370, 71, 31));
        inputPrim->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        inputVertice = new QTextEdit(Graphform);
        inputVertice->setObjectName("inputVertice");
        inputVertice->setGeometry(QRect(1210, 180, 71, 31));
        inputVertice->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        btnKruskal = new QPushButton(Graphform);
        btnKruskal->setObjectName("btnKruskal");
        btnKruskal->setGeometry(QRect(1100, 310, 91, 31));
        btnKruskal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #33FF99;\n"
"    padding: 6px;\n"
"}"));
        label = new QLabel(Graphform);
        label->setObjectName("label");
        label->setGeometry(QRect(1000, 180, 101, 31));
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        widget_2 = new QWidget(Graphform);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(750, 30, 481, 71));
        widget_2->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 10, 421, 51));
        label_8->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";\n"
"color: white;"));
        label_8->setTextFormat(Qt::AutoText);

        retranslateUi(Graphform);

        QMetaObject::connectSlotsByName(Graphform);
    } // setupUi

    void retranslateUi(QDialog *Graphform)
    {
        Graphform->setWindowTitle(QCoreApplication::translate("Graphform", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("Graphform", "Vertice Destino ->", nullptr));
        btnPrim->setText(QCoreApplication::translate("Graphform", "Prim", nullptr));
        label_6->setText(QCoreApplication::translate("Graphform", "Peso de la arista ->", nullptr));
        label_3->setText(QCoreApplication::translate("Graphform", "Vertice origen ->", nullptr));
        label_5->setText(QCoreApplication::translate("Graphform", "Insertar Vertice:", nullptr));
        InsArista->setText(QCoreApplication::translate("Graphform", "Insertar Arista", nullptr));
        InsVertice->setText(QCoreApplication::translate("Graphform", "Insertar", nullptr));
        label_2->setText(QCoreApplication::translate("Graphform", "Insertar Arista", nullptr));
        btn_Draw->setText(QCoreApplication::translate("Graphform", "Draw", nullptr));
        labelGrafico->setText(QString());
        btnKruskal->setText(QCoreApplication::translate("Graphform", "Kruskal", nullptr));
        label->setText(QCoreApplication::translate("Graphform", "Insertar Vertice:", nullptr));
        label_8->setText(QCoreApplication::translate("Graphform", "GRAFOS NO DIRIGIDOS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graphform: public Ui_Graphform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHFORM_H

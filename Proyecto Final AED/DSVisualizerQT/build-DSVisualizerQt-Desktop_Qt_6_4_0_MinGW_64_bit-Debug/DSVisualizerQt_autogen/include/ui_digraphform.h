/********************************************************************************
** Form generated from reading UI file 'digraphform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIGRAPHFORM_H
#define UI_DIGRAPHFORM_H

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

class Ui_Digraphform
{
public:
    QPushButton *InsVertice;
    QTextEdit *inputVertice;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QTextEdit *inputVO;
    QTextEdit *inputVD;
    QTextEdit *inputPeso;
    QPushButton *InsArista;
    QPushButton *btnDijkstra;
    QPushButton *btnFloyd;
    QPushButton *btnWarshall;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *labelGrafico;
    QPushButton *btn_Draw;
    QTextEdit *inputDij;
    QLabel *label_7;
    QWidget *widget_2;
    QLabel *label_8;
    QWidget *widget;
    QLabel *label_5;

    void setupUi(QDialog *Digraphform)
    {
        if (Digraphform->objectName().isEmpty())
            Digraphform->setObjectName("Digraphform");
        Digraphform->resize(1300, 700);
        Digraphform->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        InsVertice = new QPushButton(Digraphform);
        InsVertice->setObjectName("InsVertice");
        InsVertice->setGeometry(QRect(1110, 250, 111, 31));
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
        inputVertice = new QTextEdit(Digraphform);
        inputVertice->setObjectName("inputVertice");
        inputVertice->setGeometry(QRect(1010, 250, 71, 31));
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
        label = new QLabel(Digraphform);
        label->setObjectName("label");
        label->setGeometry(QRect(880, 240, 101, 31));
        label->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: #DDDDDD;"));
        label_2 = new QLabel(Digraphform);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(700, 320, 131, 61));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: #111;\n"
"background: #9DAABC;"));
        label_3 = new QLabel(Digraphform);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(850, 340, 111, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: #DDDDDD;"));
        label_4 = new QLabel(Digraphform);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(850, 380, 111, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: #DDDDDD;"));
        label_6 = new QLabel(Digraphform);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(850, 420, 111, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: #DDDDDD;"));
        inputVO = new QTextEdit(Digraphform);
        inputVO->setObjectName("inputVO");
        inputVO->setGeometry(QRect(960, 350, 104, 31));
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
        inputVD = new QTextEdit(Digraphform);
        inputVD->setObjectName("inputVD");
        inputVD->setGeometry(QRect(960, 390, 104, 31));
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
        inputPeso = new QTextEdit(Digraphform);
        inputPeso->setObjectName("inputPeso");
        inputPeso->setGeometry(QRect(960, 430, 104, 31));
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
        InsArista = new QPushButton(Digraphform);
        InsArista->setObjectName("InsArista");
        InsArista->setGeometry(QRect(1110, 390, 151, 31));
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
        btnDijkstra = new QPushButton(Digraphform);
        btnDijkstra->setObjectName("btnDijkstra");
        btnDijkstra->setGeometry(QRect(800, 620, 131, 51));
        btnDijkstra->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #33FF99;\n"
"    padding: 6px;\n"
"}"));
        btnFloyd = new QPushButton(Digraphform);
        btnFloyd->setObjectName("btnFloyd");
        btnFloyd->setGeometry(QRect(970, 560, 131, 51));
        btnFloyd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #33FF99;\n"
"    padding: 6px;\n"
"}"));
        btnWarshall = new QPushButton(Digraphform);
        btnWarshall->setObjectName("btnWarshall");
        btnWarshall->setGeometry(QRect(1140, 560, 131, 51));
        btnWarshall->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 8px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #33FF99;\n"
"    padding: 6px;\n"
"}"));
        scrollArea = new QScrollArea(Digraphform);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 10, 651, 681));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 649, 679));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        labelGrafico = new QLabel(scrollAreaWidgetContents);
        labelGrafico->setObjectName("labelGrafico");

        gridLayout->addWidget(labelGrafico, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        btn_Draw = new QPushButton(Digraphform);
        btn_Draw->setObjectName("btn_Draw");
        btn_Draw->setGeometry(QRect(910, 480, 191, 41));
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
        inputDij = new QTextEdit(Digraphform);
        inputDij->setObjectName("inputDij");
        inputDij->setGeometry(QRect(800, 560, 131, 51));
        inputDij->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:2px;\n"
"border-style:solid;\n"
"border-color:rgb(28,19,42);\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #DDD;\n"
"}"));
        label_7 = new QLabel(Digraphform);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(700, 570, 81, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"color: #DDDDDD;"));
        widget_2 = new QWidget(Digraphform);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(750, 20, 481, 71));
        widget_2->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 10, 421, 51));
        label_8->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";\n"
"color: white;"));
        label_8->setTextFormat(Qt::AutoText);
        widget = new QWidget(Digraphform);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(700, 210, 131, 71));
        widget->setStyleSheet(QString::fromUtf8("background: #9DAABC;"));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 20, 91, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px;\n"
"/*color: #DDDDDD;*/\n"
""));

        retranslateUi(Digraphform);

        QMetaObject::connectSlotsByName(Digraphform);
    } // setupUi

    void retranslateUi(QDialog *Digraphform)
    {
        Digraphform->setWindowTitle(QCoreApplication::translate("Digraphform", "Dialog", nullptr));
        InsVertice->setText(QCoreApplication::translate("Digraphform", "Insertar", nullptr));
        label->setText(QCoreApplication::translate("Digraphform", "Insertar Vertice:", nullptr));
        label_2->setText(QCoreApplication::translate("Digraphform", "Insertar Arista", nullptr));
        label_3->setText(QCoreApplication::translate("Digraphform", "Vertice origen ->", nullptr));
        label_4->setText(QCoreApplication::translate("Digraphform", "Vertice Destino ->", nullptr));
        label_6->setText(QCoreApplication::translate("Digraphform", "Peso de la arista ->", nullptr));
        InsArista->setText(QCoreApplication::translate("Digraphform", "Insertar Arista", nullptr));
        btnDijkstra->setText(QCoreApplication::translate("Digraphform", "Dijkstra", nullptr));
        btnFloyd->setText(QCoreApplication::translate("Digraphform", "Floyd", nullptr));
        btnWarshall->setText(QCoreApplication::translate("Digraphform", "Warshall", nullptr));
        labelGrafico->setText(QString());
        btn_Draw->setText(QCoreApplication::translate("Digraphform", "Draw", nullptr));
        label_7->setText(QCoreApplication::translate("Digraphform", "Elegir Nodo:", nullptr));
        label_8->setText(QCoreApplication::translate("Digraphform", "GRAFOS DIRIGIDOS", nullptr));
        label_5->setText(QCoreApplication::translate("Digraphform", "Insertar Vertice:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Digraphform: public Ui_Digraphform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIGRAPHFORM_H

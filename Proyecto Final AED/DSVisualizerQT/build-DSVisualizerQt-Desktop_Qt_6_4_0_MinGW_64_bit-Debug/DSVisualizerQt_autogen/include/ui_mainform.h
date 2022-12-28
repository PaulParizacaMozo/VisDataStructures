/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnStack;
    QPushButton *btnQueue;
    QPushButton *btnLinkedList;
    QPushButton *btnDoubleLinkedList;
    QPushButton *btnBST;
    QPushButton *btnAVLTree;
    QPushButton *btnRedBlackTree;
    QPushButton *btnHashTable;
    QPushButton *btnSparseMatrix;
    QPushButton *btnBinoHeap;
    QPushButton *btnFiboHeap;
    QPushButton *btnWarshall;
    QPushButton *btnFloyd;
    QPushButton *btnDijkstra;
    QPushButton *btnKruskal;
    QPushButton *btnPrim;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName("MainForm");
        MainForm->resize(1300, 700);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainForm->sizePolicy().hasHeightForWidth());
        MainForm->setSizePolicy(sizePolicy);
        MainForm->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 26, 26)"));
        gridLayout = new QGridLayout(MainForm);
        gridLayout->setObjectName("gridLayout");
        widget = new QWidget(MainForm);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(280, 0));
        widget->setMaximumSize(QSize(280, 16777215));
        widget->setStyleSheet(QString::fromUtf8("background: #9DAABC;"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 270, 181, 141));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 25pt \"Cooper Black\";"));
        label->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(widget, 0, 1, 1, 1);

        widget_2 = new QWidget(MainForm);
        widget_2->setObjectName("widget_2");
        QFont font;
        font.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        widget_2->setFont(font);
        widget_2->setStyleSheet(QString::fromUtf8("background: rgb(5,2,13);"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        btnStack = new QPushButton(widget_2);
        btnStack->setObjectName("btnStack");
        btnStack->setMinimumSize(QSize(180, 90));
        btnStack->setMaximumSize(QSize(160, 90));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        btnStack->setFont(font1);
        btnStack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnStack, 0, 0, 1, 1);

        btnQueue = new QPushButton(widget_2);
        btnQueue->setObjectName("btnQueue");
        btnQueue->setMinimumSize(QSize(180, 90));
        btnQueue->setMaximumSize(QSize(160, 90));
        btnQueue->setFont(font1);
        btnQueue->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #FEFCBF;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnQueue, 0, 1, 1, 1);

        btnLinkedList = new QPushButton(widget_2);
        btnLinkedList->setObjectName("btnLinkedList");
        btnLinkedList->setMinimumSize(QSize(180, 90));
        btnLinkedList->setMaximumSize(QSize(160, 90));
        btnLinkedList->setFont(font1);
        btnLinkedList->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #9AE6B0;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnLinkedList, 0, 2, 1, 1);

        btnDoubleLinkedList = new QPushButton(widget_2);
        btnDoubleLinkedList->setObjectName("btnDoubleLinkedList");
        btnDoubleLinkedList->setMinimumSize(QSize(180, 90));
        btnDoubleLinkedList->setMaximumSize(QSize(160, 90));
        btnDoubleLinkedList->setFont(font1);
        btnDoubleLinkedList->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnDoubleLinkedList, 0, 3, 1, 1);

        btnBST = new QPushButton(widget_2);
        btnBST->setObjectName("btnBST");
        btnBST->setMinimumSize(QSize(180, 90));
        btnBST->setMaximumSize(QSize(160, 90));
        btnBST->setFont(font1);
        btnBST->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #81E6D9;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnBST, 1, 0, 1, 1);

        btnAVLTree = new QPushButton(widget_2);
        btnAVLTree->setObjectName("btnAVLTree");
        btnAVLTree->setMinimumSize(QSize(180, 90));
        btnAVLTree->setMaximumSize(QSize(160, 90));
        btnAVLTree->setFont(font1);
        btnAVLTree->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #90CDF4;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnAVLTree, 1, 1, 1, 1);

        btnRedBlackTree = new QPushButton(widget_2);
        btnRedBlackTree->setObjectName("btnRedBlackTree");
        btnRedBlackTree->setMinimumSize(QSize(180, 90));
        btnRedBlackTree->setMaximumSize(QSize(160, 90));
        btnRedBlackTree->setFont(font1);
        btnRedBlackTree->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #FEB2B2;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnRedBlackTree, 1, 2, 1, 1);

        btnHashTable = new QPushButton(widget_2);
        btnHashTable->setObjectName("btnHashTable");
        btnHashTable->setMinimumSize(QSize(180, 90));
        btnHashTable->setMaximumSize(QSize(160, 90));
        btnHashTable->setFont(font1);
        btnHashTable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #A0F97A;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnHashTable, 1, 3, 1, 1);

        btnSparseMatrix = new QPushButton(widget_2);
        btnSparseMatrix->setObjectName("btnSparseMatrix");
        btnSparseMatrix->setMinimumSize(QSize(180, 90));
        btnSparseMatrix->setMaximumSize(QSize(160, 90));
        btnSparseMatrix->setFont(font1);
        btnSparseMatrix->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #E2E8F0;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnSparseMatrix, 2, 0, 1, 1);

        btnBinoHeap = new QPushButton(widget_2);
        btnBinoHeap->setObjectName("btnBinoHeap");
        btnBinoHeap->setMinimumSize(QSize(180, 90));
        btnBinoHeap->setMaximumSize(QSize(160, 90));
        btnBinoHeap->setFont(font1);
        btnBinoHeap->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #81E6D9;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnBinoHeap, 2, 1, 1, 1);

        btnFiboHeap = new QPushButton(widget_2);
        btnFiboHeap->setObjectName("btnFiboHeap");
        btnFiboHeap->setMinimumSize(QSize(180, 90));
        btnFiboHeap->setMaximumSize(QSize(160, 90));
        btnFiboHeap->setFont(font1);
        btnFiboHeap->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #FEFCB0;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnFiboHeap, 2, 2, 1, 1);

        btnWarshall = new QPushButton(widget_2);
        btnWarshall->setObjectName("btnWarshall");
        btnWarshall->setMinimumSize(QSize(180, 90));
        btnWarshall->setMaximumSize(QSize(160, 90));
        btnWarshall->setFont(font1);
        btnWarshall->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: rgb(254,215,215);\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnWarshall, 2, 3, 1, 1);

        btnFloyd = new QPushButton(widget_2);
        btnFloyd->setObjectName("btnFloyd");
        btnFloyd->setMinimumSize(QSize(180, 90));
        btnFloyd->setMaximumSize(QSize(160, 90));
        btnFloyd->setFont(font1);
        btnFloyd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #9AE6B4;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnFloyd, 3, 0, 1, 1);

        btnDijkstra = new QPushButton(widget_2);
        btnDijkstra->setObjectName("btnDijkstra");
        btnDijkstra->setMinimumSize(QSize(180, 90));
        btnDijkstra->setMaximumSize(QSize(160, 90));
        btnDijkstra->setFont(font1);
        btnDijkstra->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #FFD97F;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnDijkstra, 3, 1, 1, 1);

        btnKruskal = new QPushButton(widget_2);
        btnKruskal->setObjectName("btnKruskal");
        btnKruskal->setMinimumSize(QSize(180, 90));
        btnKruskal->setMaximumSize(QSize(160, 90));
        btnKruskal->setFont(font1);
        btnKruskal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #33FF99;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnKruskal, 3, 2, 1, 1);

        btnPrim = new QPushButton(widget_2);
        btnPrim->setObjectName("btnPrim");
        btnPrim->setMinimumSize(QSize(180, 90));
        btnPrim->setMaximumSize(QSize(160, 90));
        btnPrim->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(28,19,42);\n"
"    border-style: outset;\n"
"    border-width: 0;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 18px;\n"
"	color: #90CDF4;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(30,23,46);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #3F325C;\n"
"}"));

        gridLayout_2->addWidget(btnPrim, 3, 3, 1, 1);


        gridLayout->addWidget(widget_2, 0, 0, 1, 1);


        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "MainForm", nullptr));
        label->setText(QCoreApplication::translate("MainForm", "Data\n"
"Structures\n"
"Visualizer", nullptr));
        btnStack->setText(QCoreApplication::translate("MainForm", "Stack", nullptr));
        btnQueue->setText(QCoreApplication::translate("MainForm", "Queue", nullptr));
        btnLinkedList->setText(QCoreApplication::translate("MainForm", "Linked List", nullptr));
        btnDoubleLinkedList->setText(QCoreApplication::translate("MainForm", "Double\n"
"Linked List", nullptr));
        btnBST->setText(QCoreApplication::translate("MainForm", "Binary Serch\n"
"Tree", nullptr));
        btnAVLTree->setText(QCoreApplication::translate("MainForm", "AVL Tree", nullptr));
        btnRedBlackTree->setText(QCoreApplication::translate("MainForm", "RedBlack Tree", nullptr));
        btnHashTable->setText(QCoreApplication::translate("MainForm", "Hash Table", nullptr));
        btnSparseMatrix->setText(QCoreApplication::translate("MainForm", "Sparse Matrix", nullptr));
        btnBinoHeap->setText(QCoreApplication::translate("MainForm", "Binomial Heap", nullptr));
        btnFiboHeap->setText(QCoreApplication::translate("MainForm", "Fibonacci Heap", nullptr));
        btnWarshall->setText(QCoreApplication::translate("MainForm", "Algoritmo de\n"
"Warshall", nullptr));
        btnFloyd->setText(QCoreApplication::translate("MainForm", "Algoritmo de\n"
"Floyd", nullptr));
        btnDijkstra->setText(QCoreApplication::translate("MainForm", "Algoritmo de\n"
"Dijkstra", nullptr));
        btnKruskal->setText(QCoreApplication::translate("MainForm", "Algoritmo de\n"
"Kruskal", nullptr));
        btnPrim->setText(QCoreApplication::translate("MainForm", "Algoritmo de\n"
"Prim", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H

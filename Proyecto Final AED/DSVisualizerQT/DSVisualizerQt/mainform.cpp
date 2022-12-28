#include "mainform.h"
#include "./ui_mainform.h"
#include "avlform.h"
#include "binarysform.h"
#include "binomialheapform.h"
#include "digraphform.h"
#include "doublelistform.h"
#include "fibonnacciheapform.h"
#include "graphform.h"
#include "hashform.h"
#include "listform.h"
#include "matrizesparzaform.h"
#include "redblacktreeform.h"
#include "stackform.h"
#include "queueform.h"

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainForm)
{
    ui->setupUi(this);
}

MainForm::~MainForm()
{
    delete ui;
}


void MainForm::on_btnStack_clicked()
{
    this->hide();
    StackForm stackForm;
    stackForm.exec();
    this->show();
}


void MainForm::on_btnQueue_clicked()
{
    this->hide();
    QueueForm queueForm;
    queueForm.exec();
    this->show();
}


void MainForm::on_btnLinkedList_clicked()
{
    this->hide();
    listform listForm;
    listForm.exec();
    this->show();
}


void MainForm::on_btnDoubleLinkedList_clicked()
{
    this->hide();
    doublelistform doubleListForm;
    doubleListForm.exec();
    this->show();
}


void MainForm::on_btnSparseMatrix_clicked()
{
    this->hide();
    matrizesparzaform matrizEsparzaForm;
    matrizEsparzaForm.exec();
    this->show();
}


void MainForm::on_btnBST_clicked()
{
    this->hide();
    binarysform binarysForm;
    binarysForm.exec();
    this->show();
}

void MainForm::on_btnBinoHeap_clicked()
{
    this->hide();
    binomialheapform binomialheap;
    binomialheap.exec();
    this->show();
}

void MainForm::on_btnFiboHeap_clicked()
{
    this->hide();
    fibonnacciheapform fibonnacciHeapForm;
    fibonnacciHeapForm.exec();
    this->show();
}


void MainForm::on_btnRedBlackTree_clicked()
{
    this->hide();
    redblacktreeform redblack;
    redblack.exec();
    this->show();
}



void MainForm::on_btnHashTable_clicked()
{
    this->hide();
    hashform hashForm;
    hashForm.exec();
    this->show();
}


void MainForm::on_btnKruskal_clicked()
{
    this->hide();
    Graphform graphForm;
    graphForm.exec();
    this->show();
}


void MainForm::on_btnDijkstra_clicked()
{
    this->hide();
    Digraphform digraphForm;
    digraphForm.exec();
    this->show();
}


void MainForm::on_btnAVLTree_clicked()
{
    this->hide();
    avlform avlForm;
    avlForm.exec();
    this->show();
}


void MainForm::on_btnFloyd_clicked()
{
    this->hide();
    Digraphform digraphForm;
    digraphForm.exec();
    this->show();
}


void MainForm::on_btnWarshall_clicked()
{
    this->hide();
    Digraphform digraphForm;
    digraphForm.exec();
    this->show();
}


void MainForm::on_btnPrim_clicked()
{
    this->hide();
    Graphform graphForm;
    graphForm.exec();
    this->show();
}


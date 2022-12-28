#include "fibonnacciheapform.h"
#include "ui_fibonnacciheapform.h"

fibonnacciheapform::fibonnacciheapform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fibonnacciheapform)
{
    ui->setupUi(this);
    ui->spinBox->setRange(0,1000);
    ui->labelCodeImg->setPixmap(QPixmap(QString::fromUtf8("FotosCode/NodoFibo.png")));
    ui->labelCodeImg->setScaledContents(true);
}

fibonnacciheapform::~fibonnacciheapform()
{
    delete ui;
}

void fibonnacciheapform::on_btnPush_clicked()
{
    int dato=ui->spinBox->value();
    Fibo.insert_dato(dato);
    Fibo.Draw();
    QImage img("FiboHeap.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->spinBox->clear();
}

void fibonnacciheapform::on_btnDeleteMin_clicked()
{
    Fibo.delete_min();
    Fibo.Draw();
    QImage img("FiboHeap.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
}


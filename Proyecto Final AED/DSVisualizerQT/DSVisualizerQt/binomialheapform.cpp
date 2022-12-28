#include "binomialheapform.h"
#include "ui_binomialheapform.h"

binomialheapform::binomialheapform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::binomialheapform)
{
    ui->setupUi(this);
    ui->spinBox_2->setRange(0,1000);
    ui->labelCodeImg->setPixmap(QPixmap(QString::fromUtf8("FotosCode/NodoBinomial.png")));
    ui->labelCodeImg->setScaledContents(true);
}

binomialheapform::~binomialheapform()
{
    delete ui;
}

void binomialheapform::on_btnPush_2_clicked()
{
    int dato=ui->spinBox_2->value();
    BinoHeap.Insert(dato);
    BinoHeap.Draw();
    QImage img("BinoHeap.jpg");
    ui->labelGrafico_2->setPixmap(QPixmap::fromImage(img));
    ui->spinBox_2->clear();
}


void binomialheapform::on_btnDeleteMax_clicked()
{
    BinoHeap.Extract_Max();
    BinoHeap.Draw();
    QImage img("BinoHeap.jpg");
    ui->labelGrafico_2->setPixmap(QPixmap::fromImage(img));
    ui->spinBox_2->clear();
}


#include "matrizesparzaform.h"
#include "ui_matrizesparzaform.h"

matrizesparzaform::matrizesparzaform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrizesparzaform)
{
    ui->setupUi(this);
    ui->labelCodeImg->setPixmap(QPixmap(QString::fromUtf8("FotosCode/NodoE.png")));
    ui->labelCodeImg->setScaledContents(true);
    ui->spinBox->setRange(0,1000);
    ui->spinBoxFil->setRange(0,4);
    ui->spinBoxCol->setRange(0,4);
}

matrizesparzaform::~matrizesparzaform()
{
    delete ui;
}

void matrizesparzaform::on_btnPush_clicked()
{
    int dato=ui->spinBox->value();
    int fila=ui->spinBoxFil->value();
    int columna=ui->spinBoxCol->value();
    MatEspar.Insert(dato,fila,columna);
    MatEspar.dibujar();
    QImage img("esparzadot.jpg");
    ui->labelGrafico_2->setPixmap(QPixmap::fromImage(img));
    ui->spinBox->clear();
}


void matrizesparzaform::on_btnDelete_clicked()
{
    int fila=ui->spinBoxFil->value();
    int columna=ui->spinBoxCol->value();
    MatEspar.Delete_Cell(fila,columna);
    MatEspar.dibujar();
    QImage img("esparzadot.jpg");
    ui->labelGrafico_2->setPixmap(QPixmap::fromImage(img));
    ui->spinBox->clear();
}


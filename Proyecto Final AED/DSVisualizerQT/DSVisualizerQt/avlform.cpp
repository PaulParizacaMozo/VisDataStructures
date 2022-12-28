#include "avlform.h"
#include "ui_avlform.h"

avlform::avlform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::avlform)
{
    ui->setupUi(this);
    ui->labelCodeImg->setPixmap(QPixmap(QString::fromUtf8("FotosCode/NodoAVL.png")));
    ui->labelCodeImg->setScaledContents(true);
}

avlform::~avlform()
{
    delete ui;
}

void avlform::on_btnInsertar_clicked()
{
    QString qtDato = ui->inputT->toPlainText();
    int dato = qtDato.toInt();
    A<<dato;
    A.Draw();
    QImage img("archivoAvl.jpg");
    ui->labelGrafico_2->setPixmap(QPixmap::fromImage(img));
    ui->inputT->clear();
}


void avlform::on_btnDelete_clicked()
{

}


void avlform::on_btnBuscar_clicked()
{
    QString qtDato = ui->inputTFind->toPlainText();
    int dato = qtDato.toInt();
    A.DrawFind(dato);
    QImage img("archivoAvl.jpg");
    ui->labelGrafico_2->setPixmap(QPixmap::fromImage(img));
    ui->inputT->clear();
}


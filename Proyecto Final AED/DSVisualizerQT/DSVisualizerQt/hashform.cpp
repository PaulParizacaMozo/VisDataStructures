#include "hashform.h"
#include "ui_hashform.h"

hashform::hashform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hashform)
{
    ui->setupUi(this);
}

hashform::~hashform()
{
    delete ui;
}

void hashform::on_btnInsertar_clicked()
{
    QString qtDato = ui->inputDato->toPlainText();
    int dato = qtDato.toInt();
    QString qtDato2 = ui->inputKey->toPlainText();
    std::string dato2 = qPrintable(qtDato2);

    A.Insert(dato2,dato);
    A.Draw();
    QImage img("archivoHash.jpg");
    ui->labelGrafico_2->setPixmap(QPixmap::fromImage(img));
    ui->inputDato->clear();
    ui->inputKey->clear();
}


void hashform::on_btnDelete_clicked()
{

}


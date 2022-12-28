#include "doublelistform.h"
#include "ui_doublelistform.h"

doublelistform::doublelistform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::doublelistform)
{
    ui->setupUi(this);
    ui->labelCodeImg->setPixmap(QPixmap(QString::fromUtf8("FotosCode/NodoDL.png")));
    ui->labelCodeImg->setScaledContents(true);

}

doublelistform::~doublelistform()
{
    delete ui;
}

void doublelistform::on_btnPushBack_clicked()
{
    QString qtDato = ui->txtInputDatoPushBack->toPlainText();
    int dato = qtDato.toInt();
    listadoble.Push_Back(dato);
    listadoble.Draw();
    QImage img("archivoListaDoble.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->txtInputDatoPushBack->clear();
}


void doublelistform::on_btnPushFront_clicked()
{
    QString qtDato = ui->txtInputDatoPushFront->toPlainText();
    int dato = qtDato.toInt();
    listadoble.Push_Front(dato);
    listadoble.Draw();
    QImage img("archivoListaDoble.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->txtInputDatoPushFront->clear();
}


void doublelistform::on_btnPopBack_clicked()
{
    listadoble.Delete_Last();
    listadoble.Draw();
    QImage img("archivoListaDoble.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
}


void doublelistform::on_btnPopFront_clicked()
{
    listadoble.Delete_Front();
    listadoble.Draw();
    QImage img("archivoListaDoble.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
}


void doublelistform::on_btnInsert_clicked()
{
    QString qtDato = ui->txtInputDatoInsert->toPlainText();
    QString qtIndice = ui->txtInputDatoIndice->toPlainText();
    int dato = qtDato.toInt();
    int indice = qtIndice.toInt();
    listadoble.InsertByIndex(indice,dato);
    listadoble.Draw();
    QImage img("archivoListaDoble.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
}


#include "binarysform.h"
#include "ui_binarysform.h"

binarysform::binarysform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::binarysform)
{
    ui->setupUi(this);
    ui->labelCodeImg->setPixmap(QPixmap(QString::fromUtf8("FotosCode/NodoBST.png")));
    ui->labelCodeImg->setScaledContents(true);
}

binarysform::~binarysform()
{
    delete ui;
}

void binarysform::on_btnInsertar_clicked()
{
    QString qtDato = ui->inputT->toPlainText();
    int dato = qtDato.toInt();
    A<<dato;
    A.Draw();
    QImage img("archivoAbinario.jpg");
    ui->labelGrafico_2->setPixmap(QPixmap::fromImage(img));
    ui->inputT->clear();
}


void binarysform::on_btnDelete_clicked()
{
    QString qtDato = ui->inputT_Eliminar->toPlainText();
    int dato = qtDato.toInt();
    A.Delete(dato);
    A.Draw();
    QImage img("archivoAbinario.jpg");
    ui->labelGrafico_2->setPixmap(QPixmap::fromImage(img));
    ui->inputT->clear();
}


void binarysform::on_btnBuscar_clicked()
{
    QString qtDato = ui->inputT_Find->toPlainText();
    int dato = qtDato.toInt();
    A.DrawFind(dato);
    QImage img("archivoAbinario.jpg");
    ui->labelGrafico_2->setPixmap(QPixmap::fromImage(img));
    ui->inputT->clear();
}


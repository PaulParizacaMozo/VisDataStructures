#include "listform.h"
#include "ui_listform.h"

listform::listform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listform)
{
    ui->setupUi(this);
    ui->labelCodeImg->setPixmap(QPixmap(QString::fromUtf8("FotosCode/NodoL.png")));
    ui->labelCodeImg->setScaledContents(true);
}

listform::~listform()
{
    delete ui;
}

void listform::on_btnPushBack_clicked()
{
    QString qtDato = ui->txtInputDatoPushBack->toPlainText();
    int dato = qtDato.toInt();
    lista.Push_Back(dato);
    lista.Draw();
    QImage img("archivoLista.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->txtInputDatoPushBack->clear();
}


void listform::on_btnPushFront_clicked()
{
    QString qtDato = ui->txtInputDatoPushFront->toPlainText();
    int dato = qtDato.toInt();
    lista.Push_Front(dato);
    lista.Draw();
    QImage img("archivoLista.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->txtInputDatoPushFront->clear();
}


void listform::on_btnPopBack_clicked()
{
    lista.Pop_Last();
    lista.Draw();
    QImage img("archivoLista.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
}


void listform::on_btnPopFront_clicked()
{
    lista.Pop_Front();
    lista.Draw();
    QImage img("archivoLista.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
}


void listform::on_btnInsert_clicked()
{
    QString qtDato = ui->txtInputDatoInsert->toPlainText();
    QString qtIndice = ui->txtInputDatoIndice->toPlainText();
    int dato = qtDato.toInt();
    int indice = qtIndice.toInt();
    lista.InsertPorIndice(indice,dato);
    lista.Draw();
    QImage img("archivoLista.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
}


void listform::on_btnFind_clicked()
{
    QString qtDato = ui->txtInputDatoFind->toPlainText();
    int dato = qtDato.toInt();
    lista.Find_Draw(dato);
    QImage img("archivoLista.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->txtInputDatoPushFront->clear();
}


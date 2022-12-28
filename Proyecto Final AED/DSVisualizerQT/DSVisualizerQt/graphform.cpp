#include "graphform.h"
#include "ui_graphform.h"

Graphform::Graphform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphform)
{
    ui->setupUi(this);
    G.Insert("A");
      G.Insert("B");
      G.Insert("C");
      G.Insert("D");
      G.Insert("E");
      G.Insert("F");
      G.Insert("G");

      G.Insert_EdgeG("A","B",4);
      G.Insert_EdgeG("A","D",3);
      G.Insert_EdgeG("B","D",5);
      G.Insert_EdgeG("A","H",15);
      G.Insert_EdgeG("D","C",4);
      G.Insert_EdgeG("B","C",5);
      G.Insert_EdgeG("C","E",6);
      G.Insert_EdgeG("C","G",3);
      G.Insert_EdgeG("G","F",9);
      G.Insert_EdgeG("E","F",8);
      G.Insert_EdgeG("D","F",12);
}

Graphform::~Graphform()
{
    delete ui;
}

void Graphform::on_btn_Draw_clicked()
{
    G.Draw();
    QImage img("graph.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->inputVertice->clear();
}


void Graphform::on_btnPrim_clicked()
{
    QString qtDato = ui->inputPrim->toPlainText();
    std::string dato = qPrintable(qtDato);
    Prim<string,int>(G,dato);

    QImage img("graph.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->inputPrim->clear();
}


void Graphform::on_btnKruskal_clicked()
{
    Kruskal<string,int>(G);
    QImage img("graph.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->inputPrim->clear();
}


void Graphform::on_InsVertice_clicked()
{
    QString qtDato = ui->inputVertice->toPlainText();
    std::string dato = qPrintable(qtDato);
    G.Insert(dato);
    G.Draw();
    QImage img("graph.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->inputVertice->clear();
}


void Graphform::on_InsArista_clicked()
{
    QString qtDatoVO = ui->inputVO->toPlainText();
    QString qtDatoVD = ui->inputVD->toPlainText();
    QString qtDatoPeso = ui->inputPeso->toPlainText();
    std::string datoVO = qPrintable(qtDatoVO);
    std::string datoVD = qPrintable(qtDatoVD);
    int datoPeso = qtDatoPeso.toInt();
    G.Insert_EdgeG(datoVO,datoVD,datoPeso);
    G.Draw();
    QImage img("graph.jpg");

    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->inputVO->clear();
    ui->inputVD->clear();
    ui->inputPeso->clear();
}

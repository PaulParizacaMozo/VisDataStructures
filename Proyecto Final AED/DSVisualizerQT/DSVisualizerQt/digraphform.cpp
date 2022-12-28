#include "digraphform.h"
#include "ui_digraphform.h"

Digraphform::Digraphform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Digraphform)
{
    ui->setupUi(this);
    G.Insert("A");
      G.Insert("B");
      G.Insert("C");
      G.Insert("D");
      G.Insert("E");
      G.Insert("F");
      G.Insert("G");

      G.Insert_Edge("A","B",4);
      G.Insert_Edge("A","D",3);
      G.Insert_Edge("B","D",5);
      G.Insert_Edge("A","H",15);
      G.Insert_Edge("D","C",4);
      G.Insert_Edge("B","C",5);
      G.Insert_Edge("C","E",6);
      G.Insert_Edge("C","G",3);
      G.Insert_Edge("G","F",9);
      G.Insert_Edge("E","F",8);
      G.Insert_Edge("D","F",12);

}

Digraphform::~Digraphform()
{
    delete ui;
}
void Digraphform::on_InsVertice_clicked()
{
    QString qtDato = ui->inputVertice->toPlainText();
    std::string dato = qPrintable(qtDato);
    G.Insert(dato);
    G.Draw();
    QImage img("archivoFloyd_Warshall.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->inputVertice->clear();
}


void Digraphform::on_InsArista_clicked()
{
    QString qtDatoVO = ui->inputVO->toPlainText();
    QString qtDatoVD = ui->inputVD->toPlainText();
    QString qtDatoPeso = ui->inputPeso->toPlainText();
    std::string datoVO = qPrintable(qtDatoVO);
    std::string datoVD = qPrintable(qtDatoVD);
    int datoPeso = qtDatoPeso.toInt();
    G.Insert_Edge(datoVO,datoVD,datoPeso);
    G.Draw();
    QImage img("archivoFloyd_Warshall.jpg");

    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->inputVO->clear();
    ui->inputVD->clear();
    ui->inputPeso->clear();
}


void Digraphform::on_btnDijkstra_clicked()
{
    QString qtDato = ui->inputDij->toPlainText();
    std::string dato = qPrintable(qtDato);
    G.dijkstra(dato);
    QImage img("archivoFloyd_Warshall.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->inputDij->clear();
}


void Digraphform::on_btnFloyd_clicked()
{
    G.Floyd();
    G.PrintFloyd();
    G.DrawFloyd();
    QImage img("archivoFloyd_Warshall.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
}


void Digraphform::on_btnWarshall_clicked()
{
    G.Warshal();
    G.PrintWarshall(); cout<<endl;
    G.DrawWarshall();
    QImage img("archivoFloyd_Warshall.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
}


void Digraphform::on_btn_Draw_clicked()
{
    G.Draw();
    QImage img("archivoFloyd_Warshall.jpg");

    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->inputVertice->clear();
}


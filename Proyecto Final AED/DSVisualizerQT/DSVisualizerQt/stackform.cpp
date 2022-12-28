#include "stackform.h"
#include "ui_stackform.h"

StackForm::StackForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StackForm)
{
    ui->setupUi(this);
    ui->txtInputDato->setAlignment(Qt::AlignCenter);
    ui->labelCodeImg->setPixmap(QPixmap(QString::fromUtf8("FotosCode/NodoP.png")));
    ui->labelCodeImg->setScaledContents(true);

}

StackForm::~StackForm()
{
    delete ui;
}

void StackForm::on_btnPush_clicked()
{
    QString qtDato = ui->txtInputDato->toPlainText();
    std::string dato = qPrintable(qtDato);
    pila.push(dato);
    pila.draw();
    QImage img("archivoPila.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->txtInputDato->clear();
}


void StackForm::on_btnPop_clicked()
{
    pila.pop();
    pila.draw();
    QImage img("archivoPila.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
}


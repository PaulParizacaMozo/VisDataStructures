#include "redblacktreeform.h"
#include "ui_redblacktreeform.h"

redblacktreeform::redblacktreeform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::redblacktreeform)
{
    ui->setupUi(this);
    ui->spinBox->setRange(0,1000);
    ui->labelCodeImg->setPixmap(QPixmap(QString::fromUtf8("FotosCode/NodoRB.png")));
    ui->labelCodeImg->setScaledContents(true);

}

redblacktreeform::~redblacktreeform()
{
    delete ui;
}

void redblacktreeform::on_btnPush_clicked()
{
    int dato=ui->spinBox->value();
    RBTree.Insert_i(dato);
    RBTree.Draw();
    QImage img("archivoRB.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->spinBox->clear();
}


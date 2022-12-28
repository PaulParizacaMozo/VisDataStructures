#include "queueform.h"
#include "ui_queueform.h"

QueueForm::QueueForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueueForm)
{
    ui->setupUi(this);
    ui->labelCodeImg->setPixmap(QPixmap(QString::fromUtf8("FotosCode/NodoC.png")));
    ui->labelCodeImg->setScaledContents(true);

}

QueueForm::~QueueForm()
{
    delete ui;
}

void QueueForm::on_btnPush_clicked()
{
    QString qtDato = ui->txtInputDato->toPlainText();
    std::string dato = qPrintable(qtDato);
    queue.Push(dato);
    queue.Draw();
    QImage img("archivoCola.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
    ui->txtInputDato->clear();
}


void QueueForm::on_btnPop_clicked()
{
    queue.Pop();
    queue.Draw();
    QImage img("archivoCola.jpg");
    ui->labelGrafico->setPixmap(QPixmap::fromImage(img));
}


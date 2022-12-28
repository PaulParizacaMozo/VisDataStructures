#ifndef MATRIZESPARZAFORM_H
#define MATRIZESPARZAFORM_H

#include <QDialog>
#include <MatrizEsparza.h>

namespace Ui {
class matrizesparzaform;
}

class matrizesparzaform : public QDialog
{
    Q_OBJECT
public:
    Matrix<int,5,5> MatEspar;
public:
    explicit matrizesparzaform(QWidget *parent = nullptr);
    ~matrizesparzaform();

private slots:
    void on_btnPush_clicked();

    void on_btnDelete_clicked();

private:
    Ui::matrizesparzaform *ui;
};

#endif // MATRIZESPARZAFORM_H

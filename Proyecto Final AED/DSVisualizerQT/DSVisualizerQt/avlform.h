#ifndef AVLFORM_H
#define AVLFORM_H

#include <avl.h>

#include <QDialog>

namespace Ui {
class avlform;
}

class avlform : public QDialog
{
    Q_OBJECT

public:
    Avl<int> A;

public:
    explicit avlform(QWidget *parent = nullptr);
    ~avlform();

private slots:
    void on_btnInsertar_clicked();

    void on_btnDelete_clicked();

    void on_btnBuscar_clicked();

private:
    Ui::avlform *ui;
};

#endif // AVLFORM_H

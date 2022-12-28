#ifndef BINARYSFORM_H
#define BINARYSFORM_H

#include <QDialog>
#include <binarys.h>

namespace Ui {
class binarysform;
}

class binarysform : public QDialog
{
    Q_OBJECT
public:
    Tree<int> A;

public:
    explicit binarysform(QWidget *parent = nullptr);
    ~binarysform();

private slots:
    void on_btnInsertar_clicked();

    void on_btnDelete_clicked();

    void on_btnBuscar_clicked();

private:
    Ui::binarysform *ui;
};

#endif // BINARYSFORM_H

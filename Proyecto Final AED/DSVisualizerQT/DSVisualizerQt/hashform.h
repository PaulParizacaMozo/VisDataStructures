#ifndef HASHFORM_H
#define HASHFORM_H

#include <QDialog>
#include <hash.h>
#include <fd.h>
namespace Ui {
class hashform;
}

class hashform : public QDialog
{
    Q_OBJECT
public:
    Hash<int, FD> A;

public:
    explicit hashform(QWidget *parent = nullptr);
    ~hashform();

private slots:
    void on_btnInsertar_clicked();

    void on_btnDelete_clicked();

private:
    Ui::hashform *ui;
};

#endif // HASHFORM_H

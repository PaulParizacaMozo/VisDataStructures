#ifndef DOUBLELISTFORM_H
#define DOUBLELISTFORM_H

#include <QDialog>
#include "DoubleLinkedList.h"

namespace Ui {
class doublelistform;
}

class doublelistform : public QDialog
{
public:
    DoubleLinkedList<int> listadoble;
    Q_OBJECT

public:
    explicit doublelistform(QWidget *parent = nullptr);
    ~doublelistform();

private slots:
    void on_btnPushBack_clicked();

    void on_btnPushFront_clicked();

    void on_btnPopBack_clicked();

    void on_btnPopFront_clicked();

    void on_btnInsert_clicked();

private:
    Ui::doublelistform *ui;
};

#endif // DOUBLELISTFORM_H

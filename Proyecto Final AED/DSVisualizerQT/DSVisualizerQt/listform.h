#ifndef LISTFORM_H
#define LISTFORM_H

#include <QDialog>
#include "LinkedList.h"

namespace Ui {
class listform;
}

class listform : public QDialog
{
    Q_OBJECT
public:
    List<int> lista;

public:
    explicit listform(QWidget *parent = nullptr);
    ~listform();

private slots:
    void on_btnPushBack_clicked();

    void on_btnPushFront_clicked();

    void on_btnPopBack_clicked();

    void on_btnPopFront_clicked();

    void on_btnInsert_clicked();

    void on_btnFind_clicked();

private:
    Ui::listform *ui;
};

#endif // LISTFORM_H

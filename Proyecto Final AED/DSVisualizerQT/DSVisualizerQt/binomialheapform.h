#ifndef BINOMIALHEAPFORM_H
#define BINOMIALHEAPFORM_H

#include <QDialog>
#include <BinomialHeap.h>

namespace Ui {
class binomialheapform;
}

class binomialheapform : public QDialog
{
    Q_OBJECT
public:
    Binomial_Heap<int> BinoHeap;
public:
    explicit binomialheapform(QWidget *parent = nullptr);
    ~binomialheapform();

private slots:
    void on_btnPush_2_clicked();

    void on_btnDeleteMax_clicked();

private:
    Ui::binomialheapform *ui;
};

#endif // BINOMIALHEAPFORM_H

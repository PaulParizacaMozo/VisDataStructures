#ifndef FIBONNACCIHEAPFORM_H
#define FIBONNACCIHEAPFORM_H

#include <QDialog>
#include <FibonnacciHeaps.h>

namespace Ui {
class fibonnacciheapform;
}

class fibonnacciheapform : public QDialog
{
    Q_OBJECT
//  another public
public:
    Fibo_heaps<int> Fibo;
public:
    explicit fibonnacciheapform(QWidget *parent = nullptr);
    ~fibonnacciheapform();
//  private slots
private slots:
    void on_btnPush_clicked();

    void on_btnDeleteMin_clicked();

private:
    Ui::fibonnacciheapform *ui;
};

#endif // FIBONNACCIHEAPFORM_H

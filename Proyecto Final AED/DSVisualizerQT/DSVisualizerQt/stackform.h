#ifndef STACKFORM_H
#define STACKFORM_H

#include <QDialog>
#include "Stack.h"

namespace Ui {
class StackForm;
}

class StackForm : public QDialog
{
    Q_OBJECT
public:
    Pila<std::string> pila;
public:
    explicit StackForm(QWidget *parent = nullptr);
    ~StackForm();

private slots:
    void on_btnPush_clicked();

    void on_btnPop_clicked();

private:
    Ui::StackForm *ui;
};

#endif // STACKFORM_H

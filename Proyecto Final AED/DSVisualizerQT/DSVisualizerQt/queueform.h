#ifndef QUEUEFORM_H
#define QUEUEFORM_H

#include <QDialog>
#include "Queue.h"

namespace Ui {
class QueueForm;
}

class QueueForm : public QDialog
{
    Q_OBJECT
public:
    Cola<std::string> queue;
public:
    explicit QueueForm(QWidget *parent = nullptr);
    ~QueueForm();

private slots:
    void on_btnPush_clicked();

    void on_btnPop_clicked();

private:
    Ui::QueueForm *ui;
};

#endif // QUEUEFORM_H

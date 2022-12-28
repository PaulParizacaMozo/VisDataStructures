#ifndef GRAPHFORM_H
#define GRAPHFORM_H
#include "graph.h"

#include <QDialog>

namespace Ui {
class Graphform;
}

class Graphform : public QDialog
{
    Q_OBJECT
public:
    GraphX<string, int>  G;
public:
    explicit Graphform(QWidget *parent = nullptr);
    ~Graphform();

private slots:
    void on_btn_Draw_clicked();

    void on_btnPrim_clicked();

    void on_btnKruskal_clicked();

    void on_InsVertice_clicked();

    void on_InsArista_clicked();

private:
    Ui::Graphform *ui;
};

#endif // GRAPHFORM_H

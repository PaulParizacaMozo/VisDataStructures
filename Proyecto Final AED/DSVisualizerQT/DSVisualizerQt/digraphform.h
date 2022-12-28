#ifndef DIGRAPHFORM_H
#define DIGRAPHFORM_H

#include <QDialog>
#include <Digraph.h>

namespace Ui {
class Digraphform;
}

class Digraphform : public QDialog
{
    Q_OBJECT
public:
    Graph<string, int>  G;

public:
    explicit Digraphform(QWidget *parent = nullptr);
    ~Digraphform();

private slots:
    void on_InsVertice_clicked();

    void on_InsArista_clicked();

    void on_btnDijkstra_clicked();

    void on_btnFloyd_clicked();

    void on_btnWarshall_clicked();

    void on_btn_Draw_clicked();

private:
    Ui::Digraphform *ui;
};

#endif // DIGRAPHFORM_H

#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainForm; }
QT_END_NAMESPACE

class MainForm : public QWidget
{
    Q_OBJECT

public:
    MainForm(QWidget *parent = nullptr);
    ~MainForm();

private slots:
    void on_btnStack_clicked();

    void on_btnQueue_clicked();

    void on_btnLinkedList_clicked();

    void on_btnDoubleLinkedList_clicked();

    void on_btnSparseMatrix_clicked();

    void on_btnBST_clicked();

    void on_btnBinoHeap_clicked();

    void on_btnFiboHeap_clicked();

    void on_btnRedBlackTree_clicked();

    void on_btnHashTable_clicked();

    void on_btnKruskal_clicked();

    void on_btnDijkstra_clicked();

    void on_btnAVLTree_clicked();

    void on_btnFloyd_clicked();

    void on_btnWarshall_clicked();

    void on_btnPrim_clicked();

private:
    Ui::MainForm *ui;
};
#endif // MAINFORM_H

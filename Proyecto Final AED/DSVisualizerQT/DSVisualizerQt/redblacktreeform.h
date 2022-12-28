#ifndef REDBLACKTREEFORM_H
#define REDBLACKTREEFORM_H

#include <QDialog>
#include <RedBlackTree.h>

namespace Ui {
class redblacktreeform;
}

class redblacktreeform : public QDialog
{
    Q_OBJECT
public:
    RedBlackTree<int> RBTree;
public:
    explicit redblacktreeform(QWidget *parent = nullptr);
    ~redblacktreeform();

private slots:
    void on_btnPush_clicked();

private:
    Ui::redblacktreeform *ui;
};

#endif // REDBLACKTREEFORM_H

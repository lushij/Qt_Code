#ifndef SETDIALOG_H
#define SETDIALOG_H

#include <QDialog>

namespace Ui {
class setDialog;
}

class setDialog : public QDialog
{
    Q_OBJECT//想要使用信号槽，必须包含这个

public:
    explicit setDialog(QWidget *parent = nullptr);
    ~setDialog();
private slots:
    void on_btnAdd_clicked();
signals://自定义信号
    void sig_addOne(int num);
private:
    Ui::setDialog *ui;
};

#endif // SETDIALOG_H

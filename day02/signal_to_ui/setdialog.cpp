#include "setdialog.h"
#include "ui_setdialog.h"

setDialog::setDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setDialog)
{
    ui->setupUi(this);
}

setDialog::~setDialog()
{
    delete ui;
}

 void setDialog::on_btnAdd_clicked()
 {
    //发送信号
     static int value = 100;
     emit sig_addOne(value++);
 }

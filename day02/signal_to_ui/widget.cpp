#include "widget.h"
#include "ui_widget.h"
#include "setdialog.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnOpen_clicked()
{
    setDialog dlg;
//    dlg.exec();//事件循环，会阻塞ui
    //接收信号用connect
    connect(&dlg,&setDialog::sig_addOne,[=](int value){
        ui->lineEdit->setText((QString::number(value)));
    });
    dlg.exec();
}

#include "widget.h"
#include "ui_widget.h"
#include "thread.h"
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
  void Widget::on_btnUpdate_clicked()
  {
      //点击按钮触发线程开启
      child_thread *pthread = new child_thread();
      connect(pthread,&child_thread::sig_SendScore,this,&Widget::show_info);
      pthread->start();
  }

  void Widget::show_info(Score sc)
  {
      string info = sc.name+" id = "+to_string(sc.id)+" age = "+to_string(sc.age);
      ui->lineEdit->setText(QString::fromStdString(info));
  }

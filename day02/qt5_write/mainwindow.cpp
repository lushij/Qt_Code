#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>//引入弹窗
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qt4写法
//    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(btnSlot()));
    //qt5写法 常用
//    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::btnSlot);
    //lamda表达式 也常用但是代码一旦多了，会复杂使代码不美观
    connect(ui->pushButton,&QPushButton::clicked,[&](){
        QMessageBox::information(this,u8"标题",u8"点击了按钮");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

 void MainWindow::btnSlot()
 {
     QMessageBox::information(this,u8"标题",u8"点击了按钮");
 }

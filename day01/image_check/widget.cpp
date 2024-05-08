#include "widget.h"
#include "ui_widget.h"
#include <QDebug>//加入调试信息
#include <QFileDialog>
#include <QSettings>//读取配置文件
#include <QSettings>
#include <QStandardPaths>//
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label_image->clear();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_btnOpen_clicked()
{
//    qDebug() << "clicked ！" ;
    //QString 是文本类型
    QString config_path = qApp->applicationDirPath() + "/config/Setting.ini";//解决如何记住上次打开文件的位置
    qDebug() << config_path;
    QSettings *pIniSet = new QSettings(config_path,QSettings::IniFormat);//也可以采用智能指针
    QString  lastPath = pIniSet->value("/LastPath/path").toString();
    if(lastPath.isEmpty())
    {
       lastPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    }
    QString fileName = QFileDialog::getOpenFileName(this,"请选择图片",lastPath,"图片(*.png *.jpeg);;");
    if(fileName.isEmpty())
    {
        return;
    }
    ui->lineEdit_path->setText(fileName);
    //在展示之前进行自适应缩放
    QPixmap *pix = new QPixmap(fileName);
    pix->scaled(ui->label_image->size(),Qt::KeepAspectRatio);
    ui->label_image->setScaledContents(true);//ui界面也支持自由缩放
    ui->label_image->setPixmap(*pix);
    delete pix;
    pix = nullptr;
    int end = fileName.lastIndexOf("/");
    QString _path = fileName.left(end);//截取字符串
    qDebug() << _path;
    //重新写入配置文件
    pIniSet->setValue("/LastPath/path",_path);
    delete pIniSet;
    pIniSet=nullptr;
}

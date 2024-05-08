#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBox->addItem("11");//添加下拉选项
    ui->comboBox->addItem("12");
    ui->comboBox->addItem("13");
//    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(onidx(int)));
    //currentIndexChanged有两个参数重载，若用qt5写法不行，可以用qt4
    //也可以用泛化编程
    connect(ui->comboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&Widget::onidx);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onidx(int idx)
{

}

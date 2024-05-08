#include "mainwindow.h"

#include <QApplication>

//信号槽使用
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

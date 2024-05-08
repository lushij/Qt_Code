/********************************************************************************
** Form generated from reading UI file 'setdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETDIALOG_H
#define UI_SETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_setDialog
{
public:
    QPushButton *btnAdd;

    void setupUi(QDialog *setDialog)
    {
        if (setDialog->objectName().isEmpty())
            setDialog->setObjectName(QString::fromUtf8("setDialog"));
        setDialog->resize(400, 300);
        btnAdd = new QPushButton(setDialog);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(130, 100, 93, 28));

        retranslateUi(setDialog);

        QMetaObject::connectSlotsByName(setDialog);
    } // setupUi

    void retranslateUi(QDialog *setDialog)
    {
        setDialog->setWindowTitle(QCoreApplication::translate("setDialog", "Dialog", nullptr));
        btnAdd->setText(QCoreApplication::translate("setDialog", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setDialog: public Ui_setDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETDIALOG_H

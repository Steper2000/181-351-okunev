/********************************************************************************
** Form generated from reading UI file 'showDB.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWDB_H
#define UI_SHOWDB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_showDB
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;

    void setupUi(QDialog *showDB)
    {
        if (showDB->objectName().isEmpty())
            showDB->setObjectName(QString::fromUtf8("showDB"));
        showDB->resize(936, 538);
        horizontalLayout = new QHBoxLayout(showDB);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(showDB);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout->addWidget(tableView);


        retranslateUi(showDB);

        QMetaObject::connectSlotsByName(showDB);
    } // setupUi

    void retranslateUi(QDialog *showDB)
    {
        showDB->setWindowTitle(QApplication::translate("showDB", "showDB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showDB: public Ui_showDB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWDB_H

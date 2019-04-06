/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *welcome;
    QPushButton *pushButton_nolog;
    QPushButton *pushButton_add;

    void setupUi(QDialog *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->resize(438, 328);
        layoutWidget = new QWidget(menu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 50, 271, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        welcome = new QLabel(layoutWidget);
        welcome->setObjectName(QString::fromUtf8("welcome"));
        welcome->setFrameShape(QFrame::NoFrame);
        welcome->setLineWidth(0);
        welcome->setMidLineWidth(0);
        welcome->setTextFormat(Qt::AutoText);
        welcome->setAlignment(Qt::AlignCenter);
        welcome->setMargin(0);
        welcome->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(welcome);

        pushButton_nolog = new QPushButton(layoutWidget);
        pushButton_nolog->setObjectName(QString::fromUtf8("pushButton_nolog"));

        verticalLayout->addWidget(pushButton_nolog);

        pushButton_add = new QPushButton(layoutWidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        verticalLayout->addWidget(pushButton_add);


        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QDialog *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "menu", nullptr));
        welcome->setText(QApplication::translate("menu", "Hello, manager! What do you want to do?", nullptr));
        pushButton_nolog->setText(QApplication::translate("menu", "Show nolog info", nullptr));
        pushButton_add->setText(QApplication::translate("menu", "Change database", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H

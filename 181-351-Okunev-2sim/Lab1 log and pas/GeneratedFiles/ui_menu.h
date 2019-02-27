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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *welcome;
    QPushButton *pushButton_nolog;
    QPushButton *pushButton_change;

    void setupUi(QDialog *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->resize(358, 219);
        groupBox = new QGroupBox(menu);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(60, 40, 231, 121));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 10, 171, 101));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        welcome = new QLabel(widget);
        welcome->setObjectName(QString::fromUtf8("welcome"));
        welcome->setFrameShape(QFrame::NoFrame);
        welcome->setLineWidth(0);
        welcome->setMidLineWidth(0);
        welcome->setTextFormat(Qt::AutoText);
        welcome->setAlignment(Qt::AlignCenter);
        welcome->setMargin(0);
        welcome->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(welcome);

        pushButton_nolog = new QPushButton(widget);
        pushButton_nolog->setObjectName(QString::fromUtf8("pushButton_nolog"));

        verticalLayout->addWidget(pushButton_nolog);

        pushButton_change = new QPushButton(widget);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));
        pushButton_change->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(pushButton_change);


        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QDialog *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "menu", nullptr));
        groupBox->setTitle(QApplication::translate("menu", "GroupBox", nullptr));
        welcome->setText(QApplication::translate("menu", "Hello! What do you want to do?", nullptr));
        pushButton_nolog->setText(QApplication::translate("menu", "Pay nolog", nullptr));
        pushButton_change->setText(QApplication::translate("menu", "Change login or password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H

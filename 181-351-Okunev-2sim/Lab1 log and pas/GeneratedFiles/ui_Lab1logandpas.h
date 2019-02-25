/********************************************************************************
** Form generated from reading UI file 'Lab1logandpas.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB1LOGANDPAS_H
#define UI_LAB1LOGANDPAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab1logandpasClass
{
public:
    QAction *actionClose;
    QAction *actionAbout;
    QWidget *centralWidget;
    QLineEdit *line_login;
    QLineEdit *line_password;
    QLabel *label_login;
    QLabel *label_password;
    QPushButton *pushButton_autorise;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab1logandpasClass)
    {
        if (Lab1logandpasClass->objectName().isEmpty())
            Lab1logandpasClass->setObjectName(QString::fromUtf8("Lab1logandpasClass"));
        Lab1logandpasClass->resize(600, 400);
        actionClose = new QAction(Lab1logandpasClass);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionAbout = new QAction(Lab1logandpasClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(Lab1logandpasClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        line_login = new QLineEdit(centralWidget);
        line_login->setObjectName(QString::fromUtf8("line_login"));
        line_login->setGeometry(QRect(90, 50, 113, 20));
        line_password = new QLineEdit(centralWidget);
        line_password->setObjectName(QString::fromUtf8("line_password"));
        line_password->setGeometry(QRect(90, 100, 113, 20));
        label_login = new QLabel(centralWidget);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        label_login->setGeometry(QRect(50, 50, 41, 16));
        label_password = new QLabel(centralWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(40, 100, 35, 10));
        pushButton_autorise = new QPushButton(centralWidget);
        pushButton_autorise->setObjectName(QString::fromUtf8("pushButton_autorise"));
        pushButton_autorise->setGeometry(QRect(120, 150, 71, 21));
        QFont font;
        font.setPointSize(16);
        pushButton_autorise->setFont(font);
        pushButton_autorise->setAutoFillBackground(false);
        Lab1logandpasClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Lab1logandpasClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        Lab1logandpasClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab1logandpasClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Lab1logandpasClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lab1logandpasClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Lab1logandpasClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose);
        menuHelp->addAction(actionAbout);

        retranslateUi(Lab1logandpasClass);
        QObject::connect(actionClose, SIGNAL(triggered()), Lab1logandpasClass, SLOT(close()));

        QMetaObject::connectSlotsByName(Lab1logandpasClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lab1logandpasClass)
    {
        Lab1logandpasClass->setWindowTitle(QApplication::translate("Lab1logandpasClass", "Lab1logandpas", nullptr));
        actionClose->setText(QApplication::translate("Lab1logandpasClass", "Close", nullptr));
        actionAbout->setText(QApplication::translate("Lab1logandpasClass", "About", nullptr));
        label_login->setText(QApplication::translate("Lab1logandpasClass", "Login", nullptr));
        label_password->setText(QApplication::translate("Lab1logandpasClass", "Password", nullptr));
        pushButton_autorise->setText(QApplication::translate("Lab1logandpasClass", "LOGIN", nullptr));
        menuFile->setTitle(QApplication::translate("Lab1logandpasClass", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("Lab1logandpasClass", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab1logandpasClass: public Ui_Lab1logandpasClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB1LOGANDPAS_H

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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab1logandpasClass
{
public:
    QAction *actionClose;
    QAction *actionAbout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_login;
    QSpacerItem *horizontalSpacer;
    QLineEdit *line_login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_password;
    QLineEdit *line_password;
    QPushButton *Ftest;
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
        Lab1logandpasClass->resize(497, 356);
        actionClose = new QAction(Lab1logandpasClass);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionAbout = new QAction(Lab1logandpasClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(Lab1logandpasClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_login = new QLabel(centralWidget);
        label_login->setObjectName(QString::fromUtf8("label_login"));

        horizontalLayout->addWidget(label_login);

        horizontalSpacer = new QSpacerItem(17, 5, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        line_login = new QLineEdit(centralWidget);
        line_login->setObjectName(QString::fromUtf8("line_login"));

        horizontalLayout->addWidget(line_login);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_password = new QLabel(centralWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        horizontalLayout_2->addWidget(label_password);

        line_password = new QLineEdit(centralWidget);
        line_password->setObjectName(QString::fromUtf8("line_password"));

        horizontalLayout_2->addWidget(line_password);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        Ftest = new QPushButton(centralWidget);
        Ftest->setObjectName(QString::fromUtf8("Ftest"));

        verticalLayout_2->addWidget(Ftest);

        pushButton_autorise = new QPushButton(centralWidget);
        pushButton_autorise->setObjectName(QString::fromUtf8("pushButton_autorise"));
        QFont font;
        font.setPointSize(16);
        pushButton_autorise->setFont(font);
        pushButton_autorise->setAutoFillBackground(false);

        verticalLayout_2->addWidget(pushButton_autorise);


        verticalLayout_3->addLayout(verticalLayout_2);

        Lab1logandpasClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Lab1logandpasClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 497, 26));
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
        Ftest->setText(QApplication::translate("Lab1logandpasClass", "PushButton", nullptr));
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

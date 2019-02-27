/********************************************************************************
** Form generated from reading UI file 'change.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_H
#define UI_CHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_change
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_blog;
    QLineEdit *line_blogin;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Nlogin;
    QLineEdit *line_Nlogin;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Npassword;
    QLineEdit *line_Npassword;
    QPushButton *pushButton_change;
    QLabel *newwelc;

    void setupUi(QDialog *change)
    {
        if (change->objectName().isEmpty())
            change->setObjectName(QString::fromUtf8("change"));
        change->resize(362, 255);
        layoutWidget = new QWidget(change);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 70, 251, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_blog = new QLabel(layoutWidget);
        label_blog->setObjectName(QString::fromUtf8("label_blog"));

        horizontalLayout_3->addWidget(label_blog);

        line_blogin = new QLineEdit(layoutWidget);
        line_blogin->setObjectName(QString::fromUtf8("line_blogin"));

        horizontalLayout_3->addWidget(line_blogin);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_Nlogin = new QLabel(layoutWidget);
        label_Nlogin->setObjectName(QString::fromUtf8("label_Nlogin"));

        horizontalLayout->addWidget(label_Nlogin);

        line_Nlogin = new QLineEdit(layoutWidget);
        line_Nlogin->setObjectName(QString::fromUtf8("line_Nlogin"));

        horizontalLayout->addWidget(line_Nlogin);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_Npassword = new QLabel(layoutWidget);
        label_Npassword->setObjectName(QString::fromUtf8("label_Npassword"));

        horizontalLayout_2->addWidget(label_Npassword);

        line_Npassword = new QLineEdit(layoutWidget);
        line_Npassword->setObjectName(QString::fromUtf8("line_Npassword"));

        horizontalLayout_2->addWidget(line_Npassword);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton_change = new QPushButton(layoutWidget);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));
        QFont font;
        font.setPointSize(16);
        pushButton_change->setFont(font);
        pushButton_change->setAutoFillBackground(false);

        verticalLayout_2->addWidget(pushButton_change);

        newwelc = new QLabel(change);
        newwelc->setObjectName(QString::fromUtf8("newwelc"));
        newwelc->setGeometry(QRect(130, 30, 131, 21));

        retranslateUi(change);

        QMetaObject::connectSlotsByName(change);
    } // setupUi

    void retranslateUi(QDialog *change)
    {
        change->setWindowTitle(QApplication::translate("change", "change", nullptr));
        label_blog->setText(QApplication::translate("change", "Old login", nullptr));
        label_Nlogin->setText(QApplication::translate("change", "New login", nullptr));
        label_Npassword->setText(QApplication::translate("change", "New password", nullptr));
        pushButton_change->setText(QApplication::translate("change", "Change", nullptr));
        newwelc->setText(QApplication::translate("change", "Enter new login and password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class change: public Ui_change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_H

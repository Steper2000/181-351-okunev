/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add
{
public:
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_comp;
    QLineEdit *lc;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_industry;
    QLineEdit *li;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_date;
    QLineEdit *ld;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_nal;
    QLineEdit *ln;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_sum;
    QLineEdit *ls;
    QPushButton *pushButton_add;
    QGroupBox *groupBox_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_del1;
    QLineEdit *ld1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_del2;
    QLineEdit *ld2;
    QPushButton *pushButton_del;

    void setupUi(QDialog *add)
    {
        if (add->objectName().isEmpty())
            add->setObjectName(QString::fromUtf8("add"));
        add->resize(747, 427);
        horizontalLayout_8 = new QHBoxLayout(add);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        groupBox = new QGroupBox(add);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 40, 301, 241));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_comp = new QLabel(layoutWidget);
        label_comp->setObjectName(QString::fromUtf8("label_comp"));
        label_comp->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(label_comp);

        lc = new QLineEdit(layoutWidget);
        lc->setObjectName(QString::fromUtf8("lc"));

        horizontalLayout->addWidget(lc);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_industry = new QLabel(layoutWidget);
        label_industry->setObjectName(QString::fromUtf8("label_industry"));

        horizontalLayout_2->addWidget(label_industry);

        li = new QLineEdit(layoutWidget);
        li->setObjectName(QString::fromUtf8("li"));

        horizontalLayout_2->addWidget(li);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_date = new QLabel(layoutWidget);
        label_date->setObjectName(QString::fromUtf8("label_date"));

        horizontalLayout_3->addWidget(label_date);

        ld = new QLineEdit(layoutWidget);
        ld->setObjectName(QString::fromUtf8("ld"));

        horizontalLayout_3->addWidget(ld);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_nal = new QLabel(layoutWidget);
        label_nal->setObjectName(QString::fromUtf8("label_nal"));

        horizontalLayout_4->addWidget(label_nal);

        ln = new QLineEdit(layoutWidget);
        ln->setObjectName(QString::fromUtf8("ln"));

        horizontalLayout_4->addWidget(ln);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_sum = new QLabel(layoutWidget);
        label_sum->setObjectName(QString::fromUtf8("label_sum"));

        horizontalLayout_5->addWidget(label_sum);

        ls = new QLineEdit(layoutWidget);
        ls->setObjectName(QString::fromUtf8("ls"));

        horizontalLayout_5->addWidget(ls);


        verticalLayout->addLayout(horizontalLayout_5);

        pushButton_add = new QPushButton(layoutWidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        verticalLayout->addWidget(pushButton_add);


        horizontalLayout_8->addWidget(groupBox);

        groupBox_2 = new QGroupBox(add);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 40, 263, 96));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_del1 = new QLabel(widget);
        label_del1->setObjectName(QString::fromUtf8("label_del1"));

        horizontalLayout_7->addWidget(label_del1);

        ld1 = new QLineEdit(widget);
        ld1->setObjectName(QString::fromUtf8("ld1"));

        horizontalLayout_7->addWidget(ld1);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_del2 = new QLabel(widget);
        label_del2->setObjectName(QString::fromUtf8("label_del2"));

        horizontalLayout_6->addWidget(label_del2);

        ld2 = new QLineEdit(widget);
        ld2->setObjectName(QString::fromUtf8("ld2"));

        horizontalLayout_6->addWidget(ld2);


        verticalLayout_2->addLayout(horizontalLayout_6);

        pushButton_del = new QPushButton(widget);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));

        verticalLayout_2->addWidget(pushButton_del);


        horizontalLayout_8->addWidget(groupBox_2);


        retranslateUi(add);

        QMetaObject::connectSlotsByName(add);
    } // setupUi

    void retranslateUi(QDialog *add)
    {
        add->setWindowTitle(QApplication::translate("add", "add", nullptr));
        groupBox->setTitle(QApplication::translate("add", "Add some data", nullptr));
        label_comp->setText(QApplication::translate("add", "Company", nullptr));
        label_industry->setText(QApplication::translate("add", "Industry", nullptr));
        label_date->setText(QApplication::translate("add", "Date", nullptr));
        label_nal->setText(QApplication::translate("add", "Tax", nullptr));
        label_sum->setText(QApplication::translate("add", "Sum", nullptr));
        pushButton_add->setText(QApplication::translate("add", "Add", nullptr));
        groupBox_2->setTitle(QApplication::translate("add", "Delete", nullptr));
        label_del1->setText(QApplication::translate("add", "row with \342\204\226", nullptr));
        label_del2->setText(QApplication::translate("add", "first row containing:", nullptr));
        pushButton_del->setText(QApplication::translate("add", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add: public Ui_add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H

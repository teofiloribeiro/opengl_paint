/********************************************************************************
** Form generated from reading UI file 'JanelaPrincipal.ui'
**
** Created: Sun 14. Mar 13:05:20 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAPRINCIPAL_H
#define UI_JANELAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>
#include "MeuPainelOpenGL.h"

QT_BEGIN_NAMESPACE

class Ui_JanelaPrincipal
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    MeuPainelOpenGL *painelGL;

    void setupUi(QWidget *JanelaPrincipal)
    {
        if (JanelaPrincipal->objectName().isEmpty())
            JanelaPrincipal->setObjectName(QString::fromUtf8("JanelaPrincipal"));
        JanelaPrincipal->resize(594, 410);
        gridLayout = new QGridLayout(JanelaPrincipal);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(JanelaPrincipal);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        spinBox = new QSpinBox(JanelaPrincipal);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximumSize(QSize(75, 20));
        spinBox->setMinimum(3);
        spinBox->setMaximum(60);

        gridLayout->addWidget(spinBox, 1, 1, 1, 1);

        label_2 = new QLabel(JanelaPrincipal);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(JanelaPrincipal);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximumSize(QSize(75, 20));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(1);
        doubleSpinBox->setMaximum(10);
        doubleSpinBox->setSingleStep(0.1);

        gridLayout->addWidget(doubleSpinBox, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(72, 270, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        pushButton = new QPushButton(JanelaPrincipal);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(75, 23));

        gridLayout->addWidget(pushButton, 5, 1, 1, 1);

        painelGL = new MeuPainelOpenGL(JanelaPrincipal);
        painelGL->setObjectName(QString::fromUtf8("painelGL"));

        gridLayout->addWidget(painelGL, 0, 0, 6, 1);


        retranslateUi(JanelaPrincipal);
        QObject::connect(pushButton, SIGNAL(clicked()), JanelaPrincipal, SLOT(close()));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), painelGL, SLOT(alterarLados(int)));
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), painelGL, SLOT(alterarRaio(double)));

        QMetaObject::connectSlotsByName(JanelaPrincipal);
    } // setupUi

    void retranslateUi(QWidget *JanelaPrincipal)
    {
        JanelaPrincipal->setWindowTitle(QApplication::translate("JanelaPrincipal", "Projeto OpenGL", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("JanelaPrincipal", "Lados:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("JanelaPrincipal", "Raio", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("JanelaPrincipal", "Sair", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class JanelaPrincipal: public Ui_JanelaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAPRINCIPAL_H

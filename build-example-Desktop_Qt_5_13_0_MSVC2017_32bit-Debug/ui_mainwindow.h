/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qslidetext.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QSlideText *_qslidetext;
    QSlideText *_qslidetext_2;
    QSlideText *_qslidetext_3;
    QSlideText *_qslidetext_4;
    QSlideText *_qslidetext_5;
    QSlideText *_qslidetext_6;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(493, 231);
        verticalLayout = new QVBoxLayout(MainWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        _qslidetext = new QSlideText(MainWindow);
        _qslidetext->setObjectName(QString::fromUtf8("_qslidetext"));

        verticalLayout->addWidget(_qslidetext);

        _qslidetext_2 = new QSlideText(MainWindow);
        _qslidetext_2->setObjectName(QString::fromUtf8("_qslidetext_2"));

        verticalLayout->addWidget(_qslidetext_2);

        _qslidetext_3 = new QSlideText(MainWindow);
        _qslidetext_3->setObjectName(QString::fromUtf8("_qslidetext_3"));
        _qslidetext_3->setProperty("textColor", QVariant(QColor(255, 0, 0)));

        verticalLayout->addWidget(_qslidetext_3);

        _qslidetext_4 = new QSlideText(MainWindow);
        _qslidetext_4->setObjectName(QString::fromUtf8("_qslidetext_4"));

        verticalLayout->addWidget(_qslidetext_4);

        _qslidetext_5 = new QSlideText(MainWindow);
        _qslidetext_5->setObjectName(QString::fromUtf8("_qslidetext_5"));

        verticalLayout->addWidget(_qslidetext_5);

        _qslidetext_6 = new QSlideText(MainWindow);
        _qslidetext_6->setObjectName(QString::fromUtf8("_qslidetext_6"));

        verticalLayout->addWidget(_qslidetext_6);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QSlideText Example", nullptr));
        _qslidetext->setProperty("text", QVariant(QCoreApplication::translate("MainWindow", "Still Mode", nullptr)));
        _qslidetext_2->setProperty("text", QVariant(QCoreApplication::translate("MainWindow", "Slide Mode Normal", nullptr)));
        _qslidetext_3->setProperty("text", QVariant(QCoreApplication::translate("MainWindow", "Intermittent Mode Slow", nullptr)));
        _qslidetext_4->setProperty("text", QVariant(QCoreApplication::translate("MainWindow", "Still Algin Right", nullptr)));
        _qslidetext_5->setProperty("text", QVariant(QCoreApplication::translate("MainWindow", "Intermittent Mode Algin Left", nullptr)));
        _qslidetext_6->setProperty("text", QVariant(QCoreApplication::translate("MainWindow", "Very Long Text Message in Slide Mode and Very Fast.", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

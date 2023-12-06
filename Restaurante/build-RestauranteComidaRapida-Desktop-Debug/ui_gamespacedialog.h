/********************************************************************************
** Form generated from reading UI file 'gamespacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESPACEDIALOG_H
#define UI_GAMESPACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GameSpaceDialog
{
public:
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Logout;

    void setupUi(QDialog *GameSpaceDialog)
    {
        if (GameSpaceDialog->objectName().isEmpty())
            GameSpaceDialog->setObjectName(QString::fromUtf8("GameSpaceDialog"));
        GameSpaceDialog->resize(585, 443);
        pushButton_Start = new QPushButton(GameSpaceDialog);
        pushButton_Start->setObjectName(QString::fromUtf8("pushButton_Start"));
        pushButton_Start->setGeometry(QRect(180, 170, 191, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Chandas"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        pushButton_Start->setFont(font);
        pushButton_Logout = new QPushButton(GameSpaceDialog);
        pushButton_Logout->setObjectName(QString::fromUtf8("pushButton_Logout"));
        pushButton_Logout->setGeometry(QRect(420, 380, 111, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Chandas"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_Logout->setFont(font1);

        retranslateUi(GameSpaceDialog);

        QMetaObject::connectSlotsByName(GameSpaceDialog);
    } // setupUi

    void retranslateUi(QDialog *GameSpaceDialog)
    {
        GameSpaceDialog->setWindowTitle(QCoreApplication::translate("GameSpaceDialog", "Dialog", nullptr));
        pushButton_Start->setText(QCoreApplication::translate("GameSpaceDialog", "Start Game!!", nullptr));
        pushButton_Logout->setText(QCoreApplication::translate("GameSpaceDialog", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameSpaceDialog: public Ui_GameSpaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESPACEDIALOG_H

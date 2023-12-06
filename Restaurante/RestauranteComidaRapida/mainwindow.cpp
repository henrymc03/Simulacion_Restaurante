#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QObject>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/img/Images/backlogin.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if((username == "test"&&password =="1234") || (username=="SistemasOP"&& password=="Sistemas.2022")
            || (username=="Josanc"&& password=="jodasami123")|| (username=="Hemore"&& password=="hemoreno2001")
            || (username=="Nubren"&& password=="SistemasOper4tlv02")|| (username=="Admin"&& password=="Admin")){
        QMessageBox::information(this, "Login Successful", QString("Welcome back, %1.").arg(username));
        hide();
        gameDialog = new simulationdialog(this);
        gameDialog->show();

    }else{
        QMessageBox::warning(this, "Login Error", "Username or password isn't correct.");
    }
}


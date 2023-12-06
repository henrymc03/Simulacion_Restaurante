#include "logdialog.h"
#include "ui_logdialog.h"
    //NBRENES
logdialog::logdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logdialog),
    File(new file())
{
    ui->setupUi(this);
    File->setFileName("LogRestaurant.txt");
    ui->txtLogs->setPlainText(" ");
    ui->txtLogs->setPlainText(File->read());
}

logdialog::~logdialog()
{
    delete ui;
}



void logdialog::on_bntSalir_clicked()
{
    this->hide();

}

file* logdialog::getFile(){
    return this->File;
}



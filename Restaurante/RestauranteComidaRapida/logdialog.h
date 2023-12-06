#ifndef LOGDIALOG_H
#define LOGDIALOG_H
    //NBRENES
#include <QDialog>
#include <QAbstractButton>
#include "file.h"
#include <QFileDialog>

namespace Ui {
class logdialog;
}

class logdialog : public QDialog
{
    Q_OBJECT

public:
    explicit logdialog(QWidget *parent = nullptr);
    ~logdialog();
    file* getFile();
private slots:


    void on_bntSalir_clicked();

private:
    Ui::logdialog *ui;
    file *File;
};

#endif // LOGDIALOG_H

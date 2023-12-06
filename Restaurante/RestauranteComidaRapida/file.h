#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
    //NBRENES
class file
{
public:
    file();
    QString getFileName();
    void setFileName(QString);
    bool exists();

    QString read();
    void write(QString);
    void update(QString);
    void copy(QString);
    void remove();
    void closeFile();

private:
    QString fileName = "LogRestaurant.txt";
};

#endif // FILE_H

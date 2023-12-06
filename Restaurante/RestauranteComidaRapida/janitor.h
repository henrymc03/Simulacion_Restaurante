#ifndef JANITOR_H
#define JANITOR_H

#include <QThread>
#include <QMutex>
#include <QList>
#include <QWaitCondition>
#include "table.h"
#include "food.h"
#include "file.h"

class Janitor : public QThread
{
     Q_OBJECT
public:
    Janitor(int x, int y, QMutex *mutex, QList<Table*> *tables,
            QWaitCondition *condJanitor,QObject *parent);

    void setY(int);
    void setX(int);
    int getX();
    int getY();
    QString getPath();
    Table* getTable();

protected:
    void run() override;
private:
    int y, x;
    QMutex *mutex;
    QWaitCondition *condJanitor;
    QList<Table*> *tables;
    QString pathImage;
    file *File;
    Table* tableJanitor;
signals:
    void cleanTable();
    void waitTable();

};

#endif // JANITOR_H

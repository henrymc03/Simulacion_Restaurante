#ifndef CHEF_H
#define CHEF_H

#include <QThread>
#include <QQueue>
#include <QMutex>
#include <QLabel>
#include <QString>
#include <customer.h>
#include <food.h>
#include <QWaitCondition>
#include "file.h"

class Chef : public QThread
{
    Q_OBJECT
public:
    Chef(int x, int y, int numOrder, QMutex *mutex, QQueue<Food*> *colaComida,
         QQueue<Customer*> *colaSinPlato, QQueue<Customer*> *colaConPlato,
         QWaitCondition *condWaiter, QWaitCondition *condChef,QObject *parent = nullptr);
    void setOrder(int);
    void setY(int);
    void setX(int);
    int getX();
    int getY();
    int getOrder();
    QString getPath();

signals:
    //void valorCambiado(int);
protected:
    void run() override;
private:
    QQueue<Food*> *colaComida;
    QQueue<Customer*> *colaSinPlato, *colaConPlato;
    int numOrder, x, y;
    Customer *customer;
    QMutex *mutex;
    QWaitCondition *condWaiter;
    QWaitCondition *condChef;
    QString pathImage;
    QLabel *labelFood;
    file *File;
    QString chefMsg;
};

#endif // CHEF_H

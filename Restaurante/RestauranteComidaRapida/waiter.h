#ifndef WAITER_H
#define WAITER_H

#include <QQueue>
#include <QThread>
#include <QMutex>
#include <QList>
#include <QWaitCondition>
#include <QString>
#include "table.h"
#include "food.h"
#include "customer.h"
#include "file.h"

class Waiter : public QThread
{
    Q_OBJECT
public:
    Waiter(int y, int x, QQueue<Food*> *colaComida, QQueue<Customer*> *colaConPlato,
           QMutex *mutex, QMutex *mutexCust, QList<Table*> *tables, QWaitCondition *condWaiter,
           QWaitCondition *condChef,QWaitCondition *condCustomer,QObject *parent = nullptr);
    void setY(int);
    void setX(int);
    void setFood(Food*);
    int getX();
    int getY();
    Food* getFood();
    QString getPath();
    Table* getTable();
protected:
    void run() override;
private:
    int y, x;
    QQueue<Food*> *colaComida;
    QQueue<Customer*> *colaConPlato;
    Food *food;
    Customer *customer;
    QMutex *mutex;
    QMutex *mutexCust;
    QWaitCondition *condWaiter;
    QWaitCondition *condChef;
    QWaitCondition *condCustomer;
    QList<Table*> *tables;
    QString pathImage;
    file *File;
    Table *tableWaiter;
signals:
    void recogeComida();
    void llevaComida();
    void esperarComida();
};

#endif // WAITER_H

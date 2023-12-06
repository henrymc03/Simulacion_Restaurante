#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <table.h>
#include <food.h>
#include "file.h"

class Customer : public QThread
{
    Q_OBJECT

public:
    Customer(int id, int y, int x,QList<Table*> *tableList,QMutex *mutex,
             QWaitCondition *condJanitor,QWaitCondition *condCustomer,
             QObject *parent = nullptr);
    void setY(int);
    void setX(int);
    void setFood(Food*);
    void setOrder(int);
    void setTable(Table*);
    Table* getTable();
    int getX();
    int getId();
    int getY();
    Food* getFood();
    int getOrder();
    int getDecision();
    QString getPath();
    bool getOutRest();
protected:
    void run() override;
private:
    int y, x, decision, order, sleepTime, id;
    QMutex *mutex;
    QWaitCondition *condJanitor;
    QWaitCondition *condCustomer;
    Food *food;
    Table *table;
    QList<Table*> *tableList;
    QString pathImage;
    file *File;
    bool outRest;
signals:
    //void waitTurn();
    void eatFood();
    void leaveRestaurant();
};

#endif // CUSTOMER_H

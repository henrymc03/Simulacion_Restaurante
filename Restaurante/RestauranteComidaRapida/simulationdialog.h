#ifndef SIMULATIONDIALOG_H
#define SIMULATIONDIALOG_H

#include <QMainWindow>
#include <customer.h>
#include <waiter.h>
#include <chef.h>
#include <food.h>
#include <table.h>
#include <janitor.h>
#include "waiteritem.h"
#include "scenerestaurant.h"
#include "janitoritem.h"
#include "logdialog.h"
#include "graphicsdialog.h"
#include <QQueue>
#include <QMutex>
#include <QList>
#include <QWaitCondition>
#include <QGraphicsScene>

namespace Ui {
class simulationdialog;
}

class Chef;
class Food;
class Waiter;
class Janitor;
class Customer;
class Table;


class simulationdialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit simulationdialog(QWidget *parent = nullptr);


private slots:
    void on_actionStart_triggered();

    void on_actionStop_triggered();

    void on_actionGeneral_Logs_triggered();

    void on_actionGeneral_Stats_triggered();

    void on_actionLogOut_triggered();

    void on_actionExit_triggered();

private:
    Ui::simulationdialog *ui;
    int contOrder = 0;
    QMutex *mutexChef;
    QMutex *mutexWaiter;
    QMutex *mutexCustomer;
    QMutex *mutexCustWait;
    QMutex *mutexJanitor;
    QWaitCondition *condCustomer;
    QWaitCondition *condJanitor;
    QWaitCondition *condChef;
    QWaitCondition *condWaiter;
    QQueue<Food*> *colaComida;
    QQueue<Customer*> *colaConPlato;
    QQueue<Customer*> *colaSinPlato;
    logdialog *log;
    QList<Table*> *tablesList;
    QList<CustomerItem*> *customerList;
    Waiter *waiter;
    Customer *customer;
    Table *table;
    Chef *chef1;
    Chef *chef2;
    Chef *chef3;
    Janitor *janitor;
    SceneRestaurant *mainScene;
    WaiterItem *waiterItem;
    CustomerItem *customerItem;
    TableItem *tableItem;
    JanitorItem *janitorItem;

    graphicsdialog *graphic;
};

#endif // SIMULATIONDIALOG_H

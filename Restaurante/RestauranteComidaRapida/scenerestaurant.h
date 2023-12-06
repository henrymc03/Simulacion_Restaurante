#ifndef SCENERESTAURANT_H
#define SCENERESTAURANT_H

#include <QGraphicsScene>
#include "waiteritem.h"
#include "customeritem.h"
#include "tableitem.h"
#include "janitoritem.h"
#include <QQueue>

class WaiterItem;

class SceneRestaurant : public QGraphicsScene
{
    //Q_OBJECT
public:
    SceneRestaurant(WaiterItem *waiterItem,JanitorItem *janitorItem,QList<Table*> *tables,
                    QList<CustomerItem*> *customerList,QObject *parent = nullptr);
public slots:
    void uptPosWaiterChef();
    void uptPosWaiterLleva();
    void uptPosWaiterWait();
    void uptPosJanitorClean();
    void uptPosJanitorWait();
    void uptPosCustomerWait();
    void uptPosCustomerEat();
    void uptPosCustomerLeave();
private:
    WaiterItem *waiterItem;
    JanitorItem *janitorItem;
    QList<Table*> *tables;
    QList<CustomerItem*> *customerList;
};

#endif // SCENERESTAURANT_H

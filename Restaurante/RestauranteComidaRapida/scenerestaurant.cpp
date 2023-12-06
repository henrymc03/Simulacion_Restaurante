#include "scenerestaurant.h"
#include <QPoint>

#define XPOS 0.0
#define YPOS 0.0
#define WIDHT 1500.0
#define HEIGHT 700.0

SceneRestaurant::SceneRestaurant(WaiterItem *waiterItem,JanitorItem *janitorItem,QList<Table*> *tables,
                                 QList<CustomerItem*> *customerList,QObject *parent)
    : QGraphicsScene(XPOS, YPOS, WIDHT, HEIGHT, parent)
{
    this->waiterItem = waiterItem;
    this->janitorItem = janitorItem;
    this->tables=tables;
    this->customerList=customerList;


    addItem(this->janitorItem);
    addItem(this->waiterItem);
    int y=100;
    for (int i = 0; i < customerList->size() ; ++i) {
        addItem(this->customerList->at(i));
        this->customerList->at(i)->setPos(new QPoint(1400,y+=100));

    }
}

void SceneRestaurant::uptPosWaiterChef(){ // VA HACIA EL CHEF A RECOGER LA COMIDA
    //Setiar posicion

    QPoint *newPos = new QPoint(1400,100);
    this->waiterItem->setPos(newPos);
    update();
}

void SceneRestaurant::uptPosWaiterLleva(){ // LLEVA LA COMIDA A LA MESA
    //Setiar posicion


    QPoint *newPos = new QPoint(this->waiterItem->getWaiter()->getTable()->getX()+15,this->waiterItem->getWaiter()->getTable()->getY()-90);
    this->waiterItem->setPos(newPos);
    update();
}

void SceneRestaurant::uptPosWaiterWait(){ // ESPERA ALGUNA OTRA ORDEN
    //Setiar posicion

    QPoint *newPos = new QPoint(1000,400);
    this->waiterItem->setPos(newPos);
    update();
}

// ---------------------------------------------    JANITOR    --------------------------------------------------------------

void SceneRestaurant::uptPosJanitorWait(){
    //Setear posicion
    QPoint *newPos = new QPoint(1000,120);
    this->janitorItem->setPos(newPos);
    update();
}

void SceneRestaurant::uptPosJanitorClean(){
    //Setear posicion
    QPoint *newPos = new QPoint(this->janitorItem->getJanitor()->getTable()->getX()+15,this->janitorItem->getJanitor()->getTable()->getY()-70);
    this->janitorItem->setPos(newPos);
    update();
}

// ---------------------------------------------    CUSTOMER    --------------------------------------------------------------

 void SceneRestaurant::uptPosCustomerWait(){
    //Setear posicion
/*
    for (int i = 0; i < customerList->size() ; ++i) {



    }
*/

}


 void SceneRestaurant::uptPosCustomerEat(){
     //Setear posicion


     for (int i = 0; i < customerList->size() ; ++i) {
         if(this->customerList->at(i)->getCustomer()->getTable()!=NULL){
             QPoint *newPos = new QPoint(this->customerList->at(i)->getCustomer()->getTable()->getX()+15,
                                         this->customerList->at(i)->getCustomer()->getTable()->getY()-40);

             this->customerList->at(i)->setPos(newPos);


             update();
         }else{
             //qDebug()<<"no tiene mesa";
         }
     }

 }

void SceneRestaurant::uptPosCustomerLeave(){
    //Setear posicion

    for (int i = 0; i < customerList->size() ; ++i) {

        if(this->customerList->at(i)->getCustomer()->getTable()==NULL &&
           this->customerList->at(i)->getCustomer()->getOutRest()==true){

            QPoint *newPos = new QPoint(5000,5000);
            this->customerList->at(i)->setPos(newPos);

            update();
        }
    }
}

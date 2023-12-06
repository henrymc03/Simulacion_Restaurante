#include "customer.h"
#include "food.h"
#include <QRandomGenerator>
#include <QDebug>

Customer::Customer(int id,int y,int x,QList<Table*> *tableList,QMutex *mutex,
                   QWaitCondition *condJanitor,QWaitCondition *condCustomer,
                   QObject *parent)
    : QThread(parent),File(new file())
{
    this->mutex = mutex;
    this->x = x;
    this->y = y;
    this->id = id;
    this->tableList = tableList;

    std::uniform_int_distribution<int> dist(1,2);
    this->decision = dist(*QRandomGenerator::global());
    this->condCustomer = condCustomer;
    this->condJanitor = condJanitor;

    this->food = NULL;
    this->table = NULL;
    this->order = 0;
    this->pathImage = ":/img/Images/customer.png";
    this->outRest = false;
}

void Customer::run()
{

    while(true){
       // msleep(1000);
            if(this->table == NULL){
                this->mutex->lock();
                    //emit waitTurn();

                    this->condJanitor->notify_all();
                    //this->outRest = false;
                    this->condCustomer->wait(this->mutex);
                this->mutex->unlock();
            }else{
                std::uniform_int_distribution<int> slpTime(10000,100000);
                this->sleepTime = slpTime(*QRandomGenerator::global());
                emit eatFood();

                File->write("Cliente "+ QString::number(this->id)  +" esta comiendo");

                this->msleep(this->sleepTime);

                this->mutex->lock();
                for (int i = 0; i < this->tableList->size(); ++i) {
                    if(this->tableList->at(i) == this->table){
                        File->write("Cliente "+ QString::number(this->id) +" termino de comer ");
                        this->tableList->at(i)->setConCliente(false);
                        this->outRest = true;
                                    msleep(1000);
                                    emit leaveRestaurant();

                    }

                    this->condJanitor->notify_all();
                }

                File->write("Cliente "+ QString::number(this->id) +" sale del restaurante");
                this->condJanitor->notify_all();
                this->table = NULL;



                this->mutex->unlock();
            }

        }

}

int Customer::getX(){
    return this->x;
}

int Customer::getId(){
    return this->id;
}

int Customer::getY(){
    return this->y;
}

int Customer::getOrder(){
    return this->order;
}

Food* Customer::getFood(){
    return this->food;
}

bool Customer::getOutRest(){
    return this->outRest;
}

int Customer::getDecision(){
    return this->decision;
}

Table* Customer::getTable(){
    return this->table;
}

QString Customer::getPath(){
    return this->pathImage;
}

void Customer::setTable(Table *table){
    this->table = table;
}

void Customer::setX(int x){
    this->x = x;
}

void Customer::setY(int y){
    this->x = y;
}

void Customer::setFood(Food *food){
    this->food = food;
}

void Customer::setOrder(int order){
    this->order = order;
}

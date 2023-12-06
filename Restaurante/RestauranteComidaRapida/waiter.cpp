#include "waiter.h"
#include <QDebug>

#include "globalvalue.h"
Waiter::Waiter(int y, int x, QQueue<Food*> *colaComida, QQueue<Customer*> *colaConPlato,
               QMutex *mutex,QMutex *mutexCust, QList<Table*> *tables, QWaitCondition *condWaiter,
               QWaitCondition *condChef,QWaitCondition *condCustomer,QObject *parent)
    : QThread(parent),File(new file())
{
    this->x = x;
    this->y = y;
    this->mutex = mutex;
    this->mutexCust = mutexCust;
    this->condChef = condChef;
    this->condWaiter = condWaiter;
    this->condCustomer = condCustomer;
    this->colaComida = colaComida;
    this->colaConPlato = colaConPlato;
    this->tables = tables;
    this->pathImage = ":/img/Images/waiter1.png";
}

void Waiter::run()
{
    bool flag = true;
    while(true){
        msleep(1000);
        if(!colaComida->isEmpty()){
            mutex->lock();

            this->food = colaComida->dequeue();
            File->write("Mesero recoge platillo de la cola de platillos");
            emit recogeComida();
            msleep(1000);
            this->condChef->wakeAll();

            globalValue::instance()->setColaComida(colaComida->size());

            if(!colaConPlato->isEmpty()){

                this->customer = colaConPlato->dequeue();
                File->write("Mesero atiende al cliente "+QString::number(this->customer->getId()));
                globalValue::instance()->setPlatosServidos(colaConPlato->size());

                for (int i = 0; i < tables->size(); ++i) {
                    if(flag == true){
                        if(tables->at(i)->getConPlato() == false &&
                            tables->at(i)->getConCliente() == false){
                            this->mutexCust->lock();

                            File->write("Mesero sirve al cliente en la mesa " + QString::number(tables->at(i)->getId()));

                            this->tableWaiter=tables->at(i);
                            this->customer->setFood(this->food);

                            tables->at(i)->setConPlato(true);
                            tables->at(i)->setConCliente(true);

                            this->customer->setTable(tables->at(i));

                            this->condCustomer->wakeAll();
                            flag = false;
                            emit llevaComida();
                            msleep(1000);
                            this->mutexCust->unlock();

                        }
                    }
                }
                flag = true;
            }else{
                emit esperarComida();
                msleep(1000);

                File->write("El mesero espera a que el chef sirva los platillos");
                this->condWaiter->wait(mutex);
            }
            this->condCustomer->wakeAll();
            mutex->unlock();
        }else{
            mutex->lock();
                File->write("Mesero termino de atender todos los clientes");

                emit esperarComida();
                this->condChef->wakeAll();
                this->condCustomer->wakeAll();
                this->condWaiter->wait(mutex);
            mutex->unlock();
        }
    }
}

int Waiter::getX(){
    return this->x;
}

int Waiter::getY(){
    return this->y;
}

Food* Waiter::getFood(){
    return this->food;
}

void Waiter::setX(int x){
    this->x = x;
}

void Waiter::setY(int y){
    this->x = y;
}

QString Waiter::getPath(){
    return this->pathImage;
}

Table *Waiter::getTable()
{
    return this->tableWaiter;
}


void Waiter::setFood(Food *food){
    this->food = food;
}

#include "chef.h"
#include <QDebug>
#include <QPixmap>
#include "globalvalue.h"

Chef::Chef(int x, int y, int numOrder, QMutex *mutex, QQueue<Food*> *colaComida,
           QQueue<Customer*> *colaSinPlato, QQueue<Customer*> *colaConPlato,
           QWaitCondition *condWaiter, QWaitCondition *condChef,QObject *parent)
    : QThread(parent),File(new file())
{
    this->numOrder = numOrder;
    this->x = x;
    this->y = y;
    this->colaComida = colaComida;
    this->colaConPlato = colaConPlato;
    this->colaSinPlato = colaSinPlato;
    this->customer = NULL;
    this->mutex = mutex;
    this->condChef = condChef;
    this->condWaiter = condWaiter;
    this->pathImage = ":/img/Images/chef2.png";

}

void Chef::run()
{
    while(true){

        if(!colaSinPlato->isEmpty()){

            globalValue::instance()->setPlatosNoServidos(colaSinPlato->size());

            if (colaComida->size() < 10 || colaComida->isEmpty()){
                this->mutex->lock();

                    this->customer = this->colaSinPlato->dequeue();
                    File->write("Cocinero atiende al cliente"+QString::number(this->customer->getId()));

                this->mutex->unlock();

                if (this->customer->getDecision() == 1){
                    this->mutex->lock();
                    this->labelFood = new QLabel();
                    QPixmap pixFood(":/img/Images/food3.png");
                    this->labelFood->setGeometry(this->x,this->y+100,100,100);
                    this->labelFood->setPixmap(pixFood);
                    Food *food = new Food(this->x,this->y,this->numOrder,":/img/Images/food6.png",this->labelFood);

                    File->write("Cocinero inserta un platillo de carne a la cola de comidas.");

                    colaComida->enqueue(food);

                    File->write("Cocinero entrega la orden "+QString::number(this->numOrder));
                    this->customer->setOrder(this->numOrder);
                    this->mutex->unlock();
                }else{
                    this->mutex->lock();
                    this->labelFood = new QLabel();
                    QPixmap pixFood(":/img/Images/food3.png");
                    this->labelFood->setGeometry(this->x,this->y+100,100,100);
                    this->labelFood->setPixmap(pixFood);
                    Food *food = new Food(this->x,this->y,this->numOrder,":/img/Images/food3.png",this->labelFood);

                    File->write("Cocinero inserta un platillo de ensalada a la cola de comidas.");
                    colaComida->enqueue(food);

                    File->write("Cocinero entrega la orden "+QString::number(this->numOrder));
                    this->customer->setOrder(this->numOrder);
                    this->mutex->unlock();
                }
                this->mutex->lock();
                File->write("Cliente esta en la cola de espera.");
                this->colaConPlato->enqueue(this->customer);
                this->numOrder++;

                this->condWaiter->wakeAll();
                this->mutex->unlock();


            }else{
                this->mutex->lock();
                    File->write("Cola de comidas llena.");
                    this->condWaiter->wakeAll();
                    this->condChef->wait(mutex);
                this->mutex->unlock();
            }
        }else{
            this->mutex->lock();
                File->write("Se han atendido todos los clientes atendidos.");
                this->condWaiter->wakeAll();
                this->condChef->wait(mutex);
            this->mutex->unlock();
        }
    }
}


int Chef::getX(){
    return this->x;
}

int Chef::getY(){
    return this->y;
}

void Chef::setX(int x){
    this->x = x;
}

void Chef::setY(int y){
    this->x = y;
}

QString Chef::getPath(){
    return this->pathImage;
}

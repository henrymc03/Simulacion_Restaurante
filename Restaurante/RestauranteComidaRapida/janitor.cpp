#include "janitor.h"

#include <QDebug>

Janitor::Janitor(int x, int y, QMutex *mutex, QList<Table*> *tables,
                 QWaitCondition *condJanitor,QObject *parent)
    : QThread(parent),File(new file())
{
    this->x = x;
    this->y = y;
    this->tables = tables;
    this->mutex = mutex;
    this->condJanitor = condJanitor;
    this->pathImage = ":/img/Images/janitor2.png";

}

void Janitor::run()
{
    while(true){
        this->msleep(1000);
        for (int i = 0; i < tables->size(); ++i) {

            if(tables->at(i)->getConPlato() == true &&
               tables->at(i)->getConCliente() == false){
                mutex->lock();
                    this->tableJanitor = this->tables->at(i);
                    emit cleanTable();
                    msleep(1000);
                    File->write("Conserje limpia la mesa "+QString::number(tables->at(i)->getId()));
                    tables->at(i)->setConPlato(false);
                mutex->unlock();
            }else{
                mutex->lock();
                emit waitTable();
                msleep(1000);
                File->write("Conserje ha limpiado todas las mesas");
                this->condJanitor->wait(mutex);
                mutex->unlock();
            }
        }

    }
}


int Janitor::getX(){
    return this->x;
}

int Janitor::getY(){
    return this->y;
}

QString Janitor::getPath(){
    return this->pathImage;
}

Table *Janitor::getTable()
{
    return this->tableJanitor;
}

void Janitor::setX(int x){
    this->x = x;
}

void Janitor::setY(int y){
    this->x = y;
}

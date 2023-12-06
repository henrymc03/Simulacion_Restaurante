#include "table.h"

Table::Table(int id, int y, int x, bool conCliente,
             bool conPlato,QObject *parent)
    : QObject{parent}
{
    this->id = id;
    this->y = y;
    this->x = x;
    this->conCliente = conCliente;
    this->conPlato = conPlato;
    this->imageTable = new QPixmap(":/img/Images/table.png");
    this->pathImage = ":/img/Images/table.png";
}

int Table::getX(){
    return this->x;
}

int Table::getY(){
    return this->y;
}

int Table::getId(){
    return this->id;
}

QString Table::getPath(){
    return this->pathImage;
}


QPixmap* Table::getImage(){
    return this->imageTable;
}

bool Table::getConCliente(){
    return this->conCliente;
}

bool Table::getConPlato(){
    return this->conPlato;
}

void Table::setConPlato(bool conPlato){
    this->conPlato = conPlato;
}

void Table::setConCliente(bool conCliente){
    this->conCliente = conCliente;
}

void Table::setId(int id){
    this->id = id;
}

void Table::setX(int x){
    this->x = x;
}

void Table::setY(int y){
    this->x = y;
}

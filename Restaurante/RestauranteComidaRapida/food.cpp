#include "food.h"

Food::Food(int y, int x, int order, QString path, QLabel *labelFood)
{
    this->x = x;
    this->y = y;
    this->order = order;
    this->path = path;
    this->labelFood = labelFood;
}

int Food::getX(){
    return this->x;
}

int Food::getY(){
    return this->y;
}

QString Food::getPath(){
    return this->path;
}

QLabel* Food::getLabel(){
    return this->labelFood;
}

void Food::setLabel(QLabel *labelFood){
    this->labelFood = labelFood;
}

void Food::setX(int x){
    this->x = x;
}

void Food::setY(int y){
    this->x = y;
}

void Food::setPath(QString path){
    this->path = path;
}

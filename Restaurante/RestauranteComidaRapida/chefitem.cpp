#include "chefitem.h"

#include <QPainter>

chefitem::chefitem(Chef *chef, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    this->chef = chef;
    this->posChef = new QPoint(900,50);
    this->velChef = new QPoint(1,1);
    this->sizeChef = new QSize(72,72);
}

QRectF chefitem::boundingRect() const{
    return QRectF(posChef->x(),posChef->y(),sizeChef->width(),sizeChef->height());
}

void chefitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawPixmap(posChef->x(),posChef->y(),sizeChef->width(),
                        sizeChef->height(),QPixmap(this->chef->getPath()));

}

void chefitem::setPos(QPoint *posChef){
    this->posChef = posChef;
}
QPoint* chefitem::getPos(){
    return this->posChef;
}

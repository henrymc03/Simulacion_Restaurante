#include "janitoritem.h"

#include <QPainter>

JanitorItem::JanitorItem(Janitor *janitor, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    this->janitor = janitor;
    this->posJanitor = new QPoint(1000,80);
    this->velJanitor = new QPoint(1,1);
    this->sizeJanitor = new QSize(72,72);
}

QRectF JanitorItem::boundingRect() const{
    return QRectF(posJanitor->x(),posJanitor->y(),sizeJanitor->width(),sizeJanitor->height());
}

void JanitorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawPixmap(posJanitor->x(),posJanitor->y(),sizeJanitor->width(),
                        sizeJanitor->height(),QPixmap(this->janitor->getPath()));

}

void JanitorItem::setPos(QPoint *posJanitor){
    this->posJanitor = posJanitor;
}

QPoint* JanitorItem::getPos(){
    return this->posJanitor;
}

Janitor *JanitorItem::getJanitor()
{
    return this->janitor;
}

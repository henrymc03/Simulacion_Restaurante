#include "waiteritem.h"

#include <QPainter>

WaiterItem::WaiterItem(Waiter *waiter, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    this->waiter = waiter;
    this->posWaiter = new QPoint(900,80);
    this->velWaiter = new QPoint(1,1);
    this->sizeWaiter = new QSize(72,72);
}

QRectF WaiterItem::boundingRect() const{
    return QRectF(posWaiter->x(),posWaiter->y(),sizeWaiter->width(),sizeWaiter->height());
}

void WaiterItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawPixmap(posWaiter->x(),posWaiter->y(),sizeWaiter->width(),
                        sizeWaiter->height(),QPixmap(this->waiter->getPath()));

}

void WaiterItem::setPos(QPoint *posWaiter){
    this->posWaiter = posWaiter;
}

QPoint* WaiterItem::getPos(){
    return this->posWaiter;
}

Waiter *WaiterItem::getWaiter()
{
    return waiter;
}

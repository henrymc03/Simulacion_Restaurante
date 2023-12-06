#include "customeritem.h"

#include <QPainter>

CustomerItem::CustomerItem(Customer *customer,QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    this->customer = customer;
    this->posCustomer = new QPoint(1350,200);
    this->velCustomer = new QPoint(1,1);
    this->sizeCustomer = new QSize(72,72);
}

QRectF CustomerItem::boundingRect() const{
    return QRectF(posCustomer->x(),posCustomer->y(),sizeCustomer->width(),sizeCustomer->height());
}

void CustomerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawPixmap(posCustomer->x(),posCustomer->y(),sizeCustomer->width(),
                        sizeCustomer->height(),QPixmap(":/img/Images/customer.png"));
}

void CustomerItem::setPos(QPoint *posCustomer){
    this->posCustomer = posCustomer;
}

QPoint* CustomerItem::getPos(){
    return this->posCustomer;
}

Customer* CustomerItem::getCustomer()
{
    return this->customer;
}

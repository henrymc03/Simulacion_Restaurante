#ifndef CUSTOMERITEM_H
#define CUSTOMERITEM_H

#include <QGraphicsItem>
#include <QPoint>
#include <QSize>
#include <QQueue>
#include "customer.h"

class CustomerItem : public QGraphicsItem
{
public:
    CustomerItem(Customer *customer, QGraphicsItem *parent = nullptr);

    void setPos(QPoint *posCustomer);
    QPoint* getPos();
    Customer* getCustomer();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

private:
    Customer *customer;
    QPoint *posCustomer;
    QPoint *velCustomer;
    QSize *sizeCustomer;
};

#endif // CUSTOMERITEM_H

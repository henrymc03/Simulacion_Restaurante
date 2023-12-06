#ifndef WAITERITEM_H
#define WAITERITEM_H

#include <QGraphicsItem>
#include <QPoint>
#include <QSize>
#include "waiter.h"

class WaiterItem : public QGraphicsItem
{
public:
    WaiterItem(Waiter *waiter, QGraphicsItem *parent = nullptr);
    void setPos(QPoint *posWaiter);
    QPoint* getPos();
    Waiter* getWaiter();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

private:
    Waiter *waiter;
    QPoint *posWaiter;
    QPoint *velWaiter;
    QSize *sizeWaiter;
};

#endif // WAITERITEM_H

#ifndef CHEFITEM_H
#define CHEFITEM_H

#include <QGraphicsItem>
#include <QPoint>
#include <QSize>
#include "chef.h"

class chefitem : public QGraphicsItem
{
public:
    chefitem(Chef *chef, QGraphicsItem *parent = nullptr);
    void setPos(QPoint *posChef);
    QPoint* getPos();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

private:
    Chef *chef;
    QPoint *posChef;
    QPoint *velChef;
    QSize *sizeChef;
};

#endif // CHEFITEM_H

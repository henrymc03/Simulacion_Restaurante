#ifndef JANITORITEM_H
#define JANITORITEM_H

#include <QGraphicsItem>
#include <QPoint>
#include <QSizeF>
#include "janitor.h"

class JanitorItem : public QGraphicsItem
{
public:
    JanitorItem(Janitor *janitor, QGraphicsItem *parent = nullptr);
    void setPos(QPoint *posWaiter);
    QPoint* getPos();
    Janitor* getJanitor();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
private:
    Janitor *janitor;
    QPoint *posJanitor;
    QPoint *velJanitor;
    QSize *sizeJanitor;

};
#endif // JANITORITEM_H

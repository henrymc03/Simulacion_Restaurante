#ifndef TABLEITEM_H
#define TABLEITEM_H

#include <QGraphicsItem>
#include <QPoint>
#include <QSize>
#include "table.h"

class TableItem : QGraphicsItem
{
public:
    TableItem(Table *table, QGraphicsItem *parent = nullptr);
    QPoint* getPos();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

private:
    Table *table;
    QPoint *posTable;
    QSize *sizeTable;
};

#endif // TABLEITEM_H

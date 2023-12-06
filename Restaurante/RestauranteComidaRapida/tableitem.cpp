#include "tableitem.h"

#include <QPainter>

TableItem::TableItem(Table *table, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    this->table = table;

    this->posTable= new QPoint(80,60);
    this->sizeTable = new QSize(72,72);

}

QRectF TableItem::boundingRect() const{
    return QRectF(this->posTable->x(),this->posTable->y(),this->sizeTable ->width(),this->sizeTable ->height());
}

void TableItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawPixmap(this->posTable->x(),this->posTable->y(),this->sizeTable ->width(),
                        this->sizeTable ->height(),QPixmap(this->table->getPath()));

}

QPoint* TableItem::getPos(){
    return this->posTable;
}

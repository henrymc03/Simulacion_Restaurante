#ifndef FOOD_H
#define FOOD_H

#include <QString>
#include <QLabel>

class Food
{
public:
    Food(int y, int x, int order, QString path, QLabel *labelFood);
    void setY(int);
    void setX(int);
    void setPath(QString);
    void setLabel(QLabel*);
    int getX();
    int getY();
    QString getPath();
    QLabel* getLabel();
private:
    int y, x, order;
    QString path;
    QLabel *labelFood;
};


#endif // FOOD_H

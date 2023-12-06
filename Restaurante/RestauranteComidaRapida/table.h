#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QPixmap>
#include <QString>

class Table : public QObject
{
    Q_OBJECT
public:
    explicit Table(int id, int y, int x, bool conCliente,
                   bool conPlato, QObject *parent = nullptr);
     void setY(int);
     void setX(int);
     void setId(int);
     void setConCliente(bool);
     void setConPlato(bool);
     int getX();
     int getId();
     int getY();
     QPixmap* getImage();
     QString getPath();
     bool getConPlato();
     bool getConCliente();
private:
     int id;
     int y;
     int x;
     QPixmap *imageTable;
     QString pathImage;
     bool conCliente;
     bool conPlato;

signals:

};

#endif // TABLE_H

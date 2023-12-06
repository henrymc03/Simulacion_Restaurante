#ifndef GLOBALVALUE_H
#define GLOBALVALUE_H

    //NBRENES
class globalValue
{
private:
    globalValue();
     int  colaComida;
     int platosServidos;
     int platosNoServidos;

public:
    static globalValue * instance();
    int getColaComida();
    void setColaComida(int value);
    int getPlatosServidos();
    void setPlatosServidos(int value);
    int getPlatosNoServidos();
    void setPlatosNoServidos(int value);

};

#endif // GLOBALVALUE_H

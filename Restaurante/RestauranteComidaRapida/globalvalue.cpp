#include "globalvalue.h"

globalValue *p_instance  = 0;

    //NBRENES
globalValue::globalValue()
{
}

globalValue *globalValue::instance(){
    if(!p_instance) p_instance = new globalValue();
    return p_instance;
}

int globalValue::getColaComida(){
    return colaComida;
}

void globalValue::setColaComida(int value){
    colaComida = value;
}

int globalValue::getPlatosServidos(){
    return platosServidos;
}

void globalValue::setPlatosServidos(int value){
    platosServidos = value;
}

int globalValue::getPlatosNoServidos(){
    return platosNoServidos;
}

void globalValue::setPlatosNoServidos(int value){
    platosNoServidos = value;
}

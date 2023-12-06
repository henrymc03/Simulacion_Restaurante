#include "file.h"
#include <QDebug>
  //NBRENES
file::file()
{

}
void file::setFileName(QString fileName){
    this->fileName = fileName;
}
QString file:: getFileName(){
    return this->fileName;
}

bool file::exists(){
    QFile file(this->fileName);
    return file.exists();
}
QString file::read(){
    QFile file(this->fileName);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){//lee el contenido del archivo      
        QTextStream data(&file);        
        return data.readAll();
    }
    return "";
}
void file::closeFile(){
    QFile file(this->fileName);
    file.close();
}
void file::write(QString text){
    QFile file(this->fileName);
    file.open(QIODevice::ReadWrite | QIODevice::Text);//crea el archivo para escribir contenido
    QString data = read() + "\n" + text;
    file.write(data.toUtf8());
    file.close();
}

void file::remove(){
    QFile file(this->fileName);
    file.remove();
}

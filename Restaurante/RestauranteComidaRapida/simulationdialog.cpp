#include "simulationdialog.h"
#include "ui_simulationdialog.h"
#include "waiter.h"
#include "scenerestaurant.h"

#include <QDebug>
#include <QPixmap>
#include <QPalette>
#include <QLabel>

simulationdialog::simulationdialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::simulationdialog),mutexChef(new QMutex()),mutexWaiter(new QMutex()),
    mutexCustomer(new QMutex()),mutexCustWait(new QMutex()),mutexJanitor(new QMutex()),
    condCustomer(new QWaitCondition()),condJanitor(new QWaitCondition()),
    condChef(new QWaitCondition()),condWaiter(new QWaitCondition()),
    colaComida(new QQueue<Food*>),colaConPlato(new QQueue<Customer*>),
    colaSinPlato(new QQueue<Customer*>),tablesList(new QList<Table*>),customerList(new QList<CustomerItem*>),
    waiter(new Waiter(80,900,colaComida,colaConPlato,mutexWaiter,mutexCustWait,tablesList,condWaiter,condChef,condCustomer,this)),
    chef1(new Chef(1250,80,contOrder,mutexChef,colaComida,colaSinPlato,colaConPlato,condWaiter,condChef,this)),
    chef2(new Chef(1350,80,contOrder,mutexChef,colaComida,colaSinPlato,colaConPlato,condWaiter,condChef,this)),
    chef3(new Chef(1450,80,contOrder,mutexChef,colaComida,colaSinPlato,colaConPlato,condWaiter,condChef,this)),
    janitor(new Janitor(1000,80,mutexJanitor,this->tablesList,condJanitor,this))
{
    ui->setupUi(this);

    //Set background of scene
    QPixmap bkgnd(":/img/Images/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    layout()->setMargin(0);

    //Set chefs
    QLabel *labelChef1 = new QLabel(this);
    QPixmap pixChef(this->chef1->getPath());
    labelChef1->setGeometry(this->chef1->getX(),this->chef1->getY(),100,100);
    labelChef1->setPixmap(pixChef);

    QLabel *labelChef2 = new QLabel(this);
    QPixmap pixChef2(":/img/Images/chef3.png");
    labelChef2->setGeometry(this->chef2->getX(),this->chef2->getY(),100,100);
    labelChef2->setPixmap(pixChef2);

    QLabel *labelChef3 = new QLabel(this);
    QPixmap pixChef3(":/img/Images/chef4.png");
    labelChef3->setGeometry(this->chef3->getX(),this->chef3->getY(),100,100);
    labelChef3->setPixmap(pixChef3);





    //Set tables of scene
    int ejex = 60;
    int ejey = 80;
    for(int i=1;i<=30 ; i++){
        this->table = new Table(i,ejey,ejex,false,false,this);
        QLabel *label = new QLabel(this);
        QPixmap pix(this->table->getPath());
        label->setGeometry(ejex,ejey,100,100);
        label->setPixmap(pix);
        this->tablesList->append(table);
        this->tableItem = new TableItem(this->table);
        ejey += 115;
        if(i==6 || i==12 || i==18 || i ==24){
            ejey = 80;
            ejex += 150;
        }
    }

    for (int i=1;i<=50 ; i++) {
        this->customer = new Customer(i,100,1350,tablesList,mutexCustomer,condJanitor,condCustomer,this);

        this->customerItem = new CustomerItem(this->customer);
        colaSinPlato->enqueue(this->customer);

        this->customerList->append(customerItem);

        //customer->start();

    }

    this->waiterItem = new WaiterItem(this->waiter);
    this->janitorItem = new JanitorItem(this->janitor);
    this->mainScene = new SceneRestaurant(this->waiterItem,this->janitorItem,this->tablesList,this->customerList,this);
    ui->graphicsView->setScene(this->mainScene);

    for (int i = 0; i < customerList->size() ; ++i) {

        connect(this->customerList->at(i)->getCustomer(),&Customer::eatFood,this->mainScene,&SceneRestaurant::uptPosCustomerEat);

        //connect(this->customerList->at(i)->getCustomer(),&Customer::waitTurn,this->mainScene,&SceneRestaurant::uptPosCustomerWait(CustomerItem*));

        connect(this->customerList->at(i)->getCustomer(),&Customer::leaveRestaurant,this->mainScene,&SceneRestaurant::uptPosCustomerLeave);

    }

    connect(this->waiter,&Waiter::llevaComida,this->mainScene,&SceneRestaurant::uptPosWaiterLleva);
    connect(this->waiter,&Waiter::esperarComida,this->mainScene,&SceneRestaurant::uptPosWaiterWait);
    connect(this->waiter,&Waiter::recogeComida,this->mainScene,&SceneRestaurant::uptPosWaiterChef);

    connect(this->janitor,&Janitor::waitTable,this->mainScene,&SceneRestaurant::uptPosJanitorWait);
    connect(this->janitor,&Janitor::cleanTable,this->mainScene,&SceneRestaurant::uptPosJanitorClean);

    for (int i = 0; i < customerList->size() ; ++i) {

        this->customerList->at(i)->getCustomer()->start();
    }

    chef1->start();
    chef2->start();
    chef3->start();
    waiter->start();
    janitor->start();

}

void simulationdialog::on_actionStart_triggered()
{
    //Set tables of scene
    int ejex = 60;
    int ejey = 80;
    for(int i=1;i<=30 ; i++){
        this->table = new Table(i,ejey,ejex,false,false,this);
        QLabel *label = new QLabel(this);
        QPixmap pix(this->table->getPath());
        label->setGeometry(ejex,ejey,100,100);
        label->setPixmap(pix);
        this->tablesList->append(table);
        this->tableItem = new TableItem(this->table);
        ejey += 115;
        if(i==6 || i==12 || i==18 || i ==24){
            ejey = 80;
            ejex += 150;
        }
    }

    for (int i=1;i<=50 ; i++) {
        this->customer = new Customer(i,100,1350,tablesList,mutexCustomer,condJanitor,condCustomer,this);

        this->customerItem = new CustomerItem(this->customer);
        colaSinPlato->enqueue(this->customer);

        this->customerList->append(customerItem);

        //customer->start();

    }

    this->waiterItem = new WaiterItem(this->waiter);
    this->janitorItem = new JanitorItem(this->janitor);
    this->mainScene = new SceneRestaurant(this->waiterItem,this->janitorItem,this->tablesList,this->customerList,this);
    ui->graphicsView->setScene(this->mainScene);

    for (int i = 0; i < customerList->size() ; ++i) {

        connect(this->customerList->at(i)->getCustomer(),&Customer::eatFood,this->mainScene,&SceneRestaurant::uptPosCustomerEat);

        //connect(this->customerList->at(i)->getCustomer(),&Customer::waitTurn,this->mainScene,&SceneRestaurant::uptPosCustomerWait(CustomerItem*));

        connect(this->customerList->at(i)->getCustomer(),&Customer::leaveRestaurant,this->mainScene,&SceneRestaurant::uptPosCustomerLeave);

    }

    connect(this->waiter,&Waiter::llevaComida,this->mainScene,&SceneRestaurant::uptPosWaiterLleva);
    connect(this->waiter,&Waiter::esperarComida,this->mainScene,&SceneRestaurant::uptPosWaiterWait);
    connect(this->waiter,&Waiter::recogeComida,this->mainScene,&SceneRestaurant::uptPosWaiterChef);

    connect(this->janitor,&Janitor::waitTable,this->mainScene,&SceneRestaurant::uptPosJanitorWait);
    connect(this->janitor,&Janitor::cleanTable,this->mainScene,&SceneRestaurant::uptPosJanitorClean);

    for (int i = 0; i < customerList->size() ; ++i) {

        this->customerList->at(i)->getCustomer()->start();
    }

    chef1->start();
    chef2->start();
    chef3->start();
    waiter->start();
    janitor->start();
}


void simulationdialog::on_actionStop_triggered()
{
    /*
    colaSinPlato->clear();
    colaComida->clear();
    colaConPlato->clear();
    tablesList->clear();

    customer->quit();
    customer->wait(1000);

    chef1->quit();
    chef1->wait(1000);
    chef2->quit();
    chef2->wait(1000);
    chef3->quit();
    chef3->wait(1000);
    waiter->quit();
    waiter->wait(1000);
    janitor->quit();
    janitor->wait(1000);
    */
}


void simulationdialog::on_actionGeneral_Logs_triggered()
{
    this->log = new logdialog();
    log->show();
}


void simulationdialog::on_actionGeneral_Stats_triggered()
{
    this->graphic = new graphicsdialog();
    graphic->show();
}


void simulationdialog::on_actionLogOut_triggered()
{

}


void simulationdialog::on_actionExit_triggered()
{
    QApplication::quit();
}


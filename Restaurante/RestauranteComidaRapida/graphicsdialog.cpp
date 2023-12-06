#include "graphicsdialog.h"
#include "ui_graphicsdialog.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <globalvalue.h>

QT_USE_NAMESPACE
    //NBRENES
graphicsdialog::graphicsdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graphicsdialog)
{

    ui->setupUi(this);
      generarGrafico();
}

graphicsdialog::~graphicsdialog()
{
    delete ui;
}

void graphicsdialog::generarGrafico(){
    this->set0 = new QtCharts::QBarSet("Cola Comida");
    this->set1 = new QtCharts::QBarSet("Cola sin Plato");
    this->set2 = new QtCharts::QBarSet("Cola con Plato");

    this->set0->append(globalValue::instance()->getColaComida());
    this->set1->append(globalValue::instance()->getPlatosNoServidos());
    this->set2->append(globalValue::instance()->getPlatosServidos());

    /*this->set0->append(1);
    this->set1->append(5);
    this->set2->append(3);*/

    this->series = new QtCharts::QBarSeries();
    this->series->append(this->set0);
    this->series->append(this->set1);
    this->series->append(this->set2);

    this->chart = new QtCharts::QChart();
    this->chart->addSeries(this->series);
    this->chart->setTitle("Colas de trabajo");
    this->chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);

    this->categorias.operator<<("Colas");
    this->axisX= new QtCharts::QBarCategoryAxis();
    this->axisX->append(this->categorias);
    this->chart->addAxis(this->axisX, Qt::AlignBottom);
    this->series->attachAxis(this->axisX);

    this->axisY = new QtCharts::QValueAxis();
    this->axisY->setRange(0,20);
    this->chart->addAxis(this->axisY, Qt::AlignLeft);
    this->series->attachAxis(this->axisY);

    this->chart->legend()->setVisible(true);
    this->chart->legend()->setAlignment(Qt::AlignBottom);

    this->chartView = new QtCharts::QChartView(this->chart);
    this->chartView->setRenderHint(QPainter::Antialiasing);

    this->chartView->setParent(ui->horizontalFrame);

}

void graphicsdialog::on_btnRegresar_clicked()
{
    this->hide();

}


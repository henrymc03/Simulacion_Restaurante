#ifndef GRAPHICSDIALOG_H
#define GRAPHICSDIALOG_H
    //NBRENES
#include <QDialog>
#include <QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QMainWindow>

namespace Ui {
class graphicsdialog;
}

class graphicsdialog : public QDialog
{
    Q_OBJECT

public:
    explicit graphicsdialog(QWidget *parent = nullptr);
    ~graphicsdialog();

    void generarGrafico();

private slots:
    void on_btnRegresar_clicked();

private:
    Ui::graphicsdialog *ui;
    QtCharts::QBarSet *set0;
    QtCharts::QBarSet *set1;
    QtCharts::QBarSet *set2;

    QtCharts::QBarSeries *series;
    QtCharts::QChart *chart;
    QStringList categorias;

    QtCharts::QBarCategoryAxis *axisX;
    QtCharts::QValueAxis *axisY;

    QtCharts::QChartView *chartView;

};

#endif // GRAPHICSDIALOG_H

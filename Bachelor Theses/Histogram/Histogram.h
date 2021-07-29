//
// Created by paula on 6/21/2021.
//

#ifndef BACHELOR_THESES_HISTOGRAM_H
#define BACHELOR_THESES_HISTOGRAM_H

#include <QWidget>
#include "../Observer/Observer.h"
#include "../Service/Service.h"
#include "../Teacher/Teacher.h"
#include "../StudentWindow/StudentWindow.h"
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QtCharts>
#include <QChart>
#include <QChartView>
#include <QBarSeries>


class Histogram : public QWidget, public Observer {
private:
    Service& service;
    QtCharts::QChartView* chartView;
    QtCharts::QBarSeries* bars;
    QtCharts::QChart* chart;

public:
    Histogram(Service& service);

    void initHistogram();

    void update() override;
};


#endif //BACHELOR_THESES_HISTOGRAM_H

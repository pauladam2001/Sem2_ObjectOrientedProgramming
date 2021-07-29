//
// Created by paula on 6/21/2021.
//

#include "Histogram.h"

Histogram::Histogram(Service &service): service{service} {
    this->service.addObserver(this);
    this->initHistogram();
    this->chartView->show();
}

void Histogram::initHistogram() {
    QFont legendFond("Consolas", 13, true);
    this->bars = new QtCharts::QBarSeries();
    for(auto & t: this->service.getTeachers())
    {
        int count=0;
        auto* set = new QtCharts::QBarSet(QString::fromStdString(t.getName()));
        for(auto & s: this->service.getStudents())
        {
            if(s.getCoordinator() == t.getName()){
                count++;
            }
        }

        *set << count;
        this->bars->append(set);
    }
    int c=0;
    auto* set = new QtCharts::QBarSet(QString::fromStdString("No coordinator"));
    for(auto & s: this->service.getStudents())
        if(s.getCoordinator().empty())
            c++;
    *set<<c;
    this->bars->append(set);

    this->chart = new QtCharts::QChart{};
    this->chart->addSeries(this->bars);
    this->chart->setTitle("Number of students each teacher coordinates");
    this->chart->setTitleFont(legendFond);
    this->chart->setTheme(QChart::ChartThemeQt);

    this->chart->setAnimationOptions(QtCharts::QChart::AllAnimations);
    this->chart->setAnimationDuration(2000);

    this->chart->createDefaultAxes();

    this->chart->legend()->setVisible(true);
    this->chart->legend()->setAlignment(Qt::AlignBottom);
    this->chart->legend()->setFont(legendFond);

    this->chartView = new QtCharts::QChartView(this->chart);

    this->chartView->setRenderHint(QPainter::SmoothPixmapTransform);
    this->chart->resize(1200, 800);
}

void Histogram::update() {
    this->bars->clear();
    for(auto & t: this->service.getTeachers())
    {
        int count=0;
        auto* set = new QtCharts::QBarSet(QString::fromStdString(t.getName()));
        for(auto & s: this->service.getStudents())
        {
            if(s.getCoordinator() == t.getName()){
                count++;
            }
        }

        *set << count;
        this->bars->append(set);
    }
    int c=0;
    auto* set = new QtCharts::QBarSet(QString::fromStdString("No coordinator"));
    for(auto & s: this->service.getStudents())
        if(s.getCoordinator().empty())
            c++;
    *set<<c;
    this->bars->append(set);
    this->chart->removeSeries(this->bars);
    this->chart->addSeries(this->bars);
    this->chart->createDefaultAxes();
}

//
// Created by paula on 5/20/2021.
//

#ifndef CARS_GUI_H
#define CARS_GUI_H

#include "service.h"
#include <qwidget.h>
#include <QListWidget>
#include <QPushButton>

class GUI : public QWidget {
private:
    Service& service;

    QListWidget* taskListWidget{};
    QPushButton* durationButton{}, *priorityButton{};
    QLineEdit* priorityEdit{};

public:
    GUI(Service& service);

    ~GUI();

private:
    void init_GUI();

    void populate_list();

    void connectSignalsAndSlots();

    void compute_duration();

    void bold_priority1();
};

#endif //CARS_GUI_H

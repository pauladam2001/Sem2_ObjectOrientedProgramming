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

    QListWidget* carListWidget{};
    QPushButton* colorButton{}, *modelButton{};
    QLineEdit* modelEdit{};

public:
    GUI(Service& service);

    ~GUI();

private:
    void init_GUI();

    void populate_list();

    void connectSignalsAndSlots();

    void change_color();

    void show_nr_of_cars();
};

#endif //CARS_GUI_H

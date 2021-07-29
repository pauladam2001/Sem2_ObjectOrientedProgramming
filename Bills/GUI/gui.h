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

    QListWidget* billsListWidget{};
    QPushButton* sortButton{}, *unpaidButton{};
    QLineEdit* unpaidLineEdit{}, *resultLineEdit{};

public:
    GUI(Service& service);

    ~GUI();

private:
    void init_GUI();

    void populate_list();

    void connectSignalsAndSlots();

    void sort_list();

    void calculate_unpaid();
};

#endif //CARS_GUI_H

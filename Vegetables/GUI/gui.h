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

    QListWidget* familiesListWidget{}, *vegetablesListWidget{};
    QPushButton* searchButton{};
    QLineEdit* nameLineEdit{}, *partsConsumedLineEdit{};

public:
    GUI(Service& service);

    ~GUI();

private:
    void init_GUI();

    void populate_list();

    void connectSignalsAndSlots();

    void add_to_vegetablesList();

    int get_selected_index();

    void highlight_vegetable_and_get_parts();
};

#endif //CARS_GUI_H

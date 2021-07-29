//
// Created by paula on 5/21/2021.
//

#ifndef SHOPPING_LIST_GUI_H
#define SHOPPING_LIST_GUI_H

#include "service.h"
#include "qwidget.h"
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

class GUI : public QWidget {
private:
    Service& service;

    QListWidget* shoppingListWidget{};
    QPushButton* deleteButton{}, *filterButton{};
    QLineEdit* categoryEdit{};

public:
    GUI(Service& service);

    ~GUI();

private:
    void init_GUI();

    void populate_list();

    void connectSignalsAndSlots();

    void delete_item();

    void filter_categ();

    int get_selected_index();
};

#endif //SHOPPING_LIST_GUI_H

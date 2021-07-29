//
// Created by paula on 5/24/2021.
//

#ifndef T3_PAULADAM2001_GUI_H
#define T3_PAULADAM2001_GUI_H

#include "service.h"
#include <qwidget.h>
#include <QListWidget>
#include <QPushButton>
#include <QSlider>
#include <QCheckBox>

class GUI : public QWidget {
private:
    Service& service;

    QListWidget* weatherListWidget{};
    QSlider* slider{};
    QCheckBox* checkBox1{}, *checkBox2{}, *checkBox3{}, *checkBox4{}, *checkBox5{};
    QPushButton* button{};

    vector<string> descriptions;
    vector<QCheckBox*> checkboxes;

public:
    GUI(Service& service);

    ~GUI();

private:
    void init_GUI();

    void populate_list();

    void connectSignalsAndSlots();

    void filter_list();

    void filter_checkbox();

    void return_to_unfiltered();

    void filter_through_both();

    void init_checkboxes();
};

#endif //T3_PAULADAM2001_GUI_H

//
// Created by paula on 6/22/2021.
//

#ifndef E2_PAULADAM2001_1_ETHNOLOGISTWINDOW_H
#define E2_PAULADAM2001_1_ETHNOLOGISTWINDOW_H

#include <QWidget>
#include "../Observer/Observer.h"
#include "../Service/Service.h"
#include "../Ethnologist/Ethnologist.h"
#include "../TableModel/TableModel.h"
#include <QPushButton>
#include <QLineEdit>
#include <QTableView>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QLabel>
#include <QSortFilterProxyModel>


class EthnologistWindow : public QWidget, public Observer {
private:
    Service& service;
    Ethnologist& e;

    TableModel* tableModel;
    QTableView* buildingsTableView;
    QVBoxLayout* mainLayout;
    QLineEdit* descriptionLineEdit, *locationsLineEdit, *descriptionUpdateLineEdit, *locationsUpdateLineEdit;
    QGridLayout* buttonsLayout;
    QPushButton* addButton, *updateButton;

public:
    EthnologistWindow(Service& service, Ethnologist& e, QWidget* parent = Q_NULLPTR);

    void initGUI();

    void connectSignals();

    void notifyModel();

    void update() override;

    void add_building();

    int get_selected_index();

    void update_building();

    ~EthnologistWindow() override;
};


#endif //E2_PAULADAM2001_1_ETHNOLOGISTWINDOW_H

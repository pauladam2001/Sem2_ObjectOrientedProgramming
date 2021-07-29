//
// Created by paula on 6/20/2021.
//

#ifndef DEVELOPMENT_TEAM_MEMBERWINDOW_H
#define DEVELOPMENT_TEAM_MEMBERWINDOW_H

#include "../Observer/Observer.h"
#include "../Service/Service.h"
#include "../TableModel/TableModel.h"
#include <QWidget>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSortFilterProxyModel>
#include <QLabel>
#include <QMessageBox>


class MemberWindow : public QWidget, public Observer {
private:
    Service& service;
    Member& m;

    TableModel* tableModel;
    QTableView* issuesTableView;
    QLineEdit* issuesLineEdit;
    QPushButton* reportButton, *removeButton, *resolveButton;
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    QSortFilterProxyModel* filterModel;

public:
    MemberWindow(Service& service, Member& m);

    void initGUI();

    void connectSignals();

    void reportIssue();

    void update() override;

    void notifyModel();

    void removeIssue();

    void check();

    void resolveIssue();

    int getSelectedIndex();

    ~MemberWindow() override;
};


#endif //DEVELOPMENT_TEAM_MEMBERWINDOW_H

//
// Created by paula on 6/20/2021.
//

#ifndef STAR_CATALOGUE_ASTRONOMERWINDOW_H
#define STAR_CATALOGUE_ASTRONOMERWINDOW_H

#include "../Observer/Observer.h"
#include "../TableModel/TableModel.h"
#include "../RepoAstronomers/RepoAstronomers.h"
#include "../RepoStars/RepoStars.h"
#include <QWidget>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSortFilterProxyModel>
#include <QLabel>
#include <QMessageBox>
#include <QListWidget>
#include <QCheckBox>
#include "../ConstellationWindow/ConstellationWindow.h"


class AstronomerWindow : public QWidget, public Observer {
private:
    RepoStars& stars;
    Astronomer& a;

    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    QCheckBox* constellationCheckBox;
    QLineEdit* searchLineEdit;
    QLineEdit* nameLineEdit, *raLineEdit, *decLineEdit, *diameterLineEdit;
    QPushButton* addButton, *viewButton;
    QListWidget* starsListWidget;
    QTableView* starsTableView;
    TableModel* tableModel;

public:
    AstronomerWindow(RepoStars& stars, Astronomer& astronomer);

    void update() override;

    void notifyModel();

    int getSelectedIndex();

    void connectSignals();

    void initGUI();

    void filterConstellations();

    void filterStarName();

    void addStar();

    void populateList(vector<Star> stars);

    void openApplication();

    ~AstronomerWindow() override;
};


#endif //STAR_CATALOGUE_ASTRONOMERWINDOW_H

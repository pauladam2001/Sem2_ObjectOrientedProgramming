//
// Created by paula on 6/20/2021.
//

#ifndef STAR_CATALOGUE_CONSTELLATIONWINDOW_H
#define STAR_CATALOGUE_CONSTELLATIONWINDOW_H

#include "../Observer/Observer.h"
#include "../TableModel/TableModel.h"
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
#include <QBrush>
#include <QPainter>


class ConstellationWindow : public QWidget {
private:
    RepoStars& stars;
    Star s;

    void paintEvent(QPaintEvent* event) override;

public:
    ConstellationWindow(RepoStars& stars, Star s);

    ~ConstellationWindow() override;
};


#endif //STAR_CATALOGUE_CONSTELLATIONWINDOW_H

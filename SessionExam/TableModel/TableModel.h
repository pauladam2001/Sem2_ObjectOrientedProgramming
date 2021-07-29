//
// Created by paula on 6/22/2021.
//

#ifndef E2_PAULADAM2001_1_TABLEMODEL_H
#define E2_PAULADAM2001_1_TABLEMODEL_H

#include <QAbstractTableModel>
#include "../Service/Service.h"


class TableModel : public QAbstractTableModel{
private:
    Service& service;
    Ethnologist& e;

public:

    TableModel(Service& service, Ethnologist& e, QObject* parent = NULL);

    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex & index) const override;

    void update_data_in_real_time();

    ~TableModel() override;
};

#endif //E2_PAULADAM2001_1_TABLEMODEL_H

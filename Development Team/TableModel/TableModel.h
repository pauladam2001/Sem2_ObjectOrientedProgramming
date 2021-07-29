//
// Created by paula on 6/20/2021.
//

#ifndef DEVELOPMENT_TEAM_TABLEMODEL_H
#define DEVELOPMENT_TEAM_TABLEMODEL_H

#include <QAbstractTableModel>
#include "../Service/Service.h"


class TableModel : public QAbstractTableModel {
private:
    Service& service;

public:
    TableModel(Service& service, QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

//    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void update_data_in_real_time();

    ~TableModel() override;
};


#endif //DEVELOPMENT_TEAM_TABLEMODEL_H

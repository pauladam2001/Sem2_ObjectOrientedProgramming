//
// Created by paula on 6/20/2021.
//

#ifndef STAR_CATALOGUE_TABLEMODEL_H
#define STAR_CATALOGUE_TABLEMODEL_H

#include <QAbstractTableModel>
#include "../RepoStars/RepoStars.h"


class TableModel : public QAbstractTableModel {
private:
    RepoStars& repository;

public:
    TableModel(RepoStars& repository, QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

//    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void update_data_in_real_time();

    ~TableModel() override;
};


#endif //STAR_CATALOGUE_TABLEMODEL_H

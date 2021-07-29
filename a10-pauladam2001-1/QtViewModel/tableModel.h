//
// Created by paul on 5/25/2021.
//

#ifndef A10_PAULADAM2001_1_TABLEMODEL_H
#define A10_PAULADAM2001_1_TABLEMODEL_H

#include <QAbstractTableModel>
#include "userService.h"


class CustomTableModel : public QAbstractTableModel {

private:
    UserService& userService;

public:
    CustomTableModel(UserService& userService, QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

//    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void update_data_in_real_time();

    ~CustomTableModel() override;
};


#endif //A10_PAULADAM2001_1_TABLEMODEL_H

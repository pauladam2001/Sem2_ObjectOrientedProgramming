//
// Created by paula on 6/20/2021.
//

#ifndef CODE_REVISION_TABLEMODEL_H
#define CODE_REVISION_TABLEMODEL_H

#include <QAbstractTableModel>
#include "../Repository/RepoQuestions.h"


class TableModel : public QAbstractTableModel {
private:
    RepoQuestion& repository;
    vector<int> indexes;

public:
    TableModel(RepoQuestion& repository, QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // will be called when a cell is edited
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;

    bool addBackground(int idx);

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void update_data_in_real_time();

    ~TableModel() override;
};


#endif //CODE_REVISION_TABLEMODEL_H

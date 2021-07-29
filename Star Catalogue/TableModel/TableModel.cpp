//
// Created by paula on 6/20/2021.
//

#include "TableModel.h"
#include <QFont>
#include <QBrush>

TableModel::TableModel(RepoStars &repository, QObject *parent): repository{repository}, QAbstractTableModel{parent} {

}

int TableModel::rowCount(const QModelIndex &parent) const {
    return this->repository.getAll().size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if( role == Qt::DisplayRole || role == Qt::EditRole) {
        vector<Star> stars = this->repository.getAll();
        Star s = stars[row];
        switch(column) {
            case 0:
                return QString::fromStdString(s.getName());
            case 1:
                return QString::fromStdString(s.getConstellation());
            case 2:
                return QString::number(s.getRA());
            case 3:
                return QString::number(s.getDec());
            case 4:
                return QString::number(s.getDiameter());
            default:
                break;
        }
    }

    if (role == Qt::FontRole) {
        QFont font("Times", 15, 10, true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole) {
        if(orientation == Qt::Horizontal) {
            switch(section) {
                case 0:
                    return QString{"Name"};
                case 1:
                    return QString{"Constellation"};
                case 2:
                    return QString{"Right Ascension"};
                case 3:
                    return QString{"Declination"};
                case 4:
                    return QString{"Diameter"};
                default:
                    break;
            }
        }
    }
    if(role == Qt::FontRole) {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void TableModel::update_data_in_real_time() {
    endResetModel();
}

TableModel::~TableModel() = default;

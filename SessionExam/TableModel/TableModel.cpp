//
// Created by paula on 6/22/2021.
//

#include "TableModel.h"
#include <QFont>
#include <QBrush>

TableModel::TableModel(Service &service, Ethnologist &e, QObject *parent): service{service}, e{e}, QAbstractTableModel(parent) {

}

int TableModel::rowCount(const QModelIndex &parent) const {
    return this->service.getBuiding_by_area(e).size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();

    vector<Building> buildings = this->service.getBuiding_by_area(e);
    Building building = buildings[row];

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch(column)
        {
            case 0:
                return QString::fromStdString(to_string(building.getId()));
            case 1:
                return QString::fromStdString(building.getDescription());
            case 2:
                return QString::fromStdString(building.getArea());
            case 3:{
                string location;
                for(auto square : building.getLocations()){
                    location = location + square + " ";
                }
                return QString::fromStdString(location);
            }
            default:
                break;
        }
    }

    if(role == Qt::FontRole){
        QFont font("Helvetica", 15, 10, true);
        font.setItalic(false);
        return font;
    }

    if (role == Qt::BackgroundRole) {
        if (buildings[row].getArea() == this->e.getArea())
            return QBrush{Qt::blue};
    }

    return QVariant{};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole) {
        if(orientation == Qt::Horizontal) {
            switch(section){
                case 0:
                    return QString{"Id"};
                case 1:
                    return QString{"Description"};
                case 2:
                    return QString{"Thematic area"};
                case 3:
                    return QString{"Location"};
                default:
                    break;
            }
        }
    }

    if(role == Qt::FontRole) {
        QFont font("Helvetica", 15, 10, true);
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

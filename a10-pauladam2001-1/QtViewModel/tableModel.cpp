//
// Created by paul on 5/25/2021.
//

#include <QFont>
#include "tableModel.h"

CustomTableModel::CustomTableModel(UserService &userService, QObject *parent): userService{userService}, QAbstractTableModel{parent} {

}

int CustomTableModel::rowCount(const QModelIndex &parent) const {
    return this->userService.getBasket().size();
}

int CustomTableModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant CustomTableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        vector<trenchCoat> data = this->userService.getBasket();
        trenchCoat coat = data[row];

        switch (column) {
            case 0:
                return QString::fromStdString(coat.getSize());
            case 1:
                return QString::fromStdString(coat.getColor());
            case 2:
                return QString::number(coat.getPrice());
//            case 3:
//                return QString::number(coat.getQuantity());
            case 3:
                return QString::fromStdString(coat.getPhotograph());
            default:
                break;
        }
    }

    if (role == Qt::FontRole) {
        QFont font("Helvetica", 10, QFont::Bold);
        font.setItalic(false);
        return font;
    }

//    if (role == Qt::BackgroundRole)
//    {
//        if (row % 2 == 1)
//        {
//            return QBrush{ QColor{0, 250, 154} };
//        }
//    }

    return QVariant{};
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return QString{"Size"};
                case 1:
                    return QString{"Color"};
                case 2:
                    return QString{"Price"};
//                case 3:
//                    return QString{"Quantity"};
                case 3:
                    return QString{"Photograph"};
                default:
                    break;
            }
        }
    }

    if (role == Qt::FontRole) {
        QFont font("Helvetica", 10, QFont::Bold);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

Qt::ItemFlags CustomTableModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void CustomTableModel::update_data_in_real_time() {
    endResetModel();
}

CustomTableModel::~CustomTableModel() = default;

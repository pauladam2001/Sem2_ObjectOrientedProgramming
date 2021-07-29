//
// Created by paula on 6/20/2021.
//

#include "TableModel.h"
#include <QFont>
#include <QBrush>

TableModel::TableModel(Files &repository, QObject *parent): repository{repository}, QAbstractTableModel{parent} {

}

int TableModel::rowCount(const QModelIndex &parent) const {
    return this->repository.getAll().size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if( role == Qt::DisplayRole || role == Qt::EditRole) {
        vector<SourceFile> files = this->repository.getAll();
        SourceFile f = files[row];
        switch(column) {
            case 0:
                return QString::fromStdString(f.getName());
            case 1:
                return QString::fromStdString(f.getStatus());
            case 2:
                return QString::fromStdString(f.getCreator());
            case 3:
                return QString::fromStdString(f.getReviewer());
            default:
                break;
        }
    }

    vector<SourceFile> files = this->repository.getAll();

    if (role == Qt::FontRole) {
        if (files[row].getStatus() == "not-revised") {
            QFont font("Times", 15, 10, true);
            font.setItalic(false);
            font.setBold(true);
            return font;
        }
        else {
            QFont font("Times", 15, 10, true);
            font.setItalic(false);
            return font;
        }
    }

    if (role == Qt::BackgroundRole) {
        if (files[row].getStatus() == "revised") {
            return QBrush{QColor{0, 250, 154}};
        }
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
                    return QString{"Status"};
                case 2:
                    return QString{"Creator"};
                case 3:
                    return QString{"Reviewer"};
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

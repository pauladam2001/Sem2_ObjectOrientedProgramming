//
// Created by Alexandra on 6/21/2021.
//

#include <QFont>
#include "TableModel.h"

TableModel::TableModel(Service &service, QObject *parent): service{service}, QAbstractTableModel(parent) {

}

TableModel::~TableModel() {

}

int TableModel::rowCount(const QModelIndex &parent) const {
    return this->service.getQuestions().size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if( role == Qt::DisplayRole || role == Qt::EditRole)
    {
        vector<Question> questions = this->service.getQuestions();
        Question f = questions[row];
        switch(column)
        {
            case 0:
                return QString::fromStdString(f.getID());

            case 1:
                return QString::fromStdString(f.getText());

            case 2:
                return QString::fromStdString(f.getName());

            default:
                break;

        }

    }


    if(role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section){
                case 0:
                    return QString{"ID"};

                case 1:
                    return QString{"Text"};

                case 2:
                    return QString{"Creator"};

                default:
                    break;
            }
        }
    }
    if(role == Qt::FontRole)
    {
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

void TableModel::updateInternalData() {
    endResetModel();
}

//
// Created by paula on 6/21/2021.
//

#include "TableModelPresenter.h"
#include <QFont>

TableModelPresenter::TableModelPresenter(RepoQuestion &repository, QObject *parent):repository{repository},
                                                                                     QAbstractTableModel(parent) {

}

TableModelPresenter::~TableModelPresenter() {

}

int TableModelPresenter::rowCount(const QModelIndex &parent) const {
    return this->repository.getQuestions().size();
}

int TableModelPresenter::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant TableModelPresenter::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if( role == Qt::DisplayRole || role == Qt::EditRole)
    {
        vector<Question> questions = this->repository.getQuestions();
        Question f = questions[row];
        switch(column)
        {
            case 0:
                return QString::fromStdString(to_string(f.getId()));

            case 1:
                return QString::fromStdString(f.getText());

            case 2:
                return QString::fromStdString(f.getCorrectAnswer());

            case 3:
                return QString::fromStdString(to_string(f.getScore()));
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

QVariant TableModelPresenter::headerData(int section, Qt::Orientation orientation, int role) const {
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
                    return QString{"Correct Answer"};

                case 3:
                    return QString{"Score"};

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

Qt::ItemFlags TableModelPresenter::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void TableModelPresenter::updateInternalData() {
    endResetModel();
}

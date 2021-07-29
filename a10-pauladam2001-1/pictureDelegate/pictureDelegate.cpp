//
// Created by paul on 5/26/2021.
//

#include "pictureDelegate.h"
#include <QPainter>


PictureDelegate::PictureDelegate(QWidget *parent): QStyledItemDelegate{parent} {

}

void PictureDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QString trenchCoat = index.model()->data(index, Qt::EditRole).toString();

    if (index.column() != 0) {
        QStyledItemDelegate::paint(painter, option, index);
        return;
    }

    if (trenchCoat.contains("XS")) {
        QPixmap pixMap("XS.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if (trenchCoat.contains("S")) {
        QPixmap pixMap("S.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if (trenchCoat.contains("M")) {
        QPixmap pixMap("M.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if (trenchCoat.contains("L")) {
        QPixmap pixMap("L.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if (trenchCoat.contains("XL")) {
        QPixmap pixMap("XL.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if (trenchCoat.contains("XXL")) {
        QPixmap pixMap("XXL.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    // show a picture only in the second column; the other columns remain unchanged
    if (index.column() == 0)
        return QSize(300, 300);
    return QStyledItemDelegate::sizeHint(option, index);
}

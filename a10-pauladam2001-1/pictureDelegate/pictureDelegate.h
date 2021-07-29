//
// Created by paul on 5/26/2021.
//

#ifndef A10_PAULADAM2001_1_PICTUREDELEGATE_H
#define A10_PAULADAM2001_1_PICTUREDELEGATE_H

#include <QStyledItemDelegate>
#include "userService.h"


class PictureDelegate : public QStyledItemDelegate {

public:
    explicit PictureDelegate(QWidget *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};


#endif //A10_PAULADAM2001_1_PICTUREDELEGATE_H

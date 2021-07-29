//
// Created by paula on 6/20/2021.
//

#ifndef CODE_REVISION_STATISTICSWINDOW_H
#define CODE_REVISION_STATISTICSWINDOW_H

#include "../Observer/Observer.h"
#include "../RepoProgrammers/RepoProgrammers.h"
#include "../RepoFiles/Files.h"
#include "../TableModel/TableModel.h"
#include <QWidget>
#include <QPainter>


class StatisticsWindow : public QWidget, public Observer {
private:
    RepoProgrammers& repoProgrammers;
    Files& files;
    int x = 0;
    int y = 0;

public:
    StatisticsWindow(RepoProgrammers& repoProgrammers, Files& files); // third parameter QWidget*parent=Q_NULLPTR, not really necessary

    void update() override;

    QSize sizeHint() const Q_DECL_OVERRIDE;

    void drawCircle(Programmer& p);

    void resizeEvent(QResizeEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    ~StatisticsWindow() override;
};


#endif //CODE_REVISION_STATISTICSWINDOW_H

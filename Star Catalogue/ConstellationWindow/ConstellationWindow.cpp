//
// Created by paula on 6/20/2021.
//

#include "ConstellationWindow.h"

ConstellationWindow::ConstellationWindow(RepoStars &stars, Star s): stars{stars}, s{s} {

}

void ConstellationWindow::paintEvent(QPaintEvent *event) {
    vector<Star> constellation = this->stars.filterStarsByConstellation(this->s.getConstellation());
    QPainter painter{this};
    for (auto c : constellation) {
        if (c.getName() == s.getName())
            painter.setBrush(Qt::red);
        else
            painter.setBrush(Qt::black);
        painter.drawEllipse(c.getRA(), c.getDec(), c.getDiameter(), c.getDiameter());
    }
}

ConstellationWindow::~ConstellationWindow() = default;

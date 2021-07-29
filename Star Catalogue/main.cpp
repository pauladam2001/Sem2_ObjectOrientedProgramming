#include <iostream>
#include <QApplication>
#include "RepoAstronomers/RepoAstronomers.h"
#include "AstronomerWindow/AstronomerWindow.h"
#include "RepoStars/RepoStars.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    RepoAstronomers repoAstronomers;
    RepoStars stars;
    vector<AstronomerWindow*> windows;
    for (auto& astronomer : repoAstronomers.getAll())
        windows.push_back(new AstronomerWindow(stars, astronomer));

    return a.exec();
}

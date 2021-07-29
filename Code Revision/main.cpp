#include <iostream>
#include <QApplication>
#include "RepoProgrammers/RepoProgrammers.h"
#include "RepoFiles/Files.h"
#include "ProgrammerWindow/ProgrammerWindow.h"
#include "StatisticsWindow/StatisticsWindow.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);

    RepoProgrammers repoProgrammers;
    Files files;
    vector<ProgrammerWindow*> windows;
    for(auto &p : repoProgrammers.getAll())
        windows.push_back(new ProgrammerWindow(files, p));

    StatisticsWindow statsWindow(repoProgrammers, files);

    return a.exec();
}

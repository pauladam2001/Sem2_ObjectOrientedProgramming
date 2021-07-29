//
// Created by paula on 5/24/2021.
//

#include "repo.h"
#include "service.h"
#include "gui.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    Repository repository;
    Service service(repository);
    GUI gui(service);

    gui.show();

    return a.exec();
}

//
// Created by paula on 6/22/2021.
//

#include <iostream>
#include <QApplication>
#include "Repository/Repository.h"
#include "Service/Service.h"
#include "EthnologistWindow/EthnologistWindow.h"

using namespace std;


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    Repository repository;
    Service service(repository);
    vector<EthnologistWindow*> windows;

    for (auto& e : service.getEthnologists())
        windows.push_back(new EthnologistWindow(service, e));

    return a.exec();

}


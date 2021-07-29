#include <iostream>
#include <QApplication>
#include "Repository/Repository.h"
#include "Service/Service.h"
#include "TeacherWindow/TeacherWindow.h"
#include "Histogram/Histogram.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    Repository repository;
    Service service(repository);
    vector<TeacherWindow*> windows;
    for (auto& teacher : service.getTeachers())
        windows.push_back(new TeacherWindow(service, teacher));

    Histogram h(service);

    return a.exec();
}

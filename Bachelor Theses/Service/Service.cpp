//
// Created by paula on 6/21/2021.
//

#include "Service.h"

Service::Service(Repository &repo): repo{repo} {

}

vector<Student> &Service::getStudents() {
    return this->repo.getStudents();
}

vector<Teacher> &Service::getTeachers() {
    return this->repo.getTeachers();
}

vector<Student> Service::filterStudentsName(string name) {
    vector<Student> filtered;
    for (auto& s : this->getStudents())
        if (s.getName().find(name) != std::string::npos || s.getId().find(name) != std::string::npos)
            filtered.push_back(s);
    return filtered;
}

vector<Student> Service::filteredYear(string coordinator) {
    vector<Student> filtered;
    vector<Student> selected;

    for (auto& s : this->getStudents())
        if (s.getCoordinator() == coordinator)
            selected.push_back(s);

    if (selected.empty())
        return filtered;

    for (auto& s : selected)
        if (s.getYear() == 2021)
            filtered.push_back(s);

    vector<Student> sorted(selected);
    for (int i=0;i<sorted.size()-1;i++)
        for (int j=i+1;j<sorted.size();j++)
            if (sorted[i].getYear() < sorted[j].getYear())
                swap(sorted[i], sorted[j]);

    for (auto& s : sorted)
        if (s.getYear() != 2021)
            filtered.push_back(s);

    return filtered;
}

void Service::makeCoordinator(Student &s, string name) {
    for (auto& stud : this->getStudents())
        if (stud == s)
            stud.setCoordinator(name);
    this->notify();
}

void Service::changeTitleAndEmail(Student &s, string title, string email) {
    for (auto& stud : this->getStudents())
        if (stud == s) {
            stud.setTitle(title);
            stud.setEmail(email);
        }
    this->notify();
}

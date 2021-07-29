//
// Created by paula on 6/21/2021.
//

#ifndef BACHELOR_THESES_SERVICE_H
#define BACHELOR_THESES_SERVICE_H

#include "../Repository/Repository.h"
#include "../Observer/Observer.h"

class Service : public Observable {
private:
    Repository& repo;

public:
    Service(Repository& repo);

    vector<Student>& getStudents();

    vector<Teacher>& getTeachers();

    vector<Student> filterStudentsName(string name);

    vector<Student> filteredYear(string coordinator);

    void makeCoordinator(Student& s, string name);

    void changeTitleAndEmail(Student& s, string title, string email);

    ~Service() = default;
};


#endif //BACHELOR_THESES_SERVICE_H

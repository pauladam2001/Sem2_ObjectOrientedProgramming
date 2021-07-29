//
// Created by paula on 6/21/2021.
//

#ifndef BACHELOR_THESES_REPOSITORY_H
#define BACHELOR_THESES_REPOSITORY_H

#include <vector>
#include <fstream>
#include "../Student/Student.h"
#include "../Teacher/Teacher.h"


class Repository {
private:
    vector<Teacher> teachers;
    vector<Student> students;

    void load_data_teachers();

    void load_data_students();

public:
    Repository();

    vector<Student>& getStudents();

    vector<Teacher>& getTeachers();

    ~Repository() = default;
};


#endif //BACHELOR_THESES_REPOSITORY_H

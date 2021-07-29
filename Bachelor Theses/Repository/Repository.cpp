//
// Created by paula on 6/21/2021.
//

#include "Repository.h"

Repository::Repository() {
    this->load_data_teachers();
    this->load_data_students();
}

void Repository::load_data_teachers() {
    ifstream inFile("teachers.txt");
    Teacher currentTeacher;
    this->teachers.clear();
    while (inFile >> currentTeacher)
        this->teachers.push_back(currentTeacher);
    inFile.close();
}

void Repository::load_data_students() {
    ifstream inFile("students.txt");
    Student currentStudent;
    this->students.clear();
    while (inFile >> currentStudent)
        this->students.push_back(currentStudent);
    inFile.close();
}

vector<Student> &Repository::getStudents() {
    return this->students;
}

vector<Teacher> &Repository::getTeachers() {
    return this->teachers;
}

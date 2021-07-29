//
// Created by paula on 6/22/2021.
//

#include "Person.h"

Person::Person(string name, int age): name{name}, age{age} {

}

std::ostream &operator<<(ostream &output, const Person &person) {
    output << person.name << " is " << person.age << " years old.";
    return output;
}

Person &Person::operator=(const Person &person) {
    this->name = person.name;
    this->age = person.age;
    return *this;
}

bool Person::operator==(const Person &person) const {
    if (this->name == person.name && this->age == person.age)
        return true;
    return false;
}

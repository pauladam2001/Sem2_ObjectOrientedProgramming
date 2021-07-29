//
// Created by paula on 6/18/2021.
//

#include <iostream>
#include "Person.h"

Person::Person(string name, int age): name{name}, age{age} {

}

std::ostream &operator<<(ostream &output, const Person &person) {
    output << person.name << " is " << person.age << " years old";
    return output;
}

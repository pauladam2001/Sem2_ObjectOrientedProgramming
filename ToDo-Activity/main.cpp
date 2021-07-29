#include <iostream>
#include "classes/Activity.h"
#include "classes/ToDo.h"


void ToDoList()
{
    ToDo<Activity> todo{};
    Activity tiff{ "go to TIFF movie", "20:00" };
    todo += tiff;
    Activity project{ "present project assignment", "09.20" };
    todo += project;

    // iterates through the activities and prints them as follows:
    // Activity present project assignment will take place at 09.20.
    // Activity go to TIFF movie will take place at 20.00.
    for (auto a : todo)
        std::cout << a << '\n';

    // Prints the activities as follows:
    // Activity go to TIFF movie will take place at 20.00.
    // Activity present project assignment will take place at 09.20.
    todo.reversePrint(std::cout);
}

int main() {
    ToDoList();

    return 0;
}

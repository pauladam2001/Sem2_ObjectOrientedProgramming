//
// Created by paula on 4/26/2021.
//

#include "ui.h"
#include <iostream>
#include <string>
#include <vector>
#include "except.h"
#include "measurement.h"

using namespace std;


UserInterface::UserInterface(Person &person): person{person} {

}

void UserInterface::display() {
    cout<<"                       "<<this->person.getName()<<endl;
    vector<Measurement*> array = this->person.getAllMeasurements();
    for (auto & element : array) {
        cout<<element->toString();
    }
}

void UserInterface::add_ui() {
    string type, date;
    double value;
    int systolic, diastolic;
    cout<<endl<<"Measurement type:";
    cin>>type;
    cout<<endl<<"Date:";
    cin>>date;

    if (type != "BMI" && type != "BP" && date.length() != 10) {
        throw CustomException("Invalid parameters for add!");
    }

    if (type == "BMI") {
        cout<<endl<<"Value:";
        cin>>value;
        if (this->person.add_BMI_from_ui(date, value) == 1)
            cout<<"The person is within the range of normal values!"<<endl;
        else
            cout<<"The person is not within the range of normal values!"<<endl;
    }
    else if (type == "BP") {
        cout<<endl<<"Systolic:";
        cin>>systolic;
        cout<<endl<<"Diastolic:";
        cin>>diastolic;
        if (this->person.add_BP_from_ui(date, systolic, diastolic) == 1)
            cout<<"The person is within the range of normal values!"<<endl;
        else
            cout<<"The person is not within the range of normal values!"<<endl;
    }
}

void UserInterface::save_file_ui() {
    string fileName, date;
    cout<<"Filename:"<<endl;
    cin>>fileName;
    cout<<"Date:"<<endl;
    cin>>date;
    this->person.writeToFile(fileName, date);
}

void UserInterface::print_menu() {
    cout<<endl<<"1. Add a new measurement;"<<endl;
    cout<<"2. Display the list of measurements;"<<endl;
    cout<<"3. Save measurements after a given date to file;"<<endl;
    cout<<"0. Exit program."<<endl<<endl;
    cout<<"Your option:";
}

void UserInterface::start_program() {
    char option;

    do {
        print_menu();
        cin>>option;

        switch (option) {
            case '0': {
                cout<<endl<<"See you later!";
                exit(0);
            }
            case '1': {
                try {
                    this->add_ui();
                }
                catch (const CustomException& except) {
                    cout<<endl<<except.what()<<endl;
                }
                break;
            }
            case '2': {
                this->display();
                break;
            }
            case '3': {
                this->save_file_ui();
                break;
            }
            default: {
                cout<<endl<<"This is not a command!"<<endl;
                break;
            }
        }
    } while (option != '0');
}

UserInterface::~UserInterface() = default;

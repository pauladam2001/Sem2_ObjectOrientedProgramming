//
// Created by paul on 3/20/2021.
//

#include "userInterface.h"

#include <iostream>
#include <string>

#include <windows.h>
#include <shellapi.h>
using namespace std;

UserInterface::UserInterface() {

}

UserInterface::UserInterface(Service *service, Validator *validator, UserService *userService) {
    this->service = service;
    this->validator = validator;
    this->userService = userService;
}

void UserInterface::print_coats_admin() {
    dynamicArray<trenchCoat>* dynArray = this->service->getRepository()->getDynArr();
    for (int index = 0; index < dynArray->getSize(); index++) {
        char string[100];
        dynArray->getData()[index].to_string(string);
        cout<<string<<endl;
    }

}

void UserInterface::add_coat_admin() {
    string size, color, price, quantity, photograph;
    cout<<endl<<"Size:";
    cin>>size;
    cout<<"Color:";
    cin>>color;
    cout<<"Price:";
    cin>>price;
    cout<<"Quantity:";
    cin>>quantity;
    cout<<"Photograph:";
    cin>>photograph;
    if (this->validator->validate_price_or_quantity(price) == 1 && this->validator->validate_price_or_quantity(quantity) == 1 &&
        this->validator->validate_size(size) && this->validator->validate_color(color) && this->validator->validate_photograph(photograph)) {
        int newPrice = stoi(price);
        int newQuantity = stoi(quantity);
        if (this->service->add_service(size, color, newPrice, newQuantity, photograph) == 0)
            cout<<endl<<"The trench coat already exists!"<<endl;
        else
            cout<<endl<<"Trench coat added successfully!"<<endl;
    }
    else
        cout<<endl<<"Invalid parameters!"<<endl;
}

void UserInterface::delete_coat_admin() {
    string size, color, photograph;
    cout<<endl<<"Size:";
    cin>>size;
    cout<<"Color:";
    cin>>color;
    cout<<"Photograph:";
    cin>>photograph;
    if (this->validator->validate_size(size) && this->validator->validate_color(color) && this->validator->validate_photograph(photograph)) {
        if (this->service->delete_service(size, color, photograph) == 0)
            cout<<endl<<"The trench coat does not exist or the quantity is not 0!"<<endl;
        else
            cout<<endl<<"Trench coat deleted successfully!"<<endl;
    }
    else
        cout<<endl<<"Invalid parameters!"<<endl;
}

void UserInterface::update_coat_admin() {
    string size, color, price, quantity, photograph;
    char option;
    cout<<endl<<"a. Update price;"<<endl;
    cout<<"b. Update quantity."<<endl;
    cout<<"Your option:";
    cin>>option;
    if (option == 'a') {
        cout<<endl<<"Size:";
        cin>>size;
        cout<<"Color:";
        cin>>color;
        cout<<"New price:";
        cin>>price;
        cout<<"Photograph:";
        cin>>photograph;
        if (this->validator->validate_price_or_quantity(price) == 1 &&this->validator->validate_size(size) &&
        this->validator->validate_color(color) && this->validator->validate_photograph(photograph)) {
            int newPrice = stoi(price);
            if (this->service->update_price_service(size, color, newPrice, photograph) == 0)
                cout<<endl<<"The trench coat does not exist!"<<endl;
            else
                cout<<endl<<"Trench coat updated successfully!"<<endl;
        }
        else
            cout<<endl<<"Invalid parameters!"<<endl;
    }
    else if (option == 'b') {
        cout<<endl<<"Size:";
        cin>>size;
        cout<<"Color:";
        cin>>color;
        cout<<"New quantity:";
        cin>>quantity;
        cout<<"Photograph:";
        cin>>photograph;
        if (this->validator->validate_price_or_quantity(quantity) == 1 && this->validator->validate_size(size) &&
        this->validator->validate_color(color) && this->validator->validate_photograph(photograph)) {
            int newQuantity = stoi(quantity);
            if (this->service->update_quantity_service(size, color, newQuantity, photograph) == 0)
                cout<<endl<<"The trench coat does not exist!"<<endl;
            else
                cout<<endl<<"Trench coat updated successfully!"<<endl;
        }
        else
            cout<<endl<<"Invalid parameters!"<<endl;
    }
    else
        cout<<endl<<"Invalid command!"<<endl;
}

void UserInterface::print_menu_admin() {
    cout<<endl<<"ADMINISTRATOR MODE"<<endl<<endl;
    cout<<"1. Print all trench coats;"<<endl;
    cout<<"2. Add a new trench coat;"<<endl;
    cout<<"3. Delete a sold out trench coat;"<<endl;
    cout<<"4. Update a trench coat;"<<endl;
    cout<<"0. Exit the program."<<endl<<endl;
    cout<<"Your option:";
}

void UserInterface::administrator_mode() {
    char option;

    do {
        print_menu_admin();
        cin>>option;

        switch (option) {
            case '0': {
                cout<<endl<<"See you later!";
                break;
            }
            case '1': {
                this->print_coats_admin();
                break;
            }
            case '2': {
                this->add_coat_admin();
                break;
            }
            case '3': {
                this->delete_coat_admin();
                break;
            }
            case '4': {
                this->update_coat_admin();
                break;
            }
            default: {
                cout<<endl<<"This is not a command!"<<endl;
                break;
            }
        }
    } while (option != '0');
}

void UserInterface::print_menu_view() {
    cout<<endl<<"If you want to add this coat to the basket press 'y';"<<endl;
    cout<<"If you don't want to add this coat to the basket and you want to go to the next one press 'n';"<<endl;
    cout<<"If you want to see the shopping basket and the total price press '1'"<<endl;
    cout<<"0. Exit view mode."<<endl<<endl;
    cout<<"Your option:";
}

void UserInterface::read_coat_size() {
    bool valid = false;
    while (!valid) {
        cout<<endl<<"Size (if you want an empty string, press enter):";
        string size;
        cin.ignore();
        getline(cin, size);
        cout<<endl;
        if (this->validator->validate_size(size) || size.empty()) {
            this->userService->available_size_coats(size);
            if (this->userService->getAvailableSizeCoats()->getSize() == 0)
                cout<<endl<<"This size is not in the stock anymore. Try another one."<<endl;
            else
                valid = true;
        }
        else
            cout<<"Invalid size! Try another one."<<endl;
    }
}

void UserInterface::see_trench_coats_user() {
    char option;
    int index = 0;
    int totalPrice;
    totalPrice = *this->userService->getTotalPrice();
    this->read_coat_size();
    do {
        char string[100];
        this->userService->getAvailableSizeCoats()->getData()[index].to_string(string);
        cout<<string<<endl;
        std::string photograph = this->userService->getAvailableSizeCoats()->getData()[index].getPhotograph();

//        ShellExecuteA(NULL, "open", photograph.c_str(), NULL, NULL, SW_SHOWNORMAL);

        this->print_menu_view();
        cin>>option;
        cout<<endl;
        if (option == 'y' || option == 'n') {
            if (index == this->userService->getAvailableSizeCoats()->getSize() - 1)
                index = 0;
            else
                index++;
        }
        switch (option) {
            case '0': {
                this->user_mode();
                break;
            }
            case '1': {
                this->print_basket_totalPrice();
                break;
            }
            case 'y': {
                if (index == 0) {
                    totalPrice += this->userService->getAvailableSizeCoats()->getData()[this->userService->getAvailableSizeCoats()->getSize() - 1].getPrice();
                    this->userService->update_basket(this->userService->getAvailableSizeCoats()->getSize() - 1);
                    if (this->userService->getAvailableSizeCoats()->getData()[this->userService->getAvailableSizeCoats()->getSize() - 1].getQuantity() == 0) {
                        this->userService->delete_quantity_zero(this->userService->getAvailableSizeCoats()->getSize() - 1);
                        index--;
                    }
                }
                else {
                    totalPrice += this->userService->getAvailableSizeCoats()->getData()[index - 1].getPrice();
                    this->userService->update_basket(index - 1);
                    if (this->userService->getAvailableSizeCoats()->getData()[index - 1].getQuantity() == 0) {
                        this->userService->delete_quantity_zero(index - 1);
                        index--;
                    }
                }
                this->userService->setTotalPrice(totalPrice);
                cout<<endl<<"Trench coat added! Your total price is:"<<totalPrice<<endl<<endl;
                if (this->userService->getAvailableSizeCoats()->getSize() == 0) {
                    this->print_basket_totalPrice();
                    cout<<"There are no more coats of this type in the store!"<<endl<<endl;
                    this->user_mode();
                }
                break;
            }
            case 'n': {
                break;
            }
            default: {
                cout<<endl<<"This is not a command!"<<endl<<endl;
                break;
            }
        }
    } while (option != '0');
}

void UserInterface::print_basket_totalPrice() {
    for (int index = 0; index < this->userService->getBasket()->getSize(); index++) {
        char string[100];
        this->userService->getBasket()->getData()[index].to_string(string);
        cout<<string<<endl;
    }
    cout<<endl<<"Total price:"<<*this->userService->getTotalPrice()<<endl<<endl<<endl;
}

void UserInterface::print_menu_user() {
    cout<<endl<<"USER MODE"<<endl<<endl;
    cout<<"1. See the trench coats of a given size;"<<endl;
    cout<<"2. See the shopping basket and the total price of the items;"<<endl;
    cout<<"0. Exit the program."<<endl<<endl;
    cout<<"Your option:";
}

void UserInterface::user_mode() {
    char option;

    do {
        print_menu_user();
        cin>>option;

        switch (option) {
            case '0': {
                cout<<endl<<"See you later!";
                exit(0);
            }
            case '1': {
                this->see_trench_coats_user();
                break;
            }
            case '2': {
                this->print_basket_totalPrice();
                break;
            }
            default: {
                cout<<endl<<"This is not a command!"<<endl;
                break;
            }
        }
    } while (option != '0');
}


void UserInterface::start_program() {
    char option;
    cout<<"1. Administrator mode;"<<endl;
    cout<<"2. User mode."<<endl<<endl;
    cout<<"Your option:";
    cin>>option;

    if (option == '1')
        this->administrator_mode();
    else if (option == '2')
        this->user_mode();
    else {
        cout<<"Invalid option!"<<endl<<endl;
        this->start_program();
    }
}

UserInterface::~UserInterface() {
    delete this->service;
    delete this->validator;
    delete this->userService;
}

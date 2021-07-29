//
// Created by paul on 3/20/2021.
//

#ifndef A45_PAULADAM2001_USERINTERFACE_H
#define A45_PAULADAM2001_USERINTERFACE_H

#include "service.h"
#include "userService.h"
#include "validators.h"
#include "AbstractBasket.h"


class UserInterface {
private:

    Service& service;
    Validator& validator;
    UserService& userService;
    AbstractShoppingBasket* asp{};

    void print_coats_admin();

    void add_coat_admin();

    void delete_coat_admin();

    void update_coat_admin();

    static void print_menu_admin();

    void administrator_mode();

    static void print_menu_view();

    void read_coat_size();

    void see_trench_coats_user();

    void print_basket_totalPrice();

    void see_basket_application();

    static void print_menu_user();

    void user_mode();

public:

//    UserInterface();

    UserInterface(Service& service, Validator& validator, UserService& userService);

    void start_program();

    ~UserInterface();
};


#endif //A45_PAULADAM2001_USERINTERFACE_H

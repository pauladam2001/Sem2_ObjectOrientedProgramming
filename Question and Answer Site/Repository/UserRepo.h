//
// Created by Alexandra on 6/20/2021.
//

#pragma once
#include "User.h"
#include <vector>

class UserRepo {

private:
    vector<User> users;
    void LoadData();

public:
    UserRepo();
    ~UserRepo();

    vector<User>& getUsers();

};

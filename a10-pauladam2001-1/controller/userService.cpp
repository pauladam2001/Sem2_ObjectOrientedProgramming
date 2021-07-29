//
// Created by paula on 3/24/2021.
//

#include "userService.h"
#include <algorithm>


UserService::UserService(Repository &repository):repository{repository} {
    this->totalPrice = 0;
}

void UserService::available_size_coats(const string& size) {
    vector<trenchCoat> dynArrayRepo = this->getRepository().getDynArr();
//    if (size.empty()) { //size == ""
//        for (const auto & element : dynArrayRepo)
//            this->availableSizeCoats.push_back(element);
//    }
//    else {
//        for (auto & element : dynArrayRepo)                       //for (int index = 0; index < dynArrayRepo.size(); index++) if(dynArrayRepo.at(index).getSize() == size) this->availableSizeCoats.push_back(dynArrayRepo.at(index));
//            if (element.getSize() == size)
//                this->availableSizeCoats.push_back(element);
//    }
    this->availableSizeCoats.clear();
    if (size.empty()) {
        for (const auto & element : dynArrayRepo)
            this->availableSizeCoats.push_back(element);
    }
    else {
        this->availableSizeCoats.resize(dynArrayRepo.size());
        auto it = copy_if(dynArrayRepo.begin(), dynArrayRepo.end(), this->availableSizeCoats.begin(), [&size](const trenchCoat& coat){return coat.getSize()==size;});   // maybe works if we make the getDynArray function const
        this->availableSizeCoats.resize(std::distance(this->availableSizeCoats.begin(), it));
    }
}

void UserService::update_basket(int index) {
    this->basket.push_back(this->availableSizeCoats.at(index));
    this->update_quantity_userService(this->getAvailableSizeCoats().at(index).getSize(), this->getAvailableSizeCoats().at(index).getColor(), this->getAvailableSizeCoats().at(index).getQuantity() - 1, this->getAvailableSizeCoats().at(index).getPhotograph());
    trenchCoat newCoat(this->availableSizeCoats.at(index).getSize(), this->availableSizeCoats.at(index).getColor(), this->availableSizeCoats.at(index).getPrice(), this->availableSizeCoats.at(index).getQuantity() - 1, this->availableSizeCoats.at(index).getPhotograph());
    this->availableSizeCoats[index] = newCoat;
}

void UserService::delete_quantity_zero(int index) {
    this->delete_userService(this->availableSizeCoats.at(index).getSize(), this->availableSizeCoats.at(index).getColor(), this->availableSizeCoats.at(index).getPhotograph());
    this->availableSizeCoats.erase(this->availableSizeCoats.begin() + index);
}

void UserService::delete_userService(const string& size, const string& color, const string& photograph) {
    this->repository.delete_repo(size, color, photograph);

}

void UserService::update_quantity_userService(const string& size, const string& color, int quantity, const string& photograph) {
    this->repository.update_quantity_repo(size, color, quantity, photograph);
}

Repository& UserService::getRepository() {
    return this->repository;
}

vector<trenchCoat> UserService::getAvailableSizeCoats() {
    return this->availableSizeCoats;
}

vector<trenchCoat> UserService::getBasket() {
    return this->basket;
}

int *UserService::getTotalPrice() {
    return &(this->totalPrice);
}

void UserService::setTotalPrice(int value) {
    this->totalPrice = value;
}

UserService::~UserService() = default;

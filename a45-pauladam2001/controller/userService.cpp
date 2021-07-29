//
// Created by paula on 3/24/2021.
//

#include "userService.h"


UserService::UserService(Repository *repository) {
    this->repository = repository;
    this->availableSizeCoats = new dynamicArray<trenchCoat>(100);
    this->basket = new dynamicArray<trenchCoat>(100);
    this->totalPrice = 0;
}

void UserService::available_size_coats(string size) {
    dynamicArray<trenchCoat>* dynArrayRepo = this->getRepository()->getDynArr();
    this->availableSizeCoats->empty();
    if (size == "") {
        for (int index = 0; index < dynArrayRepo->getSize(); index++)
            this->availableSizeCoats->add(dynArrayRepo->getData()[index]);
    }
    else {
        for (int index = 0; index < dynArrayRepo->getSize(); index++)
            if (dynArrayRepo->getData()[index].getSize() == size)
                availableSizeCoats->add(dynArrayRepo->getData()[index]);
    }
}

void UserService::update_basket(int index) {
    this->basket->add(this->availableSizeCoats->getData()[index]);
    this->update_quantity_userService(this->getAvailableSizeCoats()->getData()[index].getSize(), this->getAvailableSizeCoats()->getData()[index].getColor(), this->getAvailableSizeCoats()->getData()[index].getQuantity() - 1, this->getAvailableSizeCoats()->getData()[index].getPhotograph());
    trenchCoat newCoat(this->availableSizeCoats->getData()[index].getSize(), this->availableSizeCoats->getData()[index].getColor(), this->availableSizeCoats->getData()[index].getPrice(), this->availableSizeCoats->getData()[index].getQuantity() - 1, this->availableSizeCoats->getData()[index].getPhotograph());
    this->availableSizeCoats->update(index, newCoat);
}

void UserService::delete_quantity_zero(int index) {
    this->delete_userService(this->availableSizeCoats->getData()[index].getSize(), this->availableSizeCoats->getData()[index].getColor(), this->availableSizeCoats->getData()[index].getPhotograph());
    this->availableSizeCoats->delete_(index);
}

void UserService::delete_userService(string size, string color, string photograph) {
    this->repository->delete_repo(size, color, photograph) == 0;

}

void UserService::update_quantity_userService(string size, string color, int quantity, string photograph) {
    this->repository->update_quantity_repo(size, color, quantity, photograph) == 0;
}

Repository* UserService::getRepository() {
    return this->repository;
}

dynamicArray<trenchCoat>* UserService::getAvailableSizeCoats() {
    return this->availableSizeCoats;
}

dynamicArray<trenchCoat>* UserService::getBasket() {
    return this->basket;
}

int *UserService::getTotalPrice() {
    return &(this->totalPrice);
}

void UserService::setTotalPrice(int value) {
    this->totalPrice = value;
}

UserService::~UserService() {
    delete this->availableSizeCoats;
    delete this->basket;
}

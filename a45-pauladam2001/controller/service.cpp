//
// Created by paul on 3/20/2021.
//

#include "service.h"


//Service::Service() {
//
//}

Service::Service(Repository *repository) {
    this->repository = repository;
}

Repository* Service::getRepository() {
    return this->repository;
}

int Service::add_service(string size, string color, int price, int quantity, string photograph) {
    if (this->repository->add_repo(size, color, price, quantity, photograph) == 0)
        return 0;
    return 1;
}

int Service::delete_service(string size, string color, string photograph) {
    if (this->repository->delete_repo(size, color, photograph) == 0)
        return 0;
    return 1;
}

int Service::update_price_service(string size, string color, int price, string photograph) {
    if (this->repository->update_price_repo(size, color, price, photograph) == 0)
        return 0;
    return 1;
}

int Service::update_quantity_service(string size, string color, int quantity, string photograph) {
    if (this->repository->update_quantity_repo(size, color, quantity, photograph) == 0)
        return 0;
    return 1;
}

Service::~Service() {
    delete this->repository;
}

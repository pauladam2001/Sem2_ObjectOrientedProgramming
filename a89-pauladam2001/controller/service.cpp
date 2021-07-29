//
// Created by paul on 3/20/2021.
//

#include "service.h"


//Service::Service() {
//
//}

Service::Service(Repository &repository):repository{repository} {

}

Repository& Service::getRepository() {
    return this->repository;
}

void Service::add_service(const string& size, const string& color, int price, int quantity, const string& photograph) {
    this->repository.add_repo(size, color, price, quantity, photograph);
}

void Service::delete_service(const string& size, const string& color, const string& photograph) {
    this->repository.delete_repo(size, color, photograph);
}

void Service::update_price_service(const string& size, const string& color, int price, const string& photograph) {
    this->repository.update_price_repo(size, color, price, photograph);
}

void Service::update_quantity_service(const string& size, const string& color, int quantity, const string& photograph) {
    this->repository.update_quantity_repo(size, color, quantity, photograph);
}

Service::~Service() = default;

//
// Created by paul on 3/20/2021.
//

#include "service.h"
#include "../exceptions/customExceptions.h"


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
    trenchCoat coat(size, color, price, quantity, photograph);
//    Action* currentAction = new AddAction(this->repository, coat);
    std::unique_ptr<Action> currentAction = std::make_unique<AddAction>(this->repository, coat);
//    this->undoAdminStack.push_back(currentAction);
    this->undoAdminStack.push_back(std::move(currentAction));
    this->redoAdminStack.clear();
}

void Service::delete_service(const string& size, const string& color, const string& photograph) {
    trenchCoat coat = this->repository.getCoat(size, color, photograph);
    this->repository.delete_repo(size, color, photograph);
//    Action* currentAction = new DeleteAction(this->repository, coat);
    std::unique_ptr<Action> currentAction = std::make_unique<DeleteAction>(this->repository, coat);
//    this->undoAdminStack.push_back(currentAction);
    this->undoAdminStack.push_back(std::move(currentAction));
    this->redoAdminStack.clear();
}

void Service::update_price_service(const string& size, const string& color, int price, const string& photograph) {
    trenchCoat oldCoat = this->repository.getCoat(size, color, photograph);
    this->repository.update_price_repo(size, color, price, photograph);
    trenchCoat newCoat = this->repository.getCoat(size, color, photograph);
//    Action* currentAction = new UpdatePriceAction(this->repository, oldCoat, newCoat);
    std::unique_ptr<Action> currentAction = std::make_unique<UpdatePriceAction>(this->repository, oldCoat, newCoat);
//    this->undoAdminStack.push_back(currentAction);
    this->undoAdminStack.push_back(std::move(currentAction));
    this->redoAdminStack.clear();
}

void Service::update_quantity_service(const string& size, const string& color, int quantity, const string& photograph) {
    trenchCoat oldCoat = this->repository.getCoat(size, color, photograph);
    this->repository.update_quantity_repo(size, color, quantity, photograph);
    trenchCoat newCoat = this->repository.getCoat(size, color, photograph);
//    Action* currentAction = new UpdateQuantityAction(this->repository, oldCoat, newCoat);
    std::unique_ptr<Action> currentAction = std::make_unique<UpdateQuantityAction>(this->repository, oldCoat, newCoat);
//    this->undoAdminStack.push_back(currentAction);
    this->undoAdminStack.push_back(std::move(currentAction));
    this->redoAdminStack.clear();
}

void Service::undo_admin() {
    if (this->undoAdminStack.empty())
        throw ServiceException("Can't undo anymore!");

//    Action* currentAction = this->undoAdminStack.back();
    std::unique_ptr<Action> currentAction = std::move(this->undoAdminStack.back());
    currentAction->undo();
//    this->redoAdminStack.push_back(currentAction);
    this->redoAdminStack.push_back(std::move(currentAction));
    this->undoAdminStack.pop_back();
}

void Service::redo_admin() {
    if (this->redoAdminStack.empty())
        throw ServiceException("Can't redo anymore!");

//    Action* currentAction = this->redoAdminStack.back();
    std::unique_ptr<Action> currentAction = std::move(this->redoAdminStack.back());
    currentAction->redo();
//    this->undoAdminStack.push_back(currentAction);
    this->undoAdminStack.push_back(std::move(currentAction));
    this->redoAdminStack.pop_back();
}

Service::~Service() = default;

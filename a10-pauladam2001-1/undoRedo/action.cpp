//
// Created by paul on 5/25/2021.
//

#include "action.h"


AddAction::AddAction(Repository &repository, const trenchCoat& trenchCoatAdded): repository{repository}, trenchCoatAdded{trenchCoatAdded} {

}

void AddAction::undo() {
    this->repository.delete_repo(this->trenchCoatAdded.getSize(), this->trenchCoatAdded.getColor(), this->trenchCoatAdded.getPhotograph());
}

void AddAction::redo() {
    this->repository.add_repo(this->trenchCoatAdded.getSize(), this->trenchCoatAdded.getColor(), this->trenchCoatAdded.getPrice(), this->trenchCoatAdded.getQuantity(), this->trenchCoatAdded.getPhotograph());
}


DeleteAction::DeleteAction(Repository &repository, const trenchCoat& trenchCoatDeleted): repository{repository}, trenchCoatDeleted{trenchCoatDeleted} {

}

void DeleteAction::undo() {
    this->repository.add_repo(this->trenchCoatDeleted.getSize(), this->trenchCoatDeleted.getColor(), this->trenchCoatDeleted.getPrice(), this->trenchCoatDeleted.getQuantity(), this->trenchCoatDeleted.getPhotograph());
}

void DeleteAction::redo() {
    this->repository.delete_repo(this->trenchCoatDeleted.getSize(), this->trenchCoatDeleted.getColor(), this->trenchCoatDeleted.getPhotograph());
}


UpdatePriceAction::UpdatePriceAction(Repository &repository, const trenchCoat& oldTrenchCoat, const trenchCoat& newTrenchCoat): repository{repository}, oldTrenchCoat{oldTrenchCoat}, newTrenchCoat{newTrenchCoat} {

}

void UpdatePriceAction::undo() {
    this->repository.update_price_repo(this->oldTrenchCoat.getSize(), this->oldTrenchCoat.getColor(), this->oldTrenchCoat.getPrice(), this->oldTrenchCoat.getPhotograph());
}

void UpdatePriceAction::redo() {
    this->repository.update_price_repo(this->newTrenchCoat.getSize(), this->newTrenchCoat.getColor(), this->newTrenchCoat.getPrice(), this->newTrenchCoat.getPhotograph());
}


UpdateQuantityAction::UpdateQuantityAction(Repository &repository, const trenchCoat& oldTrenchCoat, const trenchCoat& newTrenchCoat): repository{repository}, oldTrenchCoat{oldTrenchCoat}, newTrenchCoat{newTrenchCoat} {

}

void UpdateQuantityAction::undo() {
    this->repository.update_quantity_repo(this->oldTrenchCoat.getSize(), this->oldTrenchCoat.getColor(), this->oldTrenchCoat.getQuantity(), this->oldTrenchCoat.getPhotograph());
}

void UpdateQuantityAction::redo() {
    this->repository.update_quantity_repo(this->newTrenchCoat.getSize(), this->newTrenchCoat.getColor(), this->newTrenchCoat.getQuantity(), this->newTrenchCoat.getPhotograph());
}

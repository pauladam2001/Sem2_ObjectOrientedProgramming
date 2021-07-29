//
// Created by paul on 5/25/2021.
//

#ifndef A10_PAULADAM2001_1_ACTION_H
#define A10_PAULADAM2001_1_ACTION_H

#include "repository.h"
#include "trenchCoat.h"


class Action {

public:
    virtual void undo() = 0;

    virtual void redo() = 0;
};

class AddAction : public Action {

private:
    Repository& repository;
    trenchCoat trenchCoatAdded;

public:
    AddAction(Repository& repository, const trenchCoat& trenchCoatAdded);

    void undo() override;

    void redo() override;

//    ~AddAction() = default;
};

class DeleteAction : public Action {

private:
    Repository& repository;
    trenchCoat trenchCoatDeleted;

public:
    DeleteAction(Repository& repository, const trenchCoat& trenchCoatDeleted);

    void undo() override;

    void redo() override;

//    ~DeleteAction() = default;
};

class UpdatePriceAction : public Action {

private:
    Repository& repository;
    trenchCoat oldTrenchCoat;
    trenchCoat newTrenchCoat;

public:
    UpdatePriceAction(Repository& repository, const trenchCoat& oldTrenchCoat, const trenchCoat& newTrenchCoat);

    void undo() override;

    void redo() override;

//    ~UpdatePriceAction() = default;
};

class UpdateQuantityAction : public Action {

private:
    Repository& repository;
    trenchCoat oldTrenchCoat;
    trenchCoat newTrenchCoat;

public:
    UpdateQuantityAction(Repository& repository, const trenchCoat& oldTrenchCoat, const trenchCoat& newTrenchCoat);

    void undo() override;

    void redo() override;

//    ~UpdateQuantityAction() = default;
};


#endif //A10_PAULADAM2001_1_ACTION_H

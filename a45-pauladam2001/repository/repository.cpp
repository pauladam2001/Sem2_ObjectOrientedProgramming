//
// Created by paul on 3/20/2021.
//

#include "repository.h"

//Repository::Repository() {
//
//}

Repository::Repository(dynamicArray<trenchCoat> *dynArray) {
    this->dynArray = dynArray;
}

void Repository::add_10_elements() {
    add_repo("XS", "blue", 120, 2, "https://bluexs.ro");
    add_repo("S", "brown", 70, 3, "https://browns.ro");
    add_repo("XS", "red", 130, 2, "https://redxs.ro");
    add_repo("XXL", "grey", 60, 25, "https://greyxxl.ro");
    add_repo("XS", "green", 80, 2, "https://greenxs.ro");
    add_repo("L", "black", 150, 7, "https://blackl.ro");
    add_repo("M", "white", 150, 10, "https://whitem.ro");
    add_repo("M", "black", 150, 9, "https://blackm.ro");
    add_repo("S", "yellow", 50, 15, "https://yellows.ro");
    add_repo("XL", "orange", 100, 50, "https://orangexl.ro");
}

dynamicArray<trenchCoat> *Repository::getDynArr() {
    return this->dynArray;
}

int Repository::add_repo(string size, string color, int price, int quantity, string photograph) {
    int inRepo = this->search_in_repository(size, color, photograph);
    if (inRepo != -1)
        return 0;   // the coat is already in the repository
    else {
        trenchCoat newCoat(size, color, price, quantity, photograph);
        this->dynArray->add(newCoat);
        return 1;
    }
}

int Repository::delete_repo(string size, string color, string photograph) {
    int inRepo = this->search_in_repository(size, color, photograph);
    if (inRepo == -1 || (*this->dynArray)[inRepo].getQuantity() != 0)
        return 0;
    else {
        this->dynArray->delete_(inRepo);
        return 1;
    }
}

int Repository::update_price_repo(string size, string color, int price, string photograph) {
    int inRepo = search_in_repository(size, color, photograph);
    if (inRepo == -1)
        return 0;
    else {
        trenchCoat newCoat(size, color, price, (*this->dynArray)[inRepo].getQuantity(), photograph);
        this->dynArray->update(inRepo, newCoat);
        return 1;
    }
}

int Repository::update_quantity_repo(string size, string color, int quantity, string photograph) {
    int inRepo = search_in_repository(size, color, photograph);
    if (inRepo == -1)
        return 0;
    else {
        trenchCoat newCoat(size, color, (*this->dynArray)[inRepo].getPrice(), quantity, photograph);
        this->dynArray->update(inRepo, newCoat);
        return 1;
    }
}

int Repository::search_in_repository(string size, string color, string photograph) {
    int index;
    for (index = 0; index < this->dynArray->getSize(); index++) {
        if ((*this->dynArray)[index].getSize() == size && (*this->dynArray)[index].getColor() == color && (*this->dynArray)[index].getPhotograph() == photograph)
            return index;
    }
    return -1;
}

Repository::~Repository() {
    delete this->dynArray;
}

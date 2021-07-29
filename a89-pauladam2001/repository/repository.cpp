//
// Created by paul on 3/20/2021.
//

#include "repository.h"
#include "../exceptions/customExceptions.h"


Repository::Repository() = default;

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

vector<trenchCoat> Repository::getDynArr() {
    return this->dynArray;
}

void Repository::add_repo(const string& size, const string& color, int price, int quantity, const string& photograph) {
    int inRepo = this->search_in_repository(size, color, photograph);
    if (inRepo != -1)
        throw(RepositoryException("Trench coat already exists!"));
    else {
        trenchCoat newCoat(size, color, price, quantity, photograph);
        this->dynArray.push_back(newCoat);
    }
}

void Repository::delete_repo(const string& size, const string& color, const string& photograph) {
    int inRepo = this->search_in_repository(size, color, photograph);
    if (inRepo == -1 || this->dynArray[inRepo].getQuantity() != 0)
        throw(RepositoryException("The coat does not exist or its quantity is not 0!"));
    else {
        this->dynArray.erase(this->dynArray.begin() + inRepo);
    }
}

void Repository::update_price_repo(const string& size, const string& color, int price, const string& photograph) {
    int inRepo = search_in_repository(size, color, photograph);
    if (inRepo == -1)
        throw(RepositoryException("The coat does not exist!"));
    else {
        trenchCoat newCoat(size, color, price, this->dynArray[inRepo].getQuantity(), photograph);
        this->dynArray.at(inRepo) = newCoat;
    }
}

void Repository::update_quantity_repo(const string& size, const string& color, int quantity, const string& photograph) {
    int inRepo = search_in_repository(size, color, photograph);
    if (inRepo == -1)
        throw(RepositoryException("The coat does not exist!"));
    else {
        trenchCoat newCoat(size, color, this->dynArray[inRepo].getPrice(), quantity, photograph);
        this->dynArray[inRepo] = newCoat;
    }
}

int Repository::search_in_repository(const string& size, const string& color, const string& photograph) {
    int index = 0;
    for(auto& element: this->dynArray) {
        if (element.getSize() == size && element.getColor() == color && element.getPhotograph() == photograph)
            break;
        index++;
    }
    if (index == this->dynArray.size())
        return -1;
    return index;
}

Repository::~Repository() = default;

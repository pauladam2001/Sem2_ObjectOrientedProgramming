//
// Created by paul on 4/4/2021.
//

#include <fstream>
#include <utility>
#include "fileRepository.h"
#include "../exceptions/customExceptions.h"

using namespace std;


FileRepository::FileRepository(string fileName):fileName{std::move(fileName)} {
    this->dynArray = this->load_from_file();
//    this->fileName = fileName;
//    this->create_file(fileName);
//    std::ofstream outFile(fileName);
//    outFile << "a";
}

//bool FileRepository::create_file(const string& file_name) {
//    FILE* currFile;
//    currFile = fopen(file_name.c_str(), "w");
//    if (currFile == nullptr) {
//        return false;
//    }
//    fclose(currFile);
//    return true;
//}

vector<trenchCoat> FileRepository::load_from_file() {
    std::ifstream inFile(this->fileName);
    trenchCoat currentCoat;
    std::vector<trenchCoat> all_entries;
    if (!inFile.is_open())
        throw RepositoryException("Could not open the file!");
    while (inFile >> currentCoat) {                     // if we want another separator instead of space (like ,) we can use std::getline() (see overload for >> in entity)
        all_entries.push_back(currentCoat);
    }
    inFile.close();
    return all_entries;
}

void FileRepository::write_in_file() {
    std::ofstream outFile(this->fileName);
    if (!outFile.is_open())
        throw RepositoryException("Could not open the file!");
    for (const auto& currentCoat: this->dynArray) {
        outFile << currentCoat << "\n";
    }
    outFile.close();
}

void FileRepository::add_repo(const string &size, const string &color, int price, int quantity, const string &photograph) {
    int inRepo = this->search_in_repository(size, color, photograph);
    if (inRepo != -1)
        throw(RepositoryException("Trench coat already exists!"));
    else {
        trenchCoat newCoat(size, color, price, quantity, photograph);
        this->dynArray.push_back(newCoat);
        this->write_in_file();
    }
}

void FileRepository::delete_repo(const string &size, const string &color, const string &photograph) {
    int inRepo = this->search_in_repository(size, color, photograph);
//    if (inRepo == -1 || this->dynArray[inRepo].getQuantity() != 0)
    if (inRepo == -1)
        throw(RepositoryException("The coat does not exist!"));
//        throw(RepositoryException("The coat does not exist or its quantity is not 0!"));
    else {
        this->dynArray.erase(this->dynArray.begin() + inRepo);
        this->write_in_file();
    }
}

void FileRepository::update_price_repo(const string &size, const string &color, int price, const string &photograph) {
    int inRepo = search_in_repository(size, color, photograph);
    if (inRepo == -1)
        throw(RepositoryException("The coat does not exist!"));
    else {
        trenchCoat newCoat(size, color, price, this->dynArray[inRepo].getQuantity(), photograph);
        this->dynArray.at(inRepo) = newCoat;
        this->write_in_file();
    }
}

void FileRepository::update_quantity_repo(const string &size, const string &color, int quantity, const string &photograph) {
    int inRepo = search_in_repository(size, color, photograph);
    if (inRepo == -1)
        throw(RepositoryException("The coat does not exist!"));
    else {
        trenchCoat newCoat(size, color, this->dynArray[inRepo].getPrice(), quantity, photograph);
        this->dynArray[inRepo] = newCoat;
        this->write_in_file();
    }
}

int FileRepository::search_in_repository(const string &size, const string &color, const string &photograph) {
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

vector<trenchCoat> FileRepository::getDynArr() {
    vector<trenchCoat> newArray;
    newArray.reserve(this->dynArray.size());
    for (const auto & element : this->dynArray) {
        newArray.push_back(element);
    }
    return newArray;
}

trenchCoat FileRepository::getCoat(const string &size, const string &color, const string &photograph) {
    int inRepo = search_in_repository(size, color, photograph);
    if (inRepo == -1)
        throw(RepositoryException("The coat does not exist!"));
    else
        return this->dynArray[inRepo];
}

FileRepository::~FileRepository() = default;

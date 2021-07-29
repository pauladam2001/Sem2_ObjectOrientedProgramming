//
// Created by paul on 3/20/2021.
//

#ifndef A45_PAULADAM2001_REPOSITORY_H
#define A45_PAULADAM2001_REPOSITORY_H

#include "dynamicArray.h"
#include "trenchCoat.h"


class Repository {
private:

    dynamicArray<trenchCoat>* dynArray;

public:

//    /// Constructor
//    Repository();

    /// Constructor
    /// \param dynArray - the dynamic array
    Repository(dynamicArray<trenchCoat>* dynArray);

    /// Add 10 elements at program startup
    void add_10_elements();

    /// Get the dynamic array
    /// \return - the dynamic array
    dynamicArray<trenchCoat> *getDynArr();

    /// Add a trench coat in the repository
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param price - the price of the trench coat
    /// \param quantity - the quantity of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was added, 0 otherwise
    int add_repo(string size, string color, int price, int quantity, string photograph);

    /// Delete a trench coat from the repository
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was deleted, 0 otherwise
    int delete_repo(string size, string color, string photograph);

    /// Update the price of a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param price - the new price of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was updated, 0 otherwise
    int update_price_repo(string size, string color, int price, string photograph);

    /// Update the quantity of a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param quantity - the new quantity of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was updated, 0 otherwise
    int update_quantity_repo(string size, string color, int quantity, string photograph);

    /// Search if a trench coat is in the repository
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - the position where the trench coat is found, -1 otherwise
    int search_in_repository(string size, string color, string photograph);

    /// Destructor
    ~Repository();
};


#endif //A45_PAULADAM2001_REPOSITORY_H

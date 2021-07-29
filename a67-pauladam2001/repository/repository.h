//
// Created by paul on 3/20/2021.
//

#ifndef A45_PAULADAM2001_REPOSITORY_H
#define A45_PAULADAM2001_REPOSITORY_H

//#include "dynamicArray.h"
#include "trenchCoat.h"
#include <vector>


class Repository {
protected:

    vector<trenchCoat> dynArray{};

public:

    /// Constructor
    Repository();

    /// Add 10 elements at program startup
    void add_10_elements();

     /// Get the dynamic array
    /// \return - the dynamic array
    virtual vector<trenchCoat> getDynArr() = 0;

    /// Add a trench coat in the repository
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param price - the price of the trench coat
    /// \param quantity - the quantity of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was added, 0 otherwise
    virtual void add_repo(const string& size, const string& color, int price, int quantity, const string& photograph) = 0;

    /// Delete a trench coat from the repository
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was deleted, 0 otherwise
    virtual void delete_repo(const string& size, const string& color, const string& photograph) = 0;

    /// Update the price of a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param price - the new price of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was updated, 0 otherwise
    virtual void update_price_repo(const string& size, const string& color, int price, const string& photograph) = 0;

    /// Update the quantity of a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param quantity - the new quantity of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was updated, 0 otherwise
    virtual void update_quantity_repo(const string& size, const string& color, int quantity, const string& photograph) = 0;

    /// Search if a trench coat is in the repository
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - the position where the trench coat is found, -1 otherwise
    virtual int search_in_repository(const string& size, const string& color, const string& photograph) = 0;

    /// Destructor
    virtual ~Repository();
};


#endif //A45_PAULADAM2001_REPOSITORY_H

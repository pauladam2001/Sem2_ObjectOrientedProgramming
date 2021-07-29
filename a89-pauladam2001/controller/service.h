//
// Created by paul on 3/20/2021.
//

#ifndef A45_PAULADAM2001_SERVICE_H
#define A45_PAULADAM2001_SERVICE_H

#include "trenchCoat.h"
#include "dynamicArray.h"
#include "repository.h"


class Service {
private:

    Repository& repository;

public:

//    /// Constructor
//    Service();

    /// Constructor
    /// \param repository - the repository
    explicit Service(Repository& repository);

    /// Add a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param price - the price of the trench coat
    /// \param quantity - the quantity of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was added, 0 otherwise
    void add_service(const string& size, const string& color, int price, int quantity, const string& photograph);

    /// Delete a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was deleted, 0 otherwise
    void delete_service(const string& size, const string& color, const string& photograph);

    /// Update the price of a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param price - the new price of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was updated, 0 otherwise
    void update_price_service(const string& size, const string& color, int price, const string& photograph);

    /// Update the quantity of a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param quantity - the new quantity of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was updated, 0 otherwise
    void update_quantity_service(const string& size, const string& color, int quantity, const string& photograph);

    /// Get the repository
    /// \return - the repository
    Repository& getRepository();

    /// Destructor
    ~Service();
};


#endif //A45_PAULADAM2001_SERVICE_H

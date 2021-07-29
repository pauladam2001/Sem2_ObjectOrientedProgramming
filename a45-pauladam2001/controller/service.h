//
// Created by paul on 3/20/2021.
//

#ifndef A45_PAULADAM2001_SERVICE_H
#define A45_PAULADAM2001_SERVICE_H

#include "repository.h"


class Service {
private:

    Repository* repository;

public:

//    /// Constructor
//    Service();

    /// Constructor
    /// \param repository - the repository
    Service(Repository* repository);

    /// Add a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param price - the price of the trench coat
    /// \param quantity - the quantity of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was added, 0 otherwise
    int add_service(string size, string color, int price, int quantity, string photograph);

    /// Delete a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was deleted, 0 otherwise
    int delete_service(string size, string color, string photograph);

    /// Update the price of a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param price - the new price of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was updated, 0 otherwise
    int update_price_service(string size, string color, int price, string photograph);

    /// Update the quantity of a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param quantity - the new quantity of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - 1 if the trench coat was updated, 0 otherwise
    int update_quantity_service(string size, string color, int quantity, string photograph);

    /// Get the repository
    /// \return - the repository
    Repository* getRepository();

    /// Destructor
    ~Service();
};


#endif //A45_PAULADAM2001_SERVICE_H

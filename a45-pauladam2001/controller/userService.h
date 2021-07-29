//
// Created by paula on 3/24/2021.
//

#ifndef A45_PAULADAM2001_USERSERVICE_H
#define A45_PAULADAM2001_USERSERVICE_H

#include "repository.h"


class UserService {
private:

    Repository* repository;
    dynamicArray<trenchCoat>* availableSizeCoats;
    dynamicArray<trenchCoat>* basket;
    int totalPrice;

public:

    /// Constructor
    /// \param repository - the repository
    UserService(Repository* repository);

    /// Add in the available coats array the coats of the given size from the repository
    /// \param size - the given size
    void available_size_coats(string size);

    /// Get the repository
    /// \return - the repository
    Repository* getRepository();

    /// Get the available coats array
    /// \return - the available coats array
    dynamicArray<trenchCoat>* getAvailableSizeCoats();

    /// Add a coat to the basket and decrease its quantity in the repository and in the available coats
    /// \param index - the position where the coat is found
    void update_basket(int index);

    /// Delete a coat from the repository and from the available coats if the quantity is zero
    /// \param index - the position where the coat is found
    void delete_quantity_zero(int index);

    /// Delete a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    void delete_userService(string size, string color, string photograph);

    /// Update the quantity of a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param quantity - the new quantity of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    void update_quantity_userService(string size, string color, int quantity, string photograph);

    /// Get the basket
    /// \return - the basket
    dynamicArray<trenchCoat>* getBasket();

    /// Get the total price
    /// \return - the total price
    int *getTotalPrice();

    /// Give a new value to the total price
    /// \param value - the new price
    void setTotalPrice(int value);

    /// Destructor
    ~UserService();
};


#endif //A45_PAULADAM2001_USERSERVICE_H

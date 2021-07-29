//
// Created by paula on 3/24/2021.
//

#ifndef A45_PAULADAM2001_USERSERVICE_H
#define A45_PAULADAM2001_USERSERVICE_H

#include "repository.h"
#include <vector>


class UserService {
private:

    Repository& repository;
    vector<trenchCoat> availableSizeCoats{};
    vector<trenchCoat> basket{};
    int totalPrice;

public:

    /// Constructor
    /// \param repository - the repository
    explicit UserService(Repository& repository);

    /// Add in the available coats array the coats of the given size from the repository
    /// \param size - the given size
    void available_size_coats(const string& size);

    /// Get the repository
    /// \return - the repository
    Repository& getRepository();

    /// Get the available coats array
    /// \return - the available coats array
    vector<trenchCoat> getAvailableSizeCoats();

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
    void delete_userService(const string& size, const string& color, const string& photograph);

    /// Update the quantity of a trench coat
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param quantity - the new quantity of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    void update_quantity_userService(const string& size, const string& color, int quantity, const string& photograph);

    /// Get the basket
    /// \return - the basket
    vector<trenchCoat> getBasket();

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

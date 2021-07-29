//
// Created by paul on 3/20/2021.
//

#ifndef A45_PAULADAM2001_VALIDATORS_H
#define A45_PAULADAM2001_VALIDATORS_H

#include <string>
using namespace std;


class Validator {
public:
    /// Validate the price or the quantity of the trench coat
    /// \param priceOrQuantity - the price or the quantity of the trench coat
    /// \return - 1 if the price or quantity is valid, 0 otherwise
    static void validate_price_or_quantity(const string& priceOrQuantity);

    /// Validate the size of the trench coat
    /// \param size - the size of the trench coat
    /// \return - true if the size is valid, 0 otherwise
    static void validate_size(const string& size);

    /// Validate the color of the trench coat
    /// \param color - the color of the trench coat
    /// \return - true if the color is valid, 0 otherwise
    static void validate_color(const string& color);

    /// Validate the photograph of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    /// \return - true if the link to the photograph is valid, 0 otherwise
    static void validate_photograph(string photograph);
};


#endif //A45_PAULADAM2001_VALIDATORS_H

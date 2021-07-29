//
// Created by paul on 3/20/2021.
//

#include "validators.h"
#include "../exceptions/customExceptions.h"

#include <cctype>
#include <string>

using namespace std;


void Validator::validate_price_or_quantity(const string& priceOrQuantity) {
    for (char index: priceOrQuantity)
        if (isalpha(index))
            throw ValidatorException("Invalid parameters!");
//    int newPrice = stoi(priceOrQuantity);
}

void Validator::validate_size(const string& size) {
    if (size != "XXS" && size != "XS" && size != "S" && size != "M" && size != "L" && size != "XL" && size != "XXL")
        throw ValidatorException("Invalid parameters!");
}

void Validator::validate_color(const string& color) {
    for (char index: color)
        if (isdigit(index))
            throw ValidatorException("Invalid parameters!");
}

void Validator::validate_photograph(string photograph) {
    if (photograph.length() < 12)       // https://*.ro
        throw ValidatorException("Invalid parameters!");
    if (photograph[0] != 'h' || photograph[1] != 't' || photograph[2] != 't' || photograph[3] != 'p' || photograph[4] != 's' || photograph[5] != ':' ||
    photograph[6] != '/' || photograph[7] != '/')
        throw ValidatorException("Invalid parameters!");
    if (photograph[photograph.length() - 1] != 'o' || photograph[photograph.length() - 2] != 'r' || photograph[photograph.length() - 3] != '.')
        throw ValidatorException("Invalid parameters!");
}

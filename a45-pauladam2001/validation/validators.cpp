//
// Created by paul on 3/20/2021.
//

#include "validators.h"

#include <cctype>
#include <string>

using namespace std;


int Validator::validate_price_or_quantity(string priceOrQuantity) {
    for (char index: priceOrQuantity)
        if (isalpha(index))
            return 0;
//    int newPrice = stoi(priceOrQuantity);
    return 1;
}

bool Validator::validate_size(string size) {
    if (size != "XXS" && size != "XS" && size != "S" && size != "M" && size != "L" && size != "XL" && size != "XXL")
        return false;
    return true;
}

bool Validator::validate_color(string color) {
    for (char index: color)
        if (isdigit(index))
            return false;
    return true;
}

bool Validator::validate_photograph(string photograph) {
    if (photograph.length() < 12)       // https://*.ro
        return false;
    if (photograph[0] != 'h' || photograph[1] != 't' || photograph[2] != 't' || photograph[3] != 'p' || photograph[4] != 's' || photograph[5] != ':' ||
    photograph[6] != '/' || photograph[7] != '/')
        return false;
    if (photograph[photograph.length() - 1] != 'o' || photograph[photograph.length() - 2] != 'r' || photograph[photograph.length() - 3] != '.')
        return false;
    return true;
}

//
// Created by paul on 3/20/2021.
//

#ifndef A45_PAULADAM2001_TRENCHCOAT_H
#define A45_PAULADAM2001_TRENCHCOAT_H

#include <string>
using namespace std;


class trenchCoat {
private:

    string size;
    string color;
    int price{};
    int quantity{};
    string photograph;

public:

    /// Constructor
    trenchCoat();

    /// Constructor
    /// \param size - the size of the trench coat
    /// \param color - the color of the trench coat
    /// \param price - the price of the trench coat
    /// \param quantity - the quantity of the trench coat
    /// \param photograph - the link to the photograph of the trench coat
    trenchCoat(const string& size, const string& color, int price, int quantity, const string& photograph);

    trenchCoat(const trenchCoat&);

    trenchCoat& operator=(const trenchCoat&);

    bool operator==(const trenchCoat&) const;

    friend std::ostream& operator<<(std::ostream&, const trenchCoat&);

    friend std::istream& operator>>(std::istream&, trenchCoat&);

    /// Get the size of the trench coat
    /// \return - the size of the trench coat
    string getSize() const;

    /// Get the color of the trench coat
    /// \return - the color of the trench coat
    string getColor() const;

    /// Get the price of the trench coat
    /// \return - the price of the trench coat
    int getPrice() const;

    /// Get the quantity of the trench coat
    /// \return - the quantity of the trench coat
    int getQuantity() const;

    /// Get the photograph of the trench coat
    /// \return - the photograph of the trench coat
    string getPhotograph() const;

//    void setPrice(int value);
//
//    void setQuantity(int value);

    /// Transform the attributes into a char (used for printing)
    /// \param stringParam the attributes transformed in char
    void to_string(char stringParam[]);

    std::string getCSVRepresentation();

    std::string getHTMLRepresentation();

    /// Destructor
    ~trenchCoat();
};


#endif //A45_PAULADAM2001_TRENCHCOAT_H

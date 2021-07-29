//
// Created by paul on 3/1/2021.
//

#ifndef A23_PAULADAM2001_MEDICINE_H
#define A23_PAULADAM2001_MEDICINE_H

typedef struct {
    char name[100];
    int concentration;
    int quantity;
    int price;
} Medicine;


Medicine init_medicine(char* name, int concentration, int quantity, int price);
/*
 * Creates a new medicine with the given parameters
 * Input: - name = string; the name of the medicine
 *        - concentration = integer; the concentration of the medicine
 *        - quantity = integer; the quantity stored
 *        - price = integer; the price for the medicine
 * Output: A new object of type Medicine
 */

void to_string(Medicine med, char string[]);
/*
 * Stores in string the output instead of printing it to the console
 * Input: - med = an object of type Medicine
 *        - string - the string where we will store the output
 * Output: None
 */

char* getName(Medicine* med);
int getConcentration(Medicine* med);
int getQuantity(Medicine* med);
int getPrice(Medicine* med);
void setQuantityPlus(Medicine* med, int newQuantity);
void setQuantity(Medicine* med, int newQuantity);
void setPrice(Medicine* med, int newPrice);


#endif //A23_PAULADAM2001_MEDICINE_H

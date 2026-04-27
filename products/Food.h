#ifndef FOOD_H
#define FOOD_H

#include "Product.h"

class Food : public Product {
private:
    string expiryDate;
    int weightGrams;

public:
    Food();
    Food(int id, const string& name, double price, const string& expiry,
         int weight, const string& imageFile);

    string getExpiryDate() const;
    int getWeight() const;

    void displayDetails() const override;
    string getCategory() const override;
    string toFileString() const override;
};

#endif

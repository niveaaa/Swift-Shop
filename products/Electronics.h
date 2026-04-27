#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "Product.h"

class Electronics : public Product {
private:
    string brand;
    int warrantyMonths;

public:
    Electronics();
    Electronics(int id, const string& name, double price, const string& brand,
                int warranty, const string& imageFile);

    string getBrand() const;
    int getWarranty() const;

    void displayDetails() const override;
    string getCategory() const override;
    string toFileString() const override;
};

#endif

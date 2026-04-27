#ifndef CLOTHING_H
#define CLOTHING_H

#include "Product.h"

class Clothing : public Product {
private:
    string size;
    string material;

public:
    Clothing();
    Clothing(int id, const string& name, double price, const string& size,
             const string& material, const string& imageFile);

    string getSize() const;
    string getMaterial() const;

    void displayDetails() const override;
    string getCategory() const override;
    string toFileString() const override;
};

#endif

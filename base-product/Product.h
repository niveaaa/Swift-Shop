#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Product {
protected:
    int productId;
    string name;
    double price;
    string imageFile;

public:
    Product();
    Product(int id, const string& name, double price, const string& imageFile);
    virtual ~Product();

    int getId() const;
    string getName() const;
    double getPrice() const;
    string getImageFile() const;

    void viewImage() const;
    void displayRow() const;

    virtual void displayDetails() const;
    virtual string getCategory() const;
    virtual string toFileString() const;
};

#endif

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Product.h"

using namespace std;

class Customer {
private:
    string name;
    vector<pair<Product*, int>> cart;

public:
    Customer();
    Customer(const string& name);

    string getName() const;

    void addToCart(Product* product, int quantity = 1);
    void removeFromCart(int index);
    void viewCart() const;
    void clearCart();
    double getCartTotal() const;
    const vector<pair<Product*, int>>& getCart() const;
    bool isCartEmpty() const;
};

#endif

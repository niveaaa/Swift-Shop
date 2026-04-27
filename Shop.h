#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Product.h"
#include "Electronics.h"
#include "Clothing.h"
#include "Food.h"
#include "Order.h"
#include "Customer.h"

class Shop {
private:
    vector<Product*> products;
    vector<Order> orders;
    int nextOrderId;

    void loadProducts();
    void loadOrders();
    void createDefaultProducts();
    string getCurrentDate() const;

public:
    Shop();
    ~Shop();

    void listProducts() const;
    Product* getProduct(int id) const;
    void placeOrder(Customer& customer);
    void viewOrderHistory(const string& customerName) const;
};

#endif

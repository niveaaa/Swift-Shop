#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Order {
private:
    int orderId;
    string customerName;
    string date;
    vector<pair<string, int>> items;
    double totalPrice;

public:
    Order();
    Order(int id, const string& customer, const string& date,
          const vector<pair<string, int>>& items, double total);

    int getOrderId() const;
    string getCustomerName() const;

    void displayOrder() const;
    string toFileString() const;
    static Order fromFileString(const string& line);
};

#endif

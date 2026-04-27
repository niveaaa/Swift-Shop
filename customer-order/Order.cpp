#include "Order.h"

Order::Order() : orderId(0), customerName(""), date(""), totalPrice(0.0) {}

Order::Order(int id, const string& customer, const string& date,
             const vector<pair<string, int>>& items, double total)
    : orderId(id), customerName(customer), date(date), items(items), totalPrice(total) {}

int Order::getOrderId() const { return orderId; }
string Order::getCustomerName() const { return customerName; }

void Order::displayOrder() const {
    cout << "\nOrder #" << orderId << " | Date: " << date << endl;
    cout << "Items:" << endl;
    for (const auto& item : items) {
        cout << "  - " << item.first << " x" << item.second << endl;
    }
    cout << "Total: $" << fixed << setprecision(2) << totalPrice << endl;
}

string Order::toFileString() const {
    ostringstream oss;
    oss << orderId << "|" << customerName << "|" << date << "|";

    for (int i = 0; i < (int)items.size(); i++) {
        if (i > 0) oss << ",";
        oss << items[i].first << ":" << items[i].second;
    }

    oss << "|" << fixed << setprecision(2) << totalPrice;
    return oss.str();
}

Order Order::fromFileString(const string& line) {
    istringstream iss(line);
    string token;

    getline(iss, token, '|');
    int id = stoi(token);

    string customer;
    getline(iss, customer, '|');

    string date;
    getline(iss, date, '|');

    string itemsStr;
    getline(iss, itemsStr, '|');
    vector<pair<string, int>> items;

    istringstream itemStream(itemsStr);
    string itemToken;
    while (getline(itemStream, itemToken, ',')) {
        size_t colonPos = itemToken.rfind(':');
        if (colonPos != string::npos) {
            string name = itemToken.substr(0, colonPos);
            int qty = stoi(itemToken.substr(colonPos + 1));
            items.push_back(make_pair(name, qty));
        }
    }

    getline(iss, token, '|');
    double total = stod(token);

    return Order(id, customer, date, items, total);
}

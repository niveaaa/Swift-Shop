#include "Food.h"

Food::Food() : Product(), expiryDate(""), weightGrams(0) {}

Food::Food(int id, const string& name, double price, const string& expiry,
           int weight, const string& imageFile)
    : Product(id, name, price, imageFile), expiryDate(expiry), weightGrams(weight) {}

string Food::getExpiryDate() const { return expiryDate; }
int Food::getWeight() const { return weightGrams; }

void Food::displayDetails() const {
    Product::displayDetails();
    cout << "Category:    Food" << endl;
    cout << "Expiry Date: " << expiryDate << endl;
    cout << "Weight:      " << weightGrams << "g" << endl;
}

string Food::getCategory() const {
    return "Food";
}

string Food::toFileString() const {
    ostringstream oss;
    oss << fixed << setprecision(2);
    oss << getCategory() << "|" << productId << "|" << name << "|" << price
        << "|" << expiryDate << "|" << weightGrams << "|" << imageFile;
    return oss.str();
}

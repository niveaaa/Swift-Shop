#include "Product.h"
#include <cstdlib>

Product::Product() : productId(0), name(""), price(0.0), imageFile("") {}

Product::Product(int id, const string& name, double price, const string& imageFile)
    : productId(id), name(name), price(price), imageFile(imageFile) {}

Product::~Product() {}

int Product::getId() const { return productId; }
string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
string Product::getImageFile() const { return imageFile; }

void Product::viewImage() const {
    string command = "start images\\" + imageFile;
    system(command.c_str());
    cout << "Opening image..." << endl;
}

void Product::displayRow() const {
    cout << left << setw(6) << productId
         << setw(20) << name
         << setw(15) << getCategory()
         << "$" << fixed << setprecision(2) << price << endl;
}

void Product::displayDetails() const {
    cout << "\n--- Product Details ---" << endl;
    cout << "ID:          " << productId << endl;
    cout << "Name:        " << name << endl;
    cout << "Price:       $" << fixed << setprecision(2) << price << endl;
}

string Product::getCategory() const {
    return "General";
}

string Product::toFileString() const {
    ostringstream oss;
    oss << fixed << setprecision(2);
    oss << getCategory() << "|" << productId << "|" << name << "|" << price << "|" << imageFile;
    return oss.str();
}

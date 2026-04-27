#include "Clothing.h"

Clothing::Clothing() : Product(), size(""), material("") {}

Clothing::Clothing(int id, const string& name, double price, const string& size,
                   const string& material, const string& imageFile)
    : Product(id, name, price, imageFile), size(size), material(material) {}

string Clothing::getSize() const { return size; }
string Clothing::getMaterial() const { return material; }

void Clothing::displayDetails() const {
    Product::displayDetails();
    cout << "Category:    Clothing" << endl;
    cout << "Size:        " << size << endl;
    cout << "Material:    " << material << endl;
}

string Clothing::getCategory() const {
    return "Clothing";
}

string Clothing::toFileString() const {
    ostringstream oss;
    oss << fixed << setprecision(2);
    oss << getCategory() << "|" << productId << "|" << name << "|" << price
        << "|" << size << "|" << material << "|" << imageFile;
    return oss.str();
}

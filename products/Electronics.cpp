#include "Electronics.h"

Electronics::Electronics() : Product(), brand(""), warrantyMonths(0) {}

Electronics::Electronics(int id, const string& name, double price, const string& brand,
                         int warranty, const string& imageFile)
    : Product(id, name, price, imageFile), brand(brand), warrantyMonths(warranty) {}

string Electronics::getBrand() const { return brand; }
int Electronics::getWarranty() const { return warrantyMonths; }

void Electronics::displayDetails() const {
    Product::displayDetails();
    cout << "Category:    Electronics" << endl;
    cout << "Brand:       " << brand << endl;
    cout << "Warranty:    " << warrantyMonths << " months" << endl;
}

string Electronics::getCategory() const {
    return "Electronics";
}

string Electronics::toFileString() const {
    ostringstream oss;
    oss << fixed << setprecision(2);
    oss << getCategory() << "|" << productId << "|" << name << "|" << price
        << "|" << brand << "|" << warrantyMonths << "|" << imageFile;
    return oss.str();
}

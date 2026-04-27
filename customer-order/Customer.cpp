#include "Customer.h"

Customer::Customer() : name("") {}
Customer::Customer(const string& name) : name(name) {}

string Customer::getName() const { return name; }

void Customer::addToCart(Product* product, int quantity) {
    // Check if product already in cart
    for (auto& item : cart) {
        if (item.first->getId() == product->getId()) {
            item.second += quantity;
            cout << "Updated quantity of " << product->getName() << " in cart." << endl;
            return;
        }
    }
    cart.push_back(make_pair(product, quantity));
    cout << product->getName() << " added to cart." << endl;
}

void Customer::removeFromCart(int index) {
    if (index >= 0 && index < (int)cart.size()) {
        cout << cart[index].first->getName() << " removed from cart." << endl;
        cart.erase(cart.begin() + index);
    } else {
        cout << "Invalid item number." << endl;
    }
}

void Customer::viewCart() const {
    if (cart.empty()) {
        cout << "\nYour cart is empty." << endl;
        return;
    }

    cout << "\n--- Your Cart ---" << endl;
    cout << left << setw(6) << "No"
         << setw(20) << "Name"
         << setw(6) << "Qty"
         << setw(12) << "Price"
         << "Subtotal" << endl;
    cout << string(50, '-') << endl;

    int no = 1;
    for (const auto& item : cart) {
        double subtotal = item.first->getPrice() * item.second;
        cout << left << setw(6) << no
             << setw(20) << item.first->getName()
             << setw(6) << item.second
             << "$" << fixed << setprecision(2) << setw(11) << item.first->getPrice()
             << "$" << fixed << setprecision(2) << subtotal << endl;
        no++;
    }

    cout << string(50, '-') << endl;
    cout << "Total: $" << fixed << setprecision(2) << getCartTotal() << endl;
}

void Customer::clearCart() {
    cart.clear();
}

double Customer::getCartTotal() const {
    double total = 0;
    for (const auto& item : cart) {
        total += item.first->getPrice() * item.second;
    }
    return total;
}

const vector<pair<Product*, int>>& Customer::getCart() const {
    return cart;
}

bool Customer::isCartEmpty() const {
    return cart.empty();
}

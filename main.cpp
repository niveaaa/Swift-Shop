#include <iostream>
#include <limits>
#include "Shop.h"
#include "Customer.h"

using namespace std;

void productDetailsMenu(Shop& shop, Customer& customer, Product* product) {
    int choice;
    do {
        product->displayDetails();
        cout << "\n1. View Image" << endl;
        cout << "2. Add to Cart" << endl;
        cout << "3. Back" << endl;
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                product->viewImage();
                break;
            case 2: {
                int qty;
                cout << "Enter quantity: ";
                cin >> qty;
                if (qty > 0) {
                    customer.addToCart(product, qty);
                } else {
                    cout << "Invalid quantity." << endl;
                }
                break;
            }
            case 3:
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 3);
}

void browseProducts(Shop& shop, Customer& customer) {
    int productId;
    do {
        shop.listProducts();
        cout << "\nEnter product ID to view details (0 to go back): ";
        cin >> productId;

        if (productId == 0) break;

        Product* product = shop.getProduct(productId);
        if (product != nullptr) {
            productDetailsMenu(shop, customer, product);
        } else {
            cout << "Product not found." << endl;
        }
    } while (true);
}

void cartMenu(Customer& customer) {
    int choice;
    do {
        customer.viewCart();

        if (customer.isCartEmpty()) return;

        cout << "\n1. Remove Item" << endl;
        cout << "2. Back" << endl;
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int itemNo;
                cout << "Enter item number to remove: ";
                cin >> itemNo;
                customer.removeFromCart(itemNo - 1);
                break;
            }
            case 2:
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 2);
}

int main() {
    Shop shop;
    string name;

    cout << "===== SWIFT-SHOP =====" << endl;
    cout << "\nEnter your name: ";
    getline(cin, name);

    Customer customer(name);
    cout << "\nWelcome, " << name << "!" << endl;

    int choice;
    do {
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Browse Products" << endl;
        cout << "2. View Cart" << endl;
        cout << "3. Place Order" << endl;
        cout << "4. View Order History" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter choice: ";
        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                browseProducts(shop, customer);
                break;
            case 2:
                cartMenu(customer);
                break;
            case 3:
                shop.placeOrder(customer);
                break;
            case 4:
                shop.viewOrderHistory(customer.getName());
                break;
            case 5:
                cout << "\nThank you for shopping at Swift-Shop! Goodbye." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

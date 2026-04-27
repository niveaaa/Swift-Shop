#include "Shop.h"

Shop::Shop() : nextOrderId(1001) {
    loadProducts();
    loadOrders();

    // Set next order ID based on existing orders
    for (const auto& order : orders) {
        if (order.getOrderId() >= nextOrderId) {
            nextOrderId = order.getOrderId() + 1;
        }
    }
}

Shop::~Shop() {
    for (auto* product : products) {
        delete product;
    }
    products.clear();
}

void Shop::createDefaultProducts() {
    ofstream file("products.txt");
    if (file.is_open()) {
        file << "Electronics|1|Laptop|999.99|Dell|24|laptop.jpg" << endl;
        file << "Electronics|2|Smartphone|699.99|Samsung|12|smartphone.jpg" << endl;
        file << "Electronics|3|Headphones|149.99|Sony|18|headphones.jpg" << endl;
        file << "Clothing|4|T-Shirt|29.99|L|Cotton|tshirt.jpg" << endl;
        file << "Clothing|5|Jeans|59.99|M|Denim|jeans.jpg" << endl;
        file << "Clothing|6|Jacket|89.99|L|Polyester|jacket.jpg" << endl;
        file << "Food|7|Chocolate Box|12.99|2026-12-01|500|chocolate.jpg" << endl;
        file << "Food|8|Coffee Beans|19.99|2027-03-15|1000|coffee.jpg" << endl;
        file.close();
    }
}

void Shop::loadProducts() {
    ifstream file("products.txt");

    if (!file.is_open()) {
        createDefaultProducts();
        file.open("products.txt");
        if (!file.is_open()) {
            cout << "Error: Could not load products." << endl;
            return;
        }
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        string category;
        getline(iss, category, '|');

        string idStr, name, priceStr;
        getline(iss, idStr, '|');
        getline(iss, name, '|');
        getline(iss, priceStr, '|');

        int id = stoi(idStr);
        double price = stod(priceStr);

        if (category == "Electronics") {
            string brand, warrantyStr, imageFile;
            getline(iss, brand, '|');
            getline(iss, warrantyStr, '|');
            getline(iss, imageFile, '|');
            int warranty = stoi(warrantyStr);
            products.push_back(new Electronics(id, name, price, brand, warranty, imageFile));
        }
        else if (category == "Clothing") {
            string size, material, imageFile;
            getline(iss, size, '|');
            getline(iss, material, '|');
            getline(iss, imageFile, '|');
            products.push_back(new Clothing(id, name, price, size, material, imageFile));
        }
        else if (category == "Food") {
            string expiry, weightStr, imageFile;
            getline(iss, expiry, '|');
            getline(iss, weightStr, '|');
            getline(iss, imageFile, '|');
            int weight = stoi(weightStr);
            products.push_back(new Food(id, name, price, expiry, weight, imageFile));
        }
    }

    file.close();
}

void Shop::loadOrders() {
    ifstream file("orders.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        orders.push_back(Order::fromFileString(line));
    }
    file.close();
}

string Shop::getCurrentDate() const {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    ostringstream oss;
    oss << (1900 + ltm->tm_year) << "-"
        << (ltm->tm_mon + 1 < 10 ? "0" : "") << (1 + ltm->tm_mon) << "-"
        << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday;
    return oss.str();
}

void Shop::listProducts() const {
    cout << "\n--- Available Products ---" << endl;
    cout << left << setw(6) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Category"
         << "Price" << endl;
    cout << string(50, '-') << endl;

    for (const auto* product : products) {
        product->displayRow();
    }
}

Product* Shop::getProduct(int id) const {
    for (auto* product : products) {
        if (product->getId() == id) {
            return product;
        }
    }
    return nullptr;
}

void Shop::placeOrder(Customer& customer) {
    if (customer.isCartEmpty()) {
        cout << "\nYour cart is empty. Add items before placing an order." << endl;
        return;
    }

    // Build items list for order
    vector<pair<string, int>> orderItems;
    for (const auto& item : customer.getCart()) {
        orderItems.push_back(make_pair(item.first->getName(), item.second));
    }

    Order order(nextOrderId, customer.getName(), getCurrentDate(),
                orderItems, customer.getCartTotal());

    orders.push_back(order);
    nextOrderId++;

    // Save to file
    ofstream file("orders.txt", ios::app);
    if (file.is_open()) {
        file << order.toFileString() << endl;
        file.close();
    }

    cout << "\nOrder placed successfully!" << endl;
    cout << "Order ID: " << order.getOrderId() << endl;
    cout << "Total: $" << fixed << setprecision(2) << customer.getCartTotal() << endl;

    customer.clearCart();
}

void Shop::viewOrderHistory(const string& customerName) const {
    cout << "\n--- Order History for " << customerName << " ---" << endl;

    bool found = false;
    for (const auto& order : orders) {
        if (order.getCustomerName() == customerName) {
            order.displayOrder();
            found = true;
        }
    }

    if (!found) {
        cout << "No orders found." << endl;
    }
}

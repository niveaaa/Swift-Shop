# 🛒 Swift-Shop

A console-based e-commerce simulation built in C++, demonstrating object-oriented programming concepts including inheritance, polymorphism, file handling, and system commands.

## Features

- **Product Browsing** — View products in a tabular format across 3 categories
- **Product Categories** — Electronics, Clothing, and Food with category-specific details
- **Image Viewing** — View product images via `system()` command (Windows)
- **Shopping Cart** — Add, remove, and view items with quantity tracking
- **Order Placement** — Place orders with persistent storage to file
- **Order History** — View past orders across sessions

## OOP Concepts

| Concept | Implementation |
|---------|---------------|
| **Classes & Objects** | Product, Electronics, Clothing, Food, Customer, Order, Shop |
| **Inheritance** | Electronics, Clothing, Food inherit from Product base class |
| **Polymorphism** | `displayDetails()`, `getCategory()`, `toFileString()` — virtual methods overridden in derived classes |
| **Encapsulation** | Private/protected attributes with public getters |
| **File Handling** | `products.txt` and `orders.txt` for persistent data storage |
| **System Commands** | `system("start images\\\\...")` to open product images |

## Project Structure

```
mini-project/
├── main.cpp                  # Entry point & menu loop
├── Shop.h / Shop.cpp         # Shop manager (file I/O, orders)
├── base-product/
│   └── Product.h / .cpp      # Base Product class
├── products/
│   ├── Electronics.h / .cpp  # Electronics subclass
│   ├── Clothing.h / .cpp     # Clothing subclass
│   └── Food.h / .cpp         # Food subclass
├── customer-order/
│   ├── Customer.h / .cpp     # Customer & cart
│   └── Order.h / .cpp        # Order tracking
├── images/                   # Product images (.jpg)
├── products.txt              # Product data (pipe-delimited)
└── orders.txt                # Order history
```

## Build & Run

```bash
g++ -o Swift-Shop main.cpp Shop.cpp base-product/Product.cpp products/Electronics.cpp products/Clothing.cpp products/Food.cpp customer-order/Customer.cpp customer-order/Order.cpp

./Swift-Shop
```

## Sample Output

```
===== SWIFT-SHOP =====

Enter your name: Ankita

Welcome, Ankita!

--- Main Menu ---
1. Browse Products
2. View Cart
3. Place Order
4. View Order History
5. Exit

Enter choice: 1

--- Available Products ---
ID    Name              Category       Price
--------------------------------------------------
1     Laptop            Electronics    $999.99
2     Smartphone        Electronics    $699.99
3     Headphones        Electronics    $149.99
4     T-Shirt           Clothing       $29.99
5     Jeans             Clothing       $59.99
6     Jacket            Clothing       $89.99
7     Chocolate Box     Food           $12.99
8     Coffee Beans      Food           $19.99
```

## Data Format

**products.txt** — `Category|ID|Name|Price|...category-specific fields...|ImageFile`
```
Electronics|1|Laptop|999.99|Dell|24|laptop.jpg
Clothing|4|T-Shirt|29.99|L|Cotton|tshirt.jpg
Food|7|Chocolate Box|12.99|2026-12-01|500|chocolate.jpg
```

**orders.txt** — `OrderID|Customer|Date|Items|Total`
```
1002|Ankita|2026-04-27|ChocolateBox:1|12.99
```

## Requirements

- C++ compiler with C++14 support (g++ / MinGW)
- Windows OS (for `system("start ...")` image viewing)

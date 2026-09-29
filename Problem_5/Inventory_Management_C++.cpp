#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

int main() {
    vector<Product> inventory;
    string input;
    int choice;

    do {
        cout << "Inventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Sell Product\n";
        cout << "3. View Inventory\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        getline(cin, input);

        try {
            choice = stoi(input);
        }
        catch (...) {
            cout << "Invalid input. Please enter a number from 1 to 4.\n";
            continue;
        }

        if (choice == 1) {
            Product product;

            cout << "Enter Product ID: ";
            getline(cin, input);
            product.id = stoi(input);

            cout << "Enter Product Name: ";
            getline(cin, product.name);

            cout << "Enter Quantity: ";
            getline(cin, input);
            product.quantity = stoi(input);

            cout << "Enter Price per Unit: ";
            getline(cin, input);
            product.price = stod(input);

            inventory.push_back(product);

            cout << "Product added successfully!\n";
        }

        else if (choice == 2) {
            int id;
            int quantitySold;

            cout << "Enter Product ID: ";
            getline(cin, input);
            id = stoi(input);

            cout << "Enter Quantity to Sell: ";
            getline(cin, input);
            quantitySold = stoi(input);

            bool found = false;

            for (int i = 0; i < inventory.size(); i++) {
                if (inventory[i].id == id) {
                    found = true;

                    if (quantitySold <= inventory[i].quantity) {
                        inventory[i].quantity -= quantitySold;
                        cout << "Sale completed successfully!\n";
                    }
                    else {
                        cout << "Not enough stock!\n";
                    }

                    break;
                }
            }

            if (!found) {
                cout << "Product not found!\n";
            }
        }

        else if (choice == 3) {
            double totalValue = 0;

            cout << "Inventory Summary\n";
            cout << fixed << setprecision(2);

            if (inventory.empty()) {
                cout << "Inventory is empty.\n";
            }
            else {
                for (int i = 0; i < inventory.size(); i++) {
                    double value =
                        inventory[i].quantity * inventory[i].price;

                    totalValue += value;

                    cout << "\nProduct ID: "
                         << inventory[i].id << endl;

                    cout << "Product Name: "
                         << inventory[i].name << endl;

                    cout << "Quantity: "
                         << inventory[i].quantity << endl;

                    cout << "Price per Unit: "
                         << inventory[i].price << endl;

                    cout << "Stock Value: "
                         << value << endl;
                }

                cout << "\nTotal Stock Value: "
                     << totalValue << endl;
            }
        }

        else if (choice == 4) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice. Please enter 1-4.\n";
        }

    } while (choice != 4);

    return 0;
}
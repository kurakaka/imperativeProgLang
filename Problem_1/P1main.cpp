/*
Point of Sale (POS) System
Problem:
A small retail store needs a simple Point of Sale system to process daily 
transactions. Each transaction contains multiple items, their prices, and 
quantities. At checkout, the system should calculate the total bill, apply 
a 10% discount if the customer is a member, and generate a receipt.

Programming Task:
Write a program that:

Accepts item names, prices, and quantities.
Applies discounts (if applicable).
Prints the final bill with itemized details.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

using namespace std;

struct Item {
    string name;
    double price;
    int quantity;
};

int main() {
    vector<Item> transactionList;
    string itemName;
    int itemQuantity;
    double itemPrice,
            discount = 1.0, 
            totalPrice = 0.0;

    const int itemNameWidth = 30,
                itemPriceWidth = 10,
                itemQuantityWidth = 10,
                subTotalWidth = 10;

    cout << "Enter Item Name, Price, and Quantity." << endl;
    cout << "Type 'END' to finish checkout and generate bill." << endl;

    while (true) {
        cout << "\nEnter Item Name: ";
        getline(cin, itemName);
        
        if (itemName == "END" || itemName == "end") {
            break;
        }
        else if (itemName.empty()) {
            cout << "Error: Invalid Item Name.\n";
            continue;
        }

        bool checkDuplicate = false;
        for (const auto& item : transactionList) {
            if (item.name == itemName) {
                checkDuplicate = true;
                break;
            }
        }
        
        if (checkDuplicate) {
            cout << "Error: Item already added.\n";
            continue;
        }

        cout << "Enter Price of " << itemName << ": ";
        if (!(cin >> itemPrice) || itemPrice < 0) {
            cout << "Error: Invalid Price.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter Quantity of " << itemName << ": ";
        if (!(cin >> itemQuantity) || itemQuantity <= 0) {
            cout << "Error: Invalid Quantity.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        transactionList.push_back({itemName, itemPrice, itemQuantity});
    }

    char isMember = 'N';
    cout << "\nIs the customer a member? (Y/N): ";
    cin >> isMember;

    if (toupper(isMember) == 'Y') {
        discount = 0.9;
    }

    cout << fixed << setprecision(2);

    cout << "\n" << string(60, '-') << endl;
    cout << "FINAL BILL" << endl;
    cout << string(60, '-') << endl;
    cout << left << setw(itemNameWidth) << "ITEM NAME"
         << left << setw(itemPriceWidth) << "PRICE"
         << left << setw(itemQuantityWidth) << "QUANTITY"
         << right << setw(subTotalWidth) << "SUBTOTAL" << endl;
    cout << string(60, '-') << endl;

    for (const auto& item : transactionList) {
        double subTotal = item.price * item.quantity;
        totalPrice += subTotal;

        cout << left << setw(itemNameWidth) << item.name
             << left << "₱" << setw(itemPriceWidth) << item.price
             << left << setw(itemQuantityWidth) << item.quantity
             << right << setw(subTotalWidth) << "₱" << subTotal << endl;
    }

    cout << string(60, '-') << endl;

    if (discount < 1.0) {
        cout << left << setw(itemNameWidth + itemPriceWidth + itemQuantityWidth) << "DISCOUNT (10%)"
             << right << setw(subTotalWidth) << "₱" << -(totalPrice * 0.1) << endl;
    }

    cout << left << setw(itemNameWidth + itemPriceWidth + itemQuantityWidth) << "TOTAL"
         << right << setw(subTotalWidth) << "₱" << totalPrice * discount << endl;
    cout << string(60, '-') << endl;

    return 0;
}
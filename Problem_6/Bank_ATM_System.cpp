#include <iostream>
#include <string>

using namespace std;

int main() {
    string accNumbers[3] = {"1001", "1002", "1003"};
    string passwords[3] = {"pass123", "secret456", "atm789"};
    double balances[3] = {5000.00, 12000.50, 300.00};

    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        string inputAcc, inputPass;
        cout << "\n=== BANK ATM WITHDRAWAL SYSTEM ===\n";
        cout << "Enter Account Number: ";
        cin >> inputAcc;
        cout << "Enter Password: ";
        cin >> inputPass;

        int foundIndex = -1;

        if (inputAcc == accNumbers[0] && inputPass == passwords[0]) {
            foundIndex = 0;
        } else if (inputAcc == accNumbers[1] && inputPass == passwords[1]) {
            foundIndex = 1;
        } else if (inputAcc == accNumbers[2] && inputPass == passwords[2]) {
            foundIndex = 2;
        }

        if (foundIndex != -1) {
            double withdrawAmount;
            cout << "\nLogin Successful!";
            cout << "\nCurrent Balance: $" << balances[foundIndex] << "\n";
            cout << "Enter Withdrawal Amount: $";
            cin >> withdrawAmount;

            if (withdrawAmount <= 0) {
                cout << "\nInvalid withdrawal amount.\n";
            } else if (withdrawAmount > balances[foundIndex]) {
                cout << "\nTransaction Failed: Insufficient balance!\n";
            } else {
                balances[foundIndex] = balances[foundIndex] - withdrawAmount;
                cout << "\nTransaction Successful!\n";
                cout << "Remaining Balance: $" << balances[foundIndex] << "\n";
            }
        } else {
            cout << "\nError: Invalid Account Number or Password!\n";
        }

        cout << "\nDo you want to perform another transaction? (y/n): ";
        cin >> choice;
    }

    cout << "\nThank you for using our ATM. Goodbye!\n";
    return 0;
}
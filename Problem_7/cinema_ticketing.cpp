#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>
using namespace std;

int Regular_income = 0, Vip_income = 0;
int Vip_tickets = 0, Regular_tickets = 0;
vector<string> Name, seat_type_per_customer;
vector<int> Tickets, Customer_total, total_per_customer, tickets_per_customer;

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int readPositiveInt(const string& prompt) {
    int n;
    while (true) {
        cout << prompt;
        if (cin >> n && n > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return n;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input\n";
    }
}

void Ticket_type(const string& n) {
    string t = toLower(n);
    if (t == "regular") {
        Customer_total.push_back(250);
        Regular_tickets++;
        Regular_income += 250;
    } else if (t == "vip") {
        Customer_total.push_back(400);
        Vip_tickets++;
        Vip_income += 400;
    }
}

int main() {
    cout << "---------------\n";
    int Transaction = readPositiveInt("Enter Number of Transaction: ");
    cout << "---------------\n\n";

    cout << "---------------\n";
    for (int i = 1; i <= Transaction; i++) {
        cout << "Transaction No. " << i << "\n";
        string C;
        cout << "Name: ";
        getline(cin, C);
        Name.push_back(C);

        int T = readPositiveInt("Enter Number of tickets: ");
        Tickets.push_back(T);
        tickets_per_customer.push_back(T);

        string Tick_type;
        while (true) {
            cout << "Enter Seat Type: Regular, VIP: ";
            getline(cin, Tick_type);
            string l = toLower(Tick_type);
            if (l == "regular" || l == "vip") break;
            cout << "Invalid Input\n";
        }
        seat_type_per_customer.push_back(Tick_type);

        for (int j = 0; j < T; j++) Ticket_type(Tick_type);
        total_per_customer.push_back(accumulate(Customer_total.begin(), Customer_total.end(), 0));
        Customer_total.clear();
        cout << "---------------\n";
    }

    cout << "\n";
    for (int i = 0; i < Transaction; i++) {
        cout << "---------------\n";
        cout << "Transaction No. " << i + 1 << "\n";
        cout << "Customer Name: " << Name[i] << "\n";
        cout << "No. of Tickets: " << tickets_per_customer[i] << "\n";
        cout << "Seat Type: " << seat_type_per_customer[i] << "\n";
        cout << "Total Amount: " << total_per_customer[i] << "\n";
    }
    cout << "---------------\n\n";
    cout << "-------SUMMARY-------\n";
    cout << "Total No. of Customer: " << Name.size() << "\n";
    cout << "Total No. of Ticket Sold: " << accumulate(Tickets.begin(), Tickets.end(), 0) << "\n";
    cout << "Total Income VIP Ticket Sold: " << Vip_income << "\n";
    cout << "Total Income Regular Ticket Sold: " << Regular_income << "\n";
    cout << "Total Income Generated: " << Vip_income + Regular_income << "\n";
    cout << "---------------\n";
    return 0;
}
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int ECONOMY_PRICE = 5000;
const int BUSINESS_PRICE = 10000;

struct Booking {
    string name;
    string flight;
    string seatType;
    int cost;
};

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return tolower(c); });
    return s;
}

string peso(int amount) {
    ostringstream out;
    out << "PHP " << fixed << setprecision(2);
    string digits = to_string(amount);
    string formatted;
    int count = 0;
    for (int i = (int)digits.size() - 1; i >= 0; --i) {
        formatted.insert(formatted.begin(), digits[i]);
        if (++count % 3 == 0 && i != 0) formatted.insert(formatted.begin(), ',');
    }
    out << formatted << ".00";
    return out.str();
}

class ReservationSystem {
    vector<Booking> bookings;

public:
    Booking addBooking(const string& name, const string& flight, const string& seatType) {
        Booking b{name, flight, seatType,
                  seatType == "Economy" ? ECONOMY_PRICE : BUSINESS_PRICE};
        bookings.push_back(b);
        return b;
    }

    vector<Booking> flightBookings(const string& flight) const {
        vector<Booking> result;
        for (const auto& b : bookings) {
            if (toLower(b.flight) == toLower(flight)) result.push_back(b);
        }
        return result;
    }

    int totalRevenue(const string& flight) const {
        int total = 0;
        for (const auto& b : flightBookings(flight)) total += b.cost;
        return total;
    }

    void printPassengerList(const string& flight) const {
        auto rows = flightBookings(flight);
        cout << "\nPassenger List - Flight " << flight << "\n";
        cout << string(52, '-') << "\n";
        cout << left << setw(25) << "Name" << setw(12) << "Seat Type"
             << right << setw(15) << "Cost" << "\n";
        cout << string(52, '-') << "\n";
        if (rows.empty()) cout << "No bookings for this flight.\n";
        for (const auto& b : rows) {
            cout << left << setw(25) << b.name << setw(12) << b.seatType
                 << right << setw(15) << peso(b.cost) << "\n";
        }
        cout << string(52, '-') << "\n";
        cout << left << setw(37) << "Total Revenue:"
             << right << setw(15) << peso(totalRevenue(flight)) << "\n\n";
    }
};

string readSeatType() {
    while (true) {
        cout << "Seat type (E = Economy, B = Business): ";
        string choice;
        getline(cin, choice);
        if (!choice.empty()) {
            char c = toupper((unsigned char)choice[0]);
            if (choice.size() == 1 && c == 'E') return "Economy";
            if (choice.size() == 1 && c == 'B') return "Business";
        }
        cout << "Invalid choice. Enter E or B.\n";
    }
}

int main() {
    ReservationSystem system;
    string choice;

    while (true) {
        cout << "=== Airline Reservation System ===\n"
             << "1. Add booking\n"
             << "2. Print passenger list for a flight\n"
             << "3. Show total revenue for a flight\n"
             << "4. Exit\n"
             << "Choose: ";
        getline(cin, choice);

        if (choice == "1") {
            string name, flight;
            cout << "Passenger name: ";
            getline(cin, name);
            cout << "Flight number: ";
            getline(cin, flight);
            string seat = readSeatType();
            Booking b = system.addBooking(name, flight, seat);
            cout << "Booked " << b.name << " on " << b.flight << " ("
                 << b.seatType << ") - " << peso(b.cost) << "\n\n";
        } else if (choice == "2") {
            string flight;
            cout << "Flight number: ";
            getline(cin, flight);
            system.printPassengerList(flight);
        } else if (choice == "3") {
            string flight;
            cout << "Flight number: ";
            getline(cin, flight);
            cout << "Total revenue for " << flight << ": "
                 << peso(system.totalRevenue(flight)) << "\n\n";
        } else if (choice == "4") {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid option.\n\n";
        }
    }
    return 0;
}

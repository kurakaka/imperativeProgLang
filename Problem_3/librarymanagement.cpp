/*Problem:
A school library wants to track books borrowed by students. Each transaction includes:

Student ID, book title, borrow date, and return date.
The system should calculate the number of days borrowed and charge a ₱5 fine per day late (after 7 days).
Programming Task:
Write a program that:

Accepts borrowing and returning details.
Calculates fines if applicable.
Displays a transaction report for each student.*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cctype>
#include <algorithm>

struct Date {
    int month;
    int day;
    int year;
};

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t\r\n");
    return str.substr(start, end - start + 1);
}

// lowercase
std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return str;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// month 
int getDaysInMonth(int month, int year) {
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) return 29;
    return days[month];
}

// trycath date
bool isValidDate(int m, int d, int y) {
    if (y < 1900 || y > 2100) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > getDaysInMonth(m, y)) return false;
    return true;
}

// m-d-y format checker
bool parseDate(const std::string& dateStr, Date& outDate) {
    std::string s = trim(dateStr);
    for (char &c : s) {
        if (c == '/') c = '-';
    }

    std::stringstream ss(s);
    int m, d, y;
    char dash1, dash2;

    if (ss >> m >> dash1 >> d >> dash2 >> y) {
        if (dash1 == '-' && dash2 == '-' && ss.eof()) {
            if (isValidDate(m, d, y)) {
                outDate = {m, d, y};
                return true;
            }
        }
    }
    return false;
}

// standarlization
long dateToDays(const Date& d) {
    int m = d.month;
    int y = d.year;
    if (m <= 2) {
        y -= 1;
        m += 12;
    }
    return 365L * y + y / 4 - y / 100 + y / 400 + (153 * (m + 1)) / 5 + d.day;
}

// now
Date getTodayDate() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    return { now->tm_mon + 1, now->tm_mday, now->tm_year + 1900 };
}

// padding
std::string formatDate(const Date& d) {
    std::ostringstream ss;
    ss << std::setw(2) << std::setfill('0') << d.month << "-"
       << std::setw(2) << std::setfill('0') << d.day << "-"
       << d.year;
    return ss.str();
}

// trcatch id
std::string getValidStudentID() {
    std::string id;
    while (true) {
        std::cout << "Enter Student ID (12 digits): " << std::flush;
        std::getline(std::cin, id);
        id = trim(id);

        bool allDigits = !id.empty();
        for (char c : id) {
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                allDigits = false;
                break;
            }
        }

        if (allDigits && id.length() == 12) {
            return id;
        }

        std::cout << "Invalid Student ID! Must consist of exactly 12 numbers with no letters or symbols.\n\n";
    }
}

// calc
void calculateFine(long daysBorrowed, long& lateDays, double& fineAmount) {
    const long allowedDays = 7;
    const double finePerDay = 5.0;

    if (daysBorrowed > allowedDays) {
        lateDays = daysBorrowed - allowedDays;
        fineAmount = lateDays * finePerDay;
    } else {
        lateDays = 0;
        fineAmount = 0.0;
    }
}

void processTransaction() {
    std::cout << "=== School Library Borrowing System ===\n";

    while (true) {
        std::cout << "\n----------------------------------------\n";
        std::cout << "NEW TRANSACTION\n";
        std::cout << "----------------------------------------\n";

        std::string studentId = getValidStudentID();

        std::string bookTitle;
        std::cout << "Enter Book Title: " << std::flush;
        std::getline(std::cin, bookTitle);
        bookTitle = trim(bookTitle);

        // input date
        Date borrowDate;
        while (true) {
            std::string borrowStr;
            std::cout << "Enter Borrow Date (MM-DD-YYYY) or type 'now' for today: " << std::flush;
            std::getline(std::cin, borrowStr);
            borrowStr = toLower(trim(borrowStr));

            if (borrowStr == "now" || borrowStr == "today") {
                borrowDate = getTodayDate();
                break;
            }

            if (parseDate(borrowStr, borrowDate)) {
                break;
            }

            std::cout << "Invalid date format. Please use MM-DD-YYYY (e.g., 09-30-2026) or type 'now'.\n";
        }

        // return date
        Date returnDate;
        while (true) {
            std::string returnStr;
            std::cout << "Enter Return Date (MM-DD-YYYY): " << std::flush;
            std::getline(std::cin, returnStr);

            if (parseDate(returnStr, returnDate)) {
                if (dateToDays(returnDate) < dateToDays(borrowDate)) {
                    std::cout << "Return date cannot be earlier than borrow date. Try again.\n";
                    continue;
                }
                break;
            }

            std::cout << "Invalid date format. Please use MM-DD-YYYY (e.g., 10-05-2026).\n";
        }

        // calc
        long daysBorrowed = dateToDays(returnDate) - dateToDays(borrowDate);
        long lateDays = 0;
        double fineAmount = 0.0;
        calculateFine(daysBorrowed, lateDays, fineAmount);

        // report
        std::cout << "\n========================================\n";
        std::cout << "        TRANSACTION REPORT\n";
        std::cout << "========================================\n";
        std::cout << "Student ID    : " << studentId << "\n";
        std::cout << "Book Title    : " << bookTitle << "\n";
        std::cout << "Borrow Date   : " << formatDate(borrowDate) << "\n";
        std::cout << "Return Date   : " << formatDate(returnDate) << "\n";
        std::cout << "Days Borrowed : " << daysBorrowed << " day(s)\n";
        std::cout << "Late Days     : " << lateDays << " day(s)\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Total Fine    : PHP " << fineAmount << "\n";
        std::cout << "========================================\n";

        // loop
        std::string choice;
        while (true) {
            std::cout << "\nDo you want to process another transaction? (y/n): " << std::flush;
            std::getline(std::cin, choice);
            choice = toLower(trim(choice));

            if (choice == "y" || choice == "yes" || choice == "n" || choice == "no") {
                break;
            }
            std::cout << "Invalid response. Please enter 'y' for yes or 'n' for no.\n";
        }

        if (choice == "n" || choice == "no") {
            std::cout << "\nExiting system. Have a great day!\n";
            break;
        }
    }
}

//main
int main() {
    std::cout << "\ncpp librarymanagement.cpp\n";
    processTransaction();
    return 0;
}
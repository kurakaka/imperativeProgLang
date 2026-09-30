/*Problem:
A school library wants to track books borrowed by students. Each transaction includes:

Student ID, book title, borrow date, and return date.
The system should calculate the number of days borrowed and charge a ₱5 fine per day late (after 7 days).
Programming Task:
Write a program that:

Accepts borrowing and returning details.
Calculates fines if applicable.
Displays a transaction report for each student.*/
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.time.temporal.ChronoUnit;
import java.util.Scanner;

public class librarymanagement {

    private static final DateTimeFormatter DATE_FORMATTER = DateTimeFormatter.ofPattern("MM-dd-yyyy");

    // now
    private static LocalDate parseDate(String dateStr) throws DateTimeParseException {
        return LocalDate.parse(dateStr.trim(), DATE_FORMATTER);
    }

    // standarilization
    private static String formatDate(LocalDate date) {
        return date.format(DATE_FORMATTER);
    }

    // id
    private static String getValidStudentID(Scanner scanner) {
        while (true) {
            System.out.print("Enter Student ID (12 digits): ");
            String studentId = scanner.nextLine().trim();

            if (studentId.matches("\\d{12}")) {
                return studentId;
            }

            System.out.println("Invalid Student ID! Must consist of exactly 12 numbers with no letters or symbols.\n");
        }
    }

    // calc
    private static FineResult calculateFine(long daysBorrowed) {
        long allowedDays = 7;
        double finePerDay = 5.0;

        if (daysBorrowed > allowedDays) {
            long lateDays = daysBorrowed - allowedDays;
            return new FineResult(lateDays, lateDays * finePerDay);
        }
        return new FineResult(0, 0.0);
    }

    private static class FineResult {
        long lateDays;
        double fineAmount;

        FineResult(long lateDays, double fineAmount) {
            this.lateDays = lateDays;
            this.fineAmount = fineAmount;
        }
    }

    public static void processTransaction() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("=== School Library Borrowing System ===");

        while (true) {
            System.out.println("\n----------------------------------------");
            System.out.println("NEW TRANSACTION");
            System.out.println("----------------------------------------");

            // input detailds
            String studentId = getValidStudentID(scanner);

            System.out.print("Enter Book Title: ");
            String bookTitle = scanner.nextLine().trim();

            // borrow date inut
            LocalDate borrowDate = null;
            while (true) {
                System.out.print("Enter Borrow Date (MM-DD-YYYY) or type 'now' for today: ");
                String borrowStr = scanner.nextLine().trim().toLowerCase();

                if (borrowStr.equals("now") || borrowStr.equals("today")) {
                    borrowDate = LocalDate.now();
                    break;
                }

                try {
                    borrowDate = parseDate(borrowStr);
                    break;
                } catch (DateTimeParseException e) {
                    System.out.println("Invalid date format. Please use MM-DD-YYYY (e.g., 09-30-2026) or type 'now'.");
                }
            }

            // returndate input
            LocalDate returnDate = null;
            while (true) {
                System.out.print("Enter Return Date (MM-DD-YYYY): ");
                String returnStr = scanner.nextLine().trim();

                try {
                    returnDate = parseDate(returnStr);

                    if (returnDate.isBefore(borrowDate)) {
                        System.out.println("Return date cannot be earlier than borrow date. Try again.");
                        continue;
                    }
                    break;
                } catch (DateTimeParseException e) {
                    System.out.println("Invalid date format. Please use MM-DD-YYYY (e.g., 10-05-2026).");
                }
            }

            // calc
            long daysBorrowed = ChronoUnit.DAYS.between(borrowDate, returnDate);
            FineResult fineResult = calculateFine(daysBorrowed);

            // report
            System.out.println("\n========================================");
            System.out.println("        TRANSACTION REPORT");
            System.out.println("========================================");
            System.out.println("Student ID    : " + studentId);
            System.out.println("Book Title    : " + bookTitle);
            System.out.println("Borrow Date   : " + formatDate(borrowDate));
            System.out.println("Return Date   : " + formatDate(returnDate));
            System.out.println("Days Borrowed : " + daysBorrowed + " day(s)");
            System.out.println("Late Days     : " + fineResult.lateDays + " day(s)");
            System.out.printf("Total Fine    : ₱%.2f%n", fineResult.fineAmount);
            System.out.println("========================================");

            // loop
            String choice = "";
            while (true) {
                System.out.print("\nDo you want to process another transaction? (y/n): ");
                choice = scanner.nextLine().trim().toLowerCase();

                if (choice.equals("y") || choice.equals("yes") || choice.equals("n") || choice.equals("no")) {
                    break;
                }
                System.out.println("Invalid response. Please enter 'y' for yes or 'n' for no.");
            }

            if (choice.equals("n") || choice.equals("no")) {
                System.out.println("\nExiting system. Have a great day!");
                break;
            }
        }

        scanner.close();
    }

    //main
    public static void main(String[] args) {
        System.out.println("\njava librarymanagement.java\n");
        processTransaction();
    }

}

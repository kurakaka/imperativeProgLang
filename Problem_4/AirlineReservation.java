import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AirlineReservation {

    static final int ECONOMY_PRICE = 5000;
    static final int BUSINESS_PRICE = 10000;

    static class Booking {
        String name;
        String flight;
        String seatType;
        int cost;

        Booking(String name, String flight, String seatType) {
            this.name = name;
            this.flight = flight;
            this.seatType = seatType;
            this.cost = seatType.equals("Economy") ? ECONOMY_PRICE : BUSINESS_PRICE;
        }
    }

    static class ReservationSystem {
        private final List<Booking> bookings = new ArrayList<>();

        Booking addBooking(String name, String flight, String seatType) {
            Booking b = new Booking(name, flight, seatType);
            bookings.add(b);
            return b;
        }

        List<Booking> flightBookings(String flight) {
            List<Booking> result = new ArrayList<>();
            for (Booking b : bookings) {
                if (b.flight.equalsIgnoreCase(flight)) {
                    result.add(b);
                }
            }
            return result;
        }

        int totalRevenue(String flight) {
            int total = 0;
            for (Booking b : flightBookings(flight)) {
                total += b.cost;
            }
            return total;
        }

        void printPassengerList(String flight) {
            List<Booking> rows = flightBookings(flight);
            System.out.println("\nPassenger List - Flight " + flight);
            System.out.println("-".repeat(52));
            System.out.printf("%-25s%-12s%15s%n", "Name", "Seat Type", "Cost");
            System.out.println("-".repeat(52));
            if (rows.isEmpty()) {
                System.out.println("No bookings for this flight.");
            }
            for (Booking b : rows) {
                System.out.printf("%-25s%-12s%15s%n", b.name, b.seatType, peso(b.cost));
            }
            System.out.println("-".repeat(52));
            System.out.printf("%-37s%15s%n%n", "Total Revenue:", peso(totalRevenue(flight)));
        }
    }

    static String peso(int amount) {
        return String.format("PHP %,.2f", (double) amount);
    }

    static String readSeatType(Scanner sc) {
        while (true) {
            System.out.print("Seat type (E = Economy, B = Business): ");
            String choice = sc.nextLine().trim().toUpperCase();
            if (choice.equals("E")) return "Economy";
            if (choice.equals("B")) return "Business";
            System.out.println("Invalid choice. Enter E or B.");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ReservationSystem system = new ReservationSystem();

        while (true) {
            System.out.println("=== Airline Reservation System ===");
            System.out.println("1. Add booking");
            System.out.println("2. Print passenger list for a flight");
            System.out.println("3. Show total revenue for a flight");
            System.out.println("4. Exit");
            System.out.print("Choose: ");
            String choice = sc.nextLine().trim();

            switch (choice) {
                case "1": {
                    System.out.print("Passenger name: ");
                    String name = sc.nextLine().trim();
                    System.out.print("Flight number: ");
                    String flight = sc.nextLine().trim();
                    String seat = readSeatType(sc);
                    Booking b = system.addBooking(name, flight, seat);
                    System.out.println("Booked " + b.name + " on " + b.flight
                            + " (" + b.seatType + ") - " + peso(b.cost) + "\n");
                    break;
                }
                case "2": {
                    System.out.print("Flight number: ");
                    system.printPassengerList(sc.nextLine().trim());
                    break;
                }
                case "3": {
                    System.out.print("Flight number: ");
                    String flight = sc.nextLine().trim();
                    System.out.println("Total revenue for " + flight + ": "
                            + peso(system.totalRevenue(flight)) + "\n");
                    break;
                }
                case "4":
                    System.out.println("Goodbye!");
                    sc.close();
                    return;
                default:
                    System.out.println("Invalid option.\n");
            }
        }
    }
}

import java.util.ArrayList;
import java.util.Scanner;

public class CinemaTicketing {
    static int regularIncome = 0, vipIncome = 0;
    static int vipTickets = 0, regularTickets = 0;
    static ArrayList<String> names = new ArrayList<>();
    static ArrayList<String> seatTypePerCustomer = new ArrayList<>();
    static ArrayList<Integer> tickets = new ArrayList<>();
    static ArrayList<Integer> customerTotal = new ArrayList<>();
    static ArrayList<Integer> totalPerCustomer = new ArrayList<>();
    static ArrayList<Integer> ticketsPerCustomer = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);

    static int readPositiveInt(String prompt) {
        while (true) {
            System.out.print(prompt);
            try {
                int n = Integer.parseInt(sc.nextLine().trim());
                if (n > 0) return n;
            } catch (NumberFormatException e) {
            }
            System.out.println("Invalid Input");
        }
    }

    static void ticketType(String n) {
        if (n.equalsIgnoreCase("regular")) {
            customerTotal.add(250);
            regularTickets++;
            regularIncome += 250;
        } else if (n.equalsIgnoreCase("vip")) {
            customerTotal.add(400);
            vipTickets++;
            vipIncome += 400;
        }
    }

    static int sum(ArrayList<Integer> list) {
        int s = 0;
        for (int x : list) s += x;
        return s;
    }

    public static void main(String[] args) {
        System.out.println("---------------");
        int transaction = readPositiveInt("Enter Number of Transaction: ");
        System.out.println("---------------");
        System.out.println();

        System.out.println("---------------");
        for (int i = 1; i <= transaction; i++) {
            System.out.println("Transaction No. " + i);
            System.out.print("Name: ");
            names.add(sc.nextLine());

            int t = readPositiveInt("Enter Number of tickets: ");
            tickets.add(t);
            ticketsPerCustomer.add(t);

            String tickType;
            while (true) {
                System.out.print("Enter Seat Type: Regular, VIP: ");
                tickType = sc.nextLine().trim();
                if (tickType.equalsIgnoreCase("regular") || tickType.equalsIgnoreCase("vip")) break;
                System.out.println("Invalid Input");
            }
            seatTypePerCustomer.add(tickType);

            for (int j = 0; j < t; j++) ticketType(tickType);
            totalPerCustomer.add(sum(customerTotal));
            customerTotal.clear();
            System.out.println("---------------");
        }

        System.out.println();
        for (int i = 0; i < transaction; i++) {
            System.out.println("---------------");
            System.out.println("Transaction No. " + (i + 1));
            System.out.println("Customer Name: " + names.get(i));
            System.out.println("No. of Tickets: " + ticketsPerCustomer.get(i));
            System.out.println("Seat Type: " + seatTypePerCustomer.get(i));
            System.out.println("Total Amount: " + totalPerCustomer.get(i));
        }
        System.out.println("---------------");
        System.out.println();
        System.out.println("-------SUMMARY-------");
        System.out.println("Total No. of Customer: " + names.size());
        System.out.println("Total No. of Ticket Sold: " + sum(tickets));
        System.out.println("Total Income VIP Ticket Sold: " + vipIncome);
        System.out.println("Total Income Regular Ticket Sold: " + regularIncome);
        System.out.println("Total Income Generated: " + (vipIncome + regularIncome));
        System.out.println("---------------");
    }
}